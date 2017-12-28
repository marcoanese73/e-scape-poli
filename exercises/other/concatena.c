#include <stdio.h>
#include <stdlib.h>
#define STOP -1

typedef struct _elem {
	int info;
	struct _elem *next;
} ilist_t;

ilist_t* fill(ilist_t*);
ilist_t* append(ilist_t*, int);
void printList(ilist_t*);
ilist_t* freeList(ilist_t*);
ilist_t* concatena(ilist_t*, ilist_t*);

int main(int argc, char *argv[])
{
	ilist_t *head_1 = NULL, *head_2 = NULL, *head_3;

	head_1 = fill(head_1);
	head_2 = fill(head_2);

	head_3 = concatena(head_1, head_2);

	printList(head_3);
	freeList(head_1);
	freeList(head_2);
	freeList(head_3);
	
	return 0;
}

ilist_t* concatena(ilist_t *head_1, ilist_t *head_2)
{
	ilist_t *head_3 = NULL, *p_1, *p_2;

	for(p_1 = head_1, p_2 = head_2; p_1 != NULL && p_2 != NULL; p_1 = p_1 -> next, p_2 = p_2 -> next) {
		head_3 = append(head_3, p_1 -> info);
		head_3 = append(head_3, p_2 -> info);
	}
	if(p_1)
		for(; p_1 != NULL; p_1 = p_1 -> next)
			head_3 = append(head_3, p_1 -> info);
	else if(p_2)
			for(; p_2 != NULL; p_2 = p_2 -> next)
				head_3 = append(head_3, p_2 -> info);

	return head_3;
}

ilist_t* fill(ilist_t *head)
{
	int num;

	scanf("%d", &num);
	while(num != STOP) {
		head = append(head, num);
		scanf("%d", &num);
	}

	return head;
}

ilist_t* append(ilist_t *head, int num)
{
	ilist_t *nuovo, *p;

	
	if(nuovo = (ilist_t*)malloc(sizeof(ilist_t))) {
		nuovo -> info = num;
		nuovo -> next = NULL;
		if(head != NULL) {
			for(p = head; p -> next != NULL; p = p -> next)
				;
			p -> next = nuovo;
			
		} else
			head = nuovo;
	} else
		printf("Errore append %d\n", num);

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
	ilist_t *tbd; /* to be deleted */

	while(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}

