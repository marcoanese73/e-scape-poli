#include <stdio.h>

#define BASE 10
#define ZERO 0

int contacifre(int);

int main(int argc, char *argv[])
{
	int num, k;
	int i, cifre;

	do
		scanf("%d", &num);
	while(num <= 0);

	do
		scanf("%d", &k);
	while(k <= 0);

	cifre = contacifre(num);

	i = 0;
	while(i < k-cifre) {
		printf("%d", ZERO);
		i++;
	}

	printf("%d\n", num);

	return 0;
}

int contacifre(int num)
{
	int cifre;

	cifre = 0;
	while(num > 0) {
		num = num / BASE;
		cifre++;
	}

	return cifre;
}
