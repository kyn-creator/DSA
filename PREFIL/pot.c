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
	
	insert(&minHeap,3);
	insert(&minHeap,4);
	insert(&minHeap,5);
	insert(&minHeap,2);
	insert(&minHeap,1);
	
	Display(minHeap);
	Delete(&minHeap);
	
	Display(minHeap);
	insert(&minHeap,6);
	Display(minHeap);
	
	
}

void insert(BinaryHeap *heap,int num){
	
	int idx = heap->count;
	int parent = (idx-1)/2;
	while(idx > 0 && num < heap->elems[parent]){
		heap->elems[idx] = heap->elems[parent];
		idx = parent;
		parent = (idx-1)/2;
		
	}
	heap->elems[idx] = num;
	heap->count++;
}

void Delete(BinaryHeap *heap){
	
	heap->elems[0] = heap->elems[heap->count-1];
	heap->count--;
	int parent=0;
	while(true){
		int idx=parent, left = 2*parent+1,right =2*parent+2;
		
		if(left < heap->count && heap->elems[left] < heap->elems[idx]){
			idx = left;
		}
		
		if(right < heap->count&&heap->elems[right]<heap->elems[idx]){
			idx = right;
		}
		
		if(idx == parent){
			break;
		}
		
		int temp = heap->elems[idx];
		heap->elems[idx] = heap->elems[parent];
		heap->elems[parent] = temp;
		
		parent = idx;
	}
}

void Display(BinaryHeap heap){
	int  i;
	for(i=0 ;i<heap.count;i++){
		printf("%d",heap.elems[i]);
	}
	printf("\n");
}
