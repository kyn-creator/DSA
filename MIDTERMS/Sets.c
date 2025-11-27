// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct set{
    int *arr;
    int length;
}set;

// Function	Goal
// MakeNull	Create an empty set
// Member	Check if element exists
// Insert	Add element if not present
// Delete	Remove element if present
// Union	Combine two sets (unique)
// Intersection	Common elements only
// Difference Elements in A not in B
// Subset	Check if A is contained in B

// Cardinality	Count number of elements
// PrintSet	Display all elements

set MakeNULL(){
   set temp;
   temp.arr = malloc(sizeof(int) *1);
   temp.length =0;
   return temp;
   
}
bool member(set a, int m){
 
    for(int i =0; i<a.length;i++){
        if(m == a.arr[i]){
            return true;
        }
    }
   
    return false;
    
}
void Insert(set *a,int n){

    if(member(*a,n) == false){
        a->arr = realloc(a->arr,sizeof(int) *(a->length+1));
        a->arr[a->length] = n;
        a->length +=1;
        }
    
}
void Del(set *a, int t){
   int tempsize =0;
   for(int i=0; i<a->length; i++){
       if(a->arr[i] != t){
           a->arr[tempsize++] = a->arr[i];
       }
   }
   
   a->length = tempsize;
   a->arr = realloc(a->arr,sizeof(int) *tempsize);
    
}
set Union(set a, set b){
    set temp = MakeNULL();
    
    for(int i =0; i<a.length; i++){
        Insert(&temp,a.arr[i]);
    }
    
    for(int i =0; i<b.length; i++){
        Insert(&temp,b.arr[i]);
    }
    return temp;
}
set Intersection(set a, set b){

    set temp = MakeNULL();
    for(int i= 0; i<a.length;i++){
        for(int j=0; j<b.length;j++){
            if(a.arr[i] == b.arr[j]){
                Insert(&temp,a.arr[i]);
            }
        }
    }
    return temp;
}
set Difference(set a,set b){
    set temp = MakeNULL();
    
    for(int i =0; i<a.length; i++){
        int flag = -1;
        
        for(int j=0; j<b.length;j++){
            if(a.arr[i] == b.arr[j]){
                flag = 99;
            }
        }
        if(flag == -1){
            Insert(&temp,a.arr[i]);
        }
    }
    return temp;
}
bool Subset(set a, set b){
    for(int i = 0; i<a.length; i++){
        int flag = -1;
        for(int j =0; j<b.length; j++){
            if(a.arr[i] == b.arr[j]){
                flag = 0;
            }
        }
        if(flag == -1){
            return false;
        }
    }
    
    return true;
}
int Cardinality(set a){
    return a.length;
}

void print(set a){
    printf("[");
    for(int i =0; i<a.length;i++){
        if(i+1 == a.length){
            printf("%d",a.arr[i]);
        }else{
              printf("%d,",a.arr[i]);
        }
    }
    printf("]");
}

int main() {
    set a = MakeNULL();
    set b = MakeNULL();
    
    Insert(&a,1);
    Insert(&a,2);
    //Insert(&a,3);
    Insert(&a,4);
    Insert(&a,4);
    Insert(&a,8);
    Del(&a,4);
    
    Insert(&b,4);
    Insert(&b,5);
    Insert(&b,6);
    Insert(&b,7);
    Insert(&b,8);
   
    printf("Set A:");
    print(a);
    printf("\n");
    printf("Set B:");
    print(b);
    
    set U = Union(a,b);
    printf("\n");
    printf("Set Union:");
    print(U);
    
    set I = Intersection(a,b);
    printf("\n");
    printf("Set Intersection:");
    print(I);
    
    set D = Difference(a,b);
    printf("\n");
    printf("Set Difference:");
    print(D);
    
    printf("\n");
    if(Subset(a,b)){
        printf("A is a subset of B");
    }else{
        printf("A is not a subset of B");
    }
    
    int bs = Cardinality(b);
    int as = Cardinality(a);
    printf("\n");
    printf("set A has the cardinality of %d",as);
    printf(" while set B has the cardinality of %d",bs);
    
    
    return 0;
}