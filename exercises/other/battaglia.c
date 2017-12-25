#include <stdio.h>
#include <stdlib.h>

#define N 5
#define BOAT 1
#define SEA 0

void analisiCampo(int[][N], int, int);

int main(int argc, char *argv)
{
	int mat[N][N];
	int i, j;

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &mat[i][j]);

	analisiCampo(mat, N, N);

	return 0;
}

void analisiCampo(int campoGioco[][N], int nr, int nc)
{
	int i, j, trovato;
	int navi_riga[nc], tot_navi;
	int len, lunghezze[nc], max_len, min_len;

	for(i = 0; i < nr; i++) {
		navi_riga[i] = 0;
		lunghezze[i] = 0;
	}

	for(i = 0, trovato = 0, len = 0; i < nr; i++) {
		for(j = 0; j < nc; j++) {
			if(campoGioco[i][j] == BOAT)
				len++;
			if(!trovato && campoGioco[i][j] == BOAT) {
				trovato = 1;
				navi_riga[i]++;
				
			} else if(campoGioco[i][j] == SEA) {
				trovato = 0;
				if(len != 0) {
					lunghezze[len-1]++;
					len = 0;
				}	
			}
		}
		if(trovato) {
			trovato = 0;
			if(len != 0) {
				lunghezze[len-1]++;
				len = 0;
			}
		}
	}
	
	for(i = 0, tot_navi = 0; i < nr; i++)
		if(navi_riga[i] != 0) {
			printf("Riga %d: %d navi\n", i+1, navi_riga[i]);
			tot_navi += navi_riga[i];
		}

	printf("\nTotale navi: %d\n", tot_navi);

	max_len = 0;
	min_len = 0;

	for(i = 0; i < nr; i++) {
		if(lunghezze[i] != 0) {
			max_len = i+1;
			min_len = i+1;
		} }

	for(i = 0; i < nr; i++)
		if(lunghezze[i] > max_len)
			max_len = i+1;
		else if(lunghezze[i] != 0 && lunghezze[i] < min_len)
			min_len = i+1;

	printf("\nLunghezza nave piu' corta trovata: %d\n", min_len);
	printf("Lunghezza nave piu' lunga trovata: %d\n", max_len);

	printf("\n");
	for(i = 0; i < nr; i++)
		printf("Numero di navi lunghe %d: %d\n", i+1, lunghezze[i]);
	
	return;
}