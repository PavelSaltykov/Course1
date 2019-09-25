#include <stdio.h>

int main()
{
	int counterOfSum[28] = {};
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				counterOfSum[i + j + k]++;
	int counterOfTickets = 0;
	for (int i = 0; i < 28; i++)
	{
		counterOfSum[i] = counterOfSum[i] * counterOfSum[i];
		counterOfTickets = counterOfTickets + counterOfSum[i];
	}
	printf("Amount of lucky tickets: %d", counterOfTickets);
	return 0;
}