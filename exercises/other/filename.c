#include <stdio.h>

#define N 50
#define SW '\\'
#define SU '/'

int main(int argc, char * argv[])
{
	char perc[N+1];
	int i;

	scanf("%s", perc);

	for(i = 0; perc[i] != '\0'; i++)
		;

	for(i = i - 1; perc[i] != SW && perc[i] != SU && i >= 0; i--)
		;

	printf("%s\n", &perc[i+1]);

	return 0;
}
