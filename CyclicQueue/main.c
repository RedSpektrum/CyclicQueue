/*
 * main.c
 *
 *  Created on: Jan 1, 2025
 *      Author: atcsol
 */
#include <stdio.h>
#include "src/CQueue.h"


int main() {


	struct CQueue_t queue;
	int data	= 0;
	int status 	= 0;

	queue_init(&queue);
	printf("The queue is actually initialized\n");

	printf("We insert 3 numbers: 3, 4 and 12\n");
	queue_insert(3);
	queue_insert(4);
	queue_insert(12);

	queue_extract(&data);
	printf("The first element is: %d\n", data);

	queue_extract(&data);
	printf("The second element is: %d\n", data);

	queue_extract(&data);
	printf("The third element is: %d\n", data);

	printf("We are going to try to get an additional element, even when the queue is empty\n");

	status = queue_extract(&data);

	if(status==0) printf("The extraction succeeded, it didn't work properly");
	else	printf("The extraction didn't succeed, it work properly");


	return 0;
}
