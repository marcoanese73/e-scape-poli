#include <stdio.h>

#define STOP 0

int main(int argc, char * argv[])
{
	int num;
	int prec;
	int min, max, trovato;

	do
		scanf("%d", &prec);
	while(prec < 0);
	
	do
		scanf("%d", &num);
	while(num < 0);

	while(num != STOP) {
		if(num != prec && num % 2 == 0 && prec % 2 == 0) {
			if(num < prec) {
				min = num;
				max = prec; }
			else {
				min = prec;
				max = num; }
			trovato = 0;
			while(!trovato && min < max) {
				if (num * prec == min * min) {
					trovato = 1;
					printf("%d %d\n", prec, num); }
				else
					min++;
			}
		}
	prec = num;
	do
		scanf("%d", &num);
	while(num < 0);
	}
	
	return 0;
}
