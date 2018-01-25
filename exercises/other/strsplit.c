/*
Scrivere un sottoprogramma che ricevuta in ingresso una stringa, restituisce
una struttura dati che contenga (con una opportuna gestione della
memoria, priva di sprechi) un insieme di stringhe di 160 caratteri ciascuna, contenenti le parti della stringa iniziale suddivisa in pezzi da 160 caratteri.

Ad esempio, se la stringa iniziale contiene la frase seguente:

	Il testo di questa stringa ha una lunghezza complessiva di 331 caratteri, per cui verra’
	spezzato in 3 stringhe di 160 caratteri ciascuna per consentire l’invio di 3 sms distinti.
	E’ necessario predisporre una opportuna struttura dati in grado di contenere esattamente le
	3 stringhe di al piu’ 160 caratteri, senza sprechi.

il sottoprogramma dovrà creare e restituire 3 stringhe, cosiffatte:

	Il testo di questa stringa ha una lunghezza complessiva di x caratteri, per cui verra’
	spezzato in 3 stringhe di 160 caratteri ciascuna per consentire l’invio d

	i 3 sms distinti.  E’ necessario predisporre una opportuna struttura dati in grado di
	contenere esattamente le 3 stringhe di al piu’ 160 caratteri, senza sprechi

	di memoria.

Il sottoprogramma restituisce e non visualizza nulla.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 160
#define DEF 1000

typedef struct _el{
	char * str;
	struct _el * next;
} str_t;

str_t * strsplit(str_t * head, char str[])
{
	
	int totlen, lastlen, nintere;
	int i,j,h;

	char strpiece[N+1];

	totlen = strlen(str);

	nintere = totlen/N;

	lastlen = totlen%N;

	j=0;

	for(i=1; i<=nintere; i++){
		for(h=0; j<i*N; j++, h++)
			strpiece[h] = str[j];

		head = append(head, strpiece, N);
	}

	head = append(head, &str[j], lastlen);

	return head;
}

str_t * append(str * head, char str[], strlen)
{
	str_t * nuovo, * p;

	if(nuovo = (str_t *) malloc(sizeof(str_t))){

		if(nuovo->str = (char *) malloc(sizeof(char)*(strlen + 1))){
			nuovo -> next = NULL;
			strcpy(nuovo->str, str);

			if(head){
				for(p=head, p->next; p=p->next)
					;
				p->next = nuovo;
			}else
				head = nuovo;
		}else
			printf("err. all. mem %s", str);
	}else
		printf("err. all. mem %s", str);

	return head;
}
	
