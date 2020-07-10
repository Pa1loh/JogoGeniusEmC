#include<unistd.h>
#include <iostream>
#include <windows.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.c>
#include <time.h>
#include <ctype.h>
#define sl 0         // define o tempo da logo


char tecla;          // para facilitar a tecla em todas as telas
int sort = 0;         // cor sorteada
int pontos;               // nao sei como fazer a pontuacao ainda
int mudacor;            // muda a cor pra selecionar
int mudacor2;           // muda a cor no sorteio e printa no começo
int s;                 // numero aleatorio gerado
int resposta[10];      // vetor gerado aleatoria
int resultado[10];         // resposta do usuario
int fase = 0;               // começa a fase na primeira
int matriz[4][4] =               // matriz para ligar e desligar cor

{
  10,1,4,6,  // verde ligado
  2,9,4,6,  //  azul ligado          
  2,1,12,6,  // vermelho ligado
  2,1,4,14,  // amarelo ligado
};

int controle();   // controla a tela
int quadrados(); // printar os quadrados e acender
int quadrados2(); // apaga os quadrados
int sorteio(); // sorteia as cores
int ajuda(); // tela de ajuda
int jogo(); // tela principal da gameplay
int menu(); // tela inicial

int controle(){
	    fflush(stdin);
	    tecla = getch();
	    
	    	    
	    
	    switch(tecla){
		    case 'd':
		     	mudacor++;
			    break;
		    case 'a':
		        mudacor--;
			    break;
			case 27 :
				menu();
			    break;
			case 32:
				if(mudacor == 0){ // respota verde
				resultado[(fase-1)] = 0;
				}
				if(mudacor == 1){ // respota azul
				resultado[(fase-1)] = 1;
				}
				if(mudacor == 0){ // respota vermelho
				resultado[(fase-1)] = 2;
				}
				if(mudacor == 0){ // respota amarelo
				resultado[(fase-1)] = 3;
				}
				
	}
		
		
		if(mudacor < 0){
			mudacor = 3;
		}
		if(mudacor > 3){
			mudacor = 0;
		}
			    textcolor(matriz[mudacor][0]);                        // 0 0  1 0  2 0 3 0
			    gotoxy(8,5);	  // printando quadrado verde   2- 10+
	            printf("#####");
	            gotoxy(8,6);
	            printf("#####");
	            gotoxy(8,7);
             	printf("#####");
             	
             	textcolor(matriz[mudacor][1]);
	            gotoxy(32,5);	  // printando quadrado azul    1-   9+
               	printf("#####");
            	gotoxy(32,6);
	            printf("#####");
             	gotoxy(32,7);
	            printf("#####");
				
				textcolor(matriz[mudacor][2]);                      // 0 1  1  1  2  1
	            gotoxy(8,11);    // printando quadrado vermelho  4- 12+
	            printf("#####");
	            gotoxy(8,12);
	            printf("#####");
	            gotoxy(8,13);
	            printf("#####");
	            
	            
	            
	            textcolor(matriz[mudacor][3]);
	            gotoxy(32,11);    // printando quadrado amarelo  6-   14+
             	printf("#####");
            	gotoxy(32,12);
	            printf("#####");
	            gotoxy(32,13);
	            printf("#####");
		
}
int quadrados2(){        // apagar todos quadrados
	textcolor(matriz[1][0]);                        // 0 0  1 0  2 0 3 0
	gotoxy(8,5);	  // printando quadrado verde   2- 10+
	printf("#####");
	gotoxy(8,6);
	printf("#####");
	gotoxy(8,7);
    printf("#####");
             	
    textcolor(matriz[0][1]);
	gotoxy(32,5);	  // printando quadrado azul    1-   9+
    printf("#####");
    gotoxy(32,6);
	printf("#####");
    gotoxy(32,7);
	printf("#####");
				
	textcolor(matriz[0][2]);                      // 0 1  1  1  2  1
	gotoxy(8,11);    // printando quadrado vermelho  4- 12+
	printf("#####");
	gotoxy(8,12);
	printf("#####");
	gotoxy(8,13);
	printf("#####");          
	            	            
    textcolor(matriz[0][3]);
	gotoxy(32,11);    // printando quadrado amarelo  6-   14+
    printf("#####");
    gotoxy(32,12);
	printf("#####");
	gotoxy(32,13);
	printf("#####");
}
int quadrados(int parametro){
	
	mudacor2 = parametro;
	
	textcolor(matriz[mudacor2][0]);                        // 0 0  1 0  2 0 3 0
	gotoxy(8,5);	  // printando quadrado verde   2- 10+
	printf("#####");
	gotoxy(8,6);
	printf("#####");
	gotoxy(8,7);
    printf("#####");
             	
    textcolor(matriz[mudacor2][1]);
	gotoxy(32,5);	  // printando quadrado azul    1-   9+
    printf("#####");
    gotoxy(32,6);
	printf("#####");
    gotoxy(32,7);
	printf("#####");
				
	textcolor(matriz[mudacor2][2]);                      // 0 1  1  1  2  1
	gotoxy(8,11);    // printando quadrado vermelho  4- 12+
	printf("#####");
	gotoxy(8,12);
	printf("#####");
	gotoxy(8,13);
	printf("#####");          
	            	            
    textcolor(matriz[mudacor2][3]);
	gotoxy(32,11);    // printando quadrado amarelo  6-   14+
    printf("#####");
    gotoxy(32,12);
	printf("#####");
	gotoxy(32,13);
	printf("#####");
	
	
	
}
int sorteio(){
	srand(time(NULL));
	for(int x=0; x<9; x++){
	s = rand()%4;
	resposta[x]=s;
}
}
int ajuda(){
	clrscr();
	gotoxy(1,1);
	printf("Memorius e um jogo no estilo do classico genius, onde algumas cores vão aparecer e você para pontuar apenas te que selecionar a ordem em que as mesmas apareceram ");
	tecla = getch();
	if(tecla == 13 || tecla == 100 || tecla == 97 ){
		menu();
	}

}
int jogo(){
	clrscr();                     //limpando a tela 2x
	system("cls");	
	gotoxy(1,1);
	textcolor(3);                 //tem q mudar isso aqui para colar a cor que aparecer
	printf("###############################################################################");
	for(int a1 = 2; a1<19; a1++){           // printa lateral esquerda
		gotoxy(1,a1);
		printf("#");
		}	
	for(int a2 = 2; a2<19; a2++){           // printa lateral direita
		gotoxy(79,a2);
		printf("#");           
	}

        // Printando os Quadrados apagados
    quadrados2();
   
	
	// printando o menu lateral
	textcolor(3); 
	gotoxy(60,2);                        // quadrado do lado
	printf("###################");
	for(int b1=3; b1<19; b1++){
		gotoxy(60,b1);
		printf("#");
	}
	
	gotoxy(62,4);                       // Palavras dentro do quadrado
	printf("Pressione enter");
	gotoxy(62,5);
	printf("para comecar");
	
	gotoxy(62,8);
	printf("Pontuacao %d",s);
	
	gotoxy(62,12);
	printf("Use A e D para ");
	gotoxy(62,13);
	printf("mover");
	gotoxy(62,16);
	printf("Use Espaco");
	gotoxy(62,17);
	printf("para selecionar");
	
	
	
	gotoxy(1,19);	
	
	printf("###############################################################################");
	
 ////////////////////////////////////////////////////////////////// PRINTOU A TELA ///////////////////////////////////////////////////////
	int comeca = 0;
	int p;	
	
	if(tecla == 13){
		tecla = getch();		
	fase++;		
	comeca = 1;
		do{	
		
		switch(fase){
			
			case1:
				p = resposta[(fase-1)];
				quadrados(p);
				quadrados();
				Sleep(2);
				quadrados2();
				if(resposta[(fase-1)] == resultado[(fase-1)]){
					fase++;
					break;
				}
				else{ menu();
				      break;
				}
				break;
				
				case2:
				p = resposta[(fase-1)];
				quadrados(p);
				quadrados();
				Sleep(2);
				quadrados2();
				for(int x = 0; x<fase; x++){							
				    if(resposta[x] == resultado[x]){
					fase++;
					if(fase == 4){
						fase = 3;
						break;
					}
					
				}
				else{ menu();
				}     break;
				break;
				
				
		}
		        case3:
				p = resposta[(fase-1)];
				quadrados(p);
				quadrados();
				Sleep(2);
				quadrados2();
				for(int x = 0; x<fase; x++){							
				    if(resposta[x] == resultado[x]){
					fase++;
					if(fase == 6){
						fase = 4;
						break;
					}
					
				}
				else{ menu();
				}     break;
				break;
				
				
		}
	 }
    
		
		    gotoxy(62,4);                       // Palavras dentro do quadrado
	        printf("     FASE :    ");
	        gotoxy(62,5);
	        printf("     %d     ",fase);
		    
	    
	    	        
		
		
		
	
		  
		  }while(comeca == 1 /* 
		    for(int x1 = (fase-1); x1<9;){
		       resultado[x1] == resposta[x1]
		   }
		*/);
	}

}

