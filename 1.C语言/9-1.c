/*
 *程序名：编写代码打印7列13行的半个菱形。
		*
		* *
		* * *
		* * * *
		* * * * *
		* * * * * *
		* * * * * * *
		* * * * * *
		* * * * *
		* * * *
		* * *
		* *
		*
 *  作者：姜宗谷
 *  日期：2023年3月11日
 */


#include<stdio.h>


int main()
{
	int i = 0;		
	int j = 1;
	for (; i>=0; i += j)
	{
		for (int k=0; k <= i;++k)
		{
			putchar('*');
			putchar(32);	//空格
		}
		if (i == 6)
		{
			j = -1;
		}
		putchar('\n');
	}

	return 0;
}