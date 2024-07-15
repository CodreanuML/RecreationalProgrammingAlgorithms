//tsodin min 34

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//#define debug 1

#define CAPACITY 640000
#define HEAP_ALLOCED_CAP 1024
#define HEAP_FREED_CAP 1024


typedef struct {
	void * start;
	size_t size;
} Heap_Chunk;


#ifdef CAPACITY 
	char heap[CAPACITY]={};
#else 
	
	char heap[10000]={};
#endif

size_t heap_size = 0 ;

Heap_Chunk heap_alloced_chunks[HEAP_ALLOCED_CAP]={};
size_t heap_alloced_size=0;

Heap_Chunk heap_freed[HEAP_FREED_CAP]={};
size_t heap_freed_size=0;

void *heap_alloc(size_t size)
{
	if (size>0){
	assert (heap_size+size<=CAPACITY);
	void * result = heap +heap_size ;
	heap_size+=size;

	const Heap_Chunk chunk={
		.start=result , .size=size
	};
	assert(heap_alloced_size<=HEAP_ALLOCED_CAP);
	heap_alloced_chunks[heap_alloced_size++]=chunk;
	return result ;
	}
	else{
		return NULL ;
	}

}

void heap_dump_alloced_chunks(void){
	printf("Allocated Chunks (%zu):\n" , heap_alloced_size);
	for(size_t i=0;i<heap_alloced_size;++i){
		printf("start: %p , size: %zu\n", heap_alloced_chunks[i].start,heap_alloced_chunks[i].size);

	}


}

void heap_free(void * ptr){
	for (size_t i=0 ;i<heap_allocated_size;++i){
		if (heap_alloced_chunks[i].start==ptr) {

		}
	}

}

void heap_collect(){
	assert(false && "TODO : heap_collect is not implemented");
}

int main(){


	printf("%d",sizeof(heap));
	
	for (int i=0;i<100;++i){
		heap_alloc(i);
	}

	heap_dump_alloced_chunks();


#ifdef debug 
	for (int i=0;i<26;i++){
		printf("%d\n",root);
		printf("%c\n",*root);
		root++;
	}
#endif
	return 0;
}
