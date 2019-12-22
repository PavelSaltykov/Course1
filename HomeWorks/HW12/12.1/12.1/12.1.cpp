#include <stdio.h>
#include <string.h>
#include "RabinKarp.h"

bool test1()
{
	char string1[] = "abcdefghijklmnopqrstuvw";
	char string2[] = "pqrstu";
	return rabinKarp(string1, string2) == 15;
}

bool test2()
{
	char string1[] = "abcdefghijklmn";
	char string2[] = "fhg";
	return rabinKarp(string1, string2) == -1;
}

bool test3()
{
	char string1[] = "abcdefghijklmnopqrstuvwxyz123456789";
	char string2[] = "bcdefghijklmnopqrstuvw";
	return rabinKarp(string1, string2) == 1;
}

bool tests()
{
	if (!test1())
	{
		printf("Error in test1\n");
		return false;
	}

	if (!test2())
	{
		printf("Error in test2\n");
		return false;
	}

	if (!test3())
	{
		printf("Error in test3\n");
		return false;
	}
	return true;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	FILE *file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found\n");
		return 1;
	}

	char text[10000] = {};
	while (!feof(file))
	{
		char buffer[1000] = {};
		fgets(buffer, 1000, file);
		strcat(text, buffer);
	}
	fclose(file);

	printf("Enter the string: ");
	char string[1000] = {};
	scanf("%[^\n]%*c", string);

	const int position = rabinKarp(text, string);
	printf(position < 0 ? "String not found in text\n" : "Position of the first occurrence: %d\n", position);
	return 0;
}