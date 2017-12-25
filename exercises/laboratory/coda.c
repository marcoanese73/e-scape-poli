#include <stdio.h>
#include <string.h>

#define N 3
#define L 30
#define CONT 4
#define STOP '0'

typedef struct elem_s {
	char nome[L];
	char descrizione[L];
} elem_t;

typedef struct coda_s {
	int n;
	elem_t c[N];
} coda_t;

int in(coda_t*, elem_t, int);
int out(coda_t*, elem_t*);
void reset(coda_t*);
void print(coda_t*);

int main(int argc, char * argv[])
{
	coda_t my_coda;
	elem_t my_elem, first;
	char strin[L+1];
	int i, check, count;

	reset(&my_coda);
	scanf("%s", strin);
	count = 0;
	while(count < CONT && strin[0] != STOP) {
		strcpy(my_elem.nome, strin);
		scanf("%s", my_elem.descrizione);
		check = in(&my_coda, my_elem, N);
		printf("%d\n", check);
		print(&my_coda);
		scanf("%s", strin);
		count++;
	}

	for(i = CONT; i > 0; i--) {
		check = out(&my_coda, &first);
		printf("%d\n", check);
		if(i > 1)
			printf("> %s %s\n", first.nome, first.descrizione);
		print(&my_coda);
	}

	return 0;
}

void reset(coda_t *my_coda)
{
	my_coda -> n = 0;

	return;
}

int in(coda_t *my_coda, elem_t my_elem, int dim)
{
	int i;

	if(my_coda -> n >= dim) 
		return 0;

	i = my_coda -> n;
	my_coda -> c[i] = my_elem;
	my_coda -> n++;

	return 1;
}

int out(coda_t *my_coda, elem_t *first)
{
	int i;
	elem_t tmp;

	if(my_coda -> n >= 1) {
		*first = my_coda -> c[0];
		for(i = 1; i <= my_coda -> n; i++) {
			strcpy(tmp.nome, (my_coda -> c[i-1]).nome);
			strcpy(tmp.descrizione, (my_coda -> c[i-1]).descrizione);
			strcpy((my_coda -> c[i-1]).nome, (my_coda -> c[i-2]).nome);
			strcpy((my_coda -> c[i-1]).descrizione, (my_coda -> c[i-2]).descrizione);
			strcpy((my_coda -> c[i-2]).nome, tmp.nome);
			strcpy((my_coda -> c[i-2]).descrizione, tmp.descrizione);
		}
		my_coda -> n--;
		return 1;
	}

	return 0;
}

void print(coda_t *my_coda)
{
	int i;

	for(i = 0; i < my_coda -> n; i++)
		printf("[%s,%s]\n", my_coda -> c[i].nome, my_coda -> c[i].descrizione);

	return;
}
