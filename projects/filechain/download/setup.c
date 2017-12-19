/* ================================================= *
 * SETUP file: ------------------------------------- *
 * Creates folders for simulation (nodes) ---------- *
 * and related registers (ledger.ldg and status.bin) *
 * ================================================= */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define README_FILE_NAME   "./simulation/readme.txt"
#define LEDGER_FILE_NAME   "./simulation/ledger.ldg"
#define LEDGER_DIR_NAME    "./simulation/"
#define MATRIX_DIR_NAME    "./simulation/matrix/"
#define NODE_1_DIR_NAME    "./simulation/matrix/node-1/"
#define NODE_1_STATUS_NAME "./simulation/matrix/node-1/status-1.bin"
#define NODE_2_DIR_NAME    "./simulation/matrix/node-2/"
#define NODE_2_STATUS_NAME "./simulation/matrix/node-2/status-2.bin"
#define NODE_3_DIR_NAME    "./simulation/matrix/node-3/"
#define NODE_3_STATUS_NAME "./simulation/matrix/node-3/status-3.bin"
#define NODE_4_DIR_NAME    "./simulation/matrix/node-4/"
#define NODE_4_STATUS_NAME "./simulation/matrix/node-4/status-4.bin"
#define NODE_5_DIR_NAME    "./simulation/matrix/node-5/"
#define NODE_5_STATUS_NAME "./simulation/matrix/node-5/status-5.bin"
#define NODE_1_LEDGER_NAME "./simulation/matrix/node-1/ledger.ldg"
#define NODE_2_LEDGER_NAME "./simulation/matrix/node-2/ledger.ldg"
#define NODE_3_LEDGER_NAME "./simulation/matrix/node-3/ledger.ldg"
#define NODE_4_LEDGER_NAME "./simulation/matrix/node-4/ledger.ldg"
#define NODE_5_LEDGER_NAME "./simulation/matrix/node-5/ledger.ldg"
#define NODE_1_SIM_NAME    "./simulation/matrix/node-1/filechain.c"
#define NODE_2_SIM_NAME    "./simulation/matrix/node-2/filechain.c"
#define NODE_3_SIM_NAME    "./simulation/matrix/node-3/filechain.c"
#define NODE_4_SIM_NAME    "./simulation/matrix/node-4/filechain.c"
#define NODE_5_SIM_NAME    "./simulation/matrix/node-5/filechain.c"
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

/* Main program */

int main(int argc, char *argv[])
{
	int errors;

	initSetup(&errors);

	createDir(LEDGER_DIR_NAME);
	createReadme(README_FILE_NAME, &errors);
	createLedger(LEDGER_FILE_NAME, &errors);
	createDir(MATRIX_DIR_NAME);
	createDir(NODE_1_DIR_NAME);
	createStatus(NODE_1_STATUS_NAME, &errors);
	createLedger(NODE_1_LEDGER_NAME, &errors);
	createSim(NODE_1_SIM_NAME, &errors);
	createDir(NODE_2_DIR_NAME);
	createStatus(NODE_2_STATUS_NAME, &errors);
	createLedger(NODE_2_LEDGER_NAME, &errors);
	createSim(NODE_2_SIM_NAME, &errors);
	createDir(NODE_3_DIR_NAME);
	createStatus(NODE_3_STATUS_NAME, &errors);
	createLedger(NODE_3_LEDGER_NAME, &errors);
	createSim(NODE_3_SIM_NAME, &errors);
	createDir(NODE_4_DIR_NAME);
	createStatus(NODE_4_STATUS_NAME, &errors);
	createLedger(NODE_4_LEDGER_NAME, &errors);
	createSim(NODE_4_SIM_NAME, &errors);
	createDir(NODE_5_DIR_NAME);
	createStatus(NODE_5_STATUS_NAME, &errors);
	createLedger(NODE_5_LEDGER_NAME, &errors);
	createSim(NODE_5_SIM_NAME, &errors);

	endSetup(&errors);

	return 0;
}

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
		fprintf(fp, "GUIDA PER L'INSTALLAZIONE (LINUX)\n\n");
		fprintf(fp, "\t1) Salva nella stessa directory i file setup.c e printable.txt\n");
		fprintf(fp, "\t2) Apri il terminale e digita il comando \"gcc -o setup setup.c\"\n");
		fprintf(fp, "\t3) Digita il comando \"./setup\"\n\n");
		fprintf(fp, "GUIDA PER LA SIMULAZIONE\n\n");
		fprintf(fp, "\t1) Apri la cartella simulation/ e poi matrix/\n");
		fprintf(fp, "\t2) Accedi alla directory di un nodo qualsiasi\n");
		fprintf(fp, "\t3) Per ogni nodo su cui non hai mai lavorato, apri il terminale e digita il comando ");
		fprintf(fp, "\"gcc -o filechain filechain.c\"\n");
		fprintf(fp, "\t4) Una volta che l'eseguibile e' stato creato, apri il terminale e digita \"./filechain\"\n");
		fprintf(fp, "\t5) Puoi iniziare la simulazione, utilizzando i comandi descritti in seguito\n\n");
		fprintf(fp, "COMANDI\n\n");
		fprintf(fp, "\tQuesta sezione deve ancora essere scritta\n");
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
	char this_car, next_car;

	if(fp = fopen(file_name, "w")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", file_name);
		if(fprint = fopen(PRINTABLE_NAME, "r")) {
			fscanf(fprint, "%c", &this_car);
			while(!feof(fprint)) {
				if(this_car == '\\') {
					fscanf(fprint, "%c", &next_car);
					if(!feof(fprint)) {
						if(next_car == 'n')
							fprintf(fp, "\n");
						else if(next_car == 't')
							fprintf(fp, "\t");
						else if(next_car == '\\')
							fprintf(fp, "\\");
						else if(next_car == '"')
							fprintf(fp, "\"");
						this_car = next_car;
					}
				} else if(this_car == '%') {
					if(!feof(fprint)) {
						fscanf(fprint, "%c", &next_car);
						if(next_car == '%')
							fprintf(fp, "%%");
						this_car = next_car;
					}
				} else
					fprintf(fp, "%c", this_car);
				fscanf(fprint, "%c", &this_car);
			}
			fclose(fp);
		} else {
			printf("Non ho trovato il file %s\n", PRINTABLE_NAME);
			fprintf(fp, "/* Non ho trovato il file %s */", PRINTABLE_NAME);
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
