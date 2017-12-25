#include <stdio.h>

#define N 30

int main(int argc, char * argv[])
{
	char seq[N+1];
	int i;

	scanf("%s", seq);

	for(i = 0; seq[i] != '\0'; i++)
		;

	for(i = i - 1; i >= 0; i--)
		printf("%c", seq[i]);

	printf("\n");

	return 0;
}