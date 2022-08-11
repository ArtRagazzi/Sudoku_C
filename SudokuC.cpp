#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int matrizJogada[9][9], matrizPrincipal[9][9], dificuldade;

void copiaMatriz(int sudoku1[9][9], int sudoku2[9][9]){
    int i,j;
    for(i=0; i < 9; i++){
        for(j=0; j < 9; j++){
            matrizJogada[i][j] = sudoku1[i][j];
            matrizPrincipal[i][j] = sudoku2[i][j];
        }
    }
}

void geraMatriz(int indice){

    if(indice == 4){
        srand( (unsigned)time(NULL) );
        indice = rand() % 3;
    }

    if(indice == 3){
        int sudokuIncompleto[9][9]=
        {{0,0,0,8,0,0,0,0,9},
        {0,1,0,0,0,5,0,3,0},
        {0,0,3,0,1,0,0,0,7},
        {4,0,0,1,0,0,0,0,3},
        {0,0,2,0,0,4,0,1,0},
        {0,8,0,0,9,0,6,0,0},
        {0,0,0,0,0,6,3,0,0},
        {0,3,0,0,7,0,0,8,0},
        {9,0,4,0,0,0,0,0,1}};

       int sudokuCompleto[9][9]=
        {{2,5,6,8,3,7,1,4,9},
        {7,1,9,4,2,5,8,3,6},
        {8,4,3,6,1,9,2,5,7},
        {4,6,7,1,5,8,9,2,3},
        {3,9,2,7,6,4,5,1,8},
        {5,8,1,3,9,2,6,7,4},
        {1,7,8,2,4,6,3,9,5},
        {6,3,5,9,7,1,4,8,2},
        {9,2,4,5,8,3,7,6,1}};

        copiaMatriz(sudokuIncompleto, sudokuCompleto);
    }
    
    if(indice == 2){
      int sudokuIncompleto[9][9]=
        {{1,0,0,0,8,0,0,0,9},
        {0,5,0,6,0,1,0,2,0},
        {0,0,0,0,0,3,0,0,0},
        {0,0,6,1,0,4,8,3,0},
        {3,0,0,0,6,0,0,0,5},
        {0,1,5,9,0,8,4,6,0},
        {0,0,0,0,0,5,0,0,0},
        {0,8,0,3,0,0,0,7,0},
        {5,0,0,0,1,0,0,0,3}};

       int sudokuCompleto[9][9]=
        {{1,3,7,4,8,2,6,5,9},
        {8,5,9,6,7,1,3,2,4},
        {6,2,4,5,9,3,7,8,1},
        {2,9,6,1,5,4,8,3,7},
        {3,4,8,2,6,7,1,9,5},
        {7,1,5,9,3,8,4,6,2},
        {9,6,3,7,4,5,2,1,8},
        {4,8,1,3,2,9,5,7,6},
        {5,7,2,8,1,6,9,4,3}};

        copiaMatriz(sudokuIncompleto, sudokuCompleto);
    }

    if(indice == 1){
       int sudokuIncompleto[9][9]=
        {{0,0,0,4,0,8,0,0,0},
        {0,6,0,0,7,0,0,1,0},
        {7,0,2,0,9,0,5,0,4},
        {0,9,0,7,0,4,0,3,0},
        {0,0,7,0,5,0,8,0,0},
        {0,8,0,9,0,6,0,5,0},
        {9,0,4,0,1,0,7,0,8},
        {0,7,0,0,6,0,0,4,0},
        {0,0,0,2,0,7,0,0,0}};

       int sudokuCompleto[9][9]=
        {{1,5,9,4,3,8,6,7,2},
        {4,6,8,5,7,2,9,1,3},
        {7,3,2,6,9,1,5,8,4},
        {2,9,5,7,8,4,1,3,6},
        {6,4,7,1,5,3,8,2,9},
        {3,8,1,9,2,6,4,5,7},
        {9,2,4,3,1,5,7,6,8},
        {5,7,3,8,6,9,2,4,1},
        {8,1,6,2,4,7,3,9,5}};

        copiaMatriz(sudokuIncompleto, sudokuCompleto);
    }
}

