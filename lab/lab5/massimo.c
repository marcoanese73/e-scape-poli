/* 4.5 MASSIMO */

/* Si scriva un sottoprogramma massimoLista che riceve in ingresso una lista e restituisce il massimo tra i valori positivi contenuti nella lista, 0 se la lista non contiene alcun valore positivo. */

#include <stdio.h>
#include <stdlib.h>
#define STOP -1

typedef struct elem_{
int num;
struct elem_ *next;
} elem;

elem* inserisciInCoda(elem*, int);
elem* inserisciInTesta(elem*, int);
elem* rimuovi(elem*, int);
void visualizza(elem*);
elem* distruggiLista(elem*);
int esisteElemento(elem*, int);
int massimoLista(elem*);

int main(int argc, char *argv[])
{
	elem *head = NULL;
	int num;

	scanf("%d", &num);
	while(num != STOP) {
		head = inserisciInCoda(head, num);
		scanf("%d", &num);
	}

	printf("%d\n", massimoLista(head));

	return 0;
}

elem* inserisciInCoda(elem *head, int value)
{
	elem *nuovo, *p;

	if(nuovo = (elem *)malloc(sizeof(elem))) {
		nuovo -> num = value;
		nuovo -> next = NULL;
		if(head) {
			for(p = head; p -> next != NULL; p = p -> next)
				;
			p -> next = nuovo;
		} else
			head = nuovo;
	} else
		printf("Errore append: %d\n", value);
	
	return head;
}

int massimoLista(elem *head)
{
	elem *p;
	int max;
	
	if(head) {
		p = head;
		while(p && p -> num <= 0)
			p = p -> next;
		if(p) {
		max = p -> num;
		for(p = p -> next; p != NULL; p = p -> next)
			if(p -> num > max)
				max = p -> num;
		return max;
		}
	}

	return 0;
}
