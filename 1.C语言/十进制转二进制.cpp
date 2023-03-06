/*
 * 程序名：编写代码，让用户输入一个随机的200以内的十进制数字可以想办法用printf打印出对应的二进制
 *	      可以考虑有8个printf函数来实现，如果懂得循环的可以循环8次来打印。
 * 作者：姜宗谷
 * 时间：2023年3月6日 13:34:56
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAXSIZE 8	//数组个数最大值
int main()
{
	//定义一个整型变量和一个整型数组
	int nNum1;	//用户输入的整数
	int nNum2[MAXSIZE];	//求余数组
	int i = 0;	//计数器

	while (1)
	{
		printf("请输入200以内的整数(输入0退出):");
		//调用scanf函数从控制台读取用户输入的整数
		scanf("%d", &nNum1);
		//输入0则退出
		if (nNum1 == 0)
			break;
		//循环取余数，如果输入的值小于2则直接输出结果
		if (nNum1 < 2)
			printf("%d", nNum1);
		else
		{
			//求商并放入数组内,商整数部位要大于0；
			//计数器i要及时清0，否则报错
			int nTmp = nNum1;
			for (i=0; nTmp > 0;)
			{
				nNum2[i] = nTmp;
				nTmp = nTmp / 2;
				i++;
			}
			
			//如果数组长度是否达到最大值
			if (i > MAXSIZE)
			{
				printf("你输入的数过大！");
				continue;//回到循环头部
			}

			//计数器减1为数组下标；
			//求余并将余数逆序排列得出结果即为二进制
			printf("整数:%d\t\t二进制:", nNum1);
			for (i--; i >= 0; i--)
			{
				printf("%d", nNum2[i] % 2);
			}
		}
		printf("\n\n");
	}
	
	
	return 0;
}