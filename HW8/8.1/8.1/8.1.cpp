#include <stdio.h>
#include "tree.h"

void begin()
{
	printf("Enter:\n 0 - log off\n");
	printf(" 1 - Add value by key\n");
	printf(" 2 - Get value by key\n");
	printf(" 3 - Check key availability\n");
	printf(" 4 - Delete key and value\n");
}

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

	int input = 0;
	bool shouldGoOut = false;
	Tree *tree = createTree();
	while (!shouldGoOut)
	{
		begin();
		scanf("%d", &input);
		int key = 0;
		switch (input)
		{
		case 0:
			shouldGoOut = true;
			break;
		case 1:
		{
			printf("Enter key: ");
			scanf("%d", &key);

			printf("Enter value: ");
			char value[1000] = {};
			scanf("%s", value);

			addValue(tree, key, value);
			break;
		}
		case 2:
		{
			printf("Enter key: ");
			scanf("%d", &key);

			char *value = getValue(tree, key);
			printf((value == nullptr) ? "Value for this key not found" : "Value: %s", value);
			printf("\n");
			delete value;
			break;
		}
		case 3:
			printf("Enter key: ");
			scanf("%d", &key);

			printf(contains(tree, key) ? "The key exists" : "The key does not exist");			
			printf("\n");
			break;
		case 4:
			printf("Enter key: ");
			scanf("%d", &key);

			deleteValue(tree, key);
			break;
		default:
			printf("Invalid input, try again\n");
			break;
		}
		printf("\n");
	}
	deleteTree(tree);
	return 0;
}