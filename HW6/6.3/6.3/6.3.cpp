#include "..\..\stack.h"
#include <string.h>
#include <stdio.h>

bool balancedBrackets(char string[])
{
	const int length = strlen(string);
	Stack *stack = createStack();
	for (int i = 0; i < length; ++i)
	{
		if (string[i] == '(')
		{
			push(stack, string[i]);
		}
		if (string[i] == ')')
		{
			if (isEmpty(stack))
			{
				return false;
			}
			pop(stack);
		}
	}
	const bool isBalanced = isEmpty(stack);
	deleteStack(stack);
	return isBalanced;
}

int priority(char operation)
{
	int priority = 0;
	switch (operation)
	{
	case '*':
	case '/':
		priority = 1;
		break;
	case '+':
	case '-':
		priority = 2;
		break;
	case '(':
		priority = 3;
		break;
	}
	return priority;
}

void convertToPostfix(char infixExpression[], char postfixExpression[])
{
	Stack *stack = createStack();
	const int infixLength = strlen(infixExpression);
	int postfixLength = 0;
	for (int i = 0; i < infixLength; ++i)
	{
		if (infixExpression[i] >= '0' && infixExpression[i] <= '9')
		{
			postfixExpression[postfixLength] = infixExpression[i];
			postfixLength++;
		}
		else switch (infixExpression[i])
		{
		case '+':
		case '-':
		case '*':
		case '/':
		{
			bool shouldCheckPriority = true;
			while (shouldCheckPriority && !isEmpty(stack))
			{
				char operationInStack = pop(stack);
				if (priority(operationInStack) <= priority(infixExpression[i]))
				{
					postfixExpression[postfixLength] = operationInStack;
					postfixLength++;
				}
				else
				{
					push(stack, operationInStack);
					shouldCheckPriority = false;
				}
			}
			push(stack, infixExpression[i]);
			break;
		}

		case '(':
			push(stack, infixExpression[i]);
			break;
		case ')':
			char operation = pop(stack);
			while (operation != '(')
			{
				postfixExpression[postfixLength] = operation;
				postfixLength++;
				operation = pop(stack);
			}
			break;
		}
	}
	while (!isEmpty(stack))
	{
		const char operation = pop(stack);
		if (operation != '(')
		{
			postfixExpression[postfixLength] = operation;
			postfixLength++;
		}
	}
	deleteStack(stack);
}

bool tests()
{
	char testString1[20] = "1 - (2 + 3 * 4) / 5";
	char result1[20] = {};
	convertToPostfix(testString1, result1);
	if (strcmp(result1, "1234*+5/-") != 0)
	{
		return false;
	}
	char testString2[14] = "5 - 4 * 3 + 1";
	char result2[14] = {};
	convertToPostfix(testString2, result2);
	if (strcmp(result2, "543*-1+") != 0)
	{
		return false;
	}
	char testString3[54] = "(5 + 4) * (3 - 4 * 1 + (9 - 0 * 3) + 2 / (8 * 7 - 3))";
	char result3[54] = {};
	convertToPostfix(testString3, result3);
	if (strcmp(result3, "54+341*-903*-+287*3-/+*") != 0)
	{
		return false;
	}
	return true;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	printf("Enter an infix expression: ");
	char inputString[1000] = {};
	fgets(inputString, 1000, stdin);
	char outputString[1000] = {};
	if (!balancedBrackets(inputString))
	{
		printf("Invalid input (brackets are not balanced)\n");
		return 1;
	}

	convertToPostfix(inputString, outputString);
	const int outputStringLength = strlen(outputString);
	if (outputStringLength == 0)
	{
		printf("Invalid input\n");
		return 1;
	}
	printf("Postfix expression: ");
	for (int i = 0; i < outputStringLength; ++i)
	{
		printf("%c ", outputString[i]);
	}
	return 0;
}