// Online C compiler to run C program online
#include<stdio.h>
#include "CircleQ.h"

//gcc main.c q.c -o program

int main() {
    List q;
    init(&q);
    for(int i = 1; i < MAX; i++){
        enQ(&q,i);
    }
    printf("Original:");
    disp(q);
    Dq(&q);
    Dq(&q);
    printf("Deq 2: ");
    disp(q);
    enQ(&q,69);
    enQ(&q,69);
    printf("Eq 2: ");
    disp(q);
    enQ(&q,41);

    return 0;
}