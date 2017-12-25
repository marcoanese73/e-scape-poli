#include <stdio.h>

#define N 40

int main(int argc, char * argv[])
{
	FILE * fp;
	char fname[N+1], car;
	int count;

	scanf("%s", fname);

	if(fp = fopen(fname, "r")) {
		count = 0;
		fscanf(fp, "%c", &car);
		while(!feof(fp)) {
			count++;
			fscanf(fp, "%c", &car);
		}
		fclose(fp);
	} else
		count = -1;
	printf("%d\n", count);

	return 0;
}
