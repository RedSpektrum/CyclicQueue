/*
 * CQueue.c
 *
 *  Created on: Apr 1, 2025
 *      Author: atcsol
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 6 		// Default size for the initialization

struct CQueue_t{

    int Elements[MAX_SIZE];			// An initial array of elements
    int Head;						// First element index of the queue
    int ElementNum;					// Actual size of the queue

};

// Singleton
static struct CQueue_t CQueue;

/**	Cyclic Queue initialization **/
void queue_init(struct CQueue_t *queue){


	CQueue.Head 		= 0;
	CQueue.ElementNum	= 0;
	queue = &CQueue;

}

/** Cyclic Queue is full **/
int queue_is_full(struct CQueue_t *queue){

	int is_full = 0;

	if(queue){
		is_full = (CQueue.ElementNum == MAX_SIZE);
	}

	return is_full;
}

/** Cyclic Queue is empty **/
int queue_is_empty(struct CQueue_t *queue){

	int is_empty = 0;

	if(queue){
		is_empty = (CQueue.ElementNum == 0);
	}

	return is_empty;

}

/** Insert item inside the Cyclic Queue **/
int queue_insert( int Element){

	int error=1; // 0 if ok | 1 if not ok

	//Valid pointer and not full queue
	if(!queue_is_full(&CQueue)){

		int next_tail = (CQueue.Head + CQueue.ElementNum)% MAX_SIZE;

		CQueue.Elements[next_tail] = Element;
		CQueue.ElementNum++;
		error=0;

	}
	return error;
}


/** Extract an element of the queue and return a copy of it **/
int queue_extract(int *element){

	int error = 1; // 0 if ok | 1 if not ok

	// Checks if pointer is okay and if the queue is empty
	if(element && !queue_is_empty(&CQueue)){

		*element = CQueue.Elements[CQueue.Head]; 	// Locates the element at the field pointed
		CQueue.Head = (CQueue.Head+1) % MAX_SIZE;  	// New Head
		CQueue.ElementNum--;
		error=0;
	}
	return error;

}
