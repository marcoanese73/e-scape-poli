#include <stdio.h>

#define LEN 80

int main(int argc, char *argv[])
{
	char source_1[LEN+1], source_2[LEN+1], dest[LEN+1];
	FILE *fin_1, *fin_2, *fout;
	char car;
	
	gets(source_1);
	gets(source_2);
	gets(dest);

	if(fin_1 = fopen(source_1, "r")) {
		if(fin_2 = fopen(source_2, "r")) {
			if(fout = fopen(dest, "w")) {
				fscanf(fin_1, "%c", &car);
					while(!feof(fin_1)) {
						fprintf(fout, "%c", car);
						fscanf(fin_1, "%c", &car);
					}
				fscanf(fin_2, "%c", &car);
					while(!feof(fin_2)) {
						fprintf(fout, "%c", car);
						fscanf(fin_2, "%c", &car);
					}
				fclose(fin_1);
				fclose(fin_2);
				fclose(fout);
			} else
				printf("Errore file %s\n", source_1);
		} else
				printf("Errore file %s\n", source_1);
	} else
				printf("Errore file %s\n", source_1);

	return 0;
}
