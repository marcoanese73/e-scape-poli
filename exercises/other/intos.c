#include <stdio.h>

#define N 6
#define BASE 10

int main(int argc, char * argv[])
{
	int num;
	char s[N+1], temp;
	int i, j;

	scanf("%d", &num);

	i = 0;

	while(num > 0) {
		s[i] = '0' + num % BASE;
		num = num / BASE;
		i++;
	}

	s[i] = '\0';

	for(j = 0, i--; j <= i; j++, i--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}

	printf("%s\n", s);

	return 0;
}