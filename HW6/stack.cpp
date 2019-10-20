#include "stack.h"

void push(StackElement **top, char value)
{
	StackElement *element = new StackElement{value, *top};
	*top = element;
}

char pop(StackElement **top)
{
	char value = (*top)->value;
	StackElement *temp = (*top)->next;
	delete *top;
	*top = temp;
	return value;
}

bool isEmpty(StackElement *top)
{
	return top == nullptr;
}