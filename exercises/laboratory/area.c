#include <stdio.h>

#define N 10

typedef struct c {
	int x;
	int y;
} coord_t;

int main(int argc, char * argv[])
{
	int n;
	int i, j, sum;
	coord_t p[N];
	float area;

	do
		scanf("%d", &n);
	while(n < 1 || n > 10);

	for(i = 0; i < n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);

	sum = 0;

	for(i = 0, j = 1; i < n; i++) {
		if(i == (n-1))
			j = 1 - n;
		sum = sum + ((p[i].x * p[i+j].y) - (p[i+j].x * p[i].y));
	}

	if(sum < 0)
		sum = - sum;

	area = sum / 2;

	printf("%.4f\n", area);
		
	return 0;
}