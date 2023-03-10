/*
 * 程序名：使用C语言pow函数代替内层循环，实现十六进制和二进制数字打印。
 *   作者：姜宗谷
 *   时间：2023年3月10日 13:48:42
*/


#include<stdio.h>
#include<math.h>


int main()
{
	int nNum = 5666666;
	int i = 31;
	
	//十进制转二进制
	while (i >= 0)
	{
		int j=pow(2.0, i);
		printf("%d", nNum /j % 2);
		if (0 == i % 4)
			putchar(32);
		--i;
	}

	putchar('\n');
	//////十进制转十六进制
	i = 7;	//十进制的16相当于十六进制的F,二进制占4位。
	while (i >= 0)
	{
		int j = pow(16.0, i);
		int m=nNum / j % 16;
		putchar(m < 10 ? m+'0' : m + 55);
		--i;
	}


}

