/*
 * CQueue.h
 *
 *  Created on: Apr 9, 2025
 *      Author: atcsol
 */

#ifndef SRC_CQUEUE_H_
#define SRC_CQUEUE_H_


struct CQueue_t{

    int Elements;					// An initial array of elements
    int Head;						// First element index of the queue
    int ElementNum;					// Actual size of the queue

};

int queue_init(struct CQueue_t *queue);
int queue_insert(int Element);
int queue_extract(int *Element);


#endif /* SRC_CQUEUE_H_ */
