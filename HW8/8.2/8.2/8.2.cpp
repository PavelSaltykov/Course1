#include <stdio.h>
#include "tree.h"

bool test(char *string, int answer)
{
	Tree *tree = build(string);
	const bool testPassed = calculate(tree) == answer;
	deleteTree(tree);
	return testPassed;
}

bool tests()
{
	char string1[] = "* (+ 52 71) (- 6 31)";
	const int answer1 = -3075;

	char string2[] = "(- (* 25 (- 70 35))(/ (* (+ 15 110) 6) 7))";
	const int answer2 = 768;

	return test(string1, answer1) && test(string2, answer2);
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
	printf("\nResult: %d", calculate(tree));

	deleteTree(tree);
	return 0;
}