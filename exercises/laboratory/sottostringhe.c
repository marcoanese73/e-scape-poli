#include <stdio.h>

#define N 200

int main(int argc, char * argv[])
{
	char s1[N+1], s2[N+1];
	int i, j, flag, conta;

	gets(s1);
	gets(s2);

	conta = 0;

	for(i = 0; s1[i] != '\0'; i++)
	{
		flag = 0;
		for(j = 0; s2[j] != '\0' && s1[i] != '\0' && flag == 0; j++)
		{
			if(s2[j] == s1[i])
				i++;
			else
				flag = 1;
		}
		if((flag == 0) && (s2[j] == '\0')) {
			conta++;
			i--;
		}
	}
	printf("%d\n", conta);
	return 0;
}