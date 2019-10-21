#include <stdio.h>
#include <string.h>
#include "..\..\stack.h"

void performOperation(char operation, StackElement **top)
{
	const int operand2 = pop(top);
	const int operand1 = pop(top);
	int result = 0;
	if (operation == '+')
	{
		result = operand1 + operand2;
		push(top, result);
	}
	else if (operation == '-')
	{
		result = operand1 - operand2;
		push(top, result);
	}
	else if (operation == '*')
	{
		result = operand1 * operand2;
		push(top, result);
	}
	else
	{
		result = operand1 / operand2;
		push(top, result);
	}
}

bool onlyOneElementOnStack(StackElement *top)
{
	if (!isEmpty(top))
	{
		return isEmpty(top->next);
	}
	else
	{
		return false;
	}
}

bool calculate(char postfixExpression[], StackElement **top)
{
	const int length = strlen(postfixExpression);
	for (int i = 0; i < length; i++)
	{
		if (postfixExpression[i] - '0' >= 0 && postfixExpression[i] - '0' < 10)
		{
			push(top, postfixExpression[i] - '0');
		}
		else switch (postfixExpression[i])
		{
		case '+':
		case '-':
		case '*':
		case '/':
			if (!isEmpty(*top))
			{
				if (!isEmpty((*top)->next) && !(postfixExpression[i] == '/' && (*top)->value == 0))
				{
					performOperation(postfixExpression[i], top);
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
			break;
		}
	}
	return onlyOneElementOnStack(*top);
}

int main()
{
	StackElement *top = nullptr;
	printf("Enter postfix expression: ");
	char string[1000] = {};
	fgets(string, 1000, stdin);
	if (calculate(string, &top))
	{
		const int result = pop(&top);
		printf("Result: %d", result);
	}
	else
	{
		printf("Input error");
	}
	delete top;
	return 0;
}
