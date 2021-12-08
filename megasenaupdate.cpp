#include <iostream>
#include"biblio.h"
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iostream>
#include <windows.h> // Funcao Sleep)
#include <cstdlib>
#include <ctime>
#include <clocale>
#include <unistd.h>
#include <string>

using namespace std;

// VARIAVEIS GLOBAIS
int i, j, qtd, escolha, aux;
void logo_caixa(int qtd); // LOGO DA CAIXA
void num_aleatorio(int num[], int qtd);
// CASE 1
void imprimir_valores_ordenados(int qtd, int num[]);
void arrumar_num_ordem_crescente(int qtd, int num[], int aux);
void sorteio_numero_megasena(int sorteio[], int aux, int qtd);
void refazer_sorteio_num_repetido(int qtd, int sorteio[]);
void refazer_sorteio_repetido(int qtd, int num[]);
void resultado_megasena(int qtd, int sorteio[], int num[]);
void exibi_sorteio(int sorteio[]);
// CASE 2
int confirmar_num_repetido_case2(int num[],int qtd);


typedef enum{black,blue,green,cyan,red,magenta,brown,ightgray,darkgray,   /* nome das cores */
lightblue,lightgreen,lightcyan,lightred,lightmagenta,yellow,white} colors;
/*  9         10         11        12        13         14    15 */

static int __BACKGROUND = 1/*BLACK*/;/*pode ser o numero ou o nome da cor*/
int __FOREGROUND = 1;

void textcolor_2 (int letras, int fundo){/*para mudar a cor de fundo mude o background*/
    __FOREGROUND = letras;
    __BACKGROUND = fundo;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letras + (__BACKGROUND << 4));
}
                  /* y = linha de 0 a 24 , x = coluna de 0 a 80 */
