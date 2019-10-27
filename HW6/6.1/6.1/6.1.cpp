#include <stdio.h>
#include <string.h>
#include "..\..\stack.h"

void performOperation(char operation, Stack *stack)
{
	const int operand2 = pop(stack);
	const int operand1 = pop(stack);
	int result = 0;
	if (operation == '+')
	{
		result = operand1 + operand2;
	}
	else if (operation == '-')
	{
		result = operand1 - operand2;
	}
	else if (operation == '*')
	{
		result = operand1 * operand2;
	}
	else
	{
		result = operand1 / operand2;
	}
	push(stack, result);
}

bool calculate(char postfixExpression[], int &result)
{
	Stack *stack = createStack();
	const int length = strlen(postfixExpression);
	for (int i = 0; i < length; i++)
	{
		if (postfixExpression[i] - '0' >= 0 && postfixExpression[i] - '0' < 10)
		{
			push(stack, postfixExpression[i] - '0');
		}
		else switch (postfixExpression[i])
		{
		case '+':
		case '-':
		case '*':
		case '/':
			if (!isEmpty(stack))
			{
				const int topValue = pop(stack);
				if (!isEmpty(stack) && !(postfixExpression[i] == '/' && topValue == 0))
				{
					push(stack, topValue);
					performOperation(postfixExpression[i], stack);
				}
				else
				{
					deleteStack(stack);
					return false;
				}
			}
			else
			{
				deleteStack(stack);
				return false;
			}
			break;
		}
	}
	bool resultFound = false;
	if (!isEmpty(stack))
	{
		result = pop(stack);
		if (isEmpty(stack))
		{
			resultFound = true;
		}
	}
	deleteStack(stack);
	return resultFound;
}

bool tests()
{
	bool testsPassed = true;
	int answer = 0;
	char testString1[4] = "+ 9";
	testsPassed = testsPassed && !calculate(testString1, answer);

	char testString2[4] = "9 +";
	testsPassed = testsPassed && !calculate(testString2, answer);

	char testString3[4] = "9 9";
	testsPassed = testsPassed && !calculate(testString3, answer);

	char testString4[16] = "without numbers";
	testsPassed = testsPassed && !calculate(testString4, answer);

	char testString5[12] = "9 0 / 5 3 +";
	testsPassed = testsPassed && !calculate(testString5, answer);

	char testString6[12] = "5 4 * 9 3 -";
	testsPassed = testsPassed && !calculate(testString6, answer);

	char testString7[14] = "9 6 - 1 2 + *";
	bool test7Passed = false;
	answer = 0;
	if (calculate(testString7, answer))
	{
		test7Passed = answer == 9;
	}
	testsPassed = testsPassed && test7Passed;

	char testString8[10] = "3 4 2 * +";
	bool test8Passed = false;
	answer = 0;
	if (calculate(testString8, answer))
	{
		test8Passed = answer == 11;
	}
	testsPassed = testsPassed && test8Passed;
	return testsPassed;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	printf("Enter postfix expression: ");
	char string[1000] = {};
	scanf("%[^\n]", string);
	int result = 0;
	if (calculate(string, result))
	{
		printf("Result: %d\n", result);
	}
	else
	{
		printf("Input error\n");
	}
	return 0;
}