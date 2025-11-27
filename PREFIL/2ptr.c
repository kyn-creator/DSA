#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
}Node,*NodePTR;

void initN(NodePTR t){
	printf("out");
	t->data = -1;
	printf("out");
}

void learning(NodePTR *t,int x){
	printf("in");
	if(*t == NULL){
		*t = malloc(sizeof(Node));
	}
	
	
	
	
	initN(*t);
	
	
}


int main(){
	int x = 769;
	int *y = &x;
	
	
	NodePTR root = NULL;
	learning(&root,10);
	
	
//	int **z = &y;
//	**z = 1000;
//	
//	printf("Z ptr: %d\n",*z);
//	printf("==============\n");
//	printf("Value of y: %d\n",y);
//	printf("Address of y: %d\n",&y);
//	printf("==============\n");
//	*y = 10;
//	printf("Address of x: %d\n",&x);
//	printf("Data of X: %d\n",x);
	
	
	
	
}