int menu(){
	clrscr();
	system("cls");
	textcolor(11);
	printf(" /|/|\n");
	Sleep(sl);
	printf("( / | ___  _ _  ___  ___         ___\n");
	Sleep(sl);
	printf("|   )|___)| | )|   )|   )| |   )|___ \n");
	Sleep(sl);
	printf("|  / |__  |  / |__/ |    | |__/  __/\n");
	Sleep(sl);
			
	printf("###############################################################################");
	for(int a1 = 6; a1<16; a1++){           // printa lateral esquerda
		gotoxy(1,a1);
		printf("#");
		}	
	for(int a2 = 6; a2<16; a2++){           // printa lateral direita
		gotoxy(79,a2);
		printf("#");           
	}
	gotoxy(10,10);	
	printf("#Iniciar#");
	for(int a3 = 10; a3<19; a3++){           // printa quadrado iniciar
		gotoxy(a3,9);
	    printf("#");
	    gotoxy(a3,11);
	    printf("#");
	}
	textcolor(11);
	gotoxy(40,10);
	printf("#Ajuda#");
	for(int a4 = 40; a4<47; a4++){         // printa o quadrado da ajuda
		gotoxy(a4,9);
		printf("#");
		gotoxy(a4,11);
		printf("#");
	}		
	gotoxy(60,10);
	printf("#Sair#");
	for(int a5 = 60; a5<66; a5++){         // printa sair
		gotoxy(a5,9);
		printf("#");
		gotoxy(a5,11);
		printf("#");
	}
	gotoxy(3,15);	
	printf("Feito por : Paulo Henrique do Carmo Faria\n");
	printf("###############################################################################");
	// colocar isso em outra função
	int contadorm = 0;
	
	do
	{
		
		
		gotoxy(3,6);
		printf("Pressione A e D para mover");
		gotoxy(3,7);
		printf("Pressione enter para selecionar");
	
	tecla = getch();
	fflush(stdin);
	switch(tecla){
		case 'd':
			contadorm++;
			break;
		case 'a':
		    contadorm--;
			break;
									
			}
					                     
		if(tecla == 13){                 //selecionar com o enter
			if(contadorm == 1){
				jogo();
			}
			if(contadorm == 2){
				ajuda();
			}
			if(contadorm == 3){
				clrscr();
				exit(1);
				
			}
		}
		
	if (contadorm > 3){ // resetar contador do menu
		contadorm = 1;
	}
	if (contadorm < 1){ // resetar contador do menu
		contadorm = 3;
	}
	if (contadorm == 1){           // muda cor do iniciar
		textcolor(9);
		gotoxy(10,10);	
	    printf("#Iniciar#");
	    for(int a3 = 10; a3<19; a3++){           // quadrado ajuda
		    gotoxy(a3,9);
	        printf("#");
	        gotoxy(a3,11);
	        printf("#");
	}	
	    textcolor(11);
	    gotoxy(40,10);
	    printf("#Ajuda#");
	    for(int a4 = 40; a4<47; a4++){         // selecionar o quadrado da ajuda
	        gotoxy(a4,9);
		    printf("#");
	      	gotoxy(a4,11);
	    	printf("#");
	}
	    textcolor(11);
		gotoxy(60,10);
	    printf("#Sair#");
	    for(int a5 = 60; a5<66; a5++){         // printa sair
		    gotoxy(a5,9);
	       	printf("#");
	    	gotoxy(a5,11);
	    	printf("#");
	       	       }
   }
    if (contadorm == 2){           // muda cor da ajuda
        textcolor(9);
	    gotoxy(40,10);
	    printf("#Ajuda#");
	    for(int a4 = 40; a4<47; a4++){         // printa o quadrado da ajuda
	        gotoxy(a4,9);
		    printf("#");
	      	gotoxy(a4,11);
	    	printf("#");
	}
	gotoxy(10,10);
	textcolor(11);	
	printf("#Iniciar#");
	for(int a3 = 10; a3<19; a3++){           // printa quadrado iniciar
		gotoxy(a3,9);
	    printf("#");
	    gotoxy(a3,11);
	    printf("#");
	}
	gotoxy(60,10);
	printf("#Sair#");
	for(int a5 = 60; a5<66; a5++){         // printa sair
		gotoxy(a5,9);
		printf("#");
		gotoxy(a5,11);
		printf("#");
	}		
	
   }
	if (contadorm == 3){           // muda a cor sair
	    textcolor(9);
		gotoxy(60,10);
	    printf("#Sair#");
	    for(int a5 = 60; a5<66; a5++){         // printa sair
		    gotoxy(a5,9);
	       	printf("#");
	    	gotoxy(a5,11);
	    	printf("#");
	       	       }
	    textcolor(11);
	    gotoxy(40,10);
	    printf("#Ajuda#");
	    for(int a4 = 40; a4<47; a4++){         // printa o quadrado da ajuda
	        gotoxy(a4,9);
		    printf("#");
	      	gotoxy(a4,11);
	    	printf("#");
	}
	    textcolor(11);
		gotoxy(10,10);	
	    printf("#Iniciar#");
	    for(int a3 = 10; a3<19; a3++){           // quadrado ajuda
		    gotoxy(a3,9);
	        printf("#");
	        gotoxy(a3,11);
	        printf("#");
	}	
	    	       	   }
				
    }while(tecla !=13);
    textcolor(11);
    clrscr();

 
}
int main(){
	menu();
	controle();
    sorteio();
	quadrados2();
	jogo();
	ajuda();
	return 0;
}
