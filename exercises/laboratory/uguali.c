#include <stdio.h>

#define N 10

int tuttiuguali(int[], int, int);

int main(int argc, char * argv[])
{
	int vett[N];
	int i;

	for(i = 0; i < N; i++)
		scanf("%d", &vett[i]);

	printf("%d\n", tuttiuguali(vett, N, vett[0]));
	
	return 0;
}

int tuttiuguali(int vett[], int dim, int n)
{
	if(vett[0] == n && dim == 1)
		return 1;

	if(vett[0] == n)
		return tuttiuguali(&vett[1], dim-1, n);

	return 0;
}
