#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Алфавит некоторого языка программирования включает латинские буквы, цифры, знаки пунктуации(., ; :!? ) и языки арифметических операций(+-*).
Программа, написанная на этом языке,
содержится в текстовом файле.Проверить допустимость текста программы.Выдать сообщение с указанием места ошибочных символов.
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
		perror("Ошибка открытия файла");
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
			printf("Ошибка в строке %d, символ %d: недопустимый символ '%c'\n", lineNumber, charNumber, c);
			fclose(file);
			return 1;
		}
		if (c == '\n') 
		{
			lineNumber++;
			charNumber = 0;
		}
	}

	printf("Текст программы допустим.\n");
	fclose(file);
	return 0;
}