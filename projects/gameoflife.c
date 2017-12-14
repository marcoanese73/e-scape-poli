/* Versione per Linux */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_HEIGHT 100
#define MAX_WIDTH 100
#define DEAD '+'
#define ALIVE '#'
#define BLUE "\x1B[34m"
#define WHITE "\x1B[37m"
#define RESET "\x1B[0m"

void configura(int [][MAX_WIDTH], int [][MAX_WIDTH], int, int, int *, int *, int *, int *, int *, int *);
void stampa_menu();
void stampa_configurazioni();
void stampa_regole();
void stampa_parametri();
void stampa_inizio(int [][MAX_WIDTH], int, int, int, int);
void carica_acorn(int [][MAX_WIDTH], int, int);
void carica_gosper(int [][MAX_WIDTH], int, int);
void carica_pulsar(int [][MAX_WIDTH], int, int);
void carica_diehard(int [][MAX_WIDTH], int, int);
void carica_pentomino(int [][MAX_WIDTH], int, int);
void carica_random(int [][MAX_WIDTH], int, int);
int conta_adiacenti(int [][MAX_WIDTH], int, int, int, int);
void chiedi_parametri(int *, int *, int *, int *, int *, int *);
void parametri_predefiniti(int *, int *, int *, int *, int *, int *);
void personalizzato(int [][MAX_WIDTH], int, int); 

int main(int argc, char * argv[])
{
	int this_gen[MAX_HEIGHT][MAX_WIDTH], next_gen[MAX_HEIGHT][MAX_WIDTH];
	int height, width, i, j;
	int frame, no_frames, infinito, vel;
	int adiacenti;
	int play;

	play = 1;

	infinito = 0;
	no_frames = 50;
	height = 20;
	width = 50;
	vel = 100000;

	while(play) {
		configura(this_gen, next_gen, MAX_HEIGHT, MAX_WIDTH, &play, &no_frames, &infinito, &height, &width, &vel);
		for(frame = 0; infinito || frame < no_frames; frame++) {
			for(i = 1; i < MAX_HEIGHT-1; i++) {
				for(j = 1; j < MAX_WIDTH-1; j++) {
					adiacenti = conta_adiacenti(this_gen, MAX_HEIGHT, MAX_WIDTH, i, j);
					if (this_gen[i][j] == 0) {
						if(adiacenti == 3)
							next_gen[i][j] = 1;
					}
					else {	/* if(this_gen[i][j] == 1) */
						if(adiacenti < 2 || adiacenti > 3)
							next_gen[i][j] = 0;
						else
							next_gen[i][j] = 1;
					}
				}
			}
			for(i = 1; i < MAX_HEIGHT-1; i++)
				for(j = 1; j < MAX_WIDTH-1; j++)
					this_gen[i][j] = next_gen[i][j];
			printf("\n");
			for(i = (MAX_HEIGHT/2)-(height/2); i < (MAX_HEIGHT/2)+(height/2); i++) {
				for(j = (MAX_WIDTH/2)-(width/2); j < (MAX_WIDTH/2)+(width/2); j++) {
					if(this_gen[i][j] == 0)
						printf(BLUE "%c " RESET, DEAD);
					else
						printf(WHITE "%c " RESET, ALIVE);
				}
			printf("\n");
			}
		usleep(vel);
		system("clear"); }
		if(play) {
			stampa_inizio(this_gen, MAX_HEIGHT, MAX_WIDTH, height, width);
		}
	}

	system("clear");
	printf("GAME OVER\n\n");

	return 0;
}