void gotoxy_2(int x, int y){/*imprimir na linha e coluna desejada */
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int som(int f){
    Beep(f,150);/* primeiro a frquência depois o tempo de duração do som */
    return 0;
}
main(){

	void finaliza_programa(int escolha);
	setlocale(LC_ALL, "Portuguese");
	textcolor(LIGHT_BLUE);
	// LOGO CAIXA MEGA SENA
	logo_caixa(qtd);
	getch();
		do {
		system("cls");
		system("color 9");
		textcolor(WHITE);
		cout<< "\n =================================        LOTERIAS FAIXA        ======================================";
		cout<< "\n" ;
			textcolor(WHITE);
		cout<< "\n\n\t\t\t\t TABELA DE NÚMEROS \n\n";
		textcolor(WHITE);
		cout<< "\n\t\t[][][][][][][][][][][][][][][][][][][][][][][][] " ;
		textcolor(WHITE);
		cout<< "\n\t\t[]             6 NÚMEROS – R$ 4,50            [] " ;
		textcolor(LIGHT_GREEN);
		cout<< "\n\t\t[]             7 NÚMEROS – R$ 31,50           [] " ;
		textcolor(GREEN);
		cout<< "\n\t\t[]             9 NÚMEROS – R$ 378,00          [] " ;
		textcolor(YELLOW);
		cout<< "\n\t\t[]            10 NÚMEROS – R$ 945,00          [] " ;
		textcolor(BROWN);
		cout<< "\n\t\t[]            11 NÚMEROS – R$ 2.079,00        [] " ;
		textcolor(LIGHT_RED);
		cout<< "\n\t\t[]            12 NÚMEROS – R$ 4.158,00        [] " ;
		textcolor(RED);
		cout<< "\n\t\t[]            13 NÚMEROS – R$ 7.722,00        [] " ;
		textcolor(LIGHT_GRAY);
		cout<< "\n\t\t[]            14 NÚMEROS – R$ 13.513,50       [] " ; 
		textcolor(DARK_GRAY);
		cout<< "\n\t\t[]            15 NÚMEROS – R$ 22.522,50       [] " ;
		textcolor(WHITE);
		cout<< "\n\t\t[][][][][][][][][][][][][][][][][][][][][][][][] " ;
			textcolor(WHITE);
		cout<<"\n\n\n Escolha quantos números você quer: ";
		cin>>qtd;
		
		if((qtd < 6) || (qtd > 15)) {
			textcolor(LIGHT_RED);
			cout<<"\n\t Número invalido, escolha outro!";
			getch();
		}}while((qtd < 6) || (qtd > 15));

	do {
		    system("cls");
		    textcolor(LIGHT_GRAY);
        	cout<<"\n                                                                    ";  
			cout<<"\n                            .(((((((((((((((((((((((((((((((((((((((((((((/ ";    
			cout<<"\n                      .**,.((((/.                                        *(((( "; 
			cout<<"\n                   ((((((((((.           PREMIO DE R$:1.000.000            ((( ";
			cout<<"\n                (((((    .(((================================================((( ";
			cout<<"\n            .(((((        (( MEGA SENA MEGA SENA MEGA SENA MEGA SENA MEGA SENA(( ";
			cout<<"\n         *((((/          .(((================================================((( ";
			cout<<"\n     .(((((.             .(((    _______________________________________    ,((/ ";
			cout<<"\n  *((((/                 .(((   |          ./(((((*                    |    ,((( ";
			cout<<"\n((((.                    .(((   |     *(((((((*,,((((  ( ) ( ) ( ) ( ) |     *((/ ";
			cout<<"\n                         .(((  .(((((((*         *((/                  |     *((( ";
			cout<<"\n                          (((((((/.              (((*  ( ) ( ) ( ) ( ) |     ,((/ "; 
			cout<<"\n                      *(((((*                  *(((*                   |     ,((( ";
			cout<<"\n                                           .(((((,     ( ) ( ) ( ) ( ) |     *((/ ";
			cout<<"\n                                      *((((((/                         |     (((  ";
			cout<<"\n                                  *((((((((((((((((((((((((((((((((((((((((((/  ";
			cout<<"\n                                ((((*.(((  ..  (((..  ..(((       ";
			cout<<"\n                             /((((    (((      (((     (((,   ";                   
			cout<<"\n                ...,,*//(((((((*    *(((*     .(((   .((( ";                      
			cout<<"\n(((((((((((((((((((((((((*.  ((((((((((((*  .((((((((((*  ";                      
		    cout<<"\n                                      ,(((((((   ";		
		    
	textcolor(WHITE);	
	cout<<"\n\n De que forma você quer seus números?";
	cout<<"\n [1] Surpresa - Aleatorio";
	cout<<"\n [2] Escolher o proprio número";
	cout<<"\n [3] Quero sair";
	cout<<"\n Escolho a opção: ";
	cin>>escolha;
	if((escolha < 1) || (escolha > 3)) {
		cout<<"\n Opção invalido, escolha outro!";
		getch();
	}
		switch(escolha) {
			case 1:{
				system("cls");
				textcolor(WHITE);
				int num[qtd], sorteio[i];
				void exibir_num_proprio(int num[], int qtd);
				srand(time(NULL));  // função que inicializa o gerador de números randômicos
    			srand((unsigned)time(NULL));
				cout<<"\n Você escolheu a opção 'Números aleatorios'.";
				cout<<"\n Seus números são:";
				// GERAR NUM DO USUARIO DE FORMA ALEATORIO
				num_aleatorio(num, qtd);
	          	// REFAZ OS NUMEROS REPETIDOS
	          	refazer_sorteio_num_repetido(qtd, num);
				// ORDEM CRESCENTE
	          	arrumar_num_ordem_crescente(qtd, num, aux);
				// IMPRIMI OS VALORES ORDENADOS
				imprimir_valores_ordenados(qtd, num);
				getch();
				textcolor(WHITE);
				cout<<"\n\n Você está pronto para o sorteio? Pressione qualquer tecla para continuar...";
				getch();
				cout<<"\n\n Os números sorteados foram: ";
				
				// FAZ SORTEIO DOS NUMEROS PREMIADOS
				sorteio_numero_megasena(sorteio, aux, qtd);
				exibi_sorteio(sorteio);
				
				
				for(i=0; i<qtd; i++){
				sorteio_repetido(qtd, sorteio);
				}
				
				resultado_megasena(qtd, sorteio, num);
				getch();
				finaliza_programa(escolha);
				escolha = 3;
				break;
			} // TERMINA SORTEIO ALEATORIO
			case 2: {
				system("cls");
				int num[qtd], result, sorteio[i];
				void num_proprio(int num[], int qtd);
				textcolor(BROWN);
				cout<<"\n\t ============================================";
                cout<<"\n\t || Você escolheu a opção 'Número proprio'.||";
                cout<<"\n\t ============================================\n";
                textcolor(WHITE);
				num_proprio(num, qtd); // INFORMAR NUM PROPRIO DO USUARIO
				do{
					result = confirmar_num_repetido_case2(num, qtd);
					if(result > 0){
						textcolor(LIGHT_RED);
					cout<<"\n\t\t Repetiu números!";
					num_proprio(num, qtd);
				}}while(result > 0); // VALIDAÇÃO DO NUM PROPRIO, SE REPETIU
					
				cout<<"\n São números são: ";
				exibir_num_proprio(num, qtd); // EXIBI NUMEROS
				// FAZ SORTEIO DOS NUMEROS PREMIADOS
				sorteio_numero_megasena(sorteio, aux, qtd);
				cout<<"\n\n Números sorteados: ";
				exibi_sorteio(sorteio);
				
				
				for(i=0; i<qtd; i++){
				sorteio_repetido(qtd, sorteio);
				}
				
				resultado_megasena(qtd, sorteio, num);
				getch();
				finaliza_programa(escolha);
				escolha = 3;
				break;
			}
			case 3: {
				finaliza_programa(escolha);
                return 0;
						break;
			}} //FIM SWITCH
			}while(escolha != 3); //FIM DO WHILE
	
	   		   time_t rawTime;
    struct tm * relogio;
    char a[100];


    while(1)
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese");
        rawTime = time(NULL);
        relogio = localtime(&rawTime);
        strftime(a, 100, "%I:%M:%S", relogio);

        std::cout << a << std::endl;

        strftime(a, 100, "%a %d %b %y", relogio);

        std::cout << a;
        Sleep(1000);
        
        string titulo;
	    titulo = "SAVE...";
	    textcolor_2(10,0);
	    gotoxy_2(10,5);
	    for(int i=0; i<6; i++){
	        Sleep(500);/* com S maiúsculo e meio segundo */
	        cout << titulo[i];
	    }
	    textcolor_2(10,12);
	    gotoxy_2(20,10);/* posiciona o cursor para imprimir nessas posições X coluna Y linha */
	    cout<<"  SAIR !"<<endl;
	    som(800);
	    getch();
	    textcolor_2(15,0);
	            return 0;
    }
    return 0;
} // FIM MAIN

