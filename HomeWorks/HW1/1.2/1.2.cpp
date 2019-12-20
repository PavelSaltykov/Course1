#include <stdio.h>
#include <math.h>

int main()
{
	printf("input a: ");
	int a;
	scanf("%d", &a);
	printf("input b: ");
	int b;
	scanf("%d", &b);
	int result = 0;
	int moduleOfa = abs(a);
	int moduleOfb = abs(b);
	if (b == 0)
	{
		printf("Division is impossible");
	}
	else
	{
		while ((moduleOfa - result * moduleOfb >= moduleOfb) || (a < 0 && moduleOfa > result * moduleOfb))
		{
			result++;
		}
		if ((a > 0) ^ (b > 0))
		{
			result = -result;
		}

		printf("result: %d", result);
	}
	return 0;
}