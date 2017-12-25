#include <stdio.h>
#include <string.h>

#define L 100

void subseq(char[]);

int main(int argc, char *argv[])
{
	char str[L+1];

	scanf("%s", str);
	subseq(str);

	return 0;
}

void subseq(char str[])
{
	int sub_len, tot_len;
	int i, j;

	tot_len = strlen(str);
	
	for(sub_len = 1; sub_len <= tot_len; sub_len++) {
		for(i = 0; str[i] != '\0'; i++) {
			if(tot_len-i >= sub_len) {
				for(j = i; (j-i) < sub_len; j++)
					printf("%c", str[j]);
				printf("\n");
			}
		}
	}

	return;
}
