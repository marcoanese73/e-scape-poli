#include <stdio.h>

int bisestile_ (int);

int main (int argc, char * argv []) {

	int day, mth, year, i, cont, ndays, flag;

	scanf ("%d%d%d", &day, &mth, &year);

	i = mth -1;

	cont = 0;

	flag = bisestile_ (year);

	while (i >= 1) {
		
		if (i == 4 || i == 6 || i == 9 || i == 11) 

			cont = cont + 30;
		
		else {

			if (i == 2) {

				if (flag == 0)

					cont = cont + 29;

				else 
					cont = cont + 28;

			} else

				cont = cont + 31;

		}
	
		i--;
	}
	
	ndays = cont + day;
	
	printf ("%d\n", ndays);
	
return 0;

}
	

int bisestile_ (int year) {

	int flag;

	flag = 1;

	if (year % 4 == 0) {

		if (year % 100 == 0) {
			
			if (year % 400 == 0)
				
				flag = 0;
		}

		else 
			flag = 0;

	}

return flag;

}









	
		











			
	
			
			
		
		
