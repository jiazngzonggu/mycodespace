/*
 * ��������ʹ��C����pow���������ڲ�ѭ����ʵ��ʮ�����ƺͶ��������ִ�ӡ��
 *   ���ߣ����ڹ�
 *   ʱ�䣺2023��3��10�� 13:48:42
*/


#include<stdio.h>
#include<math.h>


int main()
{
	int nNum = 5666666;
	int i = 31;
	
	//ʮ����ת������
	while (i >= 0)
	{
		int j=pow(2.0, i);
		printf("%d", nNum /j % 2);
		if (0 == i % 4)
			putchar(32);
		--i;
	}

	putchar('\n');
	//////ʮ����תʮ������
	i = 7;	//ʮ���Ƶ�16�൱��ʮ�����Ƶ�F,������ռ4λ��
	while (i >= 0)
	{
		int j = pow(16.0, i);
		int m=nNum / j % 16;
		putchar(m < 10 ? m+'0' : m + 55);
		--i;
	}


}

