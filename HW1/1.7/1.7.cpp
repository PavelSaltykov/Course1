#include <stdio.h>
#include <math.h>

int main()
{
	printf("input x: ");
	int x;
	scanf("%d", &x);
	if (x > 1)
		for (int i = 2; i <= x; i++)
		{
			int counter = 0;
			for (int j = 2; j <= sqrt(i); j++)
				if (i % j == 0)
					counter++;
			if (counter == 0)
				printf("%d ", i);
		}
	else
		printf("x must be > 1");
	return 0;
}