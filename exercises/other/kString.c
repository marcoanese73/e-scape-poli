#include <stdio.h>

#define L 100

int kString(char[]);

int main(int argc, char *argv[])
{
	char str[L+1];
	int k;

	scanf("%s", str);
	k = kString(str);
	printf("%d\n", k);

	return 0;
}

int kString(char str[])
{
	int i, k, k_max;

	k = 0;
	k_max = 0;
	for(i = 0; str[i+1] != '\0'; i++) {
		if(str[i+1] < str[i]) {
			k = 2;
			i++;
			while(str[i+1] != '\0' && str[i+1] < str[i]) {
				k++;
				i++;
			}
		}
		if(k > k_max)
			k_max = k;
	}

	return k_max;
}