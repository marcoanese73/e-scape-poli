#include <stdio.h>
#define NFILE "./files/dati.bin"
#define MIN 60
#define HR 24

int main(int argc, char * argv[])
{
	FILE * fp;
	float temp[MIN*HR];
	float tot, avg;
	int i, ndati;

	if(fp = fopen(NFILE, "rb")) {
		ndati = MIN*HR;
		fread(temp, sizeof(float), ndati, fp);
		fclose(fp);
		for(tot = 0, i = 0; i < ndati; i++)
			tot = tot + temp[i];
		avg = tot/ndati;
		printf("%f\n", avg);
	}
	else
		printf("Errore file %s\n", NFILE);

	return 0;
}
