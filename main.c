#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "headers/conio2.h" 
#include "headers/doubLinkedList.h" 


// prot. functions
void show_list(); // menu >> insert(+)/remove(-)/exit(1)/show_menu()
void show_text(int n); // entradas de texto

/*
	19 de março de 2020	
    Departamento de T.I., UniProjeção (Taguatinga, Campus I)
   
    Sistemas de Informação (3º semestre)
    Autor: Yan Almeida Garcia - 2019 199 05 
    
    Disciplina: Estrutura de Dados - João Evangelista

	00) Implementação de lista duplamente encadeada de números inteiros:
		- sair ao teclar -> 0;
		- exibir lista;
		- adicionar no inicio da lista -> +;
		- adicionar no final da lista -> -;
		- zerar a lista -> r;
*/

// global vars.
int i, j, k;
char op;

int main()
{
	system("mode 162");	// size screen >> 162px largura

	show_list();

	return 0;
}

// functions
	// menu >> insert - start(+)/insert - end(-)/exit(0)/show_menu()
void show_list()
{
	int a = 2, b = 63, bb = b + 21, c = 7, d = 36, e = 4, k;
	struct node info, inserts;
		
	system("title Doubly Linked List - /list_");
	system("COLOR 07");
	
	List* li = init_list();
	
	do 
	{
		system("cls");

		textcolor(WHITE);
		borders(41, 151, 4, a);
		show_text(2);
		 
			// exibir >> ordens e max/min		
		if((*li) != NULL)
		{
			textbackground(CYAN);
			gotoxy(8, 20);
			list_print(li);
			
			textbackground(BLACK);
			gotoxy(c, 42);
			printf("Size: %d", list_size(li));			
		}
		else
		{
			textcolor(WHITE);
			textbackground(GREEN);
			movexy(72, 10, " INSERT SOMETHING ");
			movexy(73, 9, " LIST IS EMPTY. ");
		}

		gotoxy(160, 45);
		op = toupper(getch());

		switch(op)
		{
				// insere elemento >> começo	
			case '+':
				system("title Doubly Linked List - Insert at the start ");
				
				textbackground(GREEN);			
				movexy(b - 7, a, " Insert: start < + > ");
				
				show_text(0); // green color

				movexy(c - 1, e, " Insert at start: ");
				scanf(" %d", &inserts);
				fflush(stdin);
				
				inserts_start_list(li, inserts);
			break;
				// insere elemento >> final
			case '-':
				system("title Doubly Linked List - Insert at the end ");
			
				textbackground(GREEN);
				movexy(bb - 1, a, " Insert: end < - > ");

				show_text(1); // green color
		
				movexy(c - 1, e, " Insert at end: ");
				scanf(" %d", &inserts);
				fflush(stdin);
				
				inserts_final_list(li, inserts);
					
			break;
				// limpa a arvore
			case 'R':
				free_list(li);
				show_list();
			break;
				// sair
			case '0':	
				free_list(li);
				textbackground(BLACK);
			
				exit(1);
			break;
				// another key								
			default:
				textbackground(BLACK);
			break;	
		}
	} while(1);

}
	// entrada de textos
void show_text(int n)
{
	int a = 2, b = 63, bb = b + 21, d = 44, e = 141;
	
	if (n == 0) 
	{	
		textbackground(BLACK);
		movexy(bb - 1, a, " Insert: end < - > ");
		movexy(e, d, " Exit < 0 > ");
		movexy(8, d, " Reset < r > ");
	} 
	else if (n == 1)
	{			
		textbackground(BLACK);
		movexy(b - 7, a, " Insert: start < + > ");
		movexy(e, d, " Exit < 0 > ");
		movexy(8, d, " Reset < r > ");
	}
	else if (n == 2)
	{
		movexy(b - 7, a, " Insert: start < + > ");
		movexy(bb - 1, a, " Insert: end < - > ");
		movexy(e, d, " Exit < 0 > ");
		movexy(8, d, " Reset < r > ");
	}	
}

