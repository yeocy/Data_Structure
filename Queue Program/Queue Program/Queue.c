#include<stdio.h>
#define SIZE 10

int queueList[SIZE];//create array of size(10)
int front = -1;//front initial
int rear = -1;//rear initial

void enqueue(int num);//enqueue function declaration
int dequeue();//dequeue function declaration
int queue_full();//queue_full function declaration
int queue_empty();//queue_empty function declaration
void print_queue();//print_queue function declaration

int main(void) {
	int number;

	if (queue_empty()) //Run first if return value is 1 and second if 0
		printf("Queue is empty\n");
	else
		printf("Queue is not empty\n");

	for (int i = 0; i < 5; i++) {//5 times a enqueue
		scanf("\n%d", &number);//Values received
		enqueue(number);
	}
	print_queue();//print out Queue LIst

	for (int i = 0; i < 3; i++)//5 times a dequeue
		printf("dequeue : %d\n", dequeue());
	print_queue();//print out Queue LIst

	if (queue_full())//Run first if return value is 1 and second if 0
		printf("Queue is full\n");
	else
		printf("Queue is not full\n");

	for (int i = 0; i < 3; i++) {//5 times a enqueue
		scanf("\n%d", &number);//Values received
		enqueue(number);
	}

	for (int i = 0; i < 3; i++)//5 times a dequeue
		printf("dequeue : %d\n", dequeue());
	print_queue();//print out Queue LIst


}

void print_queue() {//Output Queue
	printf("Queue: ");
	for (int i = front + 1; i <= rear; i++)//Repeat as many times as A to output Queue.
		printf("%d ", queueList[i]);
	printf("\n");
}

void enqueue(int num) {
	if (queue_full()) {//Run first if return value is 1 and second if 0
		printf("Queue Overflow!\n");//print Error message
	}
	else {
		queueList[++rear] = num;//Increase the rear and enter the entered value in the array.
	}
}

int dequeue() {
	if (queue_empty()) {//Run first if return value is 1 and second if 0
		printf("Queue Underflow!\n");//print Error message
		return -1;//Returns error value as - 1
	}
	else {
		return queueList[++front];//increase the front and return the front-th value to the array.
	}
}

int queue_full() {
	return rear >= SIZE - 1;//Returns 1 if true or 0 if false
}

int queue_empty() {
	return front == rear;//Returns 1 if true or 0 if false
}