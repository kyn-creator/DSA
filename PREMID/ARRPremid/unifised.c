#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    int data;
} Date;

typedef struct {
    int prodID;
    Date expr;
} Product;

typedef struct {
    Product prods[MAX];
    int front;
    int rear;
} Queue;

typedef Product ProductStk[MAX];

Product createProduct(int id, int ndata) {
    Product p;
    
    p.prodID = id;
    p.expr.data = ndata;
    
    return p;
}
void populateStack(ProductStk s) {
    s[0] = createProduct(3,0);
    s[1] = createProduct(1005,1);
    s[2] = createProduct(1010,2);
    s[3] = createProduct(1020,3);
}
Queue createQueue() {
    Queue q;
    
    q.front = 0;
    q.rear = MAX - 1;
    
    return q;
}

bool isEmpty(Queue q){
    return (q.rear+1)%MAX == q.front;
}

bool InsertSortedByExp(Queue *q, Product n){
    
   if(isEmpty(*q)){
       enqueue(q,n);
       return true;
   }
   
   
   if(q->prods[q->front])
    
    
    //if d1 > d2 deque d1 and move it to d2;
}
bool enqueue(Queue *q, Product n){
    if(isFull(*q)){
        printf("Full!!");
        return false;
    }
    q->rer = (q->rer+1)%MAX;
    q->prods[q->rer] = n;
    
    
}
bool dequeue(Queue *q){
    if(isEmpty(*q)){
        printf("NONE!");
        return false;
    }
    q->front = (q->front+1)%MAX;
    
}

int main(){
    Queue prodQ = createQueue();
    ProductStk prodStk;
    ProductStk temp;
    temp[0].prodID = 1;
    populateStack(prodStk);
    
    
     while(prodStk[0].prodID > 0) {
        temp[temp[0].prodID] = prodStk[prodStk[0].prodID];
        prodStk[0].prodID -= 1;
        temp[0].prodID +=1;
        
    }
    
   
    // insertSortedBasedExp(&prodQ,prodStk[prodStk[0].prodID]);
    
}

// InsertSortedByExp(&prodQ,prodStk[prodStk[0].prodID]);