#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct _p {
       int x, y;
       struct _p *next;
} punto_t;

int scorciatoia(punto_t*, punto_t*);
punto_t* fill(punto_t*, int);
punto_t* append(punto_t*, int, int);
punto_t* freeList(punto_t*);

int main(int argc, char *argv[])
{
	punto_t *head_1 = NULL, *head_2 = NULL;
	int np;
	
	scanf("%d", &np);
	head_1 = fill(head_1, np);
	scanf("%d", &np);
	head_2 = fill(head_2, np);
	printf("%d\n", scorciatoia(head_1, head_2));
	freeList(head_1);
	freeList(head_2);

	return 0;
}

int scorciatoia(punto_t *h_1, punto_t *h_2)
{
	punto_t *temp_1, *temp_2;
	float dist, sum_1, sum_2;

	if(h_1 -> x == h_2 -> y && h_1 -> y == h_2 -> y) {
		for(temp_1 = h_1, sum_1 = 0.0; temp_1 -> next != NULL; temp_1 = temp_1 -> next) {
			dist = sqrt(pow((temp_1->x-temp_1->y), 2) + pow((temp_1->next->x-temp_1->next->y), 2));
			sum_1 += dist;
		}
		for(temp_2 = h_2, sum_2 = 0.0; temp_2 -> next != NULL; temp_2 = temp_2 -> next) {
			dist = sqrt(pow((temp_2->x-temp_2->y), 2) + pow((temp_2->next->x-temp_2->next->y), 2));
			sum_2 += dist;
		}
		if(temp_1 -> x == temp_2 -> x && temp_1 -> y == temp_2 -> y && sum_1 < sum_2)
			return 1;
	}

	return 0;
}

punto_t* fill(punto_t *head, int np)
{
	int value_1, value_2;

	while(np > 0) {
		scanf("%d%d", &value_1, &value_2);
		head = append(head, value_1, value_2);
		np--;
	}

	return head;
}

punto_t* append(punto_t *head, int value_1, int value_2)
{
	punto_t *nuovo, *p;

	if(nuovo = (punto_t*)malloc(sizeof(punto_t))) {
		nuovo -> x = value_1;
		nuovo -> y = value_2;
		nuovo -> next = NULL;
		if(head) {
			for(p = head; p -> next != NULL; p = p -> next)
				;
			p -> next = nuovo;
		} else
			head = nuovo;
	} else
		printf("Errore append: %d %d\n", value_1, value_2);
	
	return head;
}

punto_t* freeList(punto_t *head)
{
	punto_t *tbd;

	while(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}