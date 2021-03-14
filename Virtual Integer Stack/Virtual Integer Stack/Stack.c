#include<stdio.h>
#define SIZE 10
/*
	--Queue Struct--
	Create a Struct to save the Queue
	Create a queueList[10] variable that stores values
	and front variable that stores values at the front
	and rear variable that stores values at the last
*/
typedef struct queue {
	int queueList[SIZE];
	int front;
	int rear;
}Queue;

Queue mainQueue;
Queue subQueue;
/*
	Function prototype of Main Queue
*/
void enqueue_Main(int num);
int dequeue_Main();
int queue_full_Main();
int queue_empty_Main();
/*
	Function prototype of Sub Queue
*/
void enqueue_Sub(int num);
int dequeue_Sub();
int queue_full_Sub();
int queue_empty_Sub();
/*
	Function prototype of Virtual Queue
*/
void push(int num);
int pop();
void print_stack();
/*
	--Main Function--
	Repeat to add or delete a queue and print out the queue.
*/
int main() {
	int number;
	mainQueue.front = mainQueue.rear = -1;
	subQueue.front = subQueue.rear = -1;

	for (int i = 0; i < 3; i++) {
		scanf("\n%d", &number);
		push(number);
	}
	print_stack();
	printf("pop : %d\n", pop());
	print_stack();
}
/*
	--enqueue_Main Function--
	Function to add value to Main Queue
	Generate an Overflow if the Main Queue is full
	and increase the rear if the Main Queue is not full and put a value in the Main Queue.
*/
void enqueue_Main(int num) {
	if (queue_full_Main()) {
		printf("Queue Overflow!\n");
	}
	else {
		mainQueue.queueList[++mainQueue.rear] = num;
	}
}
/*
	--dequeue_Main Function--
	A Function that deletes the first value entered.
	and increase the front
*/
int dequeue_Main() {
	if (queue_empty_Main()) {
		printf("Queue Underflow!\n");
		return -1;
	}
	else {
		return mainQueue.queueList[++mainQueue.front];
	}
}
/*
	--queue_full_Main Funtion--
	A function that checks whether the Main Queue is full.
	Returns True if the Main Queue is full and False if not full.
*/
int queue_full_Main() {
	return mainQueue.rear >= SIZE - 1;
}
/*
	--queue_empty_Main Funtion--
	A function that checks whether the Main Queue is empty.
	Returns True if the Main Queue is empty and False if not empty.
*/
int queue_empty_Main() {
	return mainQueue.front == mainQueue.rear;
}

/////////////////////////Sub Queue///////////////////////////////////////////
/*
	--enqueue_Sub Function--
	Function to add value to Sub Queue
	Generate an Overflow if the Sub Queue is full
	and increase the rear if the Sub Queue is not full and put a value in the Sub Queue.
*/
void enqueue_Sub(int num) {
	if (queue_full_Sub()) {
		printf("Queue Overflow!\n");
	}
	else {
		subQueue.queueList[++subQueue.rear] = num;
	}
}
/*
	--dequeue_Sub Function--
	A Function that deletes the first value entered.
	and increase the front
*/
int dequeue_Sub() {
	if (queue_empty_Sub()) {
		printf("Queue Underflow!\n");
		return -1;
	}
	else {
		return subQueue.queueList[++subQueue.front];
	}
}
/*
	--queue_full_Sub Funtion--
	A function that checks whether the Sub Queue is full.
	Returns True if the Sub Queue is full and False if not full.
*/
int queue_full_Sub() {
	return subQueue.rear >= SIZE - 1;
}
/*
	--queue_empty_Sub Funtion--
	A function that checks whether the Sub Queue is empty.
	Returns True if the Sub Queue is empty and False if not empty.
*/
int queue_empty_Sub() {
	return subQueue.front == subQueue.rear;
}


/////////////////////////Virtual Stack///////////////////////////////////////////
/*
	--push Function--
	This function adds a value to the Virtual Stack.
	Move all existing values from the Main Queue to the Sub Queue.
	Add a value to the Main Queue,
	then move the value back to the Main Queue.
*/
void push(int num) {
	while (!queue_empty_Main())
		enqueue_Sub(dequeue_Main());

	enqueue_Main(num);

	while (!queue_empty_Sub())
		enqueue_Main(dequeue_Sub());
}
/*
	--pop Function--
	This function deletes the last value that was placed in the Virtual Stack.
*/
int pop() {
	return dequeue_Main();
}
/*
	--print_stack Function--
	A function that outputs a stack.
	Output the stack against each sequence, moving the stack from start to finish
*/
void print_stack() {
	printf("Stack: ");
	for (int i = mainQueue.front + 1; i <= mainQueue.rear; i++)
		printf("%d ", mainQueue.queueList[i]);
	printf("\n");
}
