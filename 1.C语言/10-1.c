/*
 *程序名：1、打印十进制或十六进制时可以不用%取余数：a)而是先左移去除高位再右移。注意unsigned类型。
 *  作者：姜宗谷
 *  日期：2023年3月13日
*/


#include<stdio.h>

int main()
{
	int k = 66666666;
	int j = 0;
	while (j < 32)
	{
		unsigned int i = k;
		i <<= j;
		i >>= 31;
		printf("%d", i);
		if ((j + 1) % 4 == 0)
			putchar(32);
		++j;
	}

	return 0;
}