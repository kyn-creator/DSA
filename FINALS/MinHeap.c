#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef struct {
	int elems[MAX];
	int count;
}BinaryHeap;


void insert(BinaryHeap *heap, int num);
void Delete(BinaryHeap *heap);
void Display(BinaryHeap heap);



int main(){
	
	BinaryHeap minHeap;
	minHeap.count = 0;
	
	insert(&minHeap,10);
	insert(&minHeap,18);
	insert(&minHeap,14);
	insert(&minHeap,3);
	insert(&minHeap,12);
	insert(&minHeap,6);
	insert(&minHeap,8);
	
	printf("Before delete: ");	Display(minHeap); printf("\n");

	Delete(&minHeap);
	
	Display(minHeap);
	insert(&minHeap,6);
	Display(minHeap);
	
	
}



void insert(BinaryHeap *heap,int num){
	int indx =0;
	indx = heap->count;
	int parent = (indx-1)/2;
	
	while(indx > 0 && num < heap->elems[parent]){
		heap->elems[indx] = heap->elems[parent];
		indx = parent;
		parent = (indx-1)/2;  
	}
	
	heap->elems[indx] = num;
	heap->count++;
}

void Delete(BinaryHeap *heap){
	heap->elems[0] = heap->elems[heap->count-1];
	heap->count--;
	
	int parent =0;
	
	while(true){
		int indx = parent;
		int left = (2*parent)+1;
		int right = (2*parent)+2;
		
		if(left > heap->count && heap->elems[left] < heap->elems[indx] ){
			indx = left;
		}
		
		if(right > heap->count && heap->elems[right] < heap->elems[indx]){
			indx = right;
		}
		if(parent == indx)return;
		
		int temp = heap->elems[indx];
		heap->elems[indx] = heap->elems[parent];
		heap->elems[parent] = temp;
		parent = indx;
	}
}


void Display(BinaryHeap heap){
	int  i;
	for(i=0 ;i<heap.count;i++){
		printf("%d ",heap.elems[i]);
	}
	printf("\n");
}
