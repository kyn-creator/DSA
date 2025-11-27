#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node *left,*right;
}node,*nodeptr;

void init(nodeptr *root){
	*root = NULL;
	
}

void create(nodeptr *root,int ndata){

	
	while(*root != NULL){
		if((*root)->data == ndata){
			return;
		}
		if(ndata < (*root)->data){
			root =  &(*root)->left;
		}else if(ndata> (*root)->data){
			root = &(*root)->right;
		}
	}	
	
		nodeptr nnode = malloc(sizeof(node));
	nnode->left = NULL;
	nnode->right = NULL;
	nnode->data = ndata;
	
	*root = nnode;
}

void preorder(nodeptr root){
	if(root == NULL)return;
	
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(nodeptr root){
	if(root == NULL)return;
	
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void postorder(nodeptr root){
	if(root == NULL)return;
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}


void bfs(nodeptr root){
	nodeptr q[12];
	int front =0;
	int rear = 0;
	
	 q[rear++] = root;
	
	
	while(front < rear){
		
		nodeptr trav = q[front++];
		printf("%d ",trav->data);
		
		if(trav->left){
			q[rear++] = trav->left;
		}
		
		if(trav->right){
			q[rear++] = trav->right;
		}
	}
}

bool ismember(nodeptr root,int t){
	nodeptr trav = root;
	while(trav != NULL && trav->data != t){
		if(t < trav->data){
			trav = trav->left;
		}else{
			trav = trav->right;
		}
	}
	
	if(trav != NULL){
		return((trav->data) == t);
	}
}

int min(nodeptr root){
	nodeptr trav;
	
	for(trav = root; trav->left != NULL; trav = trav->left){}
	
	return trav->data;
}

int max(nodeptr root){
	nodeptr trav;
	
	for(trav = root; trav->right != NULL; trav = trav->right){}
	return trav->data;
}

void del(nodeptr *root, int T){
	nodeptr *trav, *trav1;
	nodeptr temp;
	
	
	//for traversing
	for(trav = root; *trav != NULL && (*trav)->data != T;){
		if(T < (*trav)->data){
			trav = &(*trav)->left;
		}else{
			trav = &(*trav)->right;
		}
	}
	
	
	//if null meaning no 'T' found else ....
	if(*trav != NULL){
		//no left child
		if((*trav)->left == NULL){
			temp = *trav;
			*trav = temp->right;
			free(temp);
		}	//no right child
		else if((*trav)->right == NULL){
			temp = *trav;
			*trav = temp->left;
			free(temp);
		}
		
	
		
		//has both left and right child
		else{
			//to get the smallest value in the right subtree
			for(trav1 = &(*trav)->right; (*trav1)->left != NULL; trav1 = &(*trav1)->left){}
			temp = *trav1;//holding the smallest value, meaning there are no left nodes connecting
			*trav1 = temp->right;// we do not know if it has a right child so we assume to be safe
			(*trav)->data = temp->data;// we copy the data of our deleted node/
			free(temp);//free
		}
		temp = NULL;
	}
}


int main(){
	nodeptr root;
	init(&root);
	
	create(&root,100);
	create(&root,20);
	create(&root,10);
	create(&root,30);
	create(&root,200);
	create(&root,150);
	create(&root,300);


	printf("InOrder: ");inorder(root);printf("\n");
	printf("PreOrder: ");preorder(root);printf("\n");
	printf("PostOrder: ");postorder(root);printf("\n");
	printf("BFS: ");bfs(root);printf("\n");
	int T = 50;
	del(&root,100);
	printf("BFS after deleting: ");bfs(root);printf("\n");
	
	if(ismember(root,T)){
		printf("Found %d\n",T);
	}else{
		printf("Notfound\n");
	}
	
	printf("The lowest value inside the BST is %d\n",min(root));
	printf("The greatest value inside the BST is %d\n",max(root));
}


