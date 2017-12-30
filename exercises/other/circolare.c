#include <stdio.h>
#define N 10

int main(int argc, char *argv[])
{
    int vett_1[N], vett_2[N];
    int i, j, k, pivot, first_pivot;
    int first, dist, diversi, trovato;

    for(i = 0; i < N; i++)
    	scanf("%d", &vett_1[i]);

    for(i = 0; i < N; i++)
    	scanf("%d", &vett_2[i]);

    first = vett_1[0];

    first_pivot = -1;
    for(i = N-1; first_pivot == -1 && i >= 0; i--)
    	if(vett_2[i] == first)
    		first_pivot = i;
    if(first_pivot != -1) {
    	trovato = 0;
    	if(first_pivot == 0) {
            trovato = 1;
            pivot = first_pivot;
            for(i = 0; i < N; i++)
                if(vett_1[i] != vett_2[i])
                    trovato = 0;
    	}
  		for(i = first_pivot; !trovato && i != first_pivot-1; i++) {
    		if(i == N)
    			i = 0;
    		if(vett_2[i] == first) {
    			pivot = i;
    		for(diversi = 0, j = 1, k = pivot+1; !diversi && k != pivot; k++, j++) {
    			if(k == N)
    				k = 0;
    			if(vett_1[j] != vett_2[k]) {
    				diversi = 1;
    			}
  			}
    			if(!diversi)
    				trovato = 1;
    		}
    	}
    	if(!trovato)
    		dist = -1;
    	else {
            if(pivot == N-1 || pivot == 0)
                dist = 0;
            else
                dist = N - pivot;
            }
	} else
		dist = -1;

    printf("%d\n", dist);

    return 0;
}
