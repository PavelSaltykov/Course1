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

bool checkString(char string[], StackElement *top)
{
	const int length = strlen(string);
	for (int i = 0; i < length; i++)
	{
		switch (string[i])
		{
		case '(':
		case '{':
		case '[':
			push(&top, string[i]);
			break;

		case ')':
		case '}':
		case ']':
			if (isEmpty(top))
			{
				return false;
			}
			else if (pop(&top) != openBracket(string[i]))
			{
				return false;
			}
			break;
		}
	}
	return isEmpty(top);
}

bool tests(StackElement *top)
{
	char testString1[5] = "({)}";
	char testString2[9] = "({}[()])";
	char testString3[24] = "string without brackets";
	return !checkString(testString1, top) && checkString(testString2, top) && checkString(testString3, top);
}

int main()
{
	StackElement *topForTests = nullptr;
	if (!tests(topForTests))
	{
		printf("Testing error\n");
		delete topForTests;
		return 1;
	}
	delete topForTests;

	StackElement *top = nullptr;
	printf("Enter the string: ");
	char string[1000] = {};
	fgets(string, 1000, stdin);
	printf(checkString(string, top) ? "balanced" : "unbalanced");
	delete top;
	return 0;
}