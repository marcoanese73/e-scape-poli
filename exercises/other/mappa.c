#include <stdio.h>

#define N 100
#define BOR 0.05

int main(int argc, char * argv[])
{
	float botx, boty, topx, topy;
	float px, py;
	float w, h;
	int i;

	scanf("%f", &px);
	scanf("%f", &py);

	botx = px;
	topx = px;
	boty = py;
	topy = py;
	i = 1;

	scanf("%f", &px);

	while(px >= 0 && i < N) {
		scanf("%f", &py);
		if(px < botx)
			botx = px;
		else if(px > topx)
			topx = px;
		if(py < boty)
			boty = py;
		else if(py > topy)
			topy = py;
		i++;
		scanf("%f", &px);
	}

	w = topx - botx;
	h = topy - boty;
	botx = botx - w * BOR;
	topx = topx + w * BOR;
	boty = boty - h * BOR;
	topy = topy + h * BOR;
	
	printf("%f %f\n%f %f\n", botx, boty, topx, topy);

	return 0;
}
