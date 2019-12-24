#include <stdio.h>
#include <string.h>
#include "searchComments.h"

bool tests()
{
	char fileName[] = "test.txt";
	char answer[] = "/*ads/*dsf***/\n/*qwe/*/\n";
	return strcmp(comments(fileName), answer) == 0;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	char fileName[] = "input.txt";
	printf("Comments from file:\n%s", comments(fileName));
	return 0;
}