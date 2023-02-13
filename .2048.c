#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>


#define N 4 // define o máximo de (linha)(coluna) trrar isso 
#define N_jogadores 1

void printa_tabela(int linhas, int colunas){
  for(int i= 0;i< linhas;i++){
    for(int j= 0;j<colunas){
      printf("%d",tabuleiro.posicao[i][j]);
    }
    printf("\n");
  }

}

//Funções feitas para o movimento do jogo(tentamos na verdade)

void move_direita(int tabuleiro[N][N]) {
    int i, j, k; // variável 'k' representa a posição que se encontra à direita 
    for (i = 0; i < N; i++) { // for passando pela lina da tabela
        for (j = 0; j < N - 1; j++) { // for passando pela coluna da tabela
            for (k = j + 1; k < N; k++) {// 'k' representado por 'j + 1' para ser a posição a direita                
                if (tabuleiro[i][k] == 0) { // caso a posição a direita seja 0(vazio)                        
                    tabuleiro[i][k] = tabuleiro[i][j]; // pocição a direita recebe posição anterior a ela
                    tabuleiro[i][j] = 0; // como a posição [i][j] foi movido para a direita, ela será zerada               
                } else if (tabuleiro[i][k] == tabuleiro[i][j]) { // se a posição a direita for um número igual
                    tabuleiro[i][k] = tabuleiro[i][j] * 2; // o valor que está a direita é dobrado(valores se juntam)
                    tabuleiro[i][j] = 0; // como a posição [i][j] foi movido para a direita, ela será zerada
                }
                break; // finaliza o movimento              
            }
        }
    }
}

void move_esquerda(int tabuleiro[N][N]) {
    int i, j, k; //variável 'k' representa a posição que se encontra à esquerda
    for (i = 0; i < N; i++) {
        for (j = N - 1; j > 0; j--) {
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

void move_cima(int tabuleiro[N][N]) {
    int i, j, k;
    for (j = 0; j < N; j++) {
        for (i = 0; i < N - 1; i++) {
            for (k = i + 1; k < N; k++) { // 'k' representado por 'i + 1' para ser a posição acima    
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
}

void move_baixo(int tabuleiro[N][N]) {
    int i, j, k;
    for (j = 0; j < N; j++) {
        for (i = N - 1; i > 0; i--) {
            for (k = i - 1; k >= 0; k--) { // 'k' representado por 'i - 1' para ser a posição abaixo
                if (tabuleiro[k][j] == 0) { // caso a posição abaixo seja 0(vazio)
                    tabuleiro[k][j] = tabuleiro[i][j]; // pocição abaixo recebe posição acima dela
                    tabuleiro[i][j] = 0; // como a posição [i][j] foi movido para baixo, ela será zerada                       
                } else if (tabuleiro[k][j] == tabuleiro[i][j]) { // se a posição abaixo for um número igual 
                    tabuleiro[k][j] = tabuleiro[i][j] * 2; // o valor que está abaixo é dobrado(valores se juntam)
                    tabuleiro[i][j] = 0; // como a posição [i][j] foi movido para baixo, ela será zerada
                }
                break; // finaliza o movimento
            }
        }
    }
}


struct jogador{
	char nome[50];//o nome que a pessoa escolheu para ser registrada ser registrada
}player[N_jogadores];//ele vai guardar os 5 jogadores 

struct matriz{ //tabuleiro de pecas
	int posicao[N][N];//alterara isso, inicializar a posicao dentro do jogo, para alocar dinamicamente a memoria
}tabuleiro;

//Faz gerar blocos de valor 2(maior probabilidade) e 
//4(menor probabilidade) numa posicao aleatoria vazia no tabuleiro

int surge_peca(void){
    int numero;
    int i, j;
 
// Parte responsavel por definir todas as posições do tabuleiro como 0(vazio)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro.posicao[i][j] = 0;
        }
    }
//Randomizacao

    numero== rand() % 10; // comando rand() sorteia de números até 10

    i = rand()%N; // faz cair em uma posicao aleatoria do tabuleiro
    j = rand()%N; // faz cair em uma posicao aleatoria do tabuleiro
        
    if(numero>= 9 && tabuleiro.posicao[i][j]== 0) tabuleiro.posicao[i][j]= 4; // caso seja 9 ou 10 printa 4 na posicao  (20% de chance)
    if(numero<= 8 && tabuleiro.posicao[i][j]== 0) tabuleiro.posicao[i][j]= 2; // caso seja de 1 até 8 printa 2 na posicao  (80% de chance)
}
 
int estado_do_jogo(void){	//checa condicoes de vitoria e derrota alem de pegar o nome do jogador vencedor
	int i,j, multiplicacao_das_posicoes= 1;
	
    for(i = 0; i<N; i++){
	    for(j = 0; j<N; j++){
		    multiplicacao_das_posicoes= multiplicacao_das_posicoes*tabuleiro.posicao[i][j];
		    if(tabuleiro.posicao[i][j] == 2048) return 1; //vitoria.
		    if(tabuleiro.posicao[i][j] != 0) return 2; // derrota porque ocupou todas as posicoes do tabuleiro
            else return 3; //continua o jogo
	    }
    }
}

int jogo(){// as mecanicas do jogo comecam aqui
	char movimento;
	
    while(3){ 
		estado_do_jogo();
		if(estado_do_jogo() == 1){
		printf("Voce venceu. Insira seu nome;");
		return 0;
		}
		if(estado_do_jogo() == 2) return 0;// vai encerrar o programa caso o num de pecas ocupe todo o tabuleiro

    surge_peca();

    //parte responsavel por printar a tabela

	printa_tabela();
	
    printf("Aperte w:move para cima  a:move para esquerda  s:move para baixo  d:move para direita  q para sair do jogo\n");
    scanf(" %c", &movimento);
 
  //Parte responsavel pela movimentacao onde as colunas e as linhas se movimentam
  
    switch (movimento) {
            case 'd':
                move_direita(tabuleiro.posicao);
                break;
            case 'a':
                move_esquerda(tabuleiro.posicao);
                break;
            case 'w':
                move_cima(tabuleiro.posicao);
                break;
            case 's':
                move_baixo(tabuleiro.posicao);
                break;
            case 'q':
                return 0;
            default:
                break;//
        }
    }
}
int main(argc,argv[2]){
  
  #define ALT argv[1]
  #define LAR argv[2]

  #ifdef ALT LAR 
  jogo();
  #else
    printf("Tamanho indefinido");
  exit(1);
}