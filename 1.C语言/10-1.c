/*
 *��������1����ӡʮ���ƻ�ʮ������ʱ���Բ���%ȡ������a)����������ȥ����λ�����ơ�ע��unsigned���͡�
 *  ���ߣ����ڹ�
 *  ���ڣ�2023��3��13��
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