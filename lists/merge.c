/* Scrivere un sottoprogramma che, ricevute due liste ordinate di numeri interi, ne restituisce una ordinata che contiene la fusione delle due liste di partenza.
Al termine del sottoprogramma le due liste non serviranno piu'. */

#include <stdio.h>
#include <stdlib.h>
#define STOP 999

typedef struct _elem {
	int val;
	struct _elem *next;
} elems;

elems* merge_ordered_lists(elems*, elems*);
elems* fill(elems*);
elems* append(elems*, int);
void printList(elems*);
elems* freeList(elems*);

int main(int argc, char *argv[])
{
	elems *head_1 = NULL, *head_2 = NULL;

	head_1 = fill(head_1);
	head_2 = fill(head_2);
	head_1 = merge_ordered_lists(head_1, head_2);
	printList(head_1);
	freeList(head_1);

	return 0;
}

elems* merge_ordered_lists(elems *h1, elems *h2)
{
	elems *tmp1, *tmp2, *tmp3, *head = NULL;

	tmp1 = h1;
	tmp2 = h2;

	if(h1 && h2) {
		if(tmp1 -> val > tmp2 -> val) {
			head = tmp2;
			tmp2 = tmp2 -> next;
		} else {
			head = tmp1;
			tmp1 = tmp1 -> next;
		}
		tmp3 = head;
		while(tmp1 != NULL && tmp2 != NULL) {
			if(tmp1 -> val > tmp2 -> val) {
				tmp3 -> next = tmp2;
				tmp2 = tmp2 -> next;
				tmp3 = tmp3 -> next;
			} else {
				tmp3 -> next = tmp1;
				tmp1 = tmp1 -> next;
				tmp3 = tmp3 -> next;
			}
		}
		while(tmp1 != NULL) {
			tmp3 -> next = tmp1;
			tmp1 = tmp1 -> next;
			tmp3 = tmp3 -> next;
		}
		while(tmp2 != NULL) {
			tmp3 -> next = tmp2;
			tmp2 = tmp2 -> next;
			tmp3 = tmp3 -> next;
		}
	}	

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
