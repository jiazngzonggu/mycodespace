/*
 *程序名： C 语言经典100例
 *  作者：姜宗谷
 *  时间：2023年3月7日 18:35:28
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
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
//****************************************************************************************************************************************


//题目：两个乒乓球队进行比赛，各出三人。甲队为a, b, c三人，乙队为x, y, z三人。
//已抽签决定比赛名单。有人向队员打听比赛的名单。
//a说他不和x比，c说他不和x, z比，请编程序找出三队赛手的名单。
void shili22()
{
	char i, j, k;
	for (i = 'x'; i <= 'z'; i++)
	{
		for (j = 'x'; j <= 'z'; j++)
		{
			if (i != j)
			{
				for (k = 'x'; k <= 'z'; k++)
				{
					if (i!= k && j != k)
					{
						printf("顺序为：a--%c\tb--%c\tc--%c\n", i, j, k);
					}
				}
			}
		}
	}



}


//程序分析：先把图形分成两部分来看待，前四行一个规律，后三行一个规律，利用双重for循环，第一层控制行，第二层控制列。

void shili23()
{
	int i, j, k;
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= 2 -i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= 4 - 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}

}

//题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
void shili24()
{
	int i, t;
	float sum = 0;
	float a = 2, b = 1;
	for (i = 1; i <= 20; i++)
	{
		sum = sum + a / b;
		t = a;
		a += b;
		b = t;
	}
	printf("%9.6f\n",sum);


}


//题目：利用递归方法求5!。
int fact(int j)
{
	int sum;
	if (j == 0)
		sum = 1;
	else
		sum = j * fact(j - 1);
	return sum;
}

void shili26()
{
	int i;
	int fact(int);
	for (i = 0; i < 6; i++)
	{
		printf("%d!=%d\n", i, fact(i));
	}


}


//题目：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。
void palin(n)
int n;			//这种写法很奇特 参数定义在外部 另一种写法: void(int n)
{
	char next;
	if (n <= 1)
	{
		next = getchar();
		printf("相反顺序输出结果\40:\40");
		putchar(next);
	}
	else
	{
		next = getchar();
		palin(n - 1);
		putchar(next);
	}
}

void shili27()
{
	int i = 5;
	void palin(int n);
	printf("请输入5个字符\40:\40");
	palin(i);
	printf("\n");


}



//题目：有5个人坐在一起，问第五个人多少岁？他说比第4个人大2岁。问第4个人岁数，他说比第3个人大2岁。问第三个人，又说比第2人大两岁。问第2个人，说比第一个人大两岁。最后问第一个人，他说是10岁。请问第五个人多大？
int age(n)
int n;
{
	int c;
	if (n == 1)
		c = 10;
	else
		c = age(n - 1) + 2;
	return(c);	//这种写法也可以 另一种写法 return c;
}

void shili28()
{
	printf("%d\n", age(5));
}


//题目：给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。
void shili29()
{
	long a, b, c, d, e, x;
	printf("请输入5位数字：");
	scanf("%ld", &x);
	a = x / 10000;		//分解出万位
	b = x % 10000 / 1000;//分解出千位
	c = x % 1000 / 100;	//分解出百位
	d = x % 100 / 10;	//分解出十位
	e = x % 10;	//分解出各位

	if (a != 0)
	{
		printf("为5位数，逆序为：%ld %ld %ld %ld %ld\n", e, d, c, b, a);
	}
	else if (b != 0)
	{
		printf("为4位数，逆序为：%ld %ld %ld %ld\n", e, d, c, b);
	}
	else if (c != 0)
	{
		printf("为3位数，逆序为：%ld %ld %ld\n", e, d, c);
	}
	else if (d != 0)
	{
		printf("为2位数，逆序为：%ld %ld\n", e, d);
	}
	else if (e != 0)
	{
		printf("为2位数，逆序为：%ld\n", e);
	}
}



//题目：一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同。
void shili30()
{
	long ge, shi, qian, wan, x;
	printf("请输入 5 位数字：");
	scanf("%ld", &x);
	wan = x / 10000;		//分解出万位
	qian = x % 10000 / 1000;	//分解出千位
	shi = x % 100 / 10;		//分解出十位
	ge = x % 10;
	if (ge == wan && shi == qian)
	{
		//各位等于万位并且十位等于千位
		printf("这是回文数！\n");
	}
	else
	{
		printf("这不是回文数！\n");
	}

}


//题目：请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，则继续判断第二个字母。
void shili31()
{
	char i, j;
	printf("请输入第一个字母:\n");
	scanf("%c", &i);
	getchar();	//scanf("%c",&j);的问题，第二次是读入的一个换行符，而不是输入的字符，因此要加一个getchar()吃掉换行符
	switch (i)
	{
	case 'm':
		printf("monday\n");
		break;
	case 'w':
		printf("wendensday\n");
		break;
	case 'f':
		printf("friday\n");
		break;
	case 't':
		printf("请输入下一个字母\n");
		scanf("%c", &j);
		if (j == 'u') { printf("tuesday\n"); break; }
		if (j == 'h') { printf("thursday\n"); break;}
	case 's':
		printf("请输入下一个字母\n");
		scanf("%c", &j);
		if (j == 'a') { printf("saturday\n"); break; }
		if (j == 'u') { printf("sunday\n"); break; }
	default:
		printf("error\n");
		break;
	}
}


//题目：删除一个字符串中的指定字母，如：字符串 "aca"，删除其中的 a 字母。
char* deleteCharacters(char* str, char* charSet)
{
	int hash[256];
	if (NULL == charSet)
		return str;
	for(int i=0;i<256;i++)
	{
		hash[i] = 0;
	}
	for (int i = 0; i < strlen(charSet); i++)
	{
		hash[charSet[i]] = 1;
	}
	int currentIndex = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (!hash[str[i]])
			str[currentIndex++] = str[i];
	}
	str[currentIndex] = '\0';
}

void shili32()
{
	char s[2] = "a";     // 要删除的字母
	char s2[5] = "aca";  // 目标字符串
	printf("%s\n", deleteCharacters(s2, s));
}


//题目：判断一个数字是否为质数。
int isPrime(int n)
{
	if (n <= 1)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}


void shili33()
{


}


//题目：练习函数调用。

void hello_world(void)
{
	printf("Hello,world\n");
}

void three_hellos(void)
{
	int counter;
	for (counter = 1; counter <= 3; counter++)
	{
		hello_world();	//调用此函数
	}
}

void shili34()
{
	three_hellos();
}


//题目：字符串反转，如将字符串 "www.runoob.com" 反转为 "moc.boonur.www"。
void reverse(char* s)
{
	//获取字符串长度
	int len = 0;
	char* p = s;
	while (*p != 0)
	{
		len++;
		p++;
	}

	//交换。。。
	int i = 0;
	char c;
	while (i <= len / 2 - 1)
	{
		c = *(s + i);
		*(s + i) = *(s + len - 1 - i);
		*(s + len - 1 - i) = c;
		i++;
	}
}

void shili35()
{
	char s[] = "www.runoob.com";
	printf("'%s'==>\n", s);
	reverse(s);
	printf("'%s'\n", s);

}


//题目：求100之内的素数
void shili36()
{
	int i, j, k, n = 0;
	for (i = 2; i <= 100; i++)
	{
		k = (int)sqrt(i);
		for (j = 2; j <= k; j++)
			if (i%j == 0) break;
		if (j > k)
		{
			printf("%d ", i);
			n++;
			if (n % 5 == 0)
				printf("\n");
		}
	}
}


//题目：对10个数进行排序
void shili37()
{
#define N 10
	int i, j, a[N], temp;
	printf("请输入 10 个数字:\n");
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < N - 1; i++)
	{
		int min = i;
		for (j = i + 1; j < N; j++)
			if (a[min] > a[j]) min = j;
		if (min != i)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
	printf("排序结果是:\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}

//题目：求一个3 * 3矩阵对角线元素之和
void shili38()
{
	int i, j, a[N][N], sum = 0;
	printf("请输入矩阵（3*3）:\n");
	for (i = 0; i < N; i++)
		for (j = 0; j < N; i++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < N; i++)
		sum += a[i][i];
	printf("对角线之和为:%d\n", sum);

}


//题目：有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中。
void shili39()
{
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	int temp1, temp2, number, end, i, j;
	printf("原始数组是：\n");
	for (i = 0; i < 10; i++)
		printf("%4d", a[i]);
	printf("\n插入一个新的数字：");
	scanf("%d", &number);
	end = a[9];
	if (number > end)
		a[10] = number;
	else
	{
		for (i = 0; i < 10; i++)
		{
			if (a[i] > number)
			{
				temp1 = a[i];
				a[i] = number;
				for (j = i + 1; j < 11; j++)
				{
					temp2 = a[j];
					a[j] = temp1;
					temp1 = temp2;
				}
				break;
			}
		}
	}
	for (i = 0; i < 11; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");


}


//题目：将一个数组逆序输出。
void shili40()
{
	int a[N] = { 0,1,2,3,4,5,6,7,8,9 };
	int i, t;
	printf("原始数组是：\n");
	for (i = 0; i < N; i++)
	{
		printf("%d", a[i]);
	}
	for (i = 0; i < N / 2; i++)
	{
		t = a[i];
		a[i] = a[N - 1 - i];
		a[N - 1 - i] = t;
	}
	printf("\n排序后的数组：\n");
	for (i = 0; i < N; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}

//题目：学习static定义静态变量的用法。
void fun()
{
	int i = 0;
	static int static_i = 0;	//只初始化赋值一次
	printf("i=%d\n", i);
	printf("static_i=%d\n", static_i);
	i++;
	static_i++;

}

void shili41()
{
	void fun();
	for (int i = 0; i < 3; i++)
		fun();
	return 0;

}



//题目：学习使用auto定义变量的用法。
void shili42()
{
	int i, num;
	num = 2;
	for (i = 0; i<3;i++)
	{
		printf("num 变量为 %d \n", num);
		num++;
		{//内置模块num和外部num不是同一个变量
			auto int num = -1;
			printf("内置模块num变量为%d.\n", num);
			//num++;
		}
	}

}


//题目：学习使用static的另一用法。　
void shili43()
{
	int i, num;
	num = 2;
	for (i = 0; i < 3; i++)
	{
		printf("num 变量为 %d \n", num);
		num++;
		{
			static int num = 1;
			printf("内置模块 num 变量为 %d\n", num);
			num++;
		}
	}

}

//题目：学习使用如何调用外部函数。
int a, b, c;
void add()
{
	int a;
	a = 3;
	c = a + b;
}
void shili44()
{
	a = b = 4;
	add();
	printf("c 的值为 %d\n", c);

}


//题目：学习使用register定义变量的方法。
void shili45()
{
	register int i;
	/*Register声明的作用
	是为了提高效率。
	它明确要求CPU把变量始终保存在寄存器里面，直至它消亡。
	不过现代编译器都很厉害，根本不需要你多此一举。
	所以根本就极少用*/
	int tmp = 0;
	for (i = 1; i <= 100; i++)
	{
		tmp += i;
	}
	printf("总和为 %d\n");

}


