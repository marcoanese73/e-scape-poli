#include <stdio.h>
#include <math.h>

#define N_FIN "./files/dati.txt"
#define N_FOUTP "./files/primi.bin"
#define N_FOUTNP "./files/nonprimi.bin"

int isprime(int);

int main(int argc, char * argv[])
{
	FILE * fin, * foutp, * foutnp;
	int n;

	if(fin = fopen(N_FIN, "r")) {
		if(foutp = fopen(N_FOUTP, "wb")) {
			if(foutnp = fopen(N_FOUTNP, "wb")) {
				fscanf(fin, "%d", &n);
				while(!feof(fin)) {
					if(isprime(n))
						fwrite(&n, sizeof(int), 1, foutp);
					else
						fwrite(&n, sizeof(int), 1, foutnp);
				fscanf(fin, "%d", &n);
				}
			fclose(foutnp);
			} else printf("Errore file %s\n", N_FOUTNP);
		fclose(foutp);
		} else printf("Errore file %s\n", N_FOUTP);
	fclose(fin);
	} else printf("Errore file %s\n", N_FIN);

	return 0;
}

int isprime(int num) {

	int i, isp;

	isp = 1;
	i = 2;
	while(i <= (int)sqrt(num)) {
		if(num % i == 0)
			isp = 0;
		i++;
	}
	
	return isp;
}