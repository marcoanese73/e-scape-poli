#include <stdio.h>

int formula(int);

int main(int argc, char *argv[])
{
	int n, i, max, temp;

	do
		scanf("%d", &n);
	while(n <= 0);

	max = formula(0);

	for(i = 1; i <= n; i++) {
		temp = formula(i);
		if(temp > max)
			max = temp;
	}

	printf("%d\n", max);

	return 0;
}

int formula(int n)
{
	if(n <= 1)
		return n;

	if(n % 2 == 0)
		return formula(n/2);

	return formula(n/2) + formula(n/2+1);
}