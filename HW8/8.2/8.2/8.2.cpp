#include <stdio.h>
#include "tree.h"

bool tests()
{

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
		printf("File not found");
		return 1;
	}

	char prefix[1000] = {};
	fgets(prefix, 1000, file);
	fclose(file);

	Tree *tree = build(prefix);
	printf("Prefix expression: ");
	printTree(tree);
	printf("\nReult: %d", calculate(tree));

	deleteTree(tree);
	return 0;
}