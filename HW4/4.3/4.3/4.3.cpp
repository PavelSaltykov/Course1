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

int countEntriesInBase(const char fileName[])
{
	FILE *file = fopen(fileName, "r");
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
	if (countEntriesInBase("database.txt") + amountOfEntriesInBuffer < 100)
	{
		printf("Введите имя: ");
		char name[50] = "";
		scanf("%s", name);
		printf("Введите номер телефона (без пробелов): ");
		char phoneNumber[50] = "";
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
	if (countEntriesInBase("database.txt") == 0)
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

const char *findPhone(const char fileName[], char enteredName[])
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
			if (strcmp(nameInBuffer, enteredName) == 0)
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

bool saveData(char (&entries)[baseSize][entryLength], int &amountOfEntriesInBuffer, const char fileName[])
{
	if (amountOfEntriesInBuffer == 0)
	{
		return false;
	}
	else
	{
		FILE *file = fopen(fileName, "a");
		for (int i = 0; i < amountOfEntriesInBuffer; ++i)
		{
			fprintf(file, "%s\n", entries[i]);
		}
		fclose(file);
		amountOfEntriesInBuffer = 0;
		memset(entries, 0, sizeof(entries));
	}
	return true;
}

bool testSavingData()
{
	char entries[baseSize][entryLength] = 
	{
		"Петя 346-32-87", 
		"Вася 89102347856", 
		"Оля 1233445", 
		"Вова +7(911)777-50-05"
	};
	int amountOfEntries = 4;
	const char fileName[9] = "test.txt";
	return saveData(entries, amountOfEntries, fileName) && countEntriesInBase(fileName) == 4;
}

bool testPhoneSearch()
{
	char name[5] = "Оля";
	const char phone[8] = "1233445";
	const char *result = findPhone("test.txt", name);
	return strcmp(result, phone) == 0;
}

bool testNameSearch()
{
	const char name[5] = "Вова";
	char phone[17] = "+7(911)777-50-05";
	const char *result = findName("test.txt", phone);
	return strcmp(result, name) == 0;
}

bool tests()
{
	FILE *file = fopen("test.txt", "w");
	fclose(file);
	if (!testSavingData())
	{
		printf("Ошибка в сохранении данных\n");
		return false;
	}
	if (!testPhoneSearch())
	{
		printf("Ошибка в поиске номера телефона\n");
		return false;
	}
	if (!testNameSearch())
	{
		printf("Ошибка в поиске имени\n");
		return false;
	}
	return true;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	if (!tests())
	{
		return 1;
	}
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
			if (saveData(entriesInBuffer, amountOfEntriesInBuffer, "database.txt"))
			{
				printf("Данные сохранены\n");
			}
			else
			{
				printf("Новых записей нет\n");
			}
			break;
		default:
			printf("Неверный ввод, попробуйте ещё раз.\n");
			break;
		}
	}
	return 0;
}