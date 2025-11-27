#include<stdio.h>
#include<stdbool.h>
#define MAX 10

typedef int data;

typedef struct{
    data elem[MAX];
    data top;
}List;

//fifo

void init(List *s){
    s->top =  -1;
}

bool isF(List s){
    return s.top == MAX-1;
}

bool push(List *s, data n){
    if(isF(*s)){
        printf("FULL!");
        return false;
    }


    s->elem[++s->top] = n;
    

}

bool isE(List s){
    return s.top ==-1;
}

bool pop(List *s){
    if(isE(*s)){
        printf("EMPTY!");
        return false;
    }
    s->top--;
    
}

data peek(List s){
    return s.elem[s.top];
}

void display(List s){
    printf("%d\n",s.top);
    while(s.top != -1){
         printf("%d->",peek(s));
         pop(&s);
    }
    
}

void print(List s){
    for(int i =0; i<s.top;i++){
        printf("%d->",s.elem[i]);
    }
}

int main(){
    List s;

    init(&s);

    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);
    push(&s,60);
    pop(&s);
    
    
    printf("Print: ");
    print(s);
    printf("\ndisplay: ");
    display(s);
}

