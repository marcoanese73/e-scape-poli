#include <stdio.h>

#define MAXN 1000
#define STOP 0
#define BASE 10

typedef struct _stat {
	int num;
	int ncifre;
} stat_t;

int numcifre(int);

int main(int argc, char *argv[])
{
	stat_t val[MAXN];
	int n, acc;
	int i, j;
	float media;

	scanf("%d", &n);
	i = 0;
	acc = 0;
	while(n != STOP) {
		val[i].num = n;
		val[i].ncifre = numcifre(val[i].num);
		acc += val[i].ncifre;
		i++;
		scanf("%d", &n);
	}
	
	if(i > 0) {
		media = (float)acc / i;
		for(j = 0; j < i; j++)
			if(val[j].ncifre > media)
				printf("%d\n", val[j].num);
	}

	return 0;
}

int numcifre(int n)
{
	int cont;

	if(n < 0)
		n = - n;

	cont = 0;
	while(n > 0) {
		n = n / BASE;
		cont++;
	}

	return cont;
}