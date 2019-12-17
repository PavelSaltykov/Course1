#include "list.h"
#include "symmetryCheck.h"
#include "tests.h"

bool test1()
{
	List *list = createList();
	addValue(list, 1);
	addValue(list, 2);
	addValue(list, 2);
	addValue(list, 1);
	const bool testPassed = isSymmetric(list);
	deleteList(list);
	return testPassed;
}

bool test2()
{
	List *list = createList();
	addValue(list, 1);
	addValue(list, 2);
	addValue(list, 3);
	addValue(list, 2);
	addValue(list, 1);
	const bool testPassed = isSymmetric(list);
	deleteList(list);
	return testPassed;
}

bool test3()
{
	List *list = createList();
	addValue(list, 1);
	addValue(list, 2);
	addValue(list, 3);
	addValue(list, 4);
	addValue(list, 2);
	addValue(list, 1);
	const bool testPassed = !isSymmetric(list);
	deleteList(list);
	return testPassed;
}

bool tests()
{
	return test1() && test2() && test3();
}