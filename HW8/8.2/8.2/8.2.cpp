#include <stdio.h>
#include "tree.h"

int main()
{
	char string[] = "* 34 - 56 110";
	Tree *tree = build(string);
	printTree(tree);
	printf("\n%d", calculate(tree));
	deleteTree(tree);
	return 0;
}