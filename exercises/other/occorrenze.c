#include <stdio.h>
#include <string.h>
#define LEN 500

int main(int argc, char *argv[])
{
	char str[LEN+1];
	int len, conta;
	int i;

	gets(str);

	len = strlen(str);

	for(i = len-1, conta = 1; i > 0; i--) {
		if(str[i-1] == str[i])
			conta++;
		else {
			printf("%c%d", str[i], conta);
			conta = 1;
		}
	}

	if(len > 0)
		printf("%c%d", str[i], conta);

	printf("\n");

	return 0;
}
