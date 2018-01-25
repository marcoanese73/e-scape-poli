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

		

		

		

		

	
