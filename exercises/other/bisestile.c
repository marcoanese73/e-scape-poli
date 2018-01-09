#include <stdio.h>
int main (int argc, char * argv []) {

	int flag, year;
	
	flag = 1;
	
	scanf ("%d", &year);

	if (year % 4 == 0) {

		if (year % 100 == 0) {
			
			if (year % 400 == 0)
				
				flag = 0;
		}

		else 
			flag = 0;

	}

printf ("%d\n", flag);

return 0;

}
