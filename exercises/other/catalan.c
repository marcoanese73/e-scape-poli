#include <stdio.h>

int cat(int);

int main(int argc, char *argv[])
{
	int n;

	scanf("%d", &n);

	printf("%d\n", cat(n));

	return 0;
}

int cat(int n)
{
	int i, ris;

	if(n == 0)
		return 1;

	ris = 0;

	for(i = 0; i <= n-1; i++)
		ris = ris + cat(i) * cat(n-i-1);

	return ris;
}
