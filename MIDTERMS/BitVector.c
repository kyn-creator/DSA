//Bit Vector == intersect.union,difference,find,add,delete
//uses MAX

#include<stdio.h>
#include<stdbool.h>

#define MAX 10

typedef int set[MAX];

void init(set s){
    for(int i =0; i <MAX; i++){
        s[i] = 0;
    }
}

bool mem(set s, int data){
    for(int i=0; i <MAX;i++){
        if(s[i]==data){
            return true;
        }
    }
    return false;
}

void disp(set s){
    for(int i =0; i<MAX;i++){
        if(s[i] == 1){
            printf("%d=>",i);
        }
    }
    printf("END!");
}
void add(set s, int elem){
    if(mem(s,elem)){
        printf("existed!");
    }else{
        s[elem] = 1;
    }
}

void del(set s, int elem){
    if(mem(s,elem)){
        s[elem] = 0;
    }else{
        printf("DNE!");
    }
}

void onion(set a, set b, set c){
    for(int i=0; i<MAX; i++){
        c[i] = (a[i] || b[i]);
    }
}


void sex(set a, set b, set c){
    for(int i=0; i<MAX; i++){
        c[i] = (a[i] && b[i]);
    }
}

void diff(set a, set b, set c){
    for(int i=0; i<MAX; i++){
        c[i] = (a[i] && (!b[i]));
    }
}


int main(){
    set a;
    init(a);
    add(a,1);
    add(a,4);
    add(a,2);
    add(a,9);
    printf("SET A: ");disp(a); printf("\n");
    
    set b;
    init(b);
    add(b,5);
    add(b,3);
    add(b,2);
    add(b,9);
    
    printf("SET B: ");disp(b); printf("\n");
    
    set c;
    init(c);
    onion(a,b,c);
    printf("Union: ");disp(c); printf("\n");

    sex(a,b,c);
    printf("Intersection: ");disp(c); printf("\n");
    
    diff(a,b,c);
    printf("Difference: ");disp(c); printf("\n");
    
    
}



 