#include<stdio.h>

/*
	--Queue Struct--
	Create a Linked List to save the queue
	Create a value variable that stores values
	and an address variable that stores addresses in the next queue.
*/
typedef struct queue {
	int value;
	struct queue *nextPtr;
}Queue;

/*
	Function prototype
*/
void enqueue(int value);
int dequeue();
int queue_empty();
void print_queue();

Queue *startPtr = NULL;
/*
	--Main Function--
	Repeat to add or delete a queue and print out the queue.
*/
int main(void) {
	int number;
	if (queue_empty())
		printf("Queue is empty\n");
	else
		printf("Queue is not empty\n");

	for (int i = 0; i < 5; i++) {
		scanf("\n%d", &number);
		enqueue(number);
	}
	print_queue();

	for (int i = 0; i < 3; i++)
		printf("dequeue : %d\n", dequeue());
	print_queue();

	for (int i = 0; i < 3; i++) {
		scanf("\n%d", &number);
		enqueue(number);
	}

	for (int i = 0; i < 3; i++)
		printf("dequeue : %d\n", dequeue());
	print_queue();


}

/*
	--print_queue Function--
	A function that outputs a queue.
	Output the queue against each sequence, moving the queue from start to finish
*/
void print_queue() {
	Queue *currentPtr = startPtr;
	while (currentPtr != NULL) {
		printf("%d  ", currentPtr->value);
		currentPtr = currentPtr->nextPtr;
	}
	printf("\n");
}
/*
	--enqueue Function--
	Function to add value to linked list
	Create a queue with dynamic allocation, insert the value,
	and add it to the LInked List queue at the end.
*/
void enqueue(int value) {
	Queue *newPtr;
	Queue *currentPtr;

	newPtr = malloc(sizeof(Queue));
	currentPtr = startPtr;

	if (newPtr != NULL) {
		newPtr->value = value;
		newPtr->nextPtr = NULL;

		if (queue_empty()) {
			startPtr = newPtr;
		}
		else {
			while (currentPtr->nextPtr != NULL) {
				currentPtr = currentPtr->nextPtr;
			}
			currentPtr->nextPtr = newPtr;
		}
	}
	else {
		printf("%d not enqueue. No memory available.\n", value);
	}
}
/*
	--dequeue Function--
	A Function that deletes the first value entered.
	Then connect the first value to the startPtr.
*/
int dequeue() {
	Queue *previousPtr;
	Queue *currentPtr = startPtr;
	int num;

	if (startPtr == NULL) {
		printf("Can not delete");
		return -1;
	}
	else {
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
		num = previousPtr->value;
		free(previousPtr);
		startPtr = currentPtr;
		return num;
	}
}
/*
	--queue_empty Funtion--
	A function that checks whether the queue is empty.
	Returns True if the queue is empty and False if not empty.
*/
int queue_empty() {
	return startPtr == NULL;
}
