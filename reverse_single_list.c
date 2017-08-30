#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nord {
	int data;
	struct nord * next;
}NODE;

NODE * create_single_list(int * array, int length)
{
	//NODE head = {0, NULL};
	NODE * head = (NODE *)malloc(sizeof(NODE));
	head->next = NULL;
	NODE * p = NULL;
	int i = 0;
	p = head;
	for(i=0; i<length;i++ ){
		NODE * element = (NODE *)malloc(sizeof(NODE));
		element->data =*(array+i);
		p->next = element;	
		p = p->next;
	}
	p->next = NULL;
	return head;
}
NODE * revert_single_list_new(NODE * head)
{
	NODE *temp = head;
	NODE *pre  = NULL;
	NODE * next = NULL;
	while(temp->next != NULL)
	{
		next = temp->next;
		temp->next = pre;	
		pre = temp;
		temp = next;
	}
	temp->next = pre;
	head = temp;
	return head;
}

NODE * revert_single_list(NODE * head)
{
	NODE * p = NULL;
	NODE * q = NULL;
	NODE * z = NULL;
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



void print_list(NODE * head)
{
	int i = 0;
	NODE * p = head;
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
	NODE * list = create_single_list(array, len = sizeof(array)/sizeof(int)); 
	printf("len=%d\n", len);
	print_list (list);
	printf("\n");

	//list = revert_single_list(list);
	list = revert_single_list_new(list);
	print_list (list);
	printf("\n");
	return 0;
}
