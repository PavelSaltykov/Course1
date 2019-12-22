#include <stdio.h>
#include <string.h>
#include "searchComments.h"

const int numberOfLines = 5;
const int numberOfColumns = 4;

bool createTable(int table[numberOfLines][numberOfColumns])
{
	FILE *fileWithTable = fopen("table.txt", "r");
	if (!fileWithTable)
	{
		printf("File with table not found\n");
		return false;
	}

	for (int i = 0; i < numberOfLines; ++i)
	{
		for (int j = 0; j < numberOfColumns; ++j)
		{
			if (i == 0)
			{
				fscanf(fileWithTable, "%c ", &table[i][j]);
				continue;
			}
			fscanf(fileWithTable, "%d", &table[i][j]);
		}
	}
	fclose(fileWithTable);
	return true;
}

int nextState(int currentState, char symbol, int table[numberOfLines][numberOfColumns])
{
	for (int i = 1; i < 3; ++i)
	{
		if (symbol == table[0][i])
		{
			return table[currentState + 1][i];
		}
	}
	return table[currentState + 1][3];	
}

char *comments(char *fileName)
{
	int table[numberOfLines][numberOfColumns] = {};
	if (!createTable(table))
	{
		return new char[0];
	}

	FILE *file = fopen(fileName, "r");
	if (!file)
	{
		printf("File not found\n");
		return new char[0];
	}

	char comments[10000] = {};
	char buffer[1000] = {};
	int state = 0;

	while (!feof(file))
	{
		char symbol = fgetc(file);
		
		if (state == 1 && symbol == table[0][2])
		{
			buffer[0] = '/';
		}

		if (state == 3 && symbol == table[0][1])
		{
			strcat(buffer, "/\n");
			strcat(comments, buffer);
			memset(buffer, 0, strlen(buffer));
		}

		state = nextState(state, symbol, table);

		if (state == 2 || state == 3)
		{
			buffer[strlen(buffer)] = symbol;
		}
	}
	return comments;
}