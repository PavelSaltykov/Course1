#include "stack.h"

void push(StackElement **top, int value)
{
	StackElement *element = new StackElement{value, *top};
	*top = element;
}

int pop(StackElement **top)
{
	int value = (*top)->value;
	StackElement *temp = (*top)->next;
	delete *top;
	*top = temp;
	return value;
}

bool isEmpty(StackElement *top)
{
	return top == nullptr;
}