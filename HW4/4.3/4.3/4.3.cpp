#include <stdio.h>
#include <windows.h>

void begin()
{
	printf("\nВведите:\n 0 - выйти\n");
	printf(" 1 - добавить запись (имя и телефон)\n");
	printf(" 5 - сохранить текущие данные\n");
}

int countEntriesInBase()
{
	FILE *file = fopen("database.txt", "r");
	int countEntries = 0;
	if (!file)
	{
		return countEntries;
	}
	while (!feof(file))
	{
		if (fgetc(file) == '\n')
		{
			countEntries++;
		}
	}
	fclose(file);
	return countEntries;
}

const int baseSize = 100;
const int entryLength = 100;

void addEntry(char (&entries)[baseSize][entryLength], int &amountOfEntriesInBuffer)
{
	if (countEntriesInBase() + amountOfEntriesInBuffer < 100)
	{
		printf("Введите имя: ");
		char name[50] = {};
		scanf("%s", name);
		printf("Введите номер телефона: ");
		char phoneNumber[50] = {};
		scanf("%s", phoneNumber);

		strncat(entries[amountOfEntriesInBuffer], name, strlen(name));
		strcat(entries[amountOfEntriesInBuffer], " ");
		strncat(entries[amountOfEntriesInBuffer], phoneNumber, strlen(phoneNumber));
		amountOfEntriesInBuffer++;
	}
	else
	{
		printf("В базе данных закончилось место\n");
	}
}

void saveData(char (&entries)[100][100], int &amountOfEntriesInBuffer)
{
	if (amountOfEntriesInBuffer == 0)
	{
		printf("Новых записей нет\n");
	}
	else
	{
		FILE *file = fopen("database.txt", "a");
		for (int i = 0; i < amountOfEntriesInBuffer; ++i)
		{
			fprintf(file, "%s\n", entries[i]);
		}
		fclose(file);
		printf("Данные сохранены\n");
		amountOfEntriesInBuffer = 0;
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Телефонный справочник\n");
	int amountOfEntriesInBuffer = 0;
	char entriesInBuffer[baseSize][entryLength] = {};
	char input[100] = "";
	bool shouldGoOut = false;

	while (!shouldGoOut)
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
			shouldGoOut = true;
			break;
		case '1':
			addEntry(entriesInBuffer, amountOfEntriesInBuffer);
			break;
		case '5':
			saveData(entriesInBuffer, amountOfEntriesInBuffer);
			break;
		default:
			printf("Неверный ввод, попробуйте ещё раз.\n");
			break;
		}
	}
	return 0;
}