#include <stdio.h>

int main()
{
	printf("input x: ");
	int x;
	scanf("%d", &x);
	int squareOfx = x * x;
	int result = (squareOfx + x) * (squareOfx + 1) + 1;
	printf("x^4 + x^3 + x^2 + x + 1 = %d", result);
	return 0;
}