#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mymalloc.h"

static char myblock[MEM_SIZE];

/*
process for malloc:
	if block is first to be malloced:
		mem requested > mem available ? err : allocate mem and return pointer to first block after metadata:
	else:
		get first meta data, check m1 size against m2 address and find how much empty space there is.
			if the second block and its metadata fits in the empty space, place it there, update next pointers of previous meta data
			else proceede to next meta data.
			if metadata.next = null compare size of that meta data with address of last block in array.  
			if there is room for requested space, return pointer to block, else err

process for free:
	TBD
*/

//@MATT INCASE YOU DONT REALIZE, I CHANGED THE MEM_SIZE(IN THE HEADER FILE) TO 25000 FOR MEMGRIND

void* mymalloc(size_t size, char* file, int line){
	//on first malloc
	void* ret;
	if (myblock[0]=='\0'){
		meta firstMeta;
		if(size + sizeof(meta) >= MEM_SIZE)
		{
			fprintf(stderr,"ERROR AT %s:%d -- MEM OUT OF BOUNDS\n",file,line);
			return NULL;
		}
		else
		{
			firstMeta.size = size;
		}
		firstMeta.free = '\?';
		firstMeta.next = NULL;
		//store first metadata struct in address of first block in array

		memcpy(&myblock[0],&firstMeta,sizeof(meta));

		//get address of first free block after metadata and return that as void*
		ret = (void*)(&myblock[0] + sizeof(meta));
		return ret;

	}
	else {
		//start with a pointer to first metadata
		meta* ptr = (meta*)&myblock[0];

		long n;
		while(ptr!=NULL){
			//consoladate adjecent free blocks of memory
			if ((ptr->free != '\?')&&ptr->next&&(ptr->next->free != '\?')){
				ptr->size+=ptr->next->size+sizeof(meta);
				ptr->next=ptr->next->next;
			}
			//if block is already free, no need to create new metadata, just update current one and return pointer. 
			if ((ptr->free != '\?')&&(ptr->size>=size)){
				ptr->size=size;
				ptr->free = '\?';
				n = ((long)(ptr) - (long)&myblock[0]) + sizeof(meta);
				return (void*)(&myblock[n]);
				}

			meta* currentMemSpaceEnd = ptr->next != NULL ? ptr->next : (meta*)&myblock[MEM_SIZE];

			n = ((long)(ptr) - (long)&myblock[0]) + ptr->size + sizeof(meta);

			// if block requested fits inbetween currently allocated block and next block, make new metadata and return pointer to allocated block
			if ((void*)(currentMemSpaceEnd)-(void*)(&myblock[n])>=(sizeof(meta)+size)){
				//insert new pointer 
				meta newMeta;
				newMeta.size=size;
				newMeta.free='\?';
				newMeta.next=ptr->next;

				//place metadata in array directly after the allocated block
				memcpy(&myblock[n],&newMeta,sizeof(meta));

				ptr->next=(meta*)&myblock[n];
				
				//return pointer to first empty byte after metadata
				return (void*)(&myblock[n+sizeof(meta)]);
			}
			else {
				if (ptr->next != NULL){
					ptr=ptr->next;
				}
				else {
					fprintf(stderr, "ERROR AT %s:%d -- OUT OF MEMORY, FREE ALLOCATED MEMORY\n",file,line);
					return NULL;
				}
			}
		} 
	}
	return NULL;
}

void myfree(void* mem, char* file, int line){
	//print error if user is attempting to free a block of memory that is outside the bounds of the simulated "memory"
	//unsure if the address of mem will actually be withing the range of 0-5000 or if it will have a legitimate address according to actual memory management

	if(mem == NULL)
	{
		fprintf(stderr, "ERROR AT %s:%d -- POINTER IS NULL\n",file,line);
		return;
	}
	if(mem > (void*)&myblock[MEM_SIZE] || mem < (void*)&myblock[0])

	{
		fprintf(stderr, "ERROR AT %s:%d -- ATTEMPTING TO FREE MEMORY THAT HAS NOT BEEN ALLOCATED BY MALLOC\n",file,line);
		return;
	}

	//make pointer to first byte of metadata corresponding to memory to be freed
	meta* ptr = (meta*)(mem - sizeof(meta));
	
	//print error if already free memory is attempting to be be freed
	if(ptr->free == '\?')
	{
		ptr->free = 1;
	}
	else
	{
		fprintf(stderr, "ERROR AT %s:%d -- ATTEMPTING TO FREE MEMORY THAT IS NOT ALLOCATED\n",file,line);
		return;
	}
	
}

/*
int main(int argc, char **argv)
{
	char* test = (char*)malloc(500);
	printf("%p\n",test);
	char* test2 = (char*)malloc(500);
	printf("%p\n",test2);
	char* test3 = (char*)malloc(500);
	printf("%p\n",test3);
	char* test4 = (char*)malloc(500);
	printf("%p\n",test4);
	free(test3);
	free(test2);
	char* test5 = (char*)malloc(500);
	printf("%p\n",test5);
	char* test6 = (char*)malloc(500);
	printf("%p\n",test6);	

	return 0;
}
*/
