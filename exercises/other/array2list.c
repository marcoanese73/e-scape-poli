/* Scrivere un sottoprogramma che riceve in ingresso un array di valori interi e qualsiasi altro parametro ritenuto strettamente necessario, e restituisce una lista contenente tutti i e soli i valori dell'array minori o uguali della media. */

#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct _elem {
	int info;
	struct _elem *next;
} ilist_t;

ilist_t* array2list(int[], int);
ilist_t* push(ilist_t*, int);
void printList(ilist_t*);
ilist_t* freeList(ilist_t*);

int main(int argc, char *argv[])
{
	int vett[N];
	ilist_t *head = NULL;
	int i;

	for(i = 0; i < N; i++)
		scanf("%d", &vett[i]);

	head = array2list(vett, N);
	printList(head);
	freeList(head);

	return 0;
}

ilist_t* array2list(int vett[], int dim)
{
	ilist_t *head = NULL;
	int i, tot;
	float avg;

	for(i = 0, tot = 0; i < dim; i++)
		tot = tot + vett[i];

	avg = tot / i;

	for(i = 0; i < dim; i++)
		if(vett[i] <= avg)
			head = push(head, vett[i]);
	
	return head;
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
