#include <stdio.h>
#include <windows.h>

void begin()
{
	printf("\nВведите:\n 0 - выйти\n");
	printf(" 1 - добавить запись (имя и телефон)\n");
	printf(" 2 - распечатать все имеющиеся записи\n");
	printf(" 3 - найти номер телефона по имени\n");
	printf(" 4 - найти имя по номеру телефону\n");
	printf(" 5 - сохранить текущие данные\n");
}

int countEntriesInBase()
{
	FILE *file = fopen("database.txt", "r");
	int countEntries = 0;
	if (file)
	{
		while (!feof(file))
		{
			if (fgetc(file) == '\n')
			{
				countEntries++;
			}
		}
		fclose(file);
	}
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
		printf("Введите номер телефона (без пробелов): ");
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

void printAllEntries()
{
	if (countEntriesInBase() == 0)
	{
		printf("Записей нет\n");
	}
	else
	{
		FILE *file = fopen("database.txt", "r");
		printf("\n");
		while (!feof(file))
		{
			char buffer[entryLength]="";
			fgets(buffer, entryLength, file);
			printf("%s", buffer);
		}
		fclose(file);
	}
}

const char *findPhone(const char fileName[], char enterednName[])
{
	FILE *file = fopen(fileName, "r");
	if (file)
	{
		while (!feof(file))
		{
			char nameInBuffer[50] = "";
			fscanf(file, "%s", nameInBuffer);
			static char phoneNumberInBuffer[50] = "";
			fscanf(file, "%s", phoneNumberInBuffer);
			if (strcmp(nameInBuffer, enterednName) == 0)
			{
				return phoneNumberInBuffer;
			}
		}
		fclose(file);
	}
	return "Номер телефона не найден";
}

const char *findName(const char fileName[], char enteredPhone[])
{
	FILE *file = fopen(fileName, "r");
	if (file)
	{
		while (!feof(file))
		{
			static char nameInBuffer[50] = "";
			fscanf(file, "%s", nameInBuffer);
			char phoneNumberInBuffer[50] = "";
			fscanf(file, "%s", phoneNumberInBuffer);
			if (strcmp(phoneNumberInBuffer, enteredPhone) == 0)
			{
				return nameInBuffer;
			}
		}
		fclose(file);
	}
	return "Имя не найдено";
}

void saveData(char (&entries)[baseSize][entryLength], int &amountOfEntriesInBuffer)
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
		memset(entries, 0, sizeof(entries));
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
		case '2':
			printAllEntries();
			break;
		case '3':
		{
			printf("Введите имя: ");
			char name[50] = "";
			scanf("%s", name);
			printf("%s\n", findPhone("database.txt", name));
			break;
		}
		case '4':
		{
			printf("Введите номер телефона: ");
			char phone[50] = "";
			scanf("%s", phone);
			printf("%s\n", findName("database.txt", phone));
			break;
		}
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