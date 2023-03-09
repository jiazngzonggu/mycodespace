/*
 * 程序名：打印99乘法表
 *   作者：姜宗谷
 *   时间：2023年3月9日 11:43:44
*/


#include<stdio.h>

int main()
{
	//定义两个整型变量
	int nNum1, nNum2;
	
	//利用两个for循环,一个for循环打印换行，另一个for循环打印打印乘法过程
	//第一个for循环打印换行
	for (nNum1 = 1; nNum1 <= 9; ++nNum1)
	{
		//第二个for循环打印乘法过程
		for (nNum2 = 1; nNum2 <= nNum1; ++nNum2)
		{
			printf("%d*%d=%-5d", nNum1, nNum2, nNum1*nNum2);
		}
		
		//打印换行
		printf("\n");
	}


	return 0;
}