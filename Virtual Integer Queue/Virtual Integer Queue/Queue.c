#include<stdio.h>
#define SIZE 10

/*
	--Stack Struct--
	Create a Struct to save the Stack
	Create a stackList[10] variable that stores values
	and top variable that stores values at the top
*/
typedef struct stack {
	int stackList[SIZE];
	int top;
}Stack;

Stack mainStack;
Stack subStack;
/*
	Function prototype of Main Stack
*/
void push_Main(int num);
int pop_Main();
int stack_full_Main();
int stack_empty_Main();
/*
	Function prototype of Sub Stack
*/
void push_Sub(int num);
int pop_Sub();
int stack_full_Sub();
int stack_empty_Sub();
/*
	Function prototype of Virtual Queue
*/
void enqueue(int num);
int dequeue();
void print_queue();
/*
	--Main Function--
	Repeat to add or delete a queue and print out the queue.
*/
int main() {
	mainStack.top = -1;
	subStack.top = -1;
	int number;

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
//////////////////////////////////Main Stack///////////////////////////////////////////
/*
	--push_Main Function--
	Function to add value to Main Stack
	Generate an Overflow if the Main stack is full
	and increase the top if the Main stack is not full and put a value in the Main Stack.
*/
void push_Main(int num) {
	if (stack_full_Main()) {
		printf("Stack Overflow!\n");
	}
	else {
		mainStack.stackList[++mainStack.top] = num;
	}
}
/*
	--pop_Main Function--
	A Function that deletes the last value entered.
	and decrease the top
*/
int pop_Main() {
	if (stack_empty_Main()) {
		printf("Stack Underflow!");
		return -1;
	}
	else {
		return mainStack.stackList[mainStack.top--];
	}
}
/*
	--stack_full_Main Funtion--
	A function that checks whether the Main Stack is full.
	Returns True if the Main Stack is full and False if not full.
*/
int stack_full_Main() {
	return mainStack.top >= SIZE - 1;
}
/*
	--stack_empty_Main Funtion--
	A function that checks whether the Stack is empty.
	Returns True if the Main Stack is empty and False if not empty.
*/
int stack_empty_Main() {
	return mainStack.top == -1;
}

/////////////////////////Sub Stack///////////////////////////////////////////
/*
	--push_Sub Function--
	Function to add value to Sub Stack
	Generate an Overflow if the Sub stack is full
	and increase the top if the Sub Stack is not full and put a value in the Sub Stack.
*/
void push_Sub(int num) {
	if (stack_full_Sub()) {
		printf("Stack Overflow!\n");
	}
	else {
		subStack.stackList[++subStack.top] = num;
	}
}
/*
	--pop_Sub Function--
	A Function that deletes the last value entered.
	and decrease the top
*/
int pop_Sub() {
	if (stack_empty_Sub()) {
		printf("Stack Underflow!");
		return -1;
	}
	else {
		return subStack.stackList[subStack.top--];
	}
}
/*
	--stack_full_Sub Funtion--
	A function that checks whether the Sub Stack is full.
	Returns True if the Sub Stack is full and False if not full.
*/
int stack_full_Sub() {
	return subStack.top >= SIZE - 1;
}
/*
	--stack_empty_Sub Funtion--
	A function that checks whether the Sub Stack is empty.
	Returns True if the Sub Stack is empty and False if not empty.
*/
int stack_empty_Sub() {
	return subStack.top == -1;
}

/////////////////////////Virtual Queue///////////////////////////////////////////
/*
	--enqueue Function--
	This function adds a value to the Virtual Queue.
	Move all existing values from the Main Stack to the Sub Stack.
	Add a value to the main stack,
	then move the value back to the Main Stack.
*/
void enqueue(int num) {
	while (!stack_empty_Main())
		push_Sub(pop_Main());

	push_Main(num);

	while (!stack_empty_Sub())
		push_Main(pop_Sub());
}
/*
	--dequeue Function--
	This function deletes the first value that was placed in the Virtual Queue.
*/
int dequeue() {
	return pop_Main();
}
/*
	--print_queue Function--
	A function that outputs a queue.
	Output the queue against each sequence, moving the queue from start to finish
*/
void print_queue() {
	printf("Queue : ");
	for (int i = 0; i <= mainStack.top; i++)
		printf("%d ", mainStack.stackList[i]);
	printf("\n");
}
