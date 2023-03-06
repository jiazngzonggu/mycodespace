#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include<wchar.h>
int main()
{
	//isanum(int c);check if character is alphanumberic
	/*int i;
	char str[] = "cC3p0...";
	i = 0;
	while (isalnum(str[i])) i++;
	printf("The first %d characters are alphanumeric.\n", i);*/

	//isalpha(int c);check if character is alphabetic
	/*int i = 0;
	char str[] = "C5++";
	while(str[i])
	{
		if (isalpha(str[i]))
			printf("character %c is alphabetc\n.", str[i]);
		else
			printf("character %c is not alphabetc\n.",str[i]);
		++i;
	}*/


	//int isblank(int c); check if character is blank
	/*char c;
	int i = 0;
	char str[] = "Example sentence to test is blank\n";
	while (str[i])
	{
		c = str[i];
		if (isblank(c))  c = '\n';
		putchar(c);
		i++;
	}*/

	//int iscntrl(int c); check if character is a control character
	/*int i = 0;
	char str[] = "first line \n seconed line \n";
	while (!iscntrl(str[i]))
	{
		putchar(str[i]);
		++i;
	}*/

	//int isdigit(int c); check if character is decimal digit
	/*char str[] = "17776ad";
	int year;
	if (isdigit(str[0]))
	{
		year = atoi(str);
		printf("The year that followed %d was %d.\n", year, year + 1);
	}*/


	//int ispraph(int c);
	/*FILE *pFile;
	int c;
	pFile = fopen("myfile.txt", "r");
	if (pFile)
	{
		do
		{
			c = fgetc(pFile);
			if (isgraph(c)) putchar(c);
		} while (c != EOF);
			fclose(pFile);

	}*/

	//int islower(int c);
	/*int i = 0;
	char str[] = "Test String.\n";
	char c;
	while (str[i])
	{
		c = str[i];
		if (islower(c))
			c = toupper(c);
		putchar(c);
		i++;
	}*/

	//int isprint(int c)
	/*int i = 0;
	char str[] = "first line \n second line \n";
	while (isprint(str[i]))
	{
		putchar(str[i]);
		i++;
	}
*/

	//int ispunct(int c);
	/*int i = 0;
	int cx = 0;
	char str[] = "Hello,welcome!";
	while (str[i])
	{
		if (ispunct(str[i])) cx++;
		i++;
	}
	printf("Sentence contains %d punctuation characters.\n", cx);
*/


	//int space(int c);
	/*char c;
	int i = 0;
	char str[] = "Example sentence to test isspace\n";
	while (str[i])
	{
		c = str[i];
		if (isspace(c)) c = '\n';
		putchar(c);
		++i;
	}*/

	//int isupper(int c);
	/*int i = 0;
	char str[] = "Test String.\n";
	char c;
	while (str[i])
	{
		c = str[i];
		if (isupper(c)) c = tolower(c);
		putchar(c);
		++i;
	}
*/

	//int isxdigit(int c)
	/*char str[] = "ffff";
	long int number;
	if (isxdigit(str[0]))
	{
		number = strtol(str, NULL, 16);
		printf("The hexadecimal number %lx is %ld.\n", number, number);
	}*/

	//int tolower(int c);
	/*int i = 0;
	char str[] = "Test String.\n";
	char c;
	while (str[i])
	{
		c = str[i];
		putchar(tolower(c));
		i++;
	}*/
	
	//int toupper(int c)
	/*int i = 0;
	char str[] = "Test String.\n";
	char c;
	while (str[i])
	{
		c = str[i];
		putchar(toupper(c));
		i++;
	}*/
	








	return 0;
}