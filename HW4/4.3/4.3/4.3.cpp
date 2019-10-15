#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Entry
{
	char name[50];
	char phone[50];
};

int countEntriesInBuffer(Entry entries[], char const fileName[])
{
	FILE *file = fopen(fileName, "a+");
	int entriesCounter = 0;
	while (!feof(file))
	{
		if (fscanf(file, "%[^-]%*c%*c", entries[entriesCounter].name) != EOF)
		{
			const int length = strlen(entries[entriesCounter].name);
			entries[entriesCounter].name[length - 1] = '\0';
			fscanf(file, "%[^\n]%*c", entries[entriesCounter].phone);
			++entriesCounter;
		}
	}
	fclose(file);
	return entriesCounter;
}

void begin()
{
	printf("\nВведите:\n 0 - выйти\n");
	printf(" 1 - добавить запись (имя и телефон)\n");
	printf(" 2 - распечатать все имеющиеся записи\n");
	printf(" 3 - найти номер телефона по имени\n");
	printf(" 4 - найти имя по номеру телефону\n");
	printf(" 5 - сохранить текущие данные\n");
}

void addEntry(Entry entries[], int &amountOfEntriesInBuffer)
{
	if (amountOfEntriesInBuffer < 100)
	{
		printf("Введите имя: ");
		scanf("\n%[^\n]", entries[amountOfEntriesInBuffer].name);
		printf("Введите номер телефона: ");
		scanf("\n%[^\n]", entries[amountOfEntriesInBuffer].phone);
		++amountOfEntriesInBuffer;
	}
	else
	{
		printf("В базе данных закончилось место\n");
	}
}

void printAllEntries(Entry entries[], int amountOfEntriesInBuffer)
{
	if (amountOfEntriesInBuffer == 0)
	{
		printf("Записей нет\n");
	}
	else
	{
		for (int i = 0; i < amountOfEntriesInBuffer; ++i)
		{
			printf("%s - %s\n", entries[i].name, entries[i].phone);
		}
	}
}

const char *findPhone(Entry entries[], int amountOfEntriesInBuffer, char enteredName[])
{
	for (int i = 0; i < amountOfEntriesInBuffer; ++i)
	{
		if (strcmp(entries[i].name, enteredName) == 0)
		{
			return entries[i].phone;
		}
	}
	return "Номер телефона не найден";
}

const char *findName(Entry entries[], int amountOfEntriesInBuffer, char enteredPhone[])
{
	for (int i = 0; i < amountOfEntriesInBuffer; ++i)
	{
		if (strcmp(entries[i].phone, enteredPhone) == 0)
		{
			return entries[i].name;
		}
	}
	return "Имя не найдено";
}

void saveData(Entry entries[], int amountOfEntriesInBuffer)
{
	if (amountOfEntriesInBuffer == 0)
	{
		printf("Записей нет\n");
	}
	else
	{
		FILE *file = fopen("database.txt", "w");
		for (int i = 0; i < amountOfEntriesInBuffer; ++i)
		{
			fprintf(file, "%s - %s\n", entries[i].name, entries[i].phone);
		}
		fclose(file);
		printf("Данные сохранены\n");
	}		
}

bool fileReadTest(Entry testEntries[])
{
	if (countEntriesInBuffer(testEntries, "test.txt") == 4)
	{
		return strcmp(testEntries[0].name, "Петя Иванов") == 0 &&
			strcmp(testEntries[0].phone, "346-32-87") == 0 &&
			strcmp(testEntries[1].name, "Вася") == 0 &&
			strcmp(testEntries[1].phone, "89102347856") == 0 &&
			strcmp(testEntries[2].name, "Оля") == 0 &&
			strcmp(testEntries[2].phone, "123 34 45") == 0 &&
			strcmp(testEntries[3].name, "Вова") == 0 &&
			strcmp(testEntries[3].phone, "+7(911)777-50-05") == 0;
	}
	return false;
}

bool testPhoneSearch(Entry testEntries[])
{
	char name[12] = "Петя Иванов";
	const char phone[10] = "346-32-87";
	const char *result = findPhone(testEntries, 4, name);
	return strcmp(result, phone) == 0;
}

bool testNameSearch(Entry testEntries[])
{
	const char name[4] = "Оля";
	char phone[10] = "123 34 45";
	const char *result = findName(testEntries, 4, phone);
	return strcmp(result, name) == 0;
}

bool tests()
{
	Entry test[20] = {};
	if (!fileReadTest(test))
	{
		printf("Ошибка в чтении файла\n");
		return false;
	}
	if (!testPhoneSearch(test))
	{
		printf("Ошибка в поиске номера телефона\n");
		return false;
	}
	if (!testNameSearch(test))
	{
		printf("Ошибка в поиске имени\n");
		return false;
	}
return true;
}

int main()
{
	system("chcp 1251>nul");
	if (!tests())
	{
		return 1;
	}
	const int baseSize = 100;
	Entry buffer[baseSize] = {};
	int entriesCounter = countEntriesInBuffer(buffer, "database.txt");
	
	char input[100] = {};
	bool shouldGoOut = false;
	printf("Телефонный справочник\n");
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
			addEntry(buffer, entriesCounter);
			break;
		case '2':
			printAllEntries(buffer, entriesCounter);
			break;
		case '3':
		{
			printf("Введите имя: ");
			char name[50] = {};
			scanf("\n%[^\n]", name);
			printf("%s\n", findPhone(buffer, entriesCounter, name));
			break;
		}
		case '4':
		{
			printf("Введите номер телефона: ");
			char phone[50] = {};
			scanf("\n%[^\n]", phone);
			printf("%s\n", findName(buffer, entriesCounter, phone));
			break;
		}
		case '5':
			saveData(buffer, entriesCounter);
			break;
		default:
			printf("Неверный ввод, попробуйте ещё раз.\n");
			break;
		}
	}
	return 0;
}