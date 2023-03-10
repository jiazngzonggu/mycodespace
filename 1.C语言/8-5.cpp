/*
 * 程序名：打印13行13列完整的菱形。
			  *
			* * *
		  * * * * *
		* * * * * * *
	  * * * * * * * * *
	* * * * * * * * * * *
  * * * * * * * * * * * * *
	* * * * * * * * * * *
	  * * * * * * * * *
		* * * * * * *
		  * * * * *
			* * *
			  *

 *   作者：姜宗谷
 *   时间：2023年3月10日
*/

#include<stdio.h>
int main()
{
	int i = 0; int m = 11;
	for (; i < 13; ++i)
	{
		
		if (i < 7)
		{//打印空格
			for (int j = 0; j < 7 - i; j++)
			{
				putchar(32);
			}
		 //打印列数
			for (int k = 0; k < 2 * (1+i) - 1; ++k)
			{
				putchar('*');
			}
		}
		else
		{
			//打印空格
			for (int j = 0; j < (i) - 5; ++j)
			{
				putchar(32);
			}
			//打印列数
			for (int k = 0; k < m; ++k)
			{
				putchar('*');
			}
			m -= 2;
		}

	putchar('\n');
	}



	return 0;
}