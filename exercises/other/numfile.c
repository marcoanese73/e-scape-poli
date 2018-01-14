#include <stdio.h>
#define LEN 500

int main(int argc, char *argv[])
{
	char fname[LEN+1];
	char car, prec_car;
	FILE *fp;
	int conta;

	gets(fname);

	if(fp = fopen(fname, "r")) {
		fscanf(fp, "%c", &car);
		prec_car = car;
		conta = 0;
		while(!feof(fp)) {
			if((prec_car - '0' >= 0 && prec_car - '0' <= 9) && !(car - '0' >= 0 && car - '0' <= 9))
				conta++;
			prec_car = car;
			fscanf(fp, "%c", &car);
		}
		fclose(fp);
		printf("%d\n", conta);
	} else
		printf("Errore file %s\n", fname);

	return 0;
}
