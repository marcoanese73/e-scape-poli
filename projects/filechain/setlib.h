#include <time.h>

void printDate(FILE *fp)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	fprintf(fp, "%0*d-%0*d-%d ", 2, tm.tm_mday, 2, tm.tm_mon + 1, tm.tm_year + 1900);
	fprintf(fp, "%0*d:%0*d:%0*d", 2, tm.tm_hour, 2, tm.tm_min, 2, tm.tm_sec);

	return;
}
