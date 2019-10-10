/*
Формат char* strcat(char* dest, const char* src).
Функция приписывает строку src к строке dest.
*/

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;

// Моя функция объединение строк
char *myStrcat(char *str1, const char *str2);

int main(){

	// Вовод и вывод русских символов 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("%s\n", "(1)Вывод встроенной функции 'strcat(char* dest, const char* src)'");
	char app[1024] = "Первая строка ";
	char dst[1024] = "Вторая строка";
	printf("%s\n", app);
	printf("%s\n", dst );
	strcat(app, dst);
	printf("%s\n", "");

	// Вывод массива dst на консоль
	printf("app(strcat): %s\n", app);
	printf("%s\n\n", "-------------------------------------");
	
	printf("%s\n", "(2)Вывод моей функции 'myStrcat(char *str1, const char *str2)'");
	char app1[1024] = "Моя Первая строка ";
	char dst1[1024] = "Моя Вторая строка";

	printf("%s\n", app1);
	printf("%s\n", dst1);
	myStrcat(app1, dst1);

	printf("%s\n", "");	
	printf("app(myStrcat): %s\n", app1);
	printf("%s\n\n", "-------------------------------------");
	system("pause");
} // main

char *myStrcat(char *str1, const char *str2){

	char* begin = str1;
	while (*str1)
		str1++;

	while (*str1++ = *str2++)
	*str1 = '\0';

	return begin;
} // myStrcat