int jogarNovamente(){
	int jogo;
    do{
        printf("Deseja novamente novamente?\n\n1 - Sim\n2 - N o");
        scanf("%d", &jogo);
        if(jogo == 1){
            printf("Eba! :D");
            return 1;
            break;
        } else if(jogo == 2){
            printf("Tudo bem, foi um prazer ter voce jogando conosco! :D");
            return 0;
            break;
        } else {
            printf("O indice digitado nao corresponde a nenhuma opcao. Tente novamente.\n");
        }
    }while(1);
}




int selecinaDificuldade(){
    int dificuldade;

    do{
        printf("Digite o indice da dificuldade do Sudoku que deseja jogar: :)\n\n1 - Facil \n2 - Medio\n3 - Dificil\n4 - Escolha uma dificuldade por mim O_O\n0 - Sair do game\n\n");
        scanf("%d", &dificuldade);
        if(dificuldade >=1 && dificuldade <= 4){
            return dificuldade;
            break;
        } else if(dificuldade == 0){
            // Para aplica  o do programa
            printf("Jogo encerrado!!!");
            exit(0);
        } else {
            printf("O  indice digitado nao corresponde a nenhuma dificuldade.");
        }
    }while(1);
}



void imprimeJogo(int matriz[9][9]){
    int i,j;

    printf("-------------------------------\n");
    for(i = 0; i<9; i++){
        for(j=0; j<9; j++){
            if(j == 0){ // Adicionando | no inicio de cada linha
                printf("|");//
                }//
                else if(j % 3 == 0){//Adicionando | a cada quadrante LINHA
                    printf("|");//
                }//
            if(matrizJogada[i][j] == 0){
                printf(" _ "); // Caso o valor atual da matriz seja 0
            }else{
                printf(" %d ", matriz[i][j]);
            }
            if(j == 8){
            	printf("|"); // Adicionando a | ao final das linhas
			}
        }
        printf("\n"); 
        if((i+1) % 3 == 0){ // Adicionar -- a cada 3 Linhas
        	printf("-------------------------------\n");
		}
        
    }
}



void verificaJogo(int escolhaLinha, int escolhaColuna, int matrizJogada[9][9], int matrizPrincipal[9][9]){
	int i,j,escolha;
	for(i = 0; i<9; i++){
		for(j=0; j<9; j++){
			while(matrizJogada[escolhaLinha][escolhaColuna] == 0){
				printf("\nInsira um numero: (Apenas os valores corretos serao aceitos) ");
				scanf("%d", &escolha);
				while(escolha > 9 || escolha < 1){
					printf("\nInsira um numero valido: ");
					scanf("%d", &escolha);
				}
				if(escolha == matrizPrincipal[escolhaLinha][escolhaColuna]){
					matrizJogada[escolhaLinha][escolhaColuna] = escolha;
				}
			}
		}
	}
}



int main(){
	
	
	geraMatriz(selecinaDificuldade());
	
	
	//Bloco 1 (Funcionamento das verifica  es)
	int i,j,contador=0;
	
	for(i =0; i<9;i++){
		for(j=0;j<9;j++){
			if(matrizJogada[i][j] == 0){
				contador++; // verifica quantos 0's existem na matriz inteira
			}
		}
	}
	
	for(i=0; i< contador; i++){ // roda a quantidade de vezes do valor do 0 obtido acima
		imprimeJogo(matrizJogada);
		//Escolha da jogada do usuario
		int escolhai, escolhaj;
		do{
		printf("\nDigite a a posicao da sua jogada: (Linha: 0-8 / Coluna 0-8)");
		printf("\nLinha\n");
		scanf("\n%d",&escolhai);
		printf("\nColuna\n");
		scanf("\n%d",&escolhaj);
		}while((escolhai > 8 || escolhai < 0)&&(escolhaj >8 || escolhaj < 0));//condi  o para permitir a posi  o do numero insterido
		//
		verificaJogo(escolhai,escolhaj,matrizJogada,matrizPrincipal);
	}
	//FIm BLOCO 1
	jogarNovamente();

	
}

#IFSP ADS 1 Semestre (ARTUR O., GUILHERME H, GUSTAVO L.)
