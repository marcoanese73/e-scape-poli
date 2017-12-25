#include <stdio.h>

#define C 35
#define N 200
#define ONE 1

typedef struct d {
	char voc_ita[C+1];
	char voc_eng[C+1];
} dizionario_t;

void inserisci(dizionario_t[], dizionario_t[], int);
int cerca(dizionario_t[], char[], char[], int);
int check_vocabolo(char[], char[]);

int main(int argc, char * argv[])
{
	dizionario_t dict[N];
	dizionario_t elem[ONE];
	int pos, presenza, i;

	for(i = 0; i < N; i++) {
		scanf("%s", dict[i].voc_ita);
		scanf("%s", dict[i].voc_eng);
	}

	scanf("%s", elem[0].voc_ita);
	scanf("%s", elem[0].voc_eng);

	do
		scanf("%d", &pos);
	while(pos < 0 || pos >= N);

	inserisci(dict, elem, pos);
	presenza = cerca(dict, elem[0].voc_ita, elem[0].voc_eng, N);
	
	if(presenza)
		printf("ITA %s, ENG %s\n", elem[0].voc_ita, elem[0].voc_eng);
	else
		printf("VOCABOLO NON PRESENTE\n");
	
	return 0;
}

void inserisci(dizionario_t dict[], dizionario_t * elem, int indice)
{
	int i;

	for(i = 0; elem[0].voc_ita[i] != '\0'; i++)
		dict[indice].voc_ita[i] = elem[0].voc_ita[i];

	dict[indice].voc_ita[i] = '\0';

	for(i = 0; elem[0].voc_eng[i] != '\0'; i++)
		dict[indice].voc_eng[i] = elem[0].voc_eng[i];

	dict[indice].voc_eng[i] = '\0';
}

int check_vocabolo(char v1[], char v2[])
{
	int i, stop;

	for(i = 0, stop = 0; !stop && !(v1[i] == '\0' && v2[i] == '\0'); i++)
		if(v1[i] != v2[i])
			stop = 1;

	if(stop == 1)
		return 0;

	return 1;
}

int cerca(dizionario_t dict[], char voc_ita[], char voc_eng[], int dim)
{
	int i, j, stop;

	for(i = 0, stop = 0; !stop && i < dim; i++)
		if(check_vocabolo(dict[i].voc_ita, voc_ita)) {
			stop = 1;
			for(j = 0; dict[i].voc_eng[j] != '\0'; j++)
				voc_eng[j] = dict[i].voc_eng[j];
			voc_eng[j] = '\0';
		}
	return stop;
}
