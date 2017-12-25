#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *next;
} divisore;

int amicali(int, int);
divisore* divisori(int);
divisore* append(divisore*, int);
divisore* freeList(divisore*);
void printList(divisore*);

int main(int argc, char *argv[])
{
	int n, m, ris;

	scanf("%d %d", &n, &m);
	ris = amicali(n, m);
	printf("%d\n", ris);

	return 0;
}

int amicali(int n, int m)
{
	divisore *head_n = NULL, *head_m = NULL, *p;
	int ris, sum_n, sum_m;

	ris = 1;
	head_n = divisori(n);
	for(p = head_n, sum_n = 0; p != NULL; p = p -> next)
		sum_n += p -> num;
	freeList(head_n);
	if(sum_n != m)
		ris = 0;
	if(ris) {
		head_m = divisori(m);
		for(p = head_m, sum_m = 0; p != NULL; p = p -> next)
			sum_m += p -> num;
		if(sum_m != n)
			ris = 0;
		freeList(head_m);
	}

	return ris;
}

divisore* divisori(int val)
{
	divisore *head = NULL;
	int i;

	i = 1;
	while(i <= val/2) {
		if(val % i == 0)
			head = append(head, i);
	i++;
	}
	
	return head;
}

divisore* append(divisore *head, int value)
{
	divisore *nuovo, *p;

	if(nuovo = (divisore*)malloc(sizeof(divisore))) {
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

divisore* freeList(divisore *head)
{
	divisore *tbd;

	while(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}

void printList(divisore *head)
{
	divisore *p;

	for(p = head; p != NULL; p = p -> next)
		printf("%d ", p -> num);
	printf("\n");

	return;
}
