//Computer word == intersect.union,difference,find,add,delete

#include<stdio.h>
#include<stdbool.h>

void init(unsigned char *s){
    *s = 0;
}


void add(unsigned char *s, int elem){
    int size = sizeof(unsigned char) * 8;
    
    if(elem >=0 && elem <size){
        *s |= (1<<elem);
    }else{
        printf("Invalid!");
    }
    
   
}

void del(unsigned char *s, int de){
    int size = sizeof(unsigned char) * 8;
    
    if(de >=0 && de<size){
        *s &= ~(1<<de);
    }
}

bool find(unsigned char s,int q){
    int size = sizeof(unsigned char) * 8;
    
    if(q >= 0 && q<size){
        return(s & (1<<q)) !=0;
    }else{
        printf("invalid!");
    }
   
    return false;
}

void display(unsigned char s){
    int size = sizeof(unsigned char) * 8;
    
    for(int i =0; i<size;i++){
        if((s &(1<<i)) !=0){
            printf("%d,",i);
        }
    }
}

unsigned char onion(unsigned char a, unsigned char b){
    return (a|b);
}

unsigned char intersection(unsigned char a, unsigned char b){
    return (a&b);
}

unsigned char difference(unsigned char a, unsigned char b){
    return (a& (~b));
}

int main(){
    unsigned char s,b,c;
    init(&s);
    add(&s,2);
    add(&s,3);
    add(&s,7);
    add(&s,1);
    
    init(&b);
    add(&b,4);
    add(&b,3);
    add(&b,6);
    add(&b,1);
    
    init(&c);
    
    
    
    // if(find(s,1)){
    //     printf("found!");
    // }else{
    //     printf("not found!");
    // };
    
    
    printf("A: ");
    display(s);
    printf("\n");
    printf("B: ");
    display(b);
    printf("\n");
    
    printf("Union: ");
    c= onion(s,b);
    display(c);
    printf("\n");
    
    printf("Intersection: ");
    c= intersection(s,b);
    display(c);
    printf("\n");
    
    printf("Difference: ");
    c= difference(s,b);
    display(c);
    printf("\n");
}