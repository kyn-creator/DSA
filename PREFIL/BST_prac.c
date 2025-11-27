#include<stdio.h>
#include<stdlib.h>

typedef int elemType;


typedef struct node{
	elemType elem;
	struct node *left,*right;
}nodeType, *bst;

void init(bst *root){
	*root= NULL;
}

void create(nodeType **root, elemType n){
	
	//you check if there are duplicates and if there are none contine to make
	for(;*root != NULL;){
		if((*root)->elem == n)return;
		
		if(n < (*root)->elem){
			root = &(*root)->left;
		}else{
			root = &(*root)->right;
		}
	}
	
	nodeType *leaf = malloc(sizeof(nodeType));
	leaf->elem = n;
	leaf->right = NULL;
	leaf->left = NULL;
	
	*root = leaf;
	
	
}


void bfs(nodeType *root){
	nodeType *q[12];
	int front =0;
	int rear = 0;
	
	q[rear++] = root;
	
	while(front < rear){
		nodeType *trav = q[front++];
		printf("%d ",trav->elem);
		
		if(trav->left){
			q[rear++] = trav->left;
		}
		
		if(trav->right){
			q[rear++] = trav->right;
		}
	}
	
}

void delMe(nodeType **root, elemType target, elemType code){
	nodeType **trav;
	nodeType *temp;
	for(trav = root; *trav != NULL && (*trav)->elem != target;){
		if(target < (*trav)->elem){
			trav = &(*trav)->left;
		}else{
			trav = &(*trav)->right;
		}
	}
	
	if(trav != NULL){
		if((*trav)->left == NULL){
			temp = *trav;
			*trav = temp->right;
			free(temp);
		}else if((*trav)->right == NULL){
			temp  = *trav;
			*trav = temp->left;
			free(temp);
		}else{
	
		nodeType **trav1;
		if(code > 1)return;
		
		if(code == 0){//successor
			for(trav1 = &(*trav)->right; (*trav1)->left != NULL; trav1 = &(*trav1)->left){}
			temp = *trav1;
			*trav1 = temp->right;
		}else if(code == 1){//predecessor
			for(trav1 = &(*trav)->left; (*trav1)->right != NULL; trav1 = &(*trav1)->right){}
			temp = *trav1;
			*trav1 = temp->left;
		}
		
		(*trav)->elem = temp->elem;
		free(temp);
		}
		
		
	}
	
}



int main(){
	nodeType *root;
	init(&root);
	
	create(&root,100);
	create(&root,20);
	create(&root,10);
	create(&root,30);
	create(&root,200);
	create(&root,150);
	create(&root,300);
	
	bfs(root);
	delMe(&root,300,0);
	printf("\n");
	bfs(root);
}



