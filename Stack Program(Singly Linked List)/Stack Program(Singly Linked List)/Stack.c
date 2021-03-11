#include<stdio.h>

/*
	--Stack Struct--
	Create a Linked List to save the Stack
	Create a value variable that stores values
	and an address variable that stores addresses in the next Stack.
*/
typedef struct stack {
	int value;
	struct stack *nextPtr;
}Stack;

/*
	Function prototype
*/
void push(int value);
int pop();
int stack_empty();
void print_stack();

Stack* startPtr = NULL;
/*
	--Main Function--
	Repeat to add or delete a stack and print out the Stack.
*/
int main() {
	int number;

	if (stack_empty())
		printf("Stack is empty\n");
	else
		printf("Stack is not empty\n");

	for (int i = 0; i < 5; i++) {
		scanf("\n%d", &number);
		push(number);
	}
	print_stack();

	for (int i = 0; i < 3; i++)
		printf("pop : %d\n", pop());

	if (stack_empty())
		printf("Stack is empty\n");
	else
		printf("Stack is not empty\n");

	print_stack();

	for (int i = 0; i < 9; i++) {
		scanf("\n%d", &number);
		push(number);
	}

	print_stack();

	for (int i = 0; i < 5; i++)
		printf("pop : %d\n", pop());
	print_stack();
}
/*
	--print_stack Function--
	A function that outputs a stack.
	Output the stack against each sequence, moving the stack from start to finish
*/
void print_stack() {
	Stack* currentPtr = startPtr;
	while (currentPtr != NULL) {
		printf("%d  ", currentPtr->value);
		currentPtr = currentPtr->nextPtr;
	}
	printf("\n");
}
/*
	--push Function--
	Function to add value to linked list
	Create a stack with dynamic allocation, insert the value,
	and add it to the LInked List stack at the end.
*/
void push(int value)
{
	Stack* newPtr;
	Stack* currentPtr;

	newPtr = malloc(sizeof(Stack));
	currentPtr = startPtr;

	if (newPtr != NULL) {
		newPtr->value = value;
		newPtr->nextPtr = NULL;

		if (stack_empty()) {
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
		printf("%d not push. No memory available.\n", value);
	}

	free(newPtr);
}
/*
	--pop Function--
	A Function that deletes the last value entered.
	Then change the nextPtr of the previous stack to NULL.
*/
int pop() {
	Stack *previousPtr;
	Stack *currentPtr = startPtr;
	int num;

	if (startPtr == NULL) {
		printf("Can not delete");
		return -1;
	}
	else {
		if (currentPtr->nextPtr == NULL) {
			startPtr = NULL;
			free(currentPtr);
		}
		else {
			while (currentPtr->nextPtr != NULL) {
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
			}
			previousPtr->nextPtr = NULL;
			num = currentPtr->value;
			free(currentPtr);
			return num;
		}
	}
}
/*
	--stack_empty Funtion--
	A function that checks whether the stack is empty.
	Returns True if the stack is empty and False if not empty.
*/
int stack_empty()
{
	return startPtr == NULL;
}
