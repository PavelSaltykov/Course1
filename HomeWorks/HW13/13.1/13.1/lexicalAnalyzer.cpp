#include <string.h>
#include <ctype.h>
#include "lexicalAnalyzer.h"

bool lexicalAnalyzer(char *string)
{
	const int length = strlen(string);
	int state = 0;
	for (int i = 0; i < length + 1; ++i)
	{
		switch (state)
		{
		case 0:
			if (isdigit(string[i]))
			{
				state = 1;
				break;
			}
			return false;

		case 1:
			if (string[i] == '\0')
			{
				return true;
			}
			if (isdigit(string[i]))
			{
				state = 1;
				break;
			}
			if (string[i] == '.')
			{
				state = 2;
				break;
			}
			if (string[i] == 'E')
			{
				state = 4;
				break;
			}
			return false;

		case 2:
			if (isdigit(string[i]))
			{
				state = 3;
				break;
			}
			return false;

		case 3:
			if (isdigit(string[i]))
			{
				state = 3;
				break;
			}
			if (string[i] == 'E')
			{
				state = 4;
				break;
			}
			if (string[i] == '\0')
			{
				return true;
			}
			return false;

		case 4:
			if (isdigit(string[i]) || string[i] == '+' || string[i] == '-')
			{
				state = 5;
				break;
			}
			return false;

		case 5:
			if (isdigit(string[i]))
			{
				state = 5;
				break;
			}
			if (string[i] == '\0')
			{
				return true;
			}
			return false;
		}
	}
}