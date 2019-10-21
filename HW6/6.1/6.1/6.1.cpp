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

bool tests()
{
	bool testsPassed = true;
	StackElement *topForTest1 = nullptr;
	char testString1[4] = "+ 9";
	testsPassed = testsPassed && !calculate(testString1, &topForTest1);
	delete topForTest1;

	StackElement *topForTest2 = nullptr;
	char testString2[4] = "9 +";
	testsPassed = testsPassed && !calculate(testString2, &topForTest2);
	delete topForTest2;

	StackElement *topForTest3 = nullptr;
	char testString3[4] = "9 9";
	testsPassed = testsPassed && !calculate(testString3, &topForTest3);
	delete topForTest3;

	StackElement *topForTest4 = nullptr;
	char testString4[16] = "without numbers";
	testsPassed = testsPassed && !calculate(testString4, &topForTest4);
	delete topForTest4;

	StackElement *topForTest5 = nullptr;
	char testString5[12] = "9 0 / 5 3 +";
	testsPassed = testsPassed && !calculate(testString5, &topForTest5);
	delete topForTest5;

	StackElement *topForTest6 = nullptr;
	char testString6[12] = "5 4 * 9 3 -";
	testsPassed = testsPassed && !calculate(testString6, &topForTest6);
	delete topForTest6;

	StackElement *topForTest7 = nullptr;
	char testString7[14] = "9 6 - 1 2 + *";
	bool test7Passed = false;
	if (calculate(testString7, &topForTest7))
	{
		test7Passed = pop(&topForTest7) == 9;
	}
	testsPassed = testsPassed && test7Passed;
	delete topForTest7;

	StackElement *topForTest8 = nullptr;
	char testString8[10] = "3 4 2 * +";
	bool test8Passed = false;
	if (calculate(testString8, &topForTest8))
	{
		test8Passed = pop(&topForTest8) == 11;
	}
	testsPassed = testsPassed && test8Passed;
	delete topForTest8;
	return testsPassed;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	StackElement *top = nullptr;
	printf("Enter postfix expression: ");
	char string[1000] = {};
	fgets(string, 1000, stdin);
	if (calculate(string, &top))
	{
		const int result = pop(&top);
		printf("Result: %d\n", result);
	}
	else
	{
		printf("Input error\n");
	}
	delete top;
	return 0;
}