/* Scrivere un programma C che chiede all'utente una sequenza di valori interni che termina con 2017.
Il programma visualizza in ordine inverso i dati acquisiti. */

#include <stdio.h>
#include <stdlib.h>
#define STOP 2017

typedef struct _el {
	int info;
	struct _el * next;
} ilist_t;

ilist_t* push(ilist_t*, int);
void printList(ilist_t*);
ilist_t* freeList(ilist_t*);

int main(int argc, char *argv[])
{
	ilist_t *head = NULL;
	int num;

	scanf("%d", &num);
	while(num != STOP) {
		head = push(head, num);
		scanf("%d", &num);
	}
	printList(head);
	freeList(head);
	
	return 0;
}

ilist_t* push(ilist_t *head, int value)
{
	ilist_t *nuovo;

	if(nuovo = (ilist_t *)malloc(sizeof(ilist_t))) {
		nuovo -> info = value;
		nuovo -> next = head;
		head = nuovo;
	} else
		printf("Errore push: %d\n", value);

	return head;
}

void printList(ilist_t *head)
{
	ilist_t *p;

	for(p = head; p != NULL; p = p -> next)
		printf("%d ", p -> info);
	printf("\n");

	return;
}

ilist_t* freeList(ilist_t *head)
{
	ilist_t *tbd;

	while(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}
