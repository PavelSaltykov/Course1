#include "stack.h"

struct StackElement
{
	int value;
	StackElement *next;
};

struct Stack
{
	StackElement *top = nullptr;
};

void push(Stack *stack, int value)
{
	stack->top = new StackElement {value, stack->top};
}

int pop(Stack *stack)
{
	int topValue = stack->top->value;
	StackElement *temp = stack->top->next;
	delete stack->top;
	stack->top = temp;
	return topValue;
}

bool isEmpty(Stack *stack)
{
	return stack->top == nullptr;
}

void deleteStack(Stack *stack)
{
	while (!isEmpty(stack))
	{
		pop(stack);
	}
	delete stack;
}

Stack *createStack()
{
	return new Stack;
}