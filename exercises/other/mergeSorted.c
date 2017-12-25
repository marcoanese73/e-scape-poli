#include <stdio.h>
#include <stdlib.h>

#define STOP -1

typedef struct _elem {
	int info;
	struct _elem *next;
} ilist_t;

ilist_t* mergeSorted(ilist_t*, ilist_t*);
ilist_t* insertSorted(ilist_t*, int);
ilist_t* fill(ilist_t*);
ilist_t* append(ilist_t*, int);
void printList(ilist_t*);
ilist_t* freeList(ilist_t*);

int main(int argc, char *argv[])
{
	ilist_t *head_1 = NULL, *head_2 = NULL, *head_3;

	head_1 = fill(head_1);
	printf("Prima lista: ");
	printList(head_1);
	head_2 = fill(head_2);
	printf("Seconda lista: ");
	printList(head_2);
	head_3 = mergeSorted(head_1, head_2);
	printList(head_3);
	freeList(head_1);
	freeList(head_2);
	freeList(head_3);

	return 0;
}

ilist_t* mergeSorted(ilist_t *head_1, ilist_t *head_2)
{
	ilist_t *head_3 = NULL;
	ilist_t *p;
	int val;
	
	for(p = head_1; p != NULL; p = p -> next)
		head_3 = insertSorted(head_3, p -> info);

	for(p = head_2; p != NULL; p = p -> next)
		head_3 = insertSorted(head_3, p -> info);

	return head_3;
}

ilist_t* fill(ilist_t *head)
{
	int val;

	scanf("%d", &val);
	while(val != STOP) {
		head = append(head, val);
		scanf("%d", &val);
	}

	return head;
}

ilist_t* append(ilist_t *head, int val)
{
	ilist_t *nuovo, *p;

	if(nuovo = (ilist_t*)malloc(sizeof(ilist_t))) {
		nuovo -> info = val;
		nuovo -> next = NULL;
		if(head) {
			for(p = head; p -> next != NULL; p = p -> next)
				;
			p -> next = nuovo;
		} else
			head = nuovo;
	} else
		printf("Errore malloc %d\n", val);

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

ilist_t* insertSorted(ilist_t *head, int val)
{
	ilist_t *nuovo, *p;

	if(nuovo = (ilist_t*)malloc(sizeof(ilist_t))) {
		nuovo -> info = val;
		if(head) {
			if(head -> info > val) {
				nuovo -> next = head;
				head = nuovo;
				return head;		
			}
			for(p = head; p -> next != NULL; p = p -> next) {
				if(p -> next -> info > val) {
					nuovo -> next = p -> next;
					p -> next = nuovo;
					return head;
				}		
			}
			p -> next = nuovo;
			nuovo -> next = NULL;
		} else {
			head = nuovo;
			nuovo -> next = NULL;
		}
	} else
		printf("Errore malloc %d", val);

	return head;
}
