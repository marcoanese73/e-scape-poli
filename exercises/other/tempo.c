#include <stdio.h>

#define MININHR 60
#define SECINMIN 60

int main(int argc, char * argv[])
{
	int time;
	int hr, min, sec;

	scanf("%d", &time);

	hr = time / (MININHR * SECINMIN);
	time = time % (MININHR * SECINMIN);
	min = time / SECINMIN;
	sec = time % SECINMIN;

	printf("%d %d %d\n", hr, min, sec);

	return 0;
}
