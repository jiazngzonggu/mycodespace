/*
 *��������1����ӡʮ���ƻ�ʮ������ʱ���Բ���%ȡ����,��λ��Ҳ��ʵ�֣�
 *  ���ߣ����ڹ�
 *  ���ڣ�2023��3��13��
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