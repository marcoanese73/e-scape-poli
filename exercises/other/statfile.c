#include <stdio.h>
#include <string.h>

#define LEN 100

int main(int argc, char *argv[])
{
	char *fname, this_car;
	FILE *fp;
	int righe, tot_car, car_riga, max, media, i;
	char this_riga[LEN+1], max_riga[LEN+1];

	fname = argv[1];

	if(fp = fopen(fname, "r")) {
		fscanf(fp, "%c", &this_car);
		righe = 0;
		tot_car = 0;
		car_riga = 0;
		max = 0;
		i = 0;
		max_riga[1] = '\0';
		while(!feof(fp)) {
			this_riga[i] = this_car;
			i++;
			if(this_car != ' ' && this_car != '\n') {
				tot_car++;
				car_riga++;
			}
			else if (this_car == '\n') {
				righe++;
				i = 0;
				if(car_riga > max) {
					max = car_riga;
					strcpy(max_riga, this_riga);
				}
				car_riga = 0;
			}
			fscanf(fp, "%c", &this_car);
		}
		if(righe != 0)
			media = tot_car / righe;
		else
			media = 0;
		printf("%d\n%d\n%d %d\n%s", righe, tot_car, max, media, max_riga);
		fclose(fp);
	} else
		printf("Errore nell'accesso al file %s\n", fname);

	return 0;
}
