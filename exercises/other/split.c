#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 160
#define L 1000

typedef struct _data {
	char s[MAX_DIM+1];
	struct _data *next;
} data_t;

data_t* splitstring(char[]);
data_t* ins_coda(data_t*, char[]);
void printList(data_t*);
data_t* freeList(data_t*);

int main(int argc, char *argv[])
{
	char str[L+1];
	data_t *head = NULL;

	gets(str);

	head = splitstring(str);
	printList(head);
	freeList(head);

	return 0;
}

data_t* splitstring(char stringa[])
{
	data_t *head = NULL;
	int i, j;
	char temp_stringa[MAX_DIM+1];

	for(i = 0, j = 0; stringa[i] != '\0'; i++) {
		temp_stringa[j] = stringa[i];
		j++;
		if(j >= MAX_DIM) {
			temp_stringa[j] = '\0';
			j = 0;
			head = ins_coda(head, temp_stringa);
		 }
	}
	temp_stringa[j] = '\0';
	head = ins_coda(head, temp_stringa);

	return head;
}

data_t* ins_coda(data_t *head, char stringa[])
{
	data_t *nuovo_elem = NULL;
	data_t *temp;
	int i;

	if(nuovo_elem = (data_t*)malloc(sizeof(data_t))) {
		for(i = 0; stringa[i] != '\0'; i++)
			nuovo_elem -> s[i] = stringa[i];
		nuovo_elem -> s[i] = '\0';
		nuovo_elem -> next = NULL;
		if(head == NULL)
			head = nuovo_elem;
		else {
			for(temp = head; temp -> next != NULL; temp = temp -> next)
				;
			temp -> next = nuovo_elem;
		}
	} else
		printf("Errore malloc %s\n", stringa);

	return head;
}

void printList(data_t *head)
{
	data_t *p;

	for(p = head; p != NULL; p = p -> next)
		printf("\n%s\n", p -> s);
	printf("\n");

	return;
}

data_t* freeList(data_t *head)
{
	data_t *tbd;

	while(head) {
		tbd = head;
		head = head -> next;
		free(tbd);
	}

	return head;
}
