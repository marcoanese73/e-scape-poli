/* Creare la funzione "sottolista" che riceve in ingresso due liste di interi positivi e ritorna 1 se una delle due è contenuta nell'altra, 0 altrimenti. */

#include <stdio.h>
#include <stdlib.h>
#define STOP 999

typedef struct _data {
	int elem;
	struct _data *next;
} data_t;

int sottolista(data_t*, data_t*);
int listlen(data_t*);
data_t* fill(data_t*);
data_t* append(data_t*, int);
data_t* freeList(data_t*);

int main(int argc, char *argv[])
{
	data_t *head_1 = NULL, *head_2 = NULL;

	head_1 = fill(head_1);
	head_2 = fill(head_2);

	printf("%d\n", sottolista(head_1, head_2));

	freeList(head_1);
	freeList(head_2);

	return 0;
}

int sottolista(data_t *head_1, data_t *head_2)
{
	int len_1, len_2;
	data_t *lstshort, *lstlong, *tmp, *ref;

	if(head_1 == NULL || head_2 == NULL)
		return 1;

	len_1 = listlen(head_1);
	len_2 = listlen(head_2);

	if(len_1 > len_2) {
		lstshort = head_2;
		lstlong = head_1;
	} else {
		lstshort = head_1;
		lstlong = head_2;
	}
	tmp = lstshort;

	while(lstlong != NULL) {
		if(lstlong -> elem == lstshort -> elem) {
			ref = lstlong;
			do {
				lstlong = lstlong -> next;
				lstshort = lstshort -> next;
			} while(lstlong != NULL && lstshort != NULL && lstlong -> elem == lstshort -> elem);
			if(lstshort == NULL)
				return 1;
			if(lstlong == NULL)
				return 0;
			lstlong = ref;
			lstshort = tmp;	
		} /* if */
		lstlong = lstlong -> next;
	}

	return 0;
}

int listlen(data_t *head)
{
	data_t *tmp;
	int cont;

	for(tmp = head, cont = 0; tmp != NULL; tmp = tmp -> next, cont++)
		;

	return cont;
}

data_t* fill(data_t *head)
{
	int value;

	scanf("%d", &value);
	while(value != STOP) {
		head = append(head, value);
		scanf("%d", &value);
	}

	return head;
}

data_t* append(data_t *head, int value)
{
	data_t *nuovo, *p;

	if(nuovo = (data_t *)malloc(sizeof(data_t))) {
		nuovo -> elem = value;
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

data_t* freeList(data_t *head)
{
	data_t *tbd;

	while(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}
