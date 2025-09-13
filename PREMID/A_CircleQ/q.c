#include "CircleQ.h"

#include<stdio.h>
#include<stdlib.h>
void init(List *q){
    q->front =0;
    q->rer = 0;
}

bool isF(List q){
    return (q.rer+1)%MAX == q.front;
}

bool enQ(List *q,data n){
    
    if(isF(*q)){
        printf("Full");
        return false;
    }
     
    q->elem[q->rer] = n;
    q->rer = (q->rer+1)%MAX;
}

void disp(List q){
    for(int i = q.front; i != q.rer; i = (i+1)%MAX){
        printf("%d=>",q.elem[i]);
    }
    printf("END\n");
}

bool isE(List q){
    return q.rer == q.front;
}

bool Dq(List *q){
    if(isE(*q)){
        printf("EmptyList");
        return false;
    }    
    q->front = (q->front+1)%MAX;
    
}