//题目：宏#define命令练习。
void shili46()
{
#define TRUE 1	//宏定义没有分号结尾
#define FALSE 0
#define SQ(x) (x)*(x)	//这是一中宏函数用法,返回x*x的值

	int num;
	int again = 1;
	printf("如果值小于 50 程序将终止。\n");
	while (again)
	{
		printf("\n请输入数字:");
		scanf("%d", &num);
		printf("该数字的平方为 %d \n", SQ(num));

		if (num >= 50)
			again = TRUE;
		else
		{
			again = FALSE;
		}
	}


}


//题目：宏#define命令练习2。
void shili47()
{
#define exchange(a,b) {int t;t=a;a=b;b=t;}	//注意放在一行里
	int x = 10;
	int y = 20;
	printf("x=%d;y=%d\n", x, y);
	exchange(x, y);
	printf("x=%d;y=%d\n", x, y);
}


//题目：宏#define命令练习3。
void shili48()
{
#define LAG >
#define SMA <
#define EQ ==
	int i, j;
	printf("请输入两个数字:\n");
	scanf("%d %d", &i, &j);
	if (i LAG j)
		printf("%d 大于 %d \n", i, j);
	else if (i EQ j)
		printf("%d 等于 %d \n", i, j);
	else if (i SMA j)
		printf("%d 小于 %d \n", i, j);
	else
		printf("没有值。\n");
}


