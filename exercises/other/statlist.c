#include <stdio.h>
#include <stdlib.h>
#define FNAME "./numeri.txt"

typedef struct _s {
	int info;
	int occ;
} stat_t;

typedef struct _slist {
	stat_t stat;
	struct _slist *next;
} statlist_t;

statlist_t* statistiche(FILE*);
int findNode(statlist_t*, int); /* cerca nodo e se lo trova incrementa occ */
statlist_t* append(statlist_t*, int);
void printList(statlist_t*);
statlist_t* freeList(statlist_t*);

int main(int argc, char *argv[])
{
	FILE *fp;
	statlist_t *head = NULL;

	if(fp = fopen(FNAME, "r")) {
		head = statistiche(fp);
		fclose(fp);
		printList(head);
		freeList(head);
	} else
		printf("Errore nell'accesso al file %s\n", FNAME);

	return 0;
}

statlist_t* statistiche(FILE *fp)
{
	statlist_t *head = NULL;
	int num;

	fscanf(fp, "%d", &num);
	while(!feof(fp)) {
		if(!findNode(head, num))
			head = append(head, num);
		fscanf(fp, "%d", &num);
	}

	return head;
}

int findNode(statlist_t *head, int num)
{
	statlist_t *p;

	for(p = head; p != NULL; p = p -> next)
		if(p -> stat.info == num) {
			(p -> stat.occ)++;
			return 1;
		}

	return 0;
}

statlist_t* append(statlist_t *head, int num)
{
	statlist_t *nuovo, *p;

	if(nuovo = (statlist_t*)malloc(sizeof(statlist_t))) {
		nuovo -> stat.info = num;
		nuovo -> stat.occ = 1;
		nuovo -> next = NULL;
		if(head) {
			for(p = head; p -> next != NULL; p = p -> next)
				;
			p -> next = nuovo;
		} else
			head = nuovo;
	} else
		printf("Errore malloc %d\n", num);

	return head;
}

void printList(statlist_t *head)
{
	statlist_t *p;

	for(p = head; p != NULL; p = p -> next)
		printf("%d %d  ", p -> stat.info, p -> stat.occ);

	printf("\n");

	return;
}

statlist_t* freeList(statlist_t* head)
{
	statlist_t *tbd; /* TO BE DELETED */

	if(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}
