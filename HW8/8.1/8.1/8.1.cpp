
#include "tree.h"

int main()
{
	Tree *tree = createTree();
	char val[2] = "1";
	addValue(tree, 10, val); 
	addValue(tree, 5, val);
	addValue(tree, 12, val);
	addValue(tree, 3, val);
	addValue(tree, 6, val);
	char *v = getValue(tree, 7);
	const bool cont = contains(tree, 6);

	deleteTree(tree);
	return 0;
}