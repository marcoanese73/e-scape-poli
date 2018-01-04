#include <stdio.h>
#define NOMEF "./randtxt.txt"

int main (int argc, char * argv []) {
	
	char elem;

	int conta, flag;

	FILE * fp;
	
	conta = 0;

	if (fp = fopen (NOMEF, "r")) {
		
		fscanf (fp, "%c", &elem);
		
		flag = 0;
		
		while (!feof (fp)) {

			if (elem >= '0' && elem <= '9') {
				
				if (flag == 0) {
					
					conta++;

					flag = 1;
				}

			} else
				flag = 0;
				

			fscanf (fp, "%c", &elem);
		
		}
		
		printf ("%d\n", conta);
	} else
		
		("Errore nell'accesso al file %s", NOMEF);
return 0;

} 
				
