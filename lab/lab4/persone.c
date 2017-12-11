/* 4.6 PERSONE */

/* Scrivere un programma che acquisisce le informazioni circa età e sesso di un gruppo di persone e visualizza prima tutte le età di persone sotto i 20 anni, indipendentemente dal sesso (adolescenti), poi tutte le età di tutte le donne, infine quelle degli uomini.
Per ogni gruppo si devono visualizzare le età in modo ordinato crescente.
I dati vengono forniti in ingresso come coppie , in cui 1 indica maschio, 2 femmina.
Quando l'utente inserisce -1 come età l'acquisizione termina.
In ingresso il programma riceve una sequenza di coppie di interi (senz'altro ragionevoli) terminata dal valore -1. */

#include <stdio.h>
#include <stdlib.h>
#define ADULT 20
#define STOP -1

/*definizione della struttura per la lista concatenata*/
typedef struct _elem {
  int num;
  struct _elem *next;
} elem_t;

/*prototipi dei sottoprogrammi */
elem_t* append(elem_t*, int);
elem_t* push(elem_t*, int);
elem_t* insertsorted(elem_t*, int);
elem_t* delete(elem_t*, int);
void printlist(elem_t*);
elem_t* freelist(elem_t*);
int exists(elem_t*, int);
void modify(elem_t*);

int main(int argc, char * argv[])
{
	elem_t *teen_h = NULL, *male_h = NULL, *femme_h = NULL;
	int age, gender;

	scanf("%d", &age);
	while(age != STOP) {
		scanf("%d", &gender);
		if(age < ADULT)
			teen_h = insertsorted(teen_h, age);
		if(gender == 1)
			male_h = insertsorted(male_h, age);
		else if(gender == 2)
			femme_h = insertsorted(femme_h, age);
		scanf("%d", &age);
	}

	printf("adolescenti:\n");
	printlist(teen_h);
	freelist(teen_h);
	printf("donne:\n");
	printlist(femme_h);
	freelist(femme_h);
	printf("uomini:\n");
	printlist(male_h);
	freelist(male_h);

	return 0;
}

elem_t* insertsorted(elem_t *h, int info)
{
	elem_t *nuovo, *p;

	if(nuovo = (elem_t *)malloc(sizeof(elem_t *))) {
		nuovo -> num = info;
		if(h) {
			if(h -> num > nuovo -> num) {
				nuovo -> next = h;
				h = nuovo;
				return h;		
			}
			for(p = h; p -> next != NULL; p = p -> next) {
				if(p -> next -> num > info) {
					nuovo -> next = p -> next;
					p -> next = nuovo;
					return h;
				}		
			}
			p -> next = nuovo;
			nuovo -> next = NULL;
		} else {
			h = nuovo;
			nuovo -> next = NULL;
		}
	} else
		printf("Errore malloc %d", info);

	return h;
}

void printlist(elem_t *h)
{
	for(; h != NULL; h = h -> next)
		printf("%d ", h -> num);
	printf("\n");

	return;
}

elem_t* freelist(elem_t *h)
{
	elem_t *tbd;

	while(h) {
		tbd = h;
		h = h -> next;
		free(tbd);
	}
	
	return h;
}
