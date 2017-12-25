#include <stdio.h>

#define SOURCE_NAME "./files/source.txt"
#define DEST_NAME "./files/dest.txt"
#define LNOME 30
#define LCOGNOME 30
#define LCITTA 20
#define LS 2
#define LTEL 10

void provincia(FILE*, FILE*, char[]);

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	char *sigla;

	if(argc < 2)
		printf("Comando non valido\n");
	else {
		sigla = argv[1];
		if(fin = fopen(SOURCE_NAME, "r")) {
			if(fout = fopen(DEST_NAME, "w")) {
				provincia(fin, fout, sigla);
				fclose(fin);
				fclose(fout);
			} else
				printf("Errore file %s\n", DEST_NAME);
		} else
			printf("Errore file %s\n", SOURCE_NAME);
	}

	return 0;
}

void provincia(FILE *source, FILE *dest, char sigla[])
{
	char cognome[LCOGNOME+1], nome[LNOME+1], citta[LCITTA+1], provincia[LS+1], telefono[LTEL+1];
	int i, trovato;

	fscanf(source, "%s", cognome);
	while(!feof(source)) {
		fscanf(source, "%s", nome);
		fscanf(source, "%s", citta);
		fscanf(source, "%s", provincia);
		fscanf(source, "%s", telefono);
		for(trovato = 1, i = 0; sigla[i] != '\0'; i++)
			if(sigla[i] != provincia[i])
				trovato = 0;
		if(trovato)
			fprintf(dest, "%s %s %s %s %s\n", cognome, nome, citta, provincia, telefono);
		fscanf(source, "%s", cognome);
	}

	return;
}