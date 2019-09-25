#include <stdio.h>
#include <string.h>

int main()
{
	printf("input string S: ");
	char s[1000];
	scanf("%s", s);
	printf("input string S1: ");
	char s1[1000];
	scanf("%s", s1);
	int length = strlen(s);
	int length1 = strlen(s1);
	int counter = 0;
	for (int i = 0; i <= length - length1; i++)
	{
		for (int j = 0; j < length1; j++)
		{
			if (s[i + j] != s1[j])
			{
				break;
			}
			else if (j == length1 - 1)
			{
				counter++;
			}
		}
	}
	printf("Number of occurrences of S1 in S: %d", counter);
	return 0;
}