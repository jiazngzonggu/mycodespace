/*
 *����������д�����ӡ�û�¼���һ��ʮ�����ƣ���ʹ��%x��%X,ʹ��pow������
 *  ���ߣ����ڹ�
 *  ���ڣ�2023��3��11��
 */

#include<stdio.h>
#include<math.h>

int main()
{
	//��ʾ�û�����һ������
	int i = 0;
	int j = 7;
	printf("������һ������:");
	scanf_s("%d", &i);
	while (j >=0)
	{
		int k = i/(int)pow(16, j)%16;
		putchar(k < 10 ? k + '0' : k + 55);
		--j;
	}

	return 0;
}

