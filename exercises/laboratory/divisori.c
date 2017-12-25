#include <stdio.h>

int main(int argc, char *argv[])
{
	int x, y, n;
	int divisori;

	do
		scanf("%d", &x);
	while(x <= 0);

	do
		scanf("%d", &y);
	while(y <= 0);

	do
		scanf("%d", &n);
	while(n <= 0);

	divisori = 0;
	while(x <= y) {
		if(x % n == 0)
			divisori++;
		x++;
	}

	printf("%d\n", divisori);

	return 0;
}