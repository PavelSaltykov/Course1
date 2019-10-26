#include <stdio.h>
#include <string.h>
#include "..\..\stack.h"

char openBracket(char closedBracket)
{
	if (closedBracket == ')')
	{
		return '(';
	}
	else if (closedBracket == '}')
	{
		return '{';
	}
	else 
	{
		return '[';
	}
}

bool checkString(char string[])
{
	Stack *stack = createStack();
	const int length = strlen(string);
	for (int i = 0; i < length; i++)
	{
		switch (string[i])
		{
		case '(':
		case '{':
		case '[':
			push(stack, string[i]);
			break;

		case ')':
		case '}':
		case ']':
			if (isEmpty(stack))
			{
				deleteStack(stack);
				return false;
			}
			else if (pop(stack) != openBracket(string[i]))
			{
				deleteStack(stack);
				return false;
			}
			break;
		}
	}
	const bool stringBalanced = isEmpty(stack);
	deleteStack(stack);
	return stringBalanced;
}

bool tests()
{
	char testString1[5] = "({)}";
	const bool test1Passed = !checkString(testString1);

	char testString2[9] = "({}[()])";
	const bool test2Passed = checkString(testString2);

	char testString3[24] = "string without brackets";
	const bool test3Passed = checkString(testString3);
	
	return test1Passed && test2Passed && test3Passed;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	printf("Enter the string: ");
	char string[1000] = {};
	scanf("%[^\n]%*c", string);
	printf(checkString(string) ? "balanced" : "unbalanced");
	return 0;
}