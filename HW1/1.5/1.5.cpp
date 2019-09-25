#include <iostream>
#include <string.h>


int main()
{
	printf("input string: ");
	char s[20];
	scanf("%s", s);
	int counter = 0;
	for (int i = 0; i < 20; i++)
	{
		if (s[i] == '(')
		{
			counter++;
		}
		if (s[i] == ')')
		{
			counter--;
		}
		if (counter == -1)
		{
			break;
		}
	}
	if (counter == 0)
	{
		printf("balanced");
	}
	else
		printf("unbalanced");
	return 0;
}