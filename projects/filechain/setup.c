/* SETUP file:
 * Crea cartelle di simulazione e i relativi registri (ledger.ldg e status.ldg) per ogni cartella di simulazione
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "./setlib.h"

#define LEDGER_FILE_NAME "./simulation/ledger.ldg"
#define LEDGER_DIR_NAME "./simulation/"
#define MATRIX_DIR_NAME "./simulation/matrix/"
#define NODE_1_DIR_NAME "./simulation/matrix/node-1/"
#define NODE_1_STATUS_NAME "./simulation/matrix/node-1/status.ldg"
#define NODE_2_DIR_NAME "./simulation/matrix/node-2/"
#define NODE_2_STATUS_NAME "./simulation/matrix/node-2/status.ldg"
#define NODE_3_DIR_NAME "./simulation/matrix/node-3/"
#define NODE_3_STATUS_NAME "./simulation/matrix/node-3/status.ldg"
#define NODE_4_DIR_NAME "./simulation/matrix/node-4/"
#define NODE_4_STATUS_NAME "./simulation/matrix/node-4/status.ldg"
#define NODE_5_DIR_NAME "./simulation/matrix/node-5/"
#define NODE_5_STATUS_NAME "./simulation/matrix/node-5/status.ldg"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define SLEEP 10000

int main(int argc, char *argv[])
{
	struct stat st;
	FILE *fp;
	int errors;

	printf("Eseguo il setup\n");
	usleep(SLEEP);
	errors = 0;

	if(stat(LEDGER_DIR_NAME, &st) == -1) {
		mkdir(LEDGER_DIR_NAME, 0700);
		printf("Creata directory %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", LEDGER_DIR_NAME);
	} else
		printf("La directory %s esiste " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", LEDGER_DIR_NAME);
	usleep(SLEEP);

	if(fp = fopen(LEDGER_FILE_NAME, "w")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", LEDGER_FILE_NAME);
		printDate(fp);
		fprintf(fp, " Created Ledger\n");
	} else {
		printf("Errore nella creazione del file %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", LEDGER_FILE_NAME);
		errors++;
	}
	usleep(SLEEP);

	if(stat(MATRIX_DIR_NAME, &st) == -1) {
		mkdir(MATRIX_DIR_NAME, 0700);
		printf("Creata directory %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", MATRIX_DIR_NAME);
	} else
		printf("La directory %s esiste " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", MATRIX_DIR_NAME);
	usleep(SLEEP);

	if(stat(NODE_1_DIR_NAME, &st) == -1) {
		mkdir(NODE_1_DIR_NAME, 0700);
		printf("Creata directory %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_1_DIR_NAME);
	} else
		printf("La directory %s esiste " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_1_DIR_NAME);
	usleep(SLEEP);

	if(fp = fopen(NODE_1_STATUS_NAME, "w")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_1_STATUS_NAME);
		printDate(fp);
		fprintf(fp, " Created Status (1)\n");
	} else {
		printf("Errore nella creazione del file %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", NODE_1_STATUS_NAME);
		errors++;
	}
	usleep(SLEEP);

	if(stat(NODE_2_DIR_NAME, &st) == -1) {
		mkdir(NODE_2_DIR_NAME, 0700);
		printf("Creata directory %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_2_DIR_NAME);
	} else
		printf("La directory %s esiste " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_2_DIR_NAME);
	usleep(SLEEP);

	if(fp = fopen(NODE_2_STATUS_NAME, "w")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_2_STATUS_NAME);
		printDate(fp);
		fprintf(fp, " Created Status (2)\n");
	} else {
		printf("Errore nella creazione del file %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", NODE_2_STATUS_NAME);
		errors++;
	}
	usleep(SLEEP);
	
	if(stat(NODE_3_DIR_NAME, &st) == -1) {
		mkdir(NODE_3_DIR_NAME, 0700);
		printf("Creata directory %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_3_DIR_NAME);
	} else
		printf("La directory %s esiste " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_3_DIR_NAME);
	usleep(SLEEP);

	if(fp = fopen(NODE_3_STATUS_NAME, "w")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_3_STATUS_NAME);
		printDate(fp);
		fprintf(fp, " Created Status (3)\n");
	} else {
		printf("Errore nella creazione del file %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", NODE_3_STATUS_NAME);
		errors++;
	}
	usleep(SLEEP);
	
	if(stat(NODE_4_DIR_NAME, &st) == -1) {
		mkdir(NODE_4_DIR_NAME, 0700);
		printf("Creata directory %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_4_DIR_NAME);
	} else
		printf("La directory %s esiste " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_4_DIR_NAME);
	usleep(SLEEP);

	if(fp = fopen(NODE_4_STATUS_NAME, "w")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_4_STATUS_NAME);
		printDate(fp);
		fprintf(fp, " Created Status (4)\n");
	} else {
		printf("Errore nella creazione del file %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", NODE_4_STATUS_NAME);
		errors++;
	}
	usleep(SLEEP);
	
	if(stat(NODE_5_DIR_NAME, &st) == -1) {
		mkdir(NODE_5_DIR_NAME, 0700);
		printf("Creata directory %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_5_DIR_NAME);
	} else
		printf("La directory %s esiste " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_5_DIR_NAME);
	usleep(SLEEP);

	if(fp = fopen(NODE_5_STATUS_NAME, "w")) {
		printf("Creato file %s " ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n", NODE_5_STATUS_NAME);
		printDate(fp);
		fprintf(fp, " Created Status (5)\n");
	} else {
		printf("Errore nella creazione del file %s " ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET "\n", NODE_5_STATUS_NAME);
		errors++;
	}
	usleep(SLEEP);

	printf("Setup completato ");
	if(errors != 1)
		printf("(%d errori)\n", errors);
	else
		printf("(%d errore)\n", errors);

	return 0;
}
