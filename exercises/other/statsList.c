#include <stdio.h>
#include <stdlib.h>

#define STOP -1

typedef struct _elem {
	int num;
	struct _elem *next;
} ilist_t;

void statsList(ilist_t*, int*, int*, float*, int*);
ilist_t* fill(ilist_t*);
ilist_t* append(ilist_t*, int);
ilist_t* freeList(ilist_t*);

int main(int argc, char *argv[])
{
	ilist_t *head = NULL;
	int min, max, len;
	float avg;

	head = fill(head);
	statsList(head, &min, &max, &avg, &len);
	if(len > 0)
		printf("%d %d %.2f %d\n", min, max, avg, len);
	freeList(head);

	return 0;
}

void statsList(ilist_t *head, int *min, int *max, float *avg, int *len)
{
	ilist_t *p;
	int tot;
	
	if(head) {
		p = head;
		*min = p -> num;
		*max = p -> num;
		tot = p -> num;
		*len = 1;
		for(p = p -> next; p != NULL; p = p -> next) {
			if(p -> num > *max)
				*max = p -> num;
			else if(p -> num < *min)
				*min = p -> num;
			tot += p -> num;
			(*len)++;
		}
		*avg = tot / *len;
	} else
		*len = 0;		

	return;
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

	if(nuovo = (ilist_t*)malloc(sizeof(ilist_t))) {
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