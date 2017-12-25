#include <stdio.h>

int main(int argc, char * argv[])
{
	int n;
	int i, isp;

	scanf("%d", &n);

	if((n % 2 == 0 && n != 2) || (n == 1))
		isp = 0;
	else {
		isp = 1;
		i = 3;
		while(isp == 1 && i < n/2) {
			if(n % i == 0)
				isp = 0; 
			else
				i = i + 2; 
		}
	}
	printf("%d\n", isp);

	return 0;
}
