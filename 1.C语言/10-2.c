/*
 *程序名：1、打印十进制或十六进制时可以不用%取余数,按位与也能实现；
 *  作者：姜宗谷
 *  日期：2023年3月13日
*/


#include<stdio.h>

int main()
{
	int nNum = 18888888;
	int i = 32;
	int k = 0;
	while (i >0)
	{		
		printf("%d", (nNum | 1 << --i) == nNum);
		if(i%4==0)
			printf(" ");
	}

	return 0;
}