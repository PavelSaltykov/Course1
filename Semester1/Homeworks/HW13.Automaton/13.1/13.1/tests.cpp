#include <stdio.h>
#include "lexicalAnalyzer.h"
#include "tests.h"

bool tests()
{
	char arrayOfStrings[10][10] = {"123", "123.4", "12E3", "123.45E56", "123.45E+6", "", "a123", "12.", "1.23E", "12.E5"};
	for (int i = 0; i < 5; ++i)
	{
		if (!lexicalAnalyzer(arrayOfStrings[i]))
		{
			printf("Error in test%d\n", i + 1);
			return false;
		}
	}

	for (int i = 5; i < 10; ++i)
	{
		if (lexicalAnalyzer(arrayOfStrings[i]))
		{
			printf("Error in test%d\n", i + 1);
			return false;
		}
	}
	return true;
}