/* ================================================= *
 * PRINTABLE:--------------------------------------- *
 * Creates a printable version of a C file!----------*
 * Cool, huh?--------------------------------------- *
 * ================================================= */

#include <stdio.h>
#include <string.h>
#define MAXLEN 500
#define OUTPUT_NAME "./printable.txt"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET  "\x1b[0m"

int main(int argc, char *argv[])
{
	char file_name[MAXLEN+3], this_car;
	FILE *fin, *fout;
	int i, name_len, found;

	printf("Inserire il nome del file da convertire, comprensivo di percorso\nSono consentiti al piu' %d caratteri: ", MAXLEN);
	scanf("%s", file_name);

	name_len = strlen(file_name);

	for(i = name_len, found = 0; !found && file_name[i] != '.'; i--)
		if(file_name[i] == '/') {
			file_name[name_len] = '.';
			file_name[name_len+1] = 'c';
			file_name[name_len+2] = '\0';
			found = 1;
			printf(ANSI_COLOR_YELLOW "ATTENZIONE" ANSI_COLOR_RESET);
			printf(": Non posso convertire un eseguibile!\n");
			printf("Aggiunta estensione: %s\n", file_name);
		}
	
	if(fin = fopen(file_name, "r")) {
		if(fout = fopen(OUTPUT_NAME, "w")) {
			fscanf(fin, "%c", &this_car);
			while(!feof(fin)) {
				switch(this_car) {
				case '"' : fprintf(fout, " \\\" ");
					   break;
				case '\\': fprintf(fout, " \\\\ ");
					   break;
				case '\n': fprintf(fout, " \\n ");
					   break;
				case '%': fprintf(fout, " %%%% ");
					   break;
				case '\t': fprintf(fout, " \\t ");
					   break;
				case ' ' : fprintf(fout, " \\s ");
					   break;
				default  : fprintf(fout, "%c", this_car);
					   break;
				}
			fscanf(fin, "%c", &this_car);
			}
			fclose(fin);
			fclose(fout);
			printf("Il file e' stato convertito in versione stampabile.\n");
		} else
			printf("Errore file %s\n", OUTPUT_NAME);
	} else
		printf("Errore file %s\n", file_name);

	return 0;
}
