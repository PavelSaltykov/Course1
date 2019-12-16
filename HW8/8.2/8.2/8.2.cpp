
#include "tree.h"

int main()
{
	char string[] = "(* (+ 1 1) 2)";
	Tree *tree = build(string);
	printTree(tree);
	deleteTree(tree);
	return 0;
}