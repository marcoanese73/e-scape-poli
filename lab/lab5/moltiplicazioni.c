/* 5.2 MOLTIPLICAZIONI */

/* Si scriva un sottoprogramma modificaLista che riceve in ingresso un puntatore ad una lista e ne modifica il contenuto, memorizzando in ciascuna posizione il prodotto tra l'elemento corrente ed il precedente (il primo elemento va lasciato invariato). Quindi:
- il primo elemento rimane invariato,
- il secondo elemento diventa uguale al prodotto tra il primo ed il secondo,
-il terzo elemento diventa uguale al prodotto del (vecchio) valore del secondo ed del terzo, e così via.
Prototipo: elem* modificaLista(elem*);
Ad esempio, una lista contenente la sequenza di interi 4 6 2 3 9 verrà modificata dal sottoprogramma nella lista 4 24 12 6 27. */

#include <stdio.h>
#include <stdlib.h>
#define STOP -1

typedef struct elem_{
  int valore;
  struct elem_ *next;
} elem;

elem* inserisciInCoda(elem*, int);
elem* inserisciInTesta(elem*, int);
elem* rimuovi(elem*, int);
void visualizza(elem*);
elem* distruggiLista(elem*);
int esisteElemento(elem*, int);
elem* modificaLista(elem*);
elem* fill(elem*);
elem* append(elem*, int);
void printList(elem*);
elem* freeList(elem*);

int main(int argc, char * argv[])
{
	elem *head = NULL;

	head = fill(head);
	head = modificaLista(head),
	printList(head);
	freeList(head);

	return 0;
}

elem* modificaLista(elem* head) {
	elem *p;
	int tmp;

	tmp = 1;
	if(head) {
		for(p = head; p -> next != NULL; p = p -> next) {
			p -> next -> valore *= (p -> valore / tmp);
			tmp = p -> valore / tmp;
		}
	}
	
	return head;
}

elem* fill(elem *head)
{
	int value;

	scanf("%d", &value);
	while(value != STOP) {
		head = append(head, value);
		scanf("%d", &value);
	}

	return head;
}

elem* append(elem *head, int value)
{
	elem *nuovo, *p;

	if(nuovo = (elem *)malloc(sizeof(elem))) {
		nuovo -> valore = value;
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

void printList(elem *head)
{
	elem *p;

	for(p = head; p != NULL; p = p -> next)
		printf("%d ", p -> valore);
	printf("\n");

	return;
}

elem* freeList(elem *head)
{
	elem *tbd;

	while(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}
