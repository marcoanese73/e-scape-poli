/* Scrivere un sottoprogramma che ricevuta in ingresso una stringa restituisce una struttura dati opportuna che dice, per ogni carattere contenuto nella stringa, quante volte questo compare. */

#include <stdio.h>
#include <stdlib.h>
#define L 30

typedef struct _el {
	char car;
	int cont;
	struct _el *next;
} statlist_t;

statlist_t* contacar(char[]);
statlist_t* appendset(statlist_t*, char);
void printList(statlist_t*);
statlist_t* freeList(statlist_t*);

int main(int argc, char *argv[])
{
	char str[L+1];
	statlist_t *head = NULL;

	scanf("%s", str);
	head = contacar(str);
	printList(head);
	freeList(head);

	return 0;
}

statlist_t* contacar(char s[])
{
	int i;
	statlist_t *head = NULL;

	for(i = 0; s[i] != '\0'; i++)
		head = appendset(head, s[i]);

	return head;
}

statlist_t* appendset(statlist_t *head, char c)
{
	statlist_t *tmp;

	if(head) {
		for(tmp = head; tmp -> next; tmp = tmp -> next)
			if(tmp -> car == c)
				tmp -> cont++;
		if(tmp -> car == c)
			tmp -> cont++;
		else
			if(tmp -> next = (statlist_t *)malloc(sizeof(statlist_t))) {
				tmp -> next -> car = c;
				tmp -> next -> cont = 1;
				tmp -> next -> next = NULL;
			} else
				printf("Errore appendset: %c\n", c);
	} else {
		if(head = (statlist_t *)malloc(sizeof(statlist_t))) {
			head -> car = c;
			head -> cont = 1;
			head -> next = NULL;
		}
	}

	return head;
}

void printList(statlist_t *head)
{
	statlist_t *p;

	for(p = head; p != NULL; p = p -> next)
		printf("%c%d ", p -> car, p -> cont);
	printf("\n");

	return;
}

statlist_t* freeList(statlist_t *head)
{
	statlist_t *tbd;

	while(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}
