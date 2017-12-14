/* Scrivere un sottoprogramma che, ricevute due liste di numeri interi che rappresentano due insiemi, restituisce una nuova lista che rappresenta l'unione insiemistica delle due liste. */

#include <stdio.h>
#include <stdlib.h>
#define STOP 999

typedef struct _elem {
	int val;
	struct _elem *next;
} elems;

elems* merge_set_lists(elems*, elems*);
elems* fill(elems*);
elems* append(elems*, int);
elems* append_unique(elems*, int);
void printList(elems*);
elems* freeList(elems*);

int main(int argc, char *argv[])
{
	elems *head_1 = NULL, *head_2 = NULL, *head_3 = NULL;

	head_1 = fill(head_1);
	head_2 = fill(head_2);
	head_3 = merge_set_lists(head_1, head_2);
	printList(head_3);
	freeList(head_1);
	freeList(head_2);
	freeList(head_3);

	return 0;
}

elems* merge_set_lists(elems *h1, elems *h2)
{
	elems *head = NULL;
	elems *temp;

	for(temp = h1; temp != NULL; temp = temp -> next)
		head = append(head, temp -> val);

	for(temp = h2; temp != NULL; temp = temp -> next)
		head = append_unique(head, temp -> val);

	return head;
}	

elems* fill(elems *head)
{
	int value;

	scanf("%d", &value);
	while(value != STOP) {
		head = append(head, value);
		scanf("%d", &value);
	}

	return head;
}

elems* append(elems *head, int value)
{
	elems *nuovo, *p;

	if(nuovo = (elems *)malloc(sizeof(elems))) {
		nuovo -> val = value;
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

elems* append_unique(elems *head, int val)
{
	elems *temp;

	for(temp = head; temp != NULL && temp -> val != val; temp = temp -> next)
		;

	if(temp == NULL)
		head = append(head, val);

	return head;
}

void printList(elems *head)
{
	elems *p;

	for(p = head; p != NULL; p = p -> next)
		printf("%d ", p -> val);
	printf("\n");

	return;
}

elems* freeList(elems *head)
{
	elems *tbd;

	while(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}
