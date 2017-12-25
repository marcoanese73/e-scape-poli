#include <stdio.h>

#define L 16
#define BASE 10

int main(int argc, char * argv[])
{
	char cred[L+1];
	int tot, prod, i, digit, left, valida;

	gets(cred);
	
	for(tot = 0, i = L-1; i >= 0; i--) {
		if(i % 2 != 0)
			tot += cred[i] - '0';
		else {
			prod = 2 * (int)(cred[i] - '0');
			if(prod >= 10) {
				digit = prod % BASE;
				tot += digit;
				left = prod / BASE;
				tot += left;
			}
			else
				tot += prod;
		}
	}

	if(tot % BASE == 0)
		valida = 1;
	else
		valida = 0;

	printf("%d\n", valida);

	return 0;



}