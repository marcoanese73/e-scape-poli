#include <stdio.h>

#define N 20

int main(int argc, char * argv[])
{
	char str[N], car;
	int i, nc;

	for(i = 0; i < N; i++)
		scanf("%c", &str[i]);

	i--;
	car = str[i];
	
	while(i >= 0) {
		for(nc = 0; i >= 0 && str[i] == car; i--)
			nc++;
		printf("%c%d", car, nc);
		car = str[i];
	}

	printf("\n");

	return 0;
}