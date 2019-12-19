#include "list.h"
#include "symmetryCheck.h"

List *reverse(List *list)
{
	List *reverseList = createList();
	const int length = listLength(list);
	for (int i = length - 1; i >= 0; --i)
	{
		const int value = returnValue(list, i);
		addValue(reverseList, value);
	}
	return reverseList;
}

bool isSymmetric(List *list)
{
	List *reverseList = reverse(list);
	const bool isSymmetric = compareLists(list, reverseList);
	deleteList(reverseList);
	return isSymmetric;
}