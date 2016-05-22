#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nord {
	int data;
	struct nord * next;
}NORD;

NORD * create_single_list(int * array, int length)
{
	//NORD head = {0, NULL};
	NORD * head = (NORD *)malloc(sizeof(NORD));
	head->next = NULL;
	NORD * p = NULL;
	int i = 0;
	p = head;
	for(i=0; i<length;i++ ){
		NORD * element = (NORD *)malloc(sizeof(NORD));
		element->data =*(array+i);
		p->next = element;	
		p = p->next;
	}
	p->next = NULL;
	return head;
}
NORD * revert_single_list(NORD * head)
{
	NORD * p = NULL;
	NORD * q = NULL;
	NORD * z = NULL;
	p = head->next;
	q = p->next;
	p->next = NULL;
	while(q->next != NULL){
	z = q->next;
	q->next = p;
	p = q;
	q = z;
	}
	q->next = p;
	head->next = q;
	return head;
}
void print_list(NORD * head)
{
	int i = 0;
	NORD * p = head;
	while(p != NULL) {
		printf("->%d", p->data);
		p = p->next;
	}
	return;
}
int main(int argc, char ** argv)
{
	int array[6] = {2, 3, 4, 6, 89, 10};
	int len = 0;
	NORD * list = create_single_list(array, len = sizeof(array)/sizeof(int)); 
	printf("len=%d\n", len);
	print_list (list);
	printf("\n");

	list = revert_single_list(list);
	print_list (list);
	printf("\n");
	return;
}
