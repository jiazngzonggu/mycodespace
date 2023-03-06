#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>     /* atof */
#include <math.h>       /* sin */
#include <time.h>       /* time */

void fnExit1(void)
{
		puts("Exit function 1.");
}

void fnExit2(void)
{
	puts("Exit function 2.");
}

int main()
{
	//double atof(const char* str)
	/*double n, m;
	double pi = 3.141592635;
	char buffer[256];
	printf("Enter degrees:");
	fgets(buffer, 256, stdin);
	n = atof(buffer);
	m = sin(n*pi / 180);
	printf("The sine of %f degrees is %f\n", n, m);*/

	//int atoi(const char* str);
	/*int i;
	double n, m;
	double pi = 3.141592635;
	char buffer[256];
	printf("Enter degrees:");
	fgets(buffer, 256, stdin);
	i = atoi(buffer);
	printf("The value entered is %d.Its double is %d", i, i * 2);*/

	//long int atol(const char* str)
	/*long int li;
	char buffer[256];
	printf("Enter a long number:");
	fgets(buffer, 256, stdin);
	li = atol(buffer);
	printf("The value entered is %ld,Its double is %ld.\n", li, li * 2);*/


	//long long int atoll(const char* str);
	/*long long int lli;
	char buffer[256];
	printf("Enter a long number:");
	fgets(buffer, 256, stdin);
	lli = atoll(buffer);
	printf("The value entered is %lld.Its double is %lld.\n", lli, lli * 2);*/

	//double strtod(const char* str,char** endptr);
	/*char sz0rbits[] = "365.24 29.53";
	char* pEnd;
	double d1, d2;
	d1 = strtod(sz0rbits, &pEnd);
	d2 = strtod(pEnd, NULL);
	printf("The moon completes %.2f orbits per Earth year.\n", d1 / d2);*/

	//float strtof(const char* str,char** endptr);
	/*char sz0rbits[] = "686.97 365.24";
	char* pEnd;
	float f1, f2;
	f1 = strtof(sz0rbits, &pEnd);
	f2 = strtof(pEnd, NULL);
	printf("One martian year takes %.2f Earth years.\n", f1 / f2);*/


	//long double strold(const char* str,char** endptr);
	/*char sz0rbits[] = "90613.30553556 o365.24";
	char* pEnd;
	long double f1, f2;
	f1 = strtold(sz0rbits, &pEnd);
	f2 = strtold(sz0rbits, NULL);
	printf("%s\n", pEnd);
	printf("Pluto takes %.2Lf years to complete an orbit.\n", f1 / f2);*/

	//long long int strtoll(const char* str,char** endptr,int base)
	/*char szNumbers[] = "1856892505 17b00a12b -01100011010110000010001101100 0x6fffff";
	char* pEnd;
	long long int lli1, lli2, lli3, lli4;
	lli1 = strtoll(szNumbers, &pEnd, 10);
	lli2 = strtoll(pEnd, &pEnd, 16);
	lli3 = strtoll(pEnd, &pEnd, 2);
	lli4 = strtoll(pEnd, &pEnd, 0);
	printf("The decimal equivalents are:%lld,%lld,%lld and %lld.\n", lli1, lli2, lli3, lli4);
*/

	//unsigned long int strtoul(const char* str,char** endptr,int base);
	/*char buffer[256];
	unsigned long ul;
	printf("Enter an unsigned number:" );
	fgets(buffer, 256, stdin);
	ul = strtoul(buffer, NULL, 0);
	printf("Value entered:%lu,Its double:%lu\n", ul, ul * 2);*/


	//usigned long long int strtoll(const char* str,char** endptr,int base)
	/*char szNumbers[] = "250068492 7b06af00 1100011011110101010001100000 0x6fffff";
	char* pEnd;
	unsigned long long int ulli1, ulli2, ulli3, ulli4;
	ulli1 = strtoull(szNumbers, &pEnd, 10);
	ulli2 = strtoull(pEnd, &pEnd, 16);
	ulli3 = strtoull(pEnd, &pEnd, 2);
	ulli4 = strtoll(pEnd, NULL, 0);
	printf("The decimal equivalents are:%llu,%llu,%llu and %llu.\n", ulli1, ulli2, ulli3, ulli4);
*/

	//int rand(void)
	//int iSecret, iGuess;

	//initalize random seed
	//srand(time(NULL));

	//generate secret number between 1 and 10;
	/*iSecret = rand() % 10 + 1;
	do
	{
		printf("Guess the number(1 to 10):");
		scanf("%d", &iGuess);
		if (iSecret < iGuess)
			puts("The secret number is lower");
		else
			puts("The secret number is higher");

	} while (iSecret != iGuess);

	puts("Congratulations!");*/


	//void* calloc(size_t num,size_t size);
	/*int i, n;
	int* pData;
	printf("Amount of number to be entered:");
	scanf("%d", &i);
	pData = (int*)calloc(i, sizeof(int));
	if (pData == NULL) exit(1);
	for (n = 0; n < i; n++)
	{
		printf("Enter number #%d:", n + 1);
		scanf("%d", &pData[n]);
	}
	printf("You have entered:");
	for (n = 0; n < i; n++)
	{
		printf("%d", pData[n]);
	}
	free(pData);*/

	//void free(void* ptr);
	/*int *buffer1, *buffer2, *buffer3;
	buffer1 = (int*)malloc(100 * sizeof(int));
	buffer2 = (int*)calloc(100, sizeof(int));
	buffer3 = (int*)realloc(buffer2, 500 * sizeof(int));
	free(buffer1);
	free(buffer3);*/
	
	//void abort(void)	
	/*FILE* pFile;
	pFile = fopen("myfile.txt", "r");
	if (pFile == NULL)
	{
		fputs("error opening file\n", stderr);
		abort();
	}
	fclose(pFile);*/
	
	//int atexit(void(*func)(void));
	
	/*atexit(fnExit1);
	atexit(fnExit2);
	puts("Main function.");*/

	





















	return 0;
}