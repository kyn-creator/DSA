#include<stdio.h>
#include<stdlib.h>


typedef int elemType;

typedef struct node{
	elemType data;
	struct node *left, *right;
}node,*bst;


void init(node **root){
	*root = NULL;
}


void create(bst *root,elemType q){
	for(;*root != NULL;){
		if((*root)->data == q)return;
		
		if(q< (*root)->data){
			root = &(*root)->left;
		}else{
			root = &(*root)->right;
		}
	}
	
	if(root != NULL){
		bst leaf = malloc(sizeof(node));
		leaf->left = NULL;
		leaf->right = NULL;
		
		leaf->data = q;
		
		*root = leaf;
	}
}


void bfs(node *root){
	node *q[10];
	int fr = 0;
	int rr = 0;
	
	q[rr++] = root;
	
	while(fr < rr){
		node *trav = q[fr++];
		printf("%d ",trav->data);
		
		if(trav->left){
			q[rr++] = trav->left;
		}
		
		if(trav->right){
			q[rr++] = trav->right;
		}
	}
	
}


void del(node **root, int terminate){
	node **trav;
	for(trav = root; *trav != NULL && (*trav)->data != terminate;){
		if(terminate < (*trav)->data){
			trav = &(*trav)->left;
		}else{
			trav = &(*trav)->right;
		}
	}
	
	if(trav != NULL){
		node **trav2;
		node *temp;
		
		if((*trav)->left == NULL){
			temp = *trav;
			*trav = temp->right;
			free(temp);
		}else if((*trav)->right == NULL){
			temp = *trav;
			*trav = temp->left;
			free(temp);
		}else{
			for(trav2 = &(*trav)->right;(*trav2)->left != NULL; trav2 = &(*trav2)->left){}
				temp = *trav2;
				*trav2 = temp->right;
				(*trav)->data = temp->data;
				free(temp);
			
		}
	} 
}


int main(){
	node *ptr;
	init(&ptr);
	
	create(&ptr,100);
	create(&ptr,50);
	create(&ptr,40);
	create(&ptr,60);
	
	create(&ptr,55);
	
	create(&ptr,150);
	create(&ptr,110);
	create(&ptr,200);
	
	bfs(ptr);
	printf("\n");
	del(&ptr,100);
	bfs(ptr);

}
