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

bool checkString(char string[], StackElement **top)
{
	const int length = strlen(string);
	for (int i = 0; i < length; i++)
	{
		switch (string[i])
		{
		case '(':
		case '{':
		case '[':
			push(top, string[i]);
			break;

		case ')':
		case '}':
		case ']':
			if (isEmpty(*top))
			{
				return false;
			}
			else if (pop(top) != openBracket(string[i]))
			{
				return false;
			}
			break;
		}
	}
	return isEmpty(*top);
}

bool tests()
{
	StackElement *topForTest1 = nullptr;
	char testString1[5] = "({)}";
	const bool test1Passed = !checkString(testString1, &topForTest1);
	delete topForTest1;

	StackElement *topForTest2 = nullptr;
	char testString2[9] = "({}[()])";
	const bool test2Passed = checkString(testString2, &topForTest2);
	delete topForTest2;

	StackElement *topForTest3 = nullptr;
	char testString3[24] = "string without brackets";
	const bool test3Passed = checkString(testString3, &topForTest3);
	delete topForTest3;
		
	return test1Passed && test2Passed && test3Passed;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	StackElement *top = nullptr;
	printf("Enter the string: ");
	char string[1000] = {};
	fgets(string, 1000, stdin);
	printf(checkString(string, &top) ? "balanced" : "unbalanced");
	delete top;
	return 0;
}