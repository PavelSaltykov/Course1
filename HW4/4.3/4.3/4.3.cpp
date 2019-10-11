#include <stdio.h>
#include <locale.h>
#include <windows.h>

void begin()
{
	printf("\nВведите:\n 0 - выйти\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Телефонный справочник\n");
	char input[100] = "";
	bool isExit = false;
	while (!isExit)
	{
		begin();
		scanf("%s", input);
		if (strlen(input) != 1)
		{
			printf("Неверный ввод, попробуйте ещё раз.\n");
			continue;
		}
		switch (input[0])
		{
		case '0':
			isExit = true;
			break;
		default:
			printf("Неверный ввод, попробуйте ещё раз.\n");
			break;
		}
	}
	return 0;
}