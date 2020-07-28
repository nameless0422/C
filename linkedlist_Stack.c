#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node* link;
}StackNODE;

StackNODE* top;

int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

void push(element item) {
	StackNODE* temp = (StackNODE*)malloc(sizeof(StackNODE));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop() {
	element item;
	StackNODE* temp = top;

	if (temp == NULL) {
		printf("\n\n Stack is Empty!\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

element peek() {
	if (top == NULL) {
		printf("\n\n Stack is Empty! \n");
		return 0;
	}
	else {
		return (top->data);
	}
}

void printStack() {
	StackNODE* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

void main() {
	element item;
	top = NULL;
	printf("\n** linked Stack **\n");
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	printf("peek = %d\n",item);

	item = pop(); printStack();
	printf("pop = %d",item);

	item = pop(); printStack();
	printf("pop = %d",item);

	item = pop(); printStack();
	printf("pop = %d",item);

	getchar();

}
