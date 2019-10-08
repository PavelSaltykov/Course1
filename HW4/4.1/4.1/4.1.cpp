#include <stdio.h>
#include <locale.h>

void convertToBinary(char number, int binaryNumber[]) 
{
	int bit = 0b10000000;
	for (int i = 0; i < 8; i++)
	{
		binaryNumber[i] = number & bit ? 1 : 0;
		bit = bit >> 1;
	}
}

int convertToDecimal(int binaryNumber[])
{
	int decimalNumber = 0;
	int powerOf2 = 1;
	bool isNegative = false;
	if (binaryNumber[0] == 1)
	{
		isNegative = true;
	}
	for (int i = 7; i >= 0; i--)
	{
		if (isNegative)
		{
			binaryNumber[i] = binaryNumber[i] == 1 ? 0 : 1;
		}
		decimalNumber += powerOf2 * binaryNumber[i];
		powerOf2 *= 2;
	}
	return isNegative ? -decimalNumber - 1 : decimalNumber;
}

bool rangeCheck(int number, int left, int right)
{
	return number >= left && number <= right;
}

void sumOfTwoBinaryNumbers(int firstNumber[], int secondNumber[], int sumOfNumbers[])
{
	int carryOver = 0;
	for (int i = 7; i >= 0; i--)
	{
		sumOfNumbers[i] = (carryOver + firstNumber[i] + secondNumber[i]) % 2;
		if (i != 0)
		{
			carryOver = (carryOver + firstNumber[i] + secondNumber[i]) / 2;
		}
	}
}

bool checkBinaryNumber(int binaryNumber[], int answer[])
{
	for (int i = 0; i < 8; i++)
	{
		if (binaryNumber[i] != answer[i])
		{
			return false;
		}
	}
	return true;
}

bool testConvertToBinary()
{
	int number = 5;
	int binaryNumber5[8] = {};
	convertToBinary(number, binaryNumber5);
	int answer5[8] = {0, 0, 0, 0, 0, 1, 0, 1};
	number = 127;
	int binaryNumber127[8] = {};
	convertToBinary(number, binaryNumber127);
	int answer127[8] = {0, 1, 1, 1, 1, 1, 1, 1};
	if (!checkBinaryNumber(binaryNumber5, answer5) && !checkBinaryNumber(binaryNumber127, answer127))
	{
		printf("Ошибка при переводе положительного числа в двоичное представление\n");
		return false;
	}

	number = -1;
	int binaryNumber1[8] = {};
	convertToBinary(number, binaryNumber1);
	int answer1[8] = {1, 1, 1, 1, 1, 1, 1, 1};
	number = -128;
	int binaryNumber128[8] = {};
	convertToBinary(number, binaryNumber128);
	int answer128[8] = {1, 0, 0, 0, 0, 0, 0, 0};
	if (!checkBinaryNumber(binaryNumber1, answer1) && !checkBinaryNumber(binaryNumber128, answer128))
	{
		printf("Ошибка при переводе отрицательного числа в двоичное представление\n");
		return false;
	}
	return true;
}

bool checkSum()
{
	int binaryNumber11[8] = {0, 0, 0, 0, 1, 0, 1, 1};
	int binaryNumber7[8] = {0, 0, 0, 0, 0, 1, 1, 1};
	int binarySum18[8] = {};
	sumOfTwoBinaryNumbers(binaryNumber11, binaryNumber7, binarySum18);
	int answer18[8] = {0, 0, 0, 1, 0, 0, 1, 0};
	if (!checkBinaryNumber(binarySum18, answer18))
	{
		printf("Ошибка при сложении чисел\n");
		return false;
	}

	int binaryNumber15[8] = {1, 1, 1, 1, 0, 0, 0, 1};
	int binaryNumber58[8] = {1, 1, 0, 0, 0, 1, 1, 0};
	int binarySum73[8] = {};
	sumOfTwoBinaryNumbers(binaryNumber15, binaryNumber58, binarySum73);
	int answer73[8] = {1, 0, 1, 1, 0, 1, 1, 1};
	if (!checkBinaryNumber(binarySum73, answer73))
	{
		printf("Ошибка при отрицательной сумме\n");
		return false;
	}
	return true;
}

bool checkConvertToDecimal()
{
	int binaryNumber63[8] = {0, 0, 1, 1, 1, 1, 1, 1};
	if (convertToDecimal(binaryNumber63) != 63)
	{
		printf("Ошибка при переводе положительного числа в десятичное представление\n");
		return false;
	}

	int binaryNumber85[8] = {1, 0, 1, 0, 1, 0, 1, 1};
	if (convertToDecimal(binaryNumber85) != -85)
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
	int left = -128;
	int right = 127;
	printf("Введите первое целое число (из диапазона от %d до %d): ", left, right);
	int temp;
	scanf("%d", &temp);
	if (temp >= 0 && rangeCheck(temp, left, right))
	{
		right -= temp;
	}
	else if(temp <= 0 && rangeCheck(temp, left, right))
	{
		left -= temp;
	}
	else
	{
		printf("Введённое число вне диапазона!");
		return 1;
	}
	const char number1 = temp;
	int binaryNumber1[8] = {};
	convertToBinary(number1, binaryNumber1);

	printf("Введите второе целое число (из диапазона от %d до %d): ", left, right);
	scanf("%d", &temp);
	if (!rangeCheck(temp, left, right))
	{
		printf("Введённое число вне диапазона!");
		return 1;
	}
	const char number2 = temp;
	int binaryNumber2[8] = {};
	convertToBinary(number2, binaryNumber2);

	printf("\nДвоичное представление в дополнительном коде:\n");
	printf("%d -> ", number1);
	for (int i = 0; i < 8; i++)
	{
		printf("%d", binaryNumber1[i]);
	}
	printf("\n%d -> ", number2);
	for (int i = 0; i < 8; i++)
	{
		printf("%d", binaryNumber2[i]);
	}
	
	printf("\n\nСумма этих чисел: ");
	int binarySum[8] = {};
	sumOfTwoBinaryNumbers(binaryNumber1, binaryNumber2, binarySum);
	for (int i = 0; i < 8; i++)
	{
		printf("%d", binarySum[i]);
	}
	printf(" -> %d\n", convertToDecimal(binarySum));
	return 0;
}