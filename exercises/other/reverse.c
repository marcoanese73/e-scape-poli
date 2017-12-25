#include <stdio.h>

#define BASE 10

int main(int argc, char * argv[])
{
	int num;
	int rev;

	scanf("%d", &num);

	rev = 0;
	while(num > 0) {
		rev = rev * BASE + (num % BASE);
		num = num / BASE;
	}

	printf("%d\n", rev);

	return 0;
}
