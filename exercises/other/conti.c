
/* Un file contiene un certo numero di righe, il cui numero non è noto a priori.
Ogni riga è strutturata nel seguente modo:
importo (espresso in euro);nominativo (sequenza di al più 30 caratteri)
che corrisponde alla spesa effettuata dal nominativo indicato.
Il file contiene l'insieme delle spese sostenute da un gruppo di personedurante un viaggio.
Al termine del viaggio, a fronte delle spese complessive fatte,
si vuole sapere per ogni nominativo, in base a quanto ha già speso, quanti soldi deve 
ricevere/dare in modo tale che il totale speso venga diviso tra i partecipanti.
Il numero dei partecipanti non è noto a priori ma va dedotto dal numero dei diversi nominativi
presenti nel file.
Scrivere un programma che chiede all'utente il nome del file contenente le informazioni 
(al più 120 caratteri) e calcola e visualizza per ogni nominativo la cifra che deve ricevere
(preceduta da un carattere '+') o che deve dare (preceduta da un carattere '-').
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LFILE 120
#define LNOM 30

typedef struct _l {

	float imp;

	char nom [LNOM +1];

	struct _l *next;

} riga_t;

int main (int argc, char * argv []) {

	FILE *fp;

	riga_t *head = NULL;
	riga_t *p;

	char nomef [LFILE + 1], nom [LNOM + 1];

	int npers, i;

	float imp, tot, avg;

	gets (nomef);

	if (fp = fopen (nomef, "r")) {

		tot = 0.0;

		npers = 0;

		fscanf (fp, "%d", &imp);

		fscanf (fp, "%s", nom);

		while (!feof (fp)) {
	
			tot += imp;

			npers++;

			for (i = 0; nom [i] != '\0'; i++)

				nom [i] = nom [i + 1];
			
			head = append (head, imp, nom);

			fscanf (fp, "%d", &imp);

			fscanf (fp, "%s", nom);

		}

		avg = tot / npers;

		for(p=head; p!=NULL; p=p->next){
			diff = p->imp - avg;
			if(diff > 0)
				printf("+%d %s", diff, p->nom);
			else
				printf("%d %s", diff, p->nom);
		}

		fclose(fp);
	}else
		printf("Err. ap. file %s", nomef);

	return 0;
}

riga_t * append(riga_t * head, float imp, char nom[])
{
	riga_t * nuovo, * p;

	int i;

	if(nuovo = (riga_t *) malloc(sizeof(riga_t))){
		nuovo -> imp = imp;
		strcpy(nuovo->nom, nom);

		nuovo->next = NULL;

		if(head){
			for(p=head; p->next!=NULL; p=p->next)
				;
			p->next = nuovo;
		}else
			head = nuovo;
	}else
		printf("Err. alloc. mem. %f", imp);

	return head;
}

		

		

		

		

	
