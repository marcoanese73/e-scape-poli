#include <stdio.h>

#define GAL2LIT 3.78541

int main(int argc, char * argv[])
{
	float prezzo, cambio;
	float eurlit;

	scanf("%f%f", &prezzo, &cambio);

	eurlit = (prezzo * cambio) / GAL2LIT;

	printf("%f\n", eurlit);

	return 0;
}
