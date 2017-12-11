/* 2.4 AREA DI UN POLIGONO */

/* Scrivere un programma che acquisisce da tastiera le coordinate x e y di un insieme ordinato di punti (al più 10 punti) che descrive un poligono (semplice).
Il numero di punti non é noto a priori, ma viene inserito come primo valore e il programma deve verificare che tale valore sia maggiore di 1 e non superiore a 10.
Il poligono viene formato collegando tra loro i punti nell'ordine in cui sono inseriti. Il primo e l'ultimo punto inseriti vengono collegati tra loro.
Il programma calcola e visualizza l'area del poligono (approssimati alla quarta cifra decimale con formato "%.4f") seguita dal carattere '\n'.
Si suggerisce l'utilizzo della formula dell'area di Gauss per svolgere il compito. */

#include <stdio.h>
#define N 10

typedef struct c {
	int x;
	int y;
} coord_t;

int main(int argc, char * argv[])
{
	int n;
	int i, j, sum;
	coord_t p[N];
	float area;

	do
		scanf("%d", &n);
	while(n < 1 || n > 10);

	for(i = 0; i < n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);

	sum = 0;

	for(i = 0, j = 1; i < n; i++) {
		if(i == (n-1))
			j = 1 - n;
		sum = sum + ((p[i].x * p[i+j].y) - (p[i+j].x * p[i].y));
	}

	if(sum < 0)
		sum = - sum;

	area = sum / 2;

	printf("%.4f\n", area);
		
	return 0;
}
