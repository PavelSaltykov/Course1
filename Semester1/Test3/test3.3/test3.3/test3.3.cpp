#include <string.h>
#include <ctype.h>
#include <stdio.h>

bool checkString(char* string)
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
			if (isdigit(string[i]))
			{
				state = 2;
				break;
			}
			return false;
		case 2:
			if (string[i] == 'B' || string[i] == 'M' || string[i] == 'S')
			{
				state = 3;
				break;
			}
			return false;
		case 3:
			if (string[i] == '1')
			{
				state = 4;
				break;
			}
			if (isdigit(string[i]) && string[i] != '0')
			{
				state = 5;
				break;
			}
			return false;
		case 4:
			if (string[i] == '0')
			{
				state = 5;
				break;
			}
			if (string[i] == '-')
			{
				state = 6;
				break;
			}
			return false;
		case 5:
			if (string[i] == '-')
			{
				state = 6;
				break;
			}
			return false;
		case 6:
			if (string[i] == 'm')
			{
				state = 7;
				break;
			}
			return false;
		case 7:
			if (string[i] == 'm')
			{
				state = 8;
				break;
			}
			return false;
		case 8:
			return string[i] == '\0';
		}
	}
}

int main()
{
	char string[100] = {};
	printf("Enter string:\n");
	scanf("%s", string);
	printf((checkString(string)) ? "String is correct group number\n" : "String isn't correct group number\n");
	return 0;
}