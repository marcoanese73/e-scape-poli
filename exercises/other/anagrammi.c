#include <stdio.h>
#define LEN 25

int fattoriale(int);
int myStrlen(char[]);

int  main(int argc, char *argv[])
{
    char parola[LEN+1], car;
    int len, num, den;
    int i, j, trovato;
    int occ, anagrammi;

    scanf("%s", parola); /* gets(parola); */

    len = myStrlen(parola); /* len = myStrlen(&parola[0]); */

    num = fattoriale(len);

    for(den = 1, i = 0; parola[i] != '\0'; i++) {
    	car = parola[i];
    	occ = 1;
    	trovato = 0;
    	if(i > 0)
    		for(j = (i-1); j >= 0; j--)
    			if(parola[j] == car)
    				trovato = 1;
    		if(!trovato)
    			for(j = (i+1); parola[j] != '\0'; j++)
    				if(parola[j] == car)
    					occ++;
    		if(occ > 1)
    			den *= fattoriale(occ);
    }

    anagrammi = num / den;
    printf("%d\n", anagrammi);

    return 0;
}

int fattoriale(int n)
{
	if(n <= 1)
		return 1;

	return n * fattoriale(n-1);
}

int myStrlen(char str[])
{
	if(str[0] == '\0')
		return 0;

	return 1 + myStrlen(&str[1]);
}
