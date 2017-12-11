/* 2.5 SIMMETRIA A L */

/* Scrivere un programma che acquisisce i dati di un array bidimensionale quadrato di dimensione 5, che memorizza valori interi.
Dopo l’acquisizione il programma verifica se valgono le seguenti proprietà:
1. la matrice é simmetrica rispetto alla diagonale principale (ogni elemento in posizione i,j ha ugual valore rispetto all’elemento in posizione j,i);
2. ogni elemento i,j (con j > i) é identico all’elemento della diagonale i,i.
Il programma visualizza il numero 1 se per la matrice entrambe le proprietà sussistono, 0 in caso contrario, seguito dal carattere a capo ('\n'). */

#include <stdio.h>
#define N 5

int main(int argc, char * argv[])
{
	int m[N][N];
	int i, j, sim;
	
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &m[i][j]);

	sim = 1;

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(m[i][j] != m[j][i])
				sim = 0;
			if(j > i) {
				if(m[i][j] != m[i][i])
					sim = 0;
			}
		}
	}

	printf("%d\n", sim);

	return 0;
}
