#include <stdio.h>
#define FILE_NAME "./dizionario.txt"
#define LEN 35

int main(int argc, char *argv[])
{
	FILE *fp;
	char parola[LEN+1], this_vowel, prev_vowel;
	int i, trovato, ordinato, consonante;

	if(fp = fopen(FILE_NAME, "r")) {
	    fscanf(fp, "%s", parola);
		while(!feof(fp)) {
			for(trovato = 0, i = 0; !trovato && parola[i] != '\0'; i++)
				switch(parola[i]) {
					case 'a': prev_vowel = 'a';
							  trovato = 1;
							  break;
					case 'e': prev_vowel = 'e';
							  trovato = 1;
							  break;
					case 'i': prev_vowel = 'i';
							  trovato = 1;
							  break;
					case 'o': prev_vowel = 'o';
							  trovato = 1;
							  break;
					case 'u': prev_vowel = 'u';
							  trovato = 1;
							  break;
				}
			for(ordinato = 1; ordinato && parola[i] != '\0'; i++) {
                consonante = 0;
				switch(parola[i]) {
					case 'a': this_vowel = 'a';
							  break;
					case 'e': this_vowel = 'e';
							  break;
					case 'i': this_vowel = 'i';
							  break;
					case 'o': this_vowel = 'o';
							  break;
					case 'u': this_vowel = 'u';
							  break;
                    default : consonante = 1;
				}
				if(!consonante) {
				if(this_vowel - 'a' < prev_vowel - 'a')
					ordinato = 0;
				prev_vowel = this_vowel;
				}
			}
			if(ordinato)
				printf("%s\n", parola);

			fscanf(fp, "%s", parola);
		}
		fclose(fp);
	} else
		printf("Errore nell'accesso al file %s\n", FILE_NAME);

    return 0;
}
