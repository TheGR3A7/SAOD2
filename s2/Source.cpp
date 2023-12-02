#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
������� ���������� ����� ���������������� �������� ��������� �����, �����, ����� ����������(., ; :!? ) � ����� �������������� ��������(+-*).
���������, ���������� �� ���� �����,
���������� � ��������� �����.��������� ������������ ������ ���������.������ ��������� � ��������� ����� ��������� ��������.
*/

bool isValidCharacter(char c) 
{
	return (c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= '0' && c <= '9') ||
		strchr(".,;:!? '\n' ' '", c) ||
		strchr("+-*/", c);
}

int main() 
{
	system("chcp 1251");
	FILE* file = fopen("program.txt", "r");

	if (file == NULL) 
	{
		perror("������ �������� �����");
		return 1;
	}

	char c;
	int lineNumber = 1;
	int charNumber = 0;

	while ((c = fgetc(file)) != EOF) 
	{
		charNumber++;
		if (!isValidCharacter(c)) 
		{
			printf("������ � ������ %d, ������ %d: ������������ ������ '%c'\n", lineNumber, charNumber, c);
			fclose(file);
			return 1;
		}
		if (c == '\n') 
		{
			lineNumber++;
			charNumber = 0;
		}
	}

	printf("����� ��������� ��������.\n");
	fclose(file);
	return 0;
}