#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int n;
	int * vett, i;

	scanf("%d", &n);

	if(vett = (int *)malloc(n * sizeof(int))) {
		for(i = 0; i < n; i++)
			scanf("%d", vett+i);
		for(i--; i >= 0; i--)
			printf("%d ", *(vett+i));
		printf("\n");
		free(vett);
	}

	return 0;
}
