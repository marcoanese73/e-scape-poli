#include <stdio.h>
#include <stdlib.h>

#define STOP 999

typedef struct _elem {
	int info;
	struct _elem *next;
} ilist_t;

ilist_t* compact(ilist_t*);
ilist_t* fill(ilist_t*);
ilist_t* append(ilist_t*, int);
void printList(ilist_t*);
ilist_t* freeList(ilist_t*);

int main(int argc, char *argv[])
{
	ilist_t *head = NULL;

	head = fill(head);
	head = compact(head);
	printList(head);
	freeList(head);

	return 0;
}

ilist_t* compact(ilist_t *head)
{
	ilist_t *tmp, *tbd;

	if(head)
		for(tmp = head, tbd = tmp -> next; tbd; tbd = tmp -> next)
			if(tmp -> info == tbd -> info) {
				tmp -> next = tbd -> next;
				free(tbd);
			} else
				tmp = tmp -> next;
	return head;
}

ilist_t* fill(ilist_t *head)
{
	int value;

	scanf("%d", &value);
	while(value != STOP) {
		head = append(head, value);
		scanf("%d", &value);
	}

	return head;
}


ilist_t* append(ilist_t *head, int value)
{
	ilist_t *nuovo, *p;

	if(nuovo = (ilist_t *)malloc(sizeof(ilist_t))) {
		nuovo -> info = value;
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
