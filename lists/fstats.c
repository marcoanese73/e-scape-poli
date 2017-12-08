/* Scrivere un programma che conta e visualizza il numero di volte che i caratteri del file "info.txt" campaiono nel file. Li visualizza nell'ordine in cui compaiono come "carattere occorrenze". Se, per esempio, il file contiene "Testo di prova, funziona?" il programma visualizza T 1 e 1 s 1 t 1 o 3   3 d 1 ... */

#include <stdio.h>
#include <stdlib.h>
#define FNAME "./info.txt"

typedef struct _elem {
	char info;
	int cont;
	struct _elem *next;
} statlist_t;

statlist_t* append(statlist_t*, char);
statlist_t* find(statlist_t*, char);
void printList(statlist_t*);
statlist_t* freeList(statlist_t*);

int main(int argc, char *argv[])
{
	FILE *fp;
	char c;
	statlist_t *head = NULL, *p;

	if(fp = fopen(FNAME, "r")) {
		fscanf(fp, "%c", &c);
		while(!feof(fp)) {
			p = find(head, c);
			if(p)
				p -> cont++;
			else
				head = append(head, c);
			fscanf(fp, "%c", &c);
		}
		fclose(fp);
		printList(head);
		freeList(head);
	} else
		printf("Errore file %s\n", FNAME);

	return 0;
}

statlist_t* append(statlist_t *head, char car)
{
	statlist_t *nuovo, *p;

	if(nuovo = (statlist_t *)malloc(sizeof(statlist_t))) {
		nuovo -> info = car;
		nuovo -> cont = 1;
		nuovo -> next = NULL;
		if(head) {
			for(p = head; p -> next != NULL; p = p -> next)
				;
			p -> next = nuovo;
		} else
			head = nuovo;
	} else
		printf("Errore append: %c\n", car);
	
	return head;
}

statlist_t* find(statlist_t *head, char car)
{
	statlist_t *p;

	for(p = head; p != NULL; p = p -> next)
		if(p -> info == car)
			return p;

	return p;
}

void printList(statlist_t *head)
{
	statlist_t *p;

	for(p = head; p != NULL; p = p -> next)
		printf("%c%d ", p -> info, p -> cont);
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
