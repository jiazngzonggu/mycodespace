/*
 *程序名： C 语言经典100例
 *  作者：姜宗谷
 *  时间：2023年3月7日 18:35:28
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
//题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
void shili1()
{
	int i, j, k;
	printf("\n");
	for (i = 1; i < 5; i++)
	{
		//以下为三重循环
		for (j = 1; j < 5; j++)
		{
			for (k = 1; k < 5; k++)
			{
				if (i != k && i != j && k != j)
					printf("%d%d%d\n", i, j, k);
			}
		}
	}
}


//题目：企业发放的奖金根据利润提成。
//利润(I)低于或等于10万元时，奖金可提10%；
//利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
//20万到40万之间时，高于20万元的部分，可提成5%；
//40万到60万之间时高于40万元的部分，可提成3%；
//60万到100万之间时，高于60万元的部分，可提成1.5%；
//高于100万元时，超过100万元的部分按1%提成。
//从键盘输入当月利润I，求应发放奖金总数？
//
//程序分析：请利用数轴来分界，定位。注意定义时需把奖金定义成双精度浮点(double)型。
void shili2()
{
	double i;
	double bonus1, bonus2, bonus4, bonus6, bonus10, bonus;
	bonus1 = 100000 * 0.1;//高于10W，低于20w
	bonus2 = bonus1 + 100000 * 0.75;
	bonus4 = bonus2 + 200000 * 0.5;
	bonus6 = bonus4 + 2000000 * 0.3;
	bonus10 = bonus6 + 400000 * 0.15;
	printf("你的净利润是：");
	scanf("%lf", &i);

	if (i < 100000)
	{
		bonus = i * 0.1;
	}
	else if (i <= 200000)
	{
		bonus = bonus1 + (i - 100000)*0.075;
	}
	else if (i <= 400000)
	{
		bonus = bonus2 + (i - 200000);
	}
	else if (i < 600000)
	{
		bonus = bonus4 + (i - 400000);
	}
	else if (i < 1000000)
	{
		bonus = bonus6 + (i - 600000);
	}
	else if (i > 1000000)
		bonus = bonus10 + (i - 1000000);
	printf("提成为：bonus=%lf", bonus);
	printf("\n");

}




//题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
//程序分析：假设该数为 x。
//1、则：x + 100 = n2, x + 100 + 168 = m2
//2、计算等式：m2 - n2 = (m + n)(m - n) = 168
//3、设置： m + n = i，m - n = j，i * j = 168，i 和 j 至少一个是偶数
//4、可得： m = (i + j) / 2， n = (i - j) / 2，i 和 j 要么都是偶数，要么都是奇数。
//5、从 3 和 4 推导可知道，i 与 j 均是大于等于 2 的偶数。
//6、由于 i * j = 168， j >= 2，则 1 < i < 168 / 2 + 1。
//7、接下来将 i 的所有数字循环计算即可。

void shili3()
{
	int i, j, m, n, x;
	for (i=1;i<168/2+1;i++)
	{
		if (168 % i == 0)
		{
			j = 168 / i;
			if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0)
			{
				m = (i + j) / 2;
				n = (i - j) / 2;
				x = n * n - 100;
				printf("%d+100=%d*%d\n", x, n, n);
				printf("%d+268=%d*%d\n", x, m, m);
			}
		}
	}
}




/*题目：输入某年某月某日，判断这一天是这一年的第几天？
程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊情况，闰年且输入月份大*//*于3时需考虑多加一天。*/
void shili4()
{
	int day, month, year, sum, leap;
	printf("\n请输入年月日，格式为：年,月,日(2015,12,10)\n");
	scanf("%d,%d,%d", &year, &month, &day);
	switch (month)//先计算某月以前月份的总天数
	{
	case 1:
		sum = 0;
		break;
	case 2:
		sum = 31;
		break;
	case 3:
		sum = 59;
		break;
	case 4:
		sum = 90;
		break;
	case 5:
		sum = 120;
		break;
	case 6:
		sum = 151;
		break;
	case 7:
		sum = 181;
		break;
	case 8:
		sum = 212;
		break;
	case 9:
		sum = 243;
		break;
	case 10:
		sum = 273;
		break;
	case 11:
		sum = 304;
		break;
	case 12:
		sum = 334;
		break;
	default:
		printf("data error");
		break;
	}

	//再加上某天的天数
	sum = sum + day;

	//判断是否是闰年
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		leap = 1;
	else
		leap = 0;
	
	//如果是闰年且月份大于2，总天数应该加1天
	if (leap == 1 && month > 2)
		sum++;
	printf("这是这一年的第%d天。", sum);
	printf("\n");


}