//题目：#if #ifdef和#ifndef的综合应用。
void shili49()
{
#define MAX
#define MAXIMUM(x,y)(x>y)?x:y
#define MINIMUM(x,y)(x>y)?x:y

	int a = 10, b = 20;
#ifdef MAX
	printf("更大的数字是 %d\n", MAXIMUM(a, b));
#else
	printf("更小的数字是 %d\n", MINIMUM(a, b));
#endif // MAX

#ifndef MIN
	printf("更小的数字是 %d\n", MINIMUM(a, b));
#else
	printf("更大的数字是 %d\n", MAXIMUM(a, b));
#endif

#undef MAX

#ifdef MAX
	printf("更大的数字是 %d\n", MAXIMUM(a, b));
#else
	printf("更小的数字是 %d\n", MINIMUM(a, b));
#endif

#define MIN
#ifndef MIN
	printf("更小的数字是 %d\n", MINIMUM(a, b));
#else
	printf("更大的数字是 %d\n", MAXIMUM(a, b));
#endif

}


//题目：#include 的应用练习。
//#include "test.h"  在当前目录下的头文件


//题目：学习使用按位与 &。
void shili51()
{
	int a, b;
	a = 077;	//111 111
	b = a & 3;	//000  11    3
	printf("a & b（decimal)为 %d \n", b);
	b &= 7;	// 111
			//  11    3
	printf("a & b(decimal)为 %d \n", b);
 

	b |= 7;// 111
		   // 011
			//111
	printf("a | b(decimal)为 %d \n", b);
	
	b ^= 7;// 111
		   // 111
			//000  
	printf("a ^ b(decimal)为 %d \n", b);


}


//题目：学习使用按位或 | 。
void shili52()
{
	int a, b;
	a = 077;	//000 111 111
	b = a | 3;	//000 000 011
				//000 111 111	=32+16+8+4+2+1=63
	printf("b的值为 %d \n", b);
	b |= 7;		//000 111 111
				//000 000 111
				//000 111 111	=63
	printf("b的值为 %d \n",b);


}


//题目：学习使用按位异或 ^。
void shili53()
{
	int a, b;
	a = 077;
	b = a ^ 3;	//0 111 111
				//0 000 011
				//0 111 100		=32+16+8+4=60
	printf("b 的值为 %d \n", b);
	b ^= 7;		//0 111 100
				//0 000 111
				//0 111 011		=32+16+8+1+2=59
	printf("b 的值为 %d \n", b);

}


//题目：取一个整数 a 从右端开始的 4～7 位。
void shili54()
{
	unsigned a, b, c, d;
	printf("请输入整数:\n");
	scanf("%o", &a);	//011 110
	b = a >> 4;			//0000 0001
	c = ~(~0 << 4);		//1111 0000
						//0000 1111
						//0000 0001
						//0000 0001
	d = b & c;//与运算	//
	printf("%o\n%o\n", a, d);

}


