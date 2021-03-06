#include <stdio.h>

#define BASE 2
#define POT 10
#define STOP 0

int dec2bin(int, int*);

int main(int argc, char *argv[])
{
	int dec, bin;
	int len;

	scanf("%d", &dec);
	while(dec != STOP) {
		bin = dec2bin(dec, &len);
		printf("%0*d\n", len, bin);
		scanf("%d", &dec);
	}

	return 0;
}

int dec2bin(int dec, int *len)
{
	int bin;
	int shift, neg;
	int digits;

	if(dec >= 0)
		neg = 0;
	else {
		neg = 1;
		dec = - dec;
	}

	bin = 0;
	shift = 1;
	digits = 1;
	while(dec > 0) {
		bin = bin + shift * (dec % BASE);
		dec = dec / BASE;
		shift = shift * POT;
		digits++;
	}

	if(neg)
		bin = bin + shift * 1;

	*len = digits;

	return bin;
}
