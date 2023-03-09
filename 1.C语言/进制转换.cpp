/*
*程序名:十进制转二进制、十进制转十六进制。
*  作者:姜宗谷
*  时间:2023年3月9日 11:54:34
*/
#include<stdio.h>

//十进制转十六进制
void inteTohex(int interger)
{
	static int i = 0;//计数递归了几次
	static int j = 0;//临时变量
	static int k = 0;//保存最后的递归次数

	//判断interger是否大于0，小于则返回
	if (interger >= 1)
	{
		//调用自身
		++i;
		inteTohex(interger / 16);
		//求余
		interger %= 16;
	
	}
	else
	{
		k = i;	//当递归到最后次数的时候，保存次数
		return;
	}
	
	//这里只需要判断一次，保证输出的格式。例如： 0008 9D36   k的作用是判断是否是最后一次的递归。
	if ((0!=i % 4) && (i==k) &&(k>4))
	{
		j = (4 - i % 4);
		for (; j > 0; j--)
		{
			printf("%d", 0);
		}
		--i;//减一的目的是与递归最大次数有区别，目的是使其不再进入第一次判断，减一次就够了。
	}
	//判断输出4次时，输出一个空格。 //递归返回的第一次不需要输出
	if ((0 == i % 4) && ((i != k)))
	{
		printf(" ");
	}

	//打印余数
	switch (interger)
	{
	case 10:
		printf("A");
		break;
	case 11:
		printf("B");
		break;
	case 12:
		printf("C");
		break;
	case 13:
		printf("D");
		break;
	case 14:
		printf("E");
		break;
	case 15:
		printf("F");
		break;
	default:
		printf("%d", interger);
		break;
	}
	
	return;
}

//十进制转二进制
void interTobin(int interger)
{
	//判断interger是否大于0
	if (interger < 0)
		return;
	char c[32] = { 0 };
	char i = 0;//计数器
	
	//求余数
	while (interger>0)
	{
		//求余并存入数组中
		c[i] = interger % 2;
		//继续除以2
		interger /= 2;
		//计数器加1
		++i;
	}
	//凑满4位，使二进制能够以四位为一组输出 例如：0101 0101 0110 1111 0100 0010 1111
	if((i % 4) > 0 && (i>4))
	{
		char ii = 4 - (i % 4);
		for (; ii > 0; ii--)
			printf("%d",0);
	}
	//打印余数,计数器i多加了1,所以数组下标要减1.
	char ntmp = i;
	while(i>0)
	{
		if ((0 == (i % 4)) && (ntmp != i))	//第一个判断：每输出4次打印一个空格。	第二个判断：第一次输出的时候不需要打空格
		{
			printf(" ");
		}
		printf("%d", c[i-1]);
		--i;
	}
}





int main()
{

	int n=0;
	printf("请输入一个大于0的整数:");
	//从控制台读取一个整数并存放到变量n
	scanf_s("%d", &n);
	printf("  十进制数是: %d\n", n);
	
	//十进制转16进制
	printf("十六进制数是: ");
	inteTohex(n);
	putchar('\n');

	//十进制转二进制
	printf("  二进制数是: ");
	interTobin(n);

	return 0;
}