void configura(int mat_1[][MAX_WIDTH], int mat_2[][MAX_WIDTH], int h, int w, int * p, int * nfr, int * inf, int * height, int * width, int * vel)
{
	int i, j;
	int option;

	for(i = 0; i < h; i++)
		for(j = 0; j < w; j++) {
			mat_1[i][j] = 0;
			mat_2[i][j] = 0;
		}
	stampa_menu();
	scanf("%d", &option);
	if(option == 0) {
		*nfr = 0;
		*p = 0;
	}
	else if(option == 1) {
		stampa_configurazioni();
		scanf("%d", &option);
		if(option == 0)
			configura(mat_1, mat_2, h, w, p, nfr, inf, height, width, vel);
		else if(option == 1)
			carica_acorn(mat_1, h, w);
		else if(option == 2)
			carica_gosper(mat_1, h, w);
		else if(option == 3)
			carica_pulsar(mat_1, h, w);
		else if(option == 4)
			carica_diehard(mat_1, h, w);
		else if(option == 5)
			carica_pentomino(mat_1, h, w);
		else if(option == 6)
			carica_random(mat_1, h, w);
		else
			configura(mat_1, mat_2, h, w, p, nfr, inf, height, width, vel);
		if(option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6) {
			stampa_parametri();
			scanf("%d", &option);
			if(option == 2)
				chiedi_parametri(p, nfr, inf, height, width, vel);
			else
				parametri_predefiniti(p, nfr, inf, height, width, vel);
			stampa_inizio(mat_1, h, w, *height, *width);
		}
	}
	else if(option == 2) {
		personalizzato(mat_1, h, w);
		stampa_parametri();
		scanf("%d", &option);
			if(option == 2)
				chiedi_parametri(p, nfr, inf, height, width, vel);
			else
				parametri_predefiniti(p, nfr, inf, height, width, vel);
			stampa_inizio(mat_1, h, w, *height, *width);
	}
	else if(option == 3) {
		stampa_regole();
		scanf("%d", &option);
			if(option == 0)
			configura(mat_1, mat_2, h, w, p, nfr, inf, height, width, vel);
			else
			configura(mat_1, mat_2, h, w, p, nfr, inf, height, width, vel);
	}
	else {
		*nfr = 0;
		/* *p = 0; */
	}

}

void stampa_menu() 
{
	system("clear");
	printf("\nGIOCO DELLA VITA DI JOHN CONWAY\n");
	printf("Marco Anese - Versione 1.0 (11 Dicembre 2017)\n\n");
	printf("MENU PRINCIPALE\n\n");
	printf("[1] Predefinito\n");
	printf("[2] Personalizzato\n");
	printf("[3] Regole\n");
	printf("[0] Chiudi\n\n");
}

void stampa_configurazioni()
{
	system("clear");
	printf("\nGIOCO DELLA VITA DI JOHN CONWAY\n");
	printf("(c) Marco Anese - Versione 0.9 (11-15-2017)\n\n");
	printf("CONFIGURAZIONI\n\n");
	printf("[1] Acorn\n");
	printf("[2] Gosper Glider Gun\n");
	printf("[3] Pulsar\n");
	printf("[4] Die Hard\n");
	printf("[5] The R-pentomino\n");
	printf("[6] Random\n");
	printf("[0] Indietro\n\n");
}

void stampa_regole()
{
	system("clear");
	printf("\nGIOCO DELLA VITA DI JOHN CONWAY\n");
	printf("(c) Marco Anese - Versione 0.9 (11-15-2017)\n\n");
	printf("REGOLE\n");
	printf("\nLe transizioni dipendono unicamente dallo stato delle celle vicine in quella generazione:\n\n");
	printf("Qualsiasi cella viva con meno di due celle vive adiacenti muore per isolamento;\n");
	printf("Qualsiasi cella viva con due o tre celle vive adiacenti sopravvive alla generazione successiva;\n");
	printf("Qualsiasi cella viva con più di tre celle vive adiacenti muore per sovrappopolazione;\n");
	printf("Qualsiasi cella morta con tre celle vive adiacenti diventa una cella viva per riproduzione.\n");
	printf("\n[0] OK\n\n");
}

void carica_acorn(int m[][MAX_WIDTH], int h, int w)
{
	m[h/2+1][w/2-3] = 1;
	m[h/2+1][w/2-2] = 1;
	m[h/2+1][w/2+1] = 1;
	m[h/2+1][w/2+2] = 1;
	m[h/2+1][w/2+3] = 1;
	m[h/2-1][w/2-2] = 1;
	m[h/2][w/2] = 1;
}

void carica_gosper(int m[][MAX_WIDTH], int h, int w)
{
	m[h/2-1][w/2-17] = 1;
	m[h/2-1][w/2-16] = 1;
	m[h/2][w/2-17] = 1;
	m[h/2][w/2-16] = 1;
	m[h/2-3][w/2-5] = 1;
	m[h/2-3][w/2-4] = 1;
	m[h/2-2][w/2-6] = 1;
	m[h/2-1][w/2-7] = 1;
	m[h/2][w/2-7] = 1;
	m[h/2+1][w/2-7] = 1;
       	m[h/2+2][w/2-6] = 1;
	m[h/2+3][w/2-5] = 1;
	m[h/2+3][w/2-4] = 1;
	m[h/2][w/2-3] = 1;
	m[h/2][w/2-1] = 1;
	m[h/2][w/2] = 1;
	m[h/2-1][w/2-1] = 1;
	m[h/2+1][w/2-1] = 1;
	m[h/2-2][w/2-2] = 1;
	m[h/2+2][w/2-2] = 1;
	m[h/2-3][w/2+3] = 1;
	m[h/2-3][w/2+4] = 1;
	m[h/2-2][w/2+3] = 1;
	m[h/2-2][w/2+4] = 1;
	m[h/2-1][w/2+3] = 1;
	m[h/2-1][w/2+4] = 1;
	m[h/2-4][w/2+5] = 1;
	m[h/2][w/2+5] = 1;
	m[h/2-4][w/2+7] = 1;
	m[h/2-5][w/2+7] = 1;
	m[h/2][w/2+7] = 1;
	m[h/2+1][w/2+7] = 1;
	m[h/2-3][w/2+17] = 1;
	m[h/2-3][w/2+18] = 1;
	m[h/2-2][w/2+17] = 1;
	m[h/2-2][w/2+18] = 1;
}

void carica_pulsar(int m[][MAX_WIDTH], int h, int w)
{
	m[h/2-4][w/2-6] = 1;
	m[h/2-3][w/2-6] = 1;
	m[h/2-2][w/2-6] = 1;
	m[h/2+2][w/2-6] = 1;
	m[h/2+3][w/2-6] = 1;
	m[h/2+4][w/2-6] = 1;
	m[h/2-4][w/2+6] = 1;
	m[h/2-3][w/2+6] = 1;
	m[h/2-2][w/2+6] = 1;
	m[h/2+2][w/2+6] = 1;
	m[h/2+3][w/2+6] = 1;
	m[h/2+4][w/2+6] = 1;
	m[h/2-1][w/2-4] = 1;
	m[h/2-1][w/2-3] = 1;
	m[h/2-1][w/2-2] = 1;
	m[h/2+1][w/2-4] = 1;
	m[h/2+1][w/2-3] = 1;
	m[h/2+1][w/2-2] = 1;
	m[h/2-1][w/2+4] = 1;
	m[h/2-1][w/2+3] = 1;
	m[h/2-1][w/2+2] = 1;
	m[h/2+1][w/2+4] = 1;
	m[h/2+1][w/2+3] = 1;
	m[h/2+1][w/2+2] = 1;
	m[h/2-4][w/2-1] = 1;
	m[h/2-3][w/2-1] = 1;
	m[h/2-2][w/2-1] = 1;
	m[h/2+4][w/2-1] = 1;
	m[h/2+3][w/2-1] = 1;
	m[h/2+2][w/2-1] = 1;
	m[h/2-4][w/2+1] = 1;
	m[h/2-3][w/2+1] = 1;
	m[h/2-2][w/2+1] = 1;
	m[h/2+4][w/2+1] = 1;
	m[h/2+3][w/2+1] = 1;
	m[h/2+2][w/2+1] = 1;
	m[h/2-6][w/2-4] = 1;
	m[h/2-6][w/2-3] = 1;
	m[h/2-6][w/2-2] = 1;
	m[h/2+6][w/2-4] = 1;
	m[h/2+6][w/2-3] = 1;
	m[h/2+6][w/2-2] = 1;
	m[h/2-6][w/2+4] = 1;
	m[h/2-6][w/2+3] = 1;
	m[h/2-6][w/2+2] = 1;
	m[h/2+6][w/2+4] = 1;
	m[h/2+6][w/2+3] = 1;
	m[h/2+6][w/2+2] = 1;
	
}

