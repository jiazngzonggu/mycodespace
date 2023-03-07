#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct
{
	char name[40];
	int age;
}person,person_copy;

int main()
{
	//void *memcpy(void* destination, const void* source, size_t num);
	
	//using memcpy to copy string:
	//char myname[] = "Pierre de Fermat";
	//memcpy(person.name, myname, strlen(myname) + 1);
	//person.age = 46;

	////using memcpy to stucture;
	//memcpy(&person_copy, &person, sizeof(person));
	//printf("person_copy:%s,%d\n", person_copy.name, person_copy.age);


	//void* memmove(void*destination,const void* source,size_t num);
	/*char str[] = "memmove can be very useful.....";
	memmove(str + 20, str + 15, 11);
	puts(str);*/

	//char* strcpy(char* destination,const char*source);
	/*char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	strcpy(str2, str1);
	strcpy(str3, "copy successful");
	printf("str1:%s\nstr2:%s\nstr3:%s\n", str1, str2, str3);*/

		
	//char* strcat(char* destination,const char * source);
	/*char str[80];
	strcpy(str, "these ");
	strcat(str, "string ");
	strcat(str, "are ");
	strcat(str, "concatenated.");
	puts(str);*/


	//char* strncat(char* destination,const char* source,size_t num);
	/*char str1[20];
	char str2[20];
	strcpy(str1, "To be ");
	strcpy(str2, "or not to be");
	strncat(str1, str2, 6);
	puts(str1);*/


	//int memcmp(const void* ptr1,const void* ptr2,zise_t num)
	/*char buffer1[]="DWgaOtP12df0";
	char buffer2[]= "DWGAOTP12DF0";

	int n;
	n = memcmp(buffer1, buffer2, sizeof(buffer1));
	if (n > 0)
		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
	else if (n < 0)
		printf("'%s' is less than '%s'.\n", buffer1, buffer2);*/
	

	//int strcmp(const char* str1, const char *str2);
	//char key[] = "apple";
	//char buffer[80];
	//do
	//{
	//	printf("Guess my favorite fruit?");
	//	fflush(stdout);
	//	scanf("%79s", buffer);

	//} while (strcmp(key, buffer) != 0);
	//puts("Correct answer!");

	//int strncmp(const char* str1,const char *str2, size_t num);
	/*char str[][15] = { "R2D2","C3PO","R1A6" };
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n < 3; n++)
	{
		if (strncmp(str[n], "R2xx", 2) == 0)
		{
			printf("found %s\n", str[n]);
		}
	}*/





	return 0;
}