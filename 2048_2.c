#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

#define N_jogadores 1
#define largur 10
#define altur 10

void printa_tabela(int linhas, int colunas,int tabuleiro[linhas][colunas]){
	
	for(int i= 0;i< linhas;i++){
    for(int j= 0;j<colunas;j++){
      printf(" %d ",tabuleiro[i][j]);
    }
    printf("\n");
  }

}

//Funções feitas para o movimento do jogo(tentamos na verdade)

void move_direita(int largura,int altura,int tabuleiro[altura][largura]) {
    int i, j, k; // variável 'k' representa a posição que se encontra à direita 
    for (i = 0; i < altura; i++) { // for passando pela lina da tabela
        for (j = 0; j < largura - 1; j++) { // for passando pela coluna da tabela
            for (k = j + 1; k < largura; k++) {// 'k' representado por 'j + 1' para ser a posição a direita                
                if (tabuleiro[i][k] == 0) { // caso a posição a direita seja 0(vazio)                        
                    tabuleiro[i][k] = tabuleiro[i][j]; // pocição a direita recebe posição anterior a ela             
                } else if (tabuleiro[i][k] == tabuleiro[i][j]) { // se a posição a direita for um número igual
                    tabuleiro[i][k] = tabuleiro[i][j] * 2; // o valor que está a direita é dobrado(valores se juntam)
                    tabuleiro[i][j]= 0;
                }
                break; // finaliza o movimento              
            }
        }
    }
}

void move_esquerda(int largura, int altura,int tabuleiro[altura][largura]) {
    int i, j, k; //variável 'k' representa a posição que se encontra à esquerda
    for (i = 0; i < altura; i++) {
        for (j =largura - 1; j > 0; j--) {
            for (k = j - 1; k >= 0; k--) { // 'k' representado por 'j - 1' para ser a posição a esquerda            
                if (tabuleiro[i][k] == 0) { // caso a posição a esquerda seja 0(vazio)
                    tabuleiro[i][k] = tabuleiro[i][j]; // pocição a esquerda recebe posição posterior a ela
                    tabuleiro[i][j] = 0; // como a posição [i][j] foi movido para a esquerda, ela será zerada
                } else if (tabuleiro[i][k] == tabuleiro[i][j]) { // se a posição a esquerda for um número igual
                    tabuleiro[i][k] = tabuleiro[i][j] * 2; // o valor que está a esquerda é dobrado(valores se juntam)
                    tabuleiro[i][j] = 0; // como a posição [i][j] foi movido para a esquerda, ela será zerada
                }
                break; // finaliza o movimento                
            }
        }
    }
}

void move_cima(int altura,int largura,int tabuleiro[altura][largura]) {
    int i, j, k;
    for (j = 0; j < largura; j++) {
        for (i = 0; i < altura - 1; i++) {
            for (k = i + 1; k < altura; k++) { // 'k' representado por 'i + 1' para ser a posição acima    
                if (tabuleiro[k][j] == 0) { // caso a posição acima seja 0(vazio)
                    tabuleiro[k][j] = tabuleiro[i][j]; // pocição acima recebe posição abaixo dela
                    tabuleiro[i][j] = 0; // como a posição [i][j] foi movido para cima, ela será zerada                        
                } else if (tabuleiro[k][j] == tabuleiro[i][j]) { // se a posição acima for um número igual
                    tabuleiro[k][j] = tabuleiro[i][j] * 2; // o valor que está acima é dobrado(valores se juntam)
                    tabuleiro[i][j] = 0; // como a posição [i][j] foi movido para cima, ela será zerada
                }
                break; // finaliza o movimento
            }
        }
    }
    //break 
}

void move_baixo(int altura,int largura, int tabuleiro[altura][largura]) {
    int i, j, k;
    for (j = 0; j < largura; j++) {
        for (i = altura - 1; i > 0; i--) {
            for (k = i - 1; k >= 0; k--) { // 'k' representado por 'i - 1' para ser a posição abaixo
                if (tabuleiro[k][j] == 0) { // caso a posição abaixo seja 0(vazio)
                    tabuleiro[k][j] = tabuleiro[i][j]; // pocição abaixo recebe posição acima dela
                    tabuleiro[i][j] = 0; // como a posicao [i][j] foi movido para baixo, ela será zerada                       
                } else if (tabuleiro[k][j] == tabuleiro[i][j]) { // se a posição abaixo for um número igual 
                    tabuleiro[k][j] = tabuleiro[i][j] * 2; // o valor que está abaixo é dobrado(valores se juntam)
                    tabuleiro[i][j] = 0; // como a posição [i][j] foi movido para baixo, ela sera zerada
                }
                break; // finaliza o movimento
            }
        }
    }
}


struct jogador{
	char nome[50];//o nome que a pessoa escolheu para ser registrada ser registrada
}player[N_jogadores];//ele vai guardar os 5 jogadores 

//Faz gerar blocos de valor 2(maior probabilidade) e 
//4(menor probabilidade) numa posicao aleatoria vazia no tabuleiro

int surge_peca(int largura, int altura,int tabuleiro[altura][largura]){
    int numero;
    int i, j;
    
//Randomizacao
    numero== rand() % 10; // comando rand() sorteia de numeros até 10

    i = rand()%altura; // faz cair em uma posicao aleatoria do tabuleiro
    j = rand()%largura; // faz cair em uma posicao aleatoria do tabuleiro
        
    if(numero>= 9 && tabuleiro[i][j]== 0) tabuleiro[i][j]= 4; // caso seja 9 ou 10 printa 4 na posicao  (10% de chance)
    if(numero<= 8 && tabuleiro[i][j]== 0) tabuleiro[i][j]= 2; // caso seja de 1 até 8 printa 2 na posicao  (90% de chance)
}
 
int estado_do_jogo(int largura, int altura,int tabuleiro[altura][largura]){	//checa condicoes de vitoria e derrota alem de pegar o nome do jogador vencedor
	int i,j, multiplicacao_das_posicoes= 1;
	
    for(i = 0; i<altura; i++){
	    for(j = 0; j<largura; j++){
		    multiplicacao_das_posicoes= multiplicacao_das_posicoes*tabuleiro[i][j];
		    if(tabuleiro[i][j] == 2048) return 1; //vitoria.
		    if(tabuleiro[i][j] != 0) return 2; // derrota porque ocupou todas as posicoes do tabuleiro
            else return 3; //continua o jogo
	    }
    }
}

int jogo(int alt, int lar,int tabuleiro[alt][lar]){// as mecanicas do jogo comecam aqui
	char movimento;
	
    while(3){ 
		estado_do_jogo(lar,alt,tabuleiro);
		if(estado_do_jogo(lar,alt,tabuleiro) == 1){
		printf("Voce venceu. Insira seu nome;");
		return 0;
		}
		if(estado_do_jogo(lar,alt,tabuleiro) == 2) return 0;// vai encerrar o programa caso o num de pecas ocupe todo o tabuleiro

    surge_peca(lar,alt,tabuleiro);

    //parte responsavel por printar a tabela

	printa_tabela(alt,lar,tabuleiro);
	
    printf("Aperte w:move para cima  a:move para esquerda  s:move para baixo  d:move para direita  q para sair do jogo\n");
    scanf(" %c", &movimento);
 
  //Parte responsavel pela movimentacao onde as colunas e as linhas se movimentam
  
    switch (movimento) {
            case 'd':
                move_direita(alt,lar,tabuleiro);
                break;
            case 'a':
                move_esquerda(alt,lar,tabuleiro);
                break;
            case 'w':
                move_cima(alt,lar,tabuleiro);
                break;
            case 's':
                move_baixo(alt,lar,tabuleiro);
                break;
            case 'q':
                return 0;
            default:
                break;//
        }
    }
}


//struct matriz{posicao[i][j]}

int main(int argc,char* argv[2]){
  
  const int largura= atoi(argv[2]);
  const int altura= atoi(argv[1]);

 struct matriz{
  int posicao[altur][largur];
}tabuleiro;

	for(int i= 0; i<altura;i++){ //preenche o vetor tabuleiro com 0
    for(int j= 0;j<largura;j++){
        tabuleiro.posicao[i][j]= 0;
    }
  }
  
  jogo(altura,largura,tabuleiro.posicao);
}
