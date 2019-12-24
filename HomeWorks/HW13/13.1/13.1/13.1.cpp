#include <stdio.h>
#include "lexicalAnalyzer.h"
#include "tests.h"

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

	char sequence[100] = {};
	fscanf(file, "%s", sequence);
	fclose(file);

	printf(lexicalAnalyzer(sequence) ? "This is a number\n" : "This isn't a number\n");
	return 0;
}
