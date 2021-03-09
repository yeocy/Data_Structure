#include<stdio.h>

#define SIZE 10

int stackList[SIZE];//create array of size(10)
int top = -1;//top initial

void push(int num);//push function declaration
int pop();//pop function declaration
int stack_full();//stack_full function declaration
int stack_empty();//stack_empty function declaration
void print_stack();//print_stack function declaration

int main(void) {
	int number;

	if (stack_empty()) //Run first if return value is 1 and second if 0
		printf("Stack is empty\n");
	else
		printf("Stack is not empty\n");

	for (int i = 0; i < 5; i++) {//5 times a push
		scanf("\n%d", &number);//Values received
		push(number);
	}

	if (stack_full())//Run first if return value is 1 and second if 0
		printf("Stack is full\n");
	else
		printf("Stack is not full\n");

	print_stack();//print out Stack LIst

	for (int i = 0; i < 3; i++)//5 times a pop
		printf("pop : %d\n", pop());

	if (stack_empty())//Run first if return value is 1 and second if 0
		printf("Stack is empty\n");
	else
		printf("Stack is not empty\n");

	print_stack();//print out Stack LIst

	for (int i = 0; i < 9; i++) {//5 times a push
		scanf("\n%d", &number);//Values received
		push(number);
	}

	if (stack_full())//Run first if return value is 1 and second if 0
		printf("Stack is full\n");
	else
		printf("Stack is not full\n");
	print_stack();//print out Stack LIst

	for (int i = 0; i < 5; i++)//
		printf("pop : %d\n", pop());//5 times a pop
	print_stack();//print out Stack LIst
}

void print_stack() {//Output Stack
	printf("Stack : ");
	for (int i = 0; i <= top; i++)//Repeat as many times as A to output Stack.
		printf("%d ", stackList[i]);
	printf("\n");
}

void push(int num) {
	if (stack_full()) {//Run first if return value is 1 and second if 0
		printf("Stack Overflow!\n");//print Error message
	}
	else {
		stackList[++top] = num;//Increase the top and enter the entered value in the array.
	}
}

int pop() {
	if (stack_empty()) {//Run first if return value is 1 and second if 0
		printf("Stack Underflow!");//print Error message
		return -1;//Returns error value as - 1
	}
	else {
		return stackList[top--];//Decrease the top and return the top-th value to the array.
	}
}

int stack_full() {//Check if stack is full
	return top >= SIZE - 1;//Returns 1 if true or 0 if false
}

int stack_empty() {//Check if stack is empty
	return top == -1;//Returns 1 if true or 0 if false
}