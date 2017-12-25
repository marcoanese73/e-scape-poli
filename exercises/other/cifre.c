#include <stdio.h>

#define BASE 10

int cifra(int num, int k)
{
	int digit;
	int ris;
	int cifre;
	int i;

	if(k > 0) {
		if(num < 0)
			num = -num;
		cifre = 0;
		i = k;
		while(i > 0 && num > 0) {
			digit = num % BASE;
			num = num / BASE;
			i--;
			cifre++;
		}
		
		if(k > cifre)
			ris = -1;
		else
			ris = digit;
	}
	else
		ris = -1;

	return ris;
}

int main(int argc, char * argv[])
{
	int num, k;

	scanf("%d%d", &num, &k);

	printf("%d\n", cifra(num,k));

	return 0;
}
