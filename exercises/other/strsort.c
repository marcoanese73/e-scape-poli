#include <stdio.h>

#define LEN 20
#define STOP '#'

int main(int argc, char *argv[])
{
	char seq[LEN+1];
	char car, temp;
	int i, j;

	i = 0;
	do {
		scanf("%c", &car);
		seq[i] = car;
		i++;
	} while(car != STOP);

	for(i = 0; seq[i+1] != STOP; i++)
		for(j = 0; seq[j+1] != STOP; j++)
			if ((seq[j] - 'a') < (seq[j+1] - 'a')) {
				temp = seq[j];
				seq[j] = seq[j+1];
				seq[j+1] = temp;
			}

	for(i = 0; seq[i] != STOP; i++)
		printf("%c", seq[i]);

	printf("\n");

	return 0;
}
