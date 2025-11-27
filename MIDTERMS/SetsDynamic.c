#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *arr;
    int length;
}sets;


void init(sets *a){
    a->arr=NULL;
    a->length =0;
}

bool mem(sets a, int t){
    for(int i =0; i<a.length; i++){
        if(a.arr[i] == t){
            return true;
        }
    }
    
    return false;
}

void add(sets *a,int elem){
    if(mem(*a,elem)){
        return;
    }
    a->arr = realloc(a->arr, sizeof(a->length+1) * sizeof(int));
    a->arr[a->length] = elem;
    a->length++;
    
}
void del(sets *b, int de){
    int q =1;
    for(int i =0; i<b->length; i++){
        if(b->arr[i] == de){
            q = 0;
            for(int j =i; j<b->length-1;j++){
                b->arr[j] = b->arr[j+1];
            }
            
        }
    }
    b->arr = realloc(b->arr,sizeof(b->length-1) * sizeof(int));
    b->length--;
    if(q==1){
        return;
    }
}

void disp(sets c){
     printf("{");
    for(int i =0; i<c.length; i++){
        if(i+1 == c.length){
            printf("%d",c.arr[i]);
        }else{
             printf("%d,",c.arr[i]);
        }
       
        
    }
    printf("}");
}

sets onion(sets a, sets b){
    sets c;
    init(&c);
    for(int i =0; i <a.length; i++){
        add(&c,a.arr[i]);
    }
    
    for(int i =0; i <b.length; i++){
        add(&c,b.arr[i]);
    }
    return c;
}

sets intersection(sets a, sets b){
    sets c;
    init(&c);
    for(int i =0; i <a.length; i++){
        for(int j =0; j<b.length; j++){
            if(a.arr[i] == b.arr[j]){
                add(&c,a.arr[i]);
            }
        }
    }

   
    return c;
}


sets difference(sets a, sets b){
    sets c;
    init(&c);
    
    for(int i =0; i <a.length; i++){
      if(!mem(b,a.arr[i])){
          add(&c,a.arr[i]);
      }
       
    }

   
    return c;
}


int main(){
    sets a;
    init(&a);
    add(&a,10);
    add(&a,20);
    add(&a,30);
    add(&a,9);
    printf("SET A: ");disp(a);printf("\n");
    
    sets b;
    init(&b);
    add(&b,9);
    add(&b,7);
    add(&b,5);
    add(&b,20);
    printf("SET B: ");disp(b);printf("\n");
    
    printf("Union: "); disp(onion(a,b)); printf("\n");
    printf("Intersection: "); disp(intersection(a,b)); printf("\n");
    
    printf("Difference: "); disp(difference(a,b)); printf("\n");
    
}


