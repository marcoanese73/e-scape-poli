#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#define ANSI_COLOR_RED	 "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define PRINTABLE_NAME "./printable.txt"
#define SLEEP 9000

/* Functions prototypes */

void initSetup(int*);
void createReadme(char[], int*);
void printDate(FILE*);
void createDir(char[]);
void createLedger(char[], int*);
void createStatus(char[], int*);
void scanStatus(char[], int*);
void createSim(char[], int*);
void endSetup(int*);

/* Initialize setup */

void initSetup(int *errors)
{
	printf("Eseguo il setup\n");
	*errors = 0;
	usleep(SLEEP);

	return;
}

/* Create a readme file */

void createReadme(char file_name[], int *errors)
{
	FILE *fp;

	if(fp = fopen(file_name, "w")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", file_name);
		fprintf(fp, "TUTORIAL\n\n");
		fprintf(fp, "1)Individua il percorso del file che vuoi venga salvato con filechain\n");
		fprintf(fp, "2)Usa il comando 'filechain -s <nome-file.txt>' per memorizzarlo nella filechain simulata (cartelle dentro 'simulation')\n");
		fprintf(fp, "2)Inserisci il nome con cui vuoi memorizzarlo (vuoto per il nome attuale) e premi INVIO\n");
		fprintf(fp, "3)Riapri il tuo file utilizzando il comando 'filechain -o <nome-file.txt>'\n\n");
		fclose(fp);
	} else {
		printf("Errore nella creazione del file %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", file_name);
		(*errors)++;
	}
	usleep(SLEEP);

	return;

}

/* Write on file current date */

void printDate(FILE *fp)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	fprintf(fp, "%0*d-%0*d-%d ", 2, tm.tm_mday, 2, tm.tm_mon + 1, tm.tm_year + 1900);
	fprintf(fp, "%0*d:%0*d:%0*d ", 2, tm.tm_hour, 2, tm.tm_min, 2, tm.tm_sec);

	return;
}

/* If it does not already exists, create a new directory */

void createDir(char dir_name[])
{
	struct stat st;

	if(stat(dir_name, &st) == -1) {
		mkdir(dir_name, 0700);
		printf("Creata directory %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", dir_name);
	} else
		printf("La directory %s esiste " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", dir_name);
	usleep(SLEEP);

	return;
}

/* If it does not already exists, create a new ledger file */

void createLedger(char file_name[], int *errors)
{
	FILE *fp;

	if(fp = fopen(file_name, "w")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", file_name);
		printDate(fp);
		fprintf(fp, "Created ledger\n");
		fclose(fp);
	} else {
		printf("Errore nella creazione del file %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", file_name);
		(*errors)++;
	}
	usleep(SLEEP);

	return;
}

/* If it does not already exists, create a new status file */

void createStatus(char file_name[], int *errors)
{
	FILE *fp;

	if(fp = fopen(file_name, "wb")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", file_name);
		fprintf(fp, "OFF\n");
		fclose(fp);
	} else {
		printf("Errore nella creazione del file %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", file_name);
		(*errors)++;
	}
	usleep(SLEEP);
	scanStatus(file_name, errors);

	return;
}

/* Read and print status */

void scanStatus(char file_name[], int *errors)
{
	FILE *fp;
	char this_car;

	if(fp = fopen(file_name, "rb")) {
		printf("Stato %s: ", file_name);
		fscanf(fp, "%c", &this_car);
		while(!feof(fp) && this_car != '\n') {
			printf("%c", this_car);
			fscanf(fp, "%c", &this_car);
		}
		printf(ANSI_COLOR_GREEN " OK" ANSI_COLOR_RESET "\n");
		fclose(fp);
	} else {
		printf("Errore nella lettura dello stato %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", file_name);
		(*errors)++;
	}
	usleep(SLEEP);

	return;
}

/* Create .c file */

void createSim(char file_name[], int *errors)
{
	FILE *fp, *fprint;
	char word[500];
	int i, space;

	if(fp = fopen(file_name, "w")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", file_name);
		if(fprint = fopen(PRINTABLE_NAME, "r")) {
			fscanf(fprint, "%s", word);
			while(!feof(fprint)) {
				for(space = 0, i = 0; word[i] != '\0'; i++)
					if(word[i] == ' ')
						space = 1;
				if(word[0] == '\\' && word[1] == 's')
					fprintf(fp, "%c", ' ');
				else if(word[0] == '\\' && word[1] == 'n')
					fprintf(fp, "\n");
				else if(word[0] == '\\' && word[1] == 't')
					fprintf(fp, "\t");
				else if(word[0] == '\\' && word[1] == '\\')
					fprintf(fp, "\\");
				else if(word[0] == '\\' && word[1] == '"')
					fprintf(fp, "\"");
				else if(word[0] == '%' && word[1] == '%')
					fprintf(fp, "%%");
				else
					fprintf(fp, "%s", word);
				fscanf(fprint, "%s", word);
			}
			fclose(fp);
		} else {
			printf("Non ho trovato il file %s\n", PRINTABLE_NAME);
			fprintf(fp, "/* Coming soon... */");
			fclose(fp);
	} } else {
		printf("Errore nella creazione del file %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", file_name);
		(*errors)++;
	}
	usleep(SLEEP);

	return;

}

/* Terminate setup */

void endSetup(int *errors)
{
	printf("Setup completato ");
	if(*errors != 1)
		printf("(%d errori)\n", *errors);
	else
		printf("(%d errore)\n", *errors);

	return;
}
