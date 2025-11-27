#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

typedef struct node{
    int data;
    struct node *link;
}*SETS;

typedef SETS Dictionary[MAX];

void init(Dictionary s);
bool isMember(Dictionary s, int n);
int hashbrown(int n);
void insertU(Dictionary s, int n);
void DelM(Dictionary s, int n);

void display(Dictionary d);



void init(Dictionary s){
    for(int i =0; i<MAX; i ++){
        s[i] = NULL;
    }
}

int hashbrown(int n){
   int sum =0;
   while(n != 0){
       sum +=(n%10);
       n /=10;
   }
   return sum%MAX;
}

bool isMember(Dictionary s, int n){
    int key = hashbrown(n);
    SETS trav;
    
    for(trav = s[key]; trav  != NULL && trav->data != n; trav = trav->link){}
    
    return(trav != NULL);
}

void insertU(Dictionary s, int n){
    int key = hashbrown(n);
    SETS *trav, temp;
    
    for(trav = &s[key];*trav != NULL && (*trav)->data < n; trav = &(*trav)->link){}
    
    if(*trav != NULL && (*trav)->data == n){
        printf("Existed!");

    }else{
         temp =malloc(sizeof(struct node));
        temp->data = n;
        temp->link = *trav;
        *trav = temp;
        
       
    }
    
}

void DelM(Dictionary s, int a){
    int key = hashbrown(a);
    SETS *trav, temp;
    
    for(trav = &s[key]; *trav != NULL && (*trav)->data != a; trav = &(*trav)->link){}
    
    if(*trav != NULL){
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }else{
        printf("Number : [%d] = Not found!\n",a);
    }
}

void disp(Dictionary s){
    for(int i =0; i<MAX; i++){
        printf("[%d] ", i);
        if(s[i] == NULL){
            printf("Empty!\n");
        }else{
            SETS ptr;
            for(ptr = s[i]; ptr != NULL; ptr = ptr->link){
                printf("%d,",ptr->data);
            }
            printf("\n");
        }
    }
}

int main() {
    Dictionary a;
    init(a);
    
    insertU(a,1);
    insertU(a,2);
    insertU(a,3);
    insertU(a,4);
    insertU(a,22);
    insertU(a,33);
    insertU(a,1203);
    insertU(a,231);
    insertU(a,32);
    insertU(a,441);
    DelM(a,331);
    DelM(a,441);
    disp(a);

    return 0;
}