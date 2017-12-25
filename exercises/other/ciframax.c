#include <stdio.h>

#define BASE 10

int ciframax(int);

int main(int argc, char * argv[])
{
	int num;

	scanf("%d", &num);
	printf("%d\n", ciframax(num));

	return 0;
}

int ciframax(int num)
{
	int cifra;

	if(num < 0)
		num = -num;

	if(num < BASE)
		return num;

	cifra = num % BASE;

	if(cifra > ciframax(num/BASE))
		return cifra;

	return ciframax(num/BASE);
}