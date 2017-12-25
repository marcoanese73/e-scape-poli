#include <stdio.h>

#define BASE 10

int primality(int);

int main(int argc, char *argv[])
{
	int val;
	int trun_dx;

	do
		scanf("%d", &val);
	while(val <= 0);

	trun_dx = 1;
	while(trun_dx && val > 0) {
		if(!primality(val))
			trun_dx = 0;
		val = val / BASE;
	}

	printf("%d\n", trun_dx);

	return 0;
}

int primality(int num)
{
	int i, isp;

	if((num % 2 == 0 && num != 2) || (num == 1))
		isp = 0;
	else {
		isp = 1;
		i = 3;
		while(isp == 1 && i < num/2) {
			if(num % i == 0)
				isp = 0; 
			else
				i = i + 2; 
		}
	}

	return isp;
}