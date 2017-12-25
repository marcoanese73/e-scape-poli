#include <stdio.h>

#define BASE 2

int main(int argc, char * argv[])
{
	int n, p;
	int ispot;

	do
		scanf("%d", &n);
	while(n <= 0);

	ispot = 1;
	p = BASE;

	while(ispot && n >= p) {
		if(n % p)
			ispot = 0;
		else
			p = p * BASE;
	}

	printf("%d\n", ispot);

	return 0;
}