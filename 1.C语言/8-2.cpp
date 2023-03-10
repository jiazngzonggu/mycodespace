/*
 * 程序名：使用C语言的位运算左移和右移来代替内层循环，实现十六进制和二进制数字打印。
 *   作者：姜宗谷
 *   时间：2023年3月10日 13:48:42
*/

#include<stdio.h>
int main()
{
	int nNumb = 65384732;
	int i = 31;
	
	
	//用左移的方法求十进制转二进制
	while (i >= 0)
	{
		putchar((nNumb >> i)%2 + '0');
		--i;
	}
	putchar('\n');
	i = 7;
	while (i >= 0)
	{
		int j = (nNumb >> i*4) % 16;	//位移4即除以16，i*4即为16的倍数
		putchar(j < 10 ? j + '0' : j + 55);
		--i;
	}





}