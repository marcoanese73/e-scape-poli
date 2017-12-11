/* 2.6 MATRICE IMPAZZITA */

/* Si inizializzi una matrice quadrata di dimensione 5x5 con gli interi da 1 a 25 in modo che la prima riga contenga i numeri da 1 a 5, la seconda da 6 a 10, etc.
Si chieda all'utente di scegliere una cella della matrice inserendo l'indice della riga r e della colonna c. Sia K il numero contenuto nella cella m[r][c].
Si modifichi quindi la matrice come descritto in seguito:
- la cella selezionata m[r][c] resti invariata;
- tutte le celle della colonna c diverse da quella selezionata assumano valore 2K;
- a tutte le celle "precedenti" (cioè su righe precedenti a r, oppure sulla stessa riga ma in colonne precedenti a c) che non siano nella colonna c venga aggiunto K;
- a tutte le celle "successive" (righe successive, oppure stessa riga ma colonne successive) che non siano sulla colonna c venga sottratto K. */

#include <stdio.h>
#define N 5

int main(int argc, char * argv[])
{
	int m[N][N];
	int i, j, num;
	int r, c;
	int k;

	for(i = 0, num = 1; i < N; i++)
		for(j = 0; j < N; j++) {
			m[i][j] = num;
			num++;
		}
	
	scanf("%d%d", &r, &c);

	k = m[r][c];

	for(i = 0; i < N; i++) {
		if(i != r)
			m[i][c] = k * 2;
	}

	for(i = 0; i <= r; i++) {
		for(j = 0; j < N; j++) {
			if(j != c && i != r)
				m[i][j] = m[i][j] + k;
			else if(j < c)
				m[i][j] = m[i][j] + k;
			else if (j != c) 
				m[i][j] = m[i][j] - k;
		}
	}

	for(i = r + 1; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(j != c)
				m[i][j] = m[i][j] - k;
		}
	}

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%d ", m[i][j]);
		}
	printf("\n");
	}

	return 0;
}
