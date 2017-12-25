#include <stdio.h>

#define BASE 10

int main(int argc, char *argv[])
{
	int num, cifre;

	do
		scanf("%d", &num);
	while(num <= 0);

	cifre = 0;
	while(num > 0) {
		num = num / BASE;
		cifre++;
	}

	printf("%d\n", cifre);

	return 0;
}
