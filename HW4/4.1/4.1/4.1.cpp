#include <stdio.h>
#include <locale.h>

const int size = sizeof(int) * 8;

void convertToBinary(int number, int binaryNumber[]) 
{
	int bit = 1;
	for (int i = size - 1; i >= 0; i--)
	{
		binaryNumber[i] = (number & bit) ? 1 : 0;
		bit = bit << 1;
	}
}

int convertToDecimal(int binaryNumber[])
{
	int decimalNumber = 0;
	int powerOf2 = 1;
	for (int i = size - 1; i >= 0; i--)
	{
		decimalNumber += powerOf2 * binaryNumber[i];
		powerOf2 *= 2;
	}
	return decimalNumber;
}

void sumOfTwoBinaryNumbers(int firstNumber[], int secondNumber[], int sumOfNumbers[])
{
	int carryOver = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		sumOfNumbers[i] = (carryOver + firstNumber[i] + secondNumber[i]) % 2;
		carryOver = (carryOver + firstNumber[i] + secondNumber[i]) / 2;
	}
}

bool checkBinaryNumber(int binaryNumber[], int answer[])
{
	for (int i = 0; i < size; i++)
	{
		if (binaryNumber[i] != answer[i])
		{
			return false;
		}
	}
	return true;
}

void printOfBinaryNumber(int array[])
{
	for (int i = 0; i < size; i++)
	{
		if (i % 8 == 0)
		{
			printf(" ");
		}
		printf("%d", array[i]);
	}
}

bool testConvertToBinary()
{
	int number = 515;
	int binaryNumber515[size] = {};
	convertToBinary(number, binaryNumber515);
	int answer515[size] = {};
	answer515[22] = 1;
	answer515[30] = 1;
	answer515[31] = 1;
	if (!checkBinaryNumber(binaryNumber515, answer515))
	{
		printf("Ошибка при переводе положительного числа в двоичное представление\n");
		return false;
	}

	number = -2057;
	int binaryNumber2057[size] = {};
	convertToBinary(number, binaryNumber2057);
	int answer2057[size] = {};
	for (int i = 0; i < size; i++)
	{
		answer2057[i] = (i == 20 || i == 28) ? 0 : 1;
	}
	if (!checkBinaryNumber(binaryNumber2057, answer2057))
	{
		printf("Ошибка при переводе отрицательного числа в двоичное представление\n");
		return false;
	}
	return true;
}

bool checkSum()
{
	int binaryNumber4600[size] = {};
	binaryNumber4600[19] = 1;
	for (int i = 23; i < 29; i++)
	{
		binaryNumber4600[i] = 1;
	}
	int binaryNumber5688[size] = {};
	for (int i = 0; i < 29; i++)
	{
		binaryNumber5688[i] = (i == 19 || i == 21 || i == 22 || i == 26 || i == 27) ? 0 : 1;
	}

	int binarySum1088[size] = {};
	sumOfTwoBinaryNumbers(binaryNumber4600, binaryNumber5688, binarySum1088);
	int answer1088[size] = {};
	for (int i = 0; i < 26; i++)
	{
		answer1088[i] = (i == 21) ? 0 : 1;
	}

	if (!checkBinaryNumber(binarySum1088, answer1088))
	{
		printf("Ошибка при сложении чисел\n");
		return false;
	}
	return true;
}

bool checkConvertToDecimal()
{
	int binaryNumber4600[size] = {};
	binaryNumber4600[19] = 1;
	for (int i = 23; i < 29; i++)
	{
		binaryNumber4600[i] = 1;
	}
	if (convertToDecimal(binaryNumber4600) != 4600)
	{
		printf("Ошибка при переводе положительного числа в десятичное представление\n");
		return false;
	}

	int binaryNumber1088[size] = {};
	for (int i = 0; i < 26; i++)
	{
		binaryNumber1088[i] = (i == 21) ? 0 : 1;
	}
	if (convertToDecimal(binaryNumber1088) != -1088)
	{
		printf("Ошибка при переводе отрицательного числа в десятичное представление\n");
		return false;
	}
	return true;
}

bool tests()
{
	return testConvertToBinary() && checkSum() && checkConvertToDecimal();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	if (!tests())
	{
		return 1;
	}
	printf("Введите первое целое число: ");
	int number1 = 0;
	scanf("%d", &number1);
	int binaryNumber1[size] = {};
	convertToBinary(number1, binaryNumber1);

	printf("Введите второе целое число: ");
	int number2 = 0;
	scanf("%d", &number2);
	int binaryNumber2[size] = {};
	convertToBinary(number2, binaryNumber2);

	printf("\nДвоичное представление в дополнительном коде:\n");
	printf("%d ->", number1);
	printOfBinaryNumber(binaryNumber1);
	printf("\n%d ->", number2);
	printOfBinaryNumber(binaryNumber2);

	printf("\n\nСумма:");
	int binarySum[size] = {};
	sumOfTwoBinaryNumbers(binaryNumber1, binaryNumber2, binarySum);
	printOfBinaryNumber(binarySum);

	printf(" -> %d\n", convertToDecimal(binarySum));
	return 0;
}