#include <string.h>
#include <climits>
#include "RabinKarp.h"

const int q = INT_MAX;
const int x = 3;

int polynomialHash(char *string, int length, int *helpArray)
{
	int result = 0;
	for (int i = 0; i < length; ++i)
	{
		result = (result + string[i] * helpArray[length - i - 1]) % q;
	}
	return result;
}

int ringHash(int helpHash, char newSymbol)
{
	return (helpHash * x + newSymbol) % q;
}

int rabinKarp(char *string, char *substring)
{
	const int substringLength = strlen(substring);
	
	int *degreesOfX = new int[substringLength];
	int help = 1;
	for (int i = 0; i < substringLength; ++i)
	{
		degreesOfX[i] = help;
		help *= x;
	}
	help /= x;

	const int substringHash = polynomialHash(substring, substringLength, degreesOfX);
	int helpHash = polynomialHash(string, substringLength, degreesOfX);
	delete[] degreesOfX;

	const int stringLength = strlen(string);
	for (int i = 0; i < stringLength - substringLength + 1; ++i)
	{
		if (helpHash == substringHash)
		{
			for (int j = 0; substring[j] != '\0'; ++j)
			{
				if (string[i + j] != substring[j])
				{
					break;
				}
				if (substring[j + 1] == '\0')
				{
					return i;
				}
			}
		}
		const int tempHash = helpHash - string[i] * help % q;
		helpHash = ringHash(tempHash, string[i + substringLength]);
	}
	return -1;
}