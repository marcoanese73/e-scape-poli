#include <stdio.h>
#define MAXCAR 3

int strlength (char * stringa) {                            
	int i, len;
	len = 0;
	for (i = 1; stringa [i] != '\0'; i++)
		len++;
	return len;
}



int relative_int (char * stringa) {	
	int i, cifra, val, len, var;
	len = strlength (stringa);        /* Sarebbe stato possibile usare la funzione di libreria strlen */	
	for (i = len, var = 1, val = 0; i >= 1; i--) {
		cifra = stringa [i] - '0';          
		val =  val + (cifra * var);  
		var = var * 10;
	}
	
	return val;
}
	

int main (int argc, char * argv  []) {
	char stringa [MAXCAR +1];
	int ris;
	scanf ("%s", stringa);
	ris = relative_int (stringa);
	printf ("%d\n", ris);
	return 0;
}

	
	
