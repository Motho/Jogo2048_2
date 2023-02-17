# Jogo2048_2
Trabalho 2 programacao 1 ufes 

Sera refeito com alocacao dinamica


char** tabuleiro;
  //aloca para as linhas
  tabuleiro= malloc(TAMANHO_LINHA*sizeof(char*));
  //loop que aloca para colunas atraves de um loop
  for(int i= 0;i<TAMANHO_LINHA;i++){
      tabuleiro[i]= malloc(TAMANHO_COLUNA*sizeof(char));
  }
  //inicializa o tabuleiro com 'A'
  for(int i= 0;i<TAMANHO_LINHA;i++){
    for(int j= 0;j<TAMANHO_COLUNA;j++){
      tabuleiro[i][j]= 'A';
    }
  }
