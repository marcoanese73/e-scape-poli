#include <stdio.h>
#include <stdlib.h>
#define STOP 999

/* Definizione del nodo di una lista di interi */

typedef struct _elem {
	int info;
	struct _elem *next;
} elem_t;

/* Prototipi dei sottoprogrammi */

elem_t* push(elem_t*, int);
elem_t* append(elem_t*, int);
elem_t* insertSorted(elem_t*, int);
elem_t* delete(elem_t*, int);
elem_t* getFirst(elem_t**);
elem_t* pop(elem_t*);
elem_t* fill(elem_t*);
elem_t* freeList(elem_t*);
int exists(elem_t*, int);
int listlen(elem_t*);
void printList(elem_t*);

/* Inserimento in testa */

elem_t* push(elem_t *head, int value)
{
	elem_t *nuovo;

	if(nuovo = (elem_t *)malloc(sizeof(elem_t))) {
		nuovo -> info = value;
		nuovo -> next = head;
		head = nuovo;
	} else
		printf("Errore push: %d\n", value);

	return head;
}

/* Inserimento in coda */

elem_t* append(elem_t *head, int value)
{
	elem_t *nuovo, *p;

	if(nuovo = (elem_t *)malloc(sizeof(elem_t))) {
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

/* Inserimento ordinato */

elem_t* insertSorted(elem_t *head, int value)
{
	elem_t *nuovo, *p;

	if(nuovo = (elem_t *)malloc(sizeof(elem_t *))) {
		nuovo -> info = value;
		if(head) {
			if(head -> info > value) {
				nuovo -> next = head;
				head = nuovo;
				return head;		
			}
			for(p = head; p -> next != NULL; p = p -> next) {
				if(p -> next -> info > value) {
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
		printf("Errore insertSorted: %d", value);

	return head;
}

/* Eliminazione dei nodi con campo info uguale a value */

elem_t* delete(elem_t *head, int value)
{
	elem_t *tmp, *tbd;

	while(head && head -> info == value) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}
	tmp = head;
	while(tmp && tmp -> next) {
		if(tmp -> next -> info == value) {
			tbd = tmp -> next;
			tmp -> next = tbd -> next;
			free(tbd);
		} else
			tmp = tmp -> next;
	}

	return head;
}

/* Estrazione del primo elemento dalla lista */

elem_t* getFirst(elem_t **head)
{
	elem_t *first, *local_head;

	local_head = *head;
	first = local_head;
	first -> next = NULL;
	if(local_head)
		local_head = local_head -> next;

	return first;
}

/* Eliminazione del primo elemento */

elem_t* pop(elem_t *head)
{
	elem_t *tbd;

	if(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}

/* Riempimento della lista */

elem_t* fill(elem_t *head)
{
	int value;

	scanf("%d", &value);
	while(value != STOP) {
		head = append(head, value);
		scanf("%d", &value);
	}

	return head;
}

/* Deallocazione di tutti i nodi della lista */

elem_t* freeList(elem_t *head)
{
	elem_t *tbd;

	while(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}

/* Verifica se esiste un nodo con campo info uguale a value */

int exists(elem_t *head, int value)
{
	elem_t *p;

	for(p = head; p != NULL; p = p -> next)
		if(p -> info == value)
			return 1;

	return 0;
}

/* Restituisce la lunghezza della lista */
int listlen(elem_t *head)
{
	if(!head)
		return 0;

	return 1 + listlen(head -> next);
}

/* Stampa lista */

void printList(elem_t *head)
{
	elem_t *p;

	for(p = head; p != NULL; p = p -> next)
		printf("%d ", p -> info);
	printf("\n");

	return;
}

/* Programma principale */

int main(int argc, char *argv[])
{
	elem_t *head = NULL, *primo;
	int value;

	printf("Test dei sottoprogrammi\n");
	printf("\nSottoprogramma fill\n");
	head = fill(head);
	printf("Visualizzazione lista: ");
	printList(head);
	printf("\nSottoprogramma listlen\n");
	printf("Lunghezza della lista: %d\n", listlen(head));
	printf("\nSottoprogramma push\n");
	scanf("%d", &value);
	head = push(head, value);
	printf("Visualizzazione lista: ");
	printList(head);
	printf("\nSottoprogramma append\n");
	scanf("%d", &value);
	head = append(head, value);
	printf("Visualizzazione lista: ");
	printList(head);
	printf("\nSottoprogramma delete\n");
	scanf("%d", &value);
	head = delete(head, value);
	printf("Visualizzazione lista: ");
	printList(head);
	printf("\nSottoprogramma pop\n");
	head = pop(head);
	printf("Visualizzazione lista: ");
	printList(head);
	printf("\nSottoprogramma insertSorted\n");
	scanf("%d", &value);
	head = insertSorted(head, value);
	printf("Visualizzazione lista: ");
	printList(head);
	printf("\nSottoprogramma exists\n");
	scanf("%d", &value);
	if(exists(head, value))
		printf("Il valore inserito esiste nella lista\n");
	else
		printf("Il valore inserito non esiste nella lista\n");
	printf("\nSottoprogramma getFirst\n");
	primo = getFirst(&head);
	printf("Primo elemento: %d\n", primo -> info);
	printf("Visualizzazione lista: ");
	printList(head);
	printf("\nSottoprogramma freelist\n");
	head = freeList(head);
	printf("Visualizzazione lista: ");
	printList(head);

	return 0;
}

