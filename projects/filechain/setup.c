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

int main(int argc, char *argv[])
{
	struct stat st;
	FILE *fp;

	printf("Eseguo il setup\n");

	if(stat(LEDGER_DIR_NAME, &st) == -1) {
		mkdir(LEDGER_DIR_NAME, 0700);
		printf("Creata directory %s\n", LEDGER_DIR_NAME);
	} else
		printf("La directory %s esiste\n", LEDGER_DIR_NAME);

	if(fp = fopen(LEDGER_FILE_NAME, "w")) {
		printf("Creato file %s\n", LEDGER_FILE_NAME);
		printDate(fp);
		fprintf(fp, " Created Ledger\n");
	} else
		printf("Errore nella creazione del file %s\n", LEDGER_FILE_NAME);

	if(stat(MATRIX_DIR_NAME, &st) == -1) {
		mkdir(MATRIX_DIR_NAME, 0700);
		printf("Creata directory %s\n", MATRIX_DIR_NAME);
	} else
		printf("La directory %s esiste\n", MATRIX_DIR_NAME);

	if(stat(NODE_1_DIR_NAME, &st) == -1) {
		mkdir(NODE_1_DIR_NAME, 0700);
		printf("Creata directory %s\n", NODE_1_DIR_NAME);
	} else
		printf("La directory %s esiste\n", NODE_1_DIR_NAME);

	if(fp = fopen(NODE_1_STATUS_NAME, "w")) {
		printf("Creato file %s\n", NODE_1_STATUS_NAME);
		printDate(fp);
		fprintf(fp, " Created Status (1)\n");
	} else
		printf("Errore nella creazione del file %s\n", NODE_1_STATUS_NAME);

	if(stat(NODE_2_DIR_NAME, &st) == -1) {
		mkdir(NODE_2_DIR_NAME, 0700);
		printf("Creata directory %s\n", NODE_2_DIR_NAME);
	} else
		printf("La directory %s esiste\n", NODE_2_DIR_NAME);

	if(fp = fopen(NODE_2_STATUS_NAME, "w")) {
		printf("Creato file %s\n", NODE_2_STATUS_NAME);
		printDate(fp);
		fprintf(fp, " Created Status (2)\n");
	} else
		printf("Errore nella creazione del file %s\n", NODE_2_STATUS_NAME);
	
	if(stat(NODE_3_DIR_NAME, &st) == -1) {
		mkdir(NODE_3_DIR_NAME, 0700);
		printf("Creata directory %s\n", NODE_3_DIR_NAME);
	} else
		printf("La directory %s esiste\n", NODE_3_DIR_NAME);

	if(fp = fopen(NODE_3_STATUS_NAME, "w")) {
		printf("Creato file %s\n", NODE_3_STATUS_NAME);
		printDate(fp);
		fprintf(fp, " Created Status (3)\n");
	} else
		printf("Errore nella creazione del file %s\n", NODE_3_STATUS_NAME);
	
	if(stat(NODE_4_DIR_NAME, &st) == -1) {
		mkdir(NODE_4_DIR_NAME, 0700);
		printf("Creata directory %s\n", NODE_4_DIR_NAME);
	} else
		printf("La directory %s esiste\n", NODE_4_DIR_NAME);

	if(fp = fopen(NODE_4_STATUS_NAME, "w")) {
		printf("Creato file %s\n", NODE_4_STATUS_NAME);
		printDate(fp);
		fprintf(fp, " Created Status (4)\n");
	} else
		printf("Errore nella creazione del file %s\n", NODE_4_STATUS_NAME);
	
	if(stat(NODE_5_DIR_NAME, &st) == -1) {
		mkdir(NODE_5_DIR_NAME, 0700);
		printf("Creata directory %s\n", NODE_5_DIR_NAME);
	} else
		printf("La directory %s esiste\n", NODE_5_DIR_NAME);

	if(fp = fopen(NODE_5_STATUS_NAME, "w")) {
		printf("Creato file %s\n", NODE_5_STATUS_NAME);
		printDate(fp);
		fprintf(fp, " Created Status (5)\n");
	} else
		printf("Errore nella creazione del file %s\n", NODE_5_STATUS_NAME);

	printf("Setup completato\n");

	return 0;
}