void carica_diehard(int m[][MAX_WIDTH], int h, int w)
{
	m[h/2+1][w/2-2] = 1;
	m[h/2][w/2-2] = 1;
	m[h/2+1][w/2-3] = 1;
	m[h/2-1][w/2+3] = 1;
	m[h/2+1][w/2+2] = 1;
	m[h/2+1][w/2+3] = 1;
	m[h/2+1][w/2+4] = 1;
}
void carica_pentomino(int m[][MAX_WIDTH], int h, int w)
{
	m[h/2][w/2] = 1;
	m[h/2][w/2-1] = 1;
	m[h/2-1][w/2] = 1;
	m[h/2+1][w/2] = 1;
	m[h/2-1][w/2+1] = 1;
}
void carica_random(int m[][MAX_WIDTH], int h, int w)
{
	int i, j;

	srand(time(NULL));
	for(i = 2; i < h-2; i++)
		for(j = 2; j < w-2; j++)
			m[i][j] = rand() % 2;
}

int conta_adiacenti(int mat[][MAX_WIDTH], int h, int w, int i, int j)
{
	int x, y;
	int sum;

	for(x = i-1, sum = 0; x <= i+1; x++)
		for(y = j-1; y <= j+1; y++)
			sum = sum + mat[x][y];

	sum = sum - mat[i][j];

	return sum;
}

void stampa_parametri()
{	
	system("clear");
	printf("\nGIOCO DELLA VITA DI JOHN CONWAY\n");
	printf("(c) Marco Anese - Versione 0.9 (11-15-2017)\n\n");
	printf("IMPOSTAZIONE PARAMETRI\n\n");
	printf("[1] Predefiniti\n");
	printf("[2] Personalizzati\n");
	printf("[0] Indietro\n\n");
}

void stampa_inizio(int this_gen[][MAX_WIDTH], int h, int w, int height, int width)
{
	int i, j;
	int start;

	system("clear");
	printf("\n");
	for(i = (h/2)-(height/2); i < (h/2)+(height/2); i++) {
		for(j = (w/2)-(width/2); j < (w/2)+(width/2); j++) {
			if(this_gen[i][j] == 0)
				printf(BLUE "%c " RESET, DEAD);
			else
				printf(WHITE "%c " RESET, ALIVE);
		}
	printf("\n");
	}
	printf("\nDigita un input qualsiasi per continuare... ");
	scanf("%d", &start);

}

void chiedi_parametri(int * p, int * nfr, int * inf, int * height, int * width, int * vel)
{
	system("clear");
	printf("\nGIOCO DELLA VITA DI JOHN CONWAY\n\n");
	printf("IMPOSTAZIONE PARAMETRI\n\n");
	printf("Lunghezza griglia (predefinito = 40): ");
	do
		scanf("%d", width);
	while(*width <= 0 || *width > MAX_WIDTH);
	printf("Altezza griglia (predefinito = 25): ");
	do
		scanf("%d", height);
	while(*width <= 0 || *width > MAX_WIDTH);
	printf("Numero di frames (predefinito = 100): ");
	scanf("%d", nfr);
	if(*nfr < 0)
	*inf = 1;
	printf("Latenza (predefinito = 100): ");
	do
		scanf("%d", vel);
	while(*vel < 0);
	*vel = *vel * 1000;
}

void parametri_predefiniti(int * p, int * nfr, int * inf, int * height, int * width, int * vel)
{
	*width = 40;
	*height = 25;
	*nfr = 100;
	*vel = 100000;
}

void personalizzato(int mat[][MAX_WIDTH], int h, int w)
{
	int i, j;
	int stop;

	system("clear");
	printf("\nGIOCO DELLA VITA DI JOHN CONWAY\n");
	printf("(c) Marco Anese - Versione 0.9 (11-15-2017)\n\n");
	printf("CONFIGURAZIONE PERSONALIZZATA\n\n");
	printf("Digita la coppia di coordinate [i j] che vuoi accendere\n");
	printf("Il punto [0 0] e' al centro della griglia\n");
	printf("Quando hai finito, digita un valore >= 100\n\n");
	stop = 0;
	while(!stop) {
		scanf("%d", &i);;
		if(i >= 100 || i <= -100)
			stop = 1;
		if(!stop) {
			scanf("%d", &j);
				if(j >= 100 || j <= -100)
					stop = 1;
		}
	if(!stop) 
		mat[i+(h/2)][j+(w/2)] = 1;
	}
}
