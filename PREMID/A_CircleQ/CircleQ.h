#ifndef CirleQ
#define CircleQ


#include<stdbool.h>
#define MAX 10

typedef int data;

typedef struct{
    data elem[MAX];
    data front;
    data rer;
}List;



void init(List *q);
bool isF(List q);
bool enQ(List *q,data n);
void disp(List q);
bool isE(List q);
bool Dq(List *q);

#endif