//题目：输入三个整数x, y, z，请把这三个数由小到大输出。
void shili5()
{
	//定义三个整型变量和一个临时变量
	int x, y, z;
	//用户收入三个整数
	printf("请输入三个整数例如（5 2 6）：");
	scanf("%d%d%d", &x, &y, &z);
	//判断三个数的大小
	if (x < y)
	{
		if (y < z)
			printf("%d<%d<%d", x, y, z);
		else
			printf("%d<%d<%d", x, z, y);
	}
	else
	{
		if (y > z)
			printf("%d<%d<%d", z, y, x);
		else
			if (x > z)
				printf("%d<%d<%d", y, z, x);
			else
				printf("%d<%d<%d", y, x, z);
		
	}

	//输出这三个数

}


//题目：用*号输出字母C的图案。
void shili6()
{
	printf("用 * 号输出字母c!\n");
	printf("***\n");
	printf("*\n");
	printf("*\n");
	printf("***\n");

}



//题目：输出特殊图案，请在c环境中运行，看一看，Very Beautiful!
void shili7()
{
	char a = 176, b = 219;
	printf("%c%c%c%c%c\n", b, a, a, a, b);
	printf("%c%c%c%c%c\n", a, b, a, b, a);
	printf("%c%c%c%c%c\n", a, a, b, a, a);
	printf("%c%c%c%c%c\n", a, b, a, b, a);
	printf("%c%c%c%c%c\n", b, a, a, a, b);


}

//题目：输出9 * 9口诀
void shili8()
{
	int i, j;
	for (i=1; i <= 9; i++)
	{
		for (j=1; j <= i; j++)
		{
			printf("%d*%d=%-5d", i, j, i*j);
		}
		printf("\n");
	}
}


//题目：要求输出国际象棋棋盘。
void shili9()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
				printf("%c%c", 219, 219);
			else
				printf(" ");
		}
		printf("\n");
	}


}


//题目：打印楼梯，同时在楼梯上方打印两个笑脸。
void shili10()
{
	int i, j;
	printf("\1\1\n");//输出两个笑脸
	for (i = 1; i < 11; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%c%c", 219, 219);
		printf("\n");
	}

}


//题目：古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月即可）
void shili11()
{
	int f1 = 1, f2 = 1, i;
	for (i = 1; i <= 20; i++)
	{
		printf("%12d%12d", f1, f2);
		if (i % 2 == 0)
			printf("\n");
		f1 = f1 + f2;
		f2 = f1 + f2;
	}


}


//题目：判断 101 到 200 之间的素数。
void shili12()
{
	int i, j;
	int count = 0;
	for (i = 101; i <= 200; i++)
	{
		for (j = 2; j < i; j++)
		{
			//如果j能被i整除再跳出循环
			if (i%j == 0)
				break;
		}

		//判断循环是否提前跳出，如果j<i说明再2-j之间，i有可整除的数
		if (j >= i)
		{
			count++;
			printf("%d ", i);
			//换行，用count计数，每五个数换行
			if (count % 5 == 0)
				printf("\n");
		}

	}

}


//题目：打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数

void shili13()
{
	int i, x, y, z;
	for (i = 100; i < 1000; i++)
	{
		x = i % 10;
		y = i / 10 % 10;
		z = i / 100 % 10;

		if (i == (x*x*x + y * y*y + z * z*z))
			printf("%d\n", i);
	}

}


//将一个正整数分解质因数。例如：输入90, 打印出90 = 2 * 3 * 3 * 5
void shili14()
{
	int n, i;
	printf("请输入整数：");
	scanf("%d", &n);
	printf("%d=", n);
	for (i = 2; i <= n; i++)
	{
		while (n%i == 0)
		{
			printf("%d", i);
			n /= i;
			if (n != 1)
				printf("*");
		}
	}
	printf("\n");

}

//利用条件运算符的嵌套来完成此题：学习成绩 >= 90分的同学用A表示，60 - 89分之间的用B表示，60分以下的用C表示。
void shili15()
{
	int score;
	char grade;
	printf("请输入分数：");
	scanf("%d", &score);
	grade = (score >= 90) ? 'A' : ((score >= 60) ? 'B' : 'C');
	printf("%c\n", grade);

}


//题目：输入两个正整数m和n，求其最大公约数和最小公倍数。
void shili16()
{
	int a, b, t, r, n;
	printf("请输入两个数字：\n");
	scanf("%d%d", &a, &b);
	if (a < b)
	{
		t = b;
		b = a;
		a = t;
	}
	r = a % b;
	n = a * b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	printf("这两个数的最大公约数是%d,最小公倍数是%d\n", b, n / b);


}


//题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
//getchar()是stdio.h中的库函数，它的作用是从stdin流中读入一个字符，
//也就是说，如果stdin有数据的话不用输入它就可以直接读取了，
//第一次调用getchar()时，确实需要人工的输入，但是如果你输了多个字符，
//以后的getchar()再执行时就会直接从缓冲区中读取了
void shili17()
{
	char c;
	int letters = 0, spaces = 0, digits = 0, others = 0;
	printf("请输入一些字母：\n");
	while ((c = getchar()) != '\n')
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			letters++;
		else if (c >= '0' && c <= '9')
			digits++;
		else if (c == ' ')
			spaces++;
		else
			others++;

	}
	printf("字母 = %d, 数字 = %d, 空格 = %d, 其他 = %d\n",letters,digits,spaces,others);

}

//题目：求s = a + aa + aaa + aaaa + aa...a的值，其中a是一个数字。例如2 + 22 + 222 + 2222 + 22222(此时共有5个数相加)，

void shili18()
{
	int s = 0, a, n, t;
	printf("请输入a和n:");
	scanf("%d%d", &a, &n);
	t = a;
	while (n > 0)
	{
		s += t;
		a *= 10;
		t += a;
		n--;

	}
	printf("a+aa+...=%d\n", s);


}


//题目：一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6 = 1＋2＋3.编程找出1000以内的所有完数。
void shili19()
{
	#define N 1000
	int i, j, k, n, sum;
	int a[256];
	for (i = 2; i <= N; i++)
	{
		sum = a[0] = 1;
		k = 0;
		for (j = 2; j <= (i / 2); j++)
		{
			if (i%j == 0)
			{
				sum += j;
				a[++k] = j;
			}
		}
		if (i == sum)
		{
			printf("%d=%d", i, a[0]);
			for (n = 1; n <= k; n++)
			{
				printf("+%d", a[n]);
			}
			printf("\n");
		}
	}
}

//题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
void shili20()
{
	float h, s;
	h = s = 100;
	h = h / 2;	//第一次反弹高度
	for (int i = 2; i <= 10; i++)
	{
		s = s + 2 * h;
		h = h / 2;
	}
	printf("第10次落地时，共经过%f米，第10次反弹高%f米\n", s, h);

}


////题目：猴子吃桃问题：
void shili21()
{
	int day, x1 = 0, x2;
	day = 9;
	x2 = 1;
	while (day > 0)
	{
		x1 = (x2 + 1) * 2;	//第一天的桃子数是第二天套装数加1后的2倍
		x2 = x1;
		day--;
	}
	printf("总数为 %d\n", x1);

}
