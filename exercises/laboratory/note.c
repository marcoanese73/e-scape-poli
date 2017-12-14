#include <stdio.h>
#include <string.h>
#define L 100
#define C 80
#define NOTES 7

int main(int argc, char * argv[])
{
	char fname[L+1], nota[3];
	int note[C], repeat, note_len, cols, space, i;
	int all_notes[NOTES], conta_div, conta_tot;
	FILE *fp;

	gets(fname);
	if(fp = fopen(fname, "r")) {
		for(i = 0; i < NOTES; i++)
				all_notes[i] = 0;
		fscanf(fp, "%s", nota);
			cols = 0;
			space = 0;
			conta_tot = 0;
			conta_div = 0;
			while(!feof(fp)) {
				if(space) {
					printf(" ");
					space = 0;
				}
				all_notes[nota[0] - 'A']++;
				note_len = strlen(nota);
				fscanf(fp, "%d", &repeat);
				for(i = 0; i < repeat; i++) {
					cols += note_len;
					if(cols >= C+1) {
						printf("\n");
						cols = note_len + 1;
					}
					printf("%s", nota);
					if(i < repeat-1)
						printf(" ");
					space = 1;
					conta_tot++;
					cols += 1;

				}
				fscanf(fp, "%s", nota);
			}
			for(i = 0; i < NOTES; i++)
				if(all_notes[i] != 0)
					conta_div++;
			printf("\n%d note diverse\n%d note totali\n", conta_div, conta_tot);
			
	} else
		printf("Errore file %s\n", fname);

	return 0;
}
