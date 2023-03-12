/*
 *程序名：编写代码打印用户录入的一个十六进制，不使用%x和%X,使用pow函数。
 *  作者：姜宗谷
 *  日期：2023年3月11日
 */

#include<stdio.h>
#include<math.h>

int main()
{
	//提示用户输入一个整数
	int i = 0;
	int j = 7;
	printf("请输入一个整数:");
	scanf_s("%d", &i);
	while (j >=0)
	{
		int k = i/(int)pow(16, j)%16;
		putchar(k < 10 ? k + '0' : k + 55);
		--j;
	}

	return 0;
}

