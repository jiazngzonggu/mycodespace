/*
 * ����������ӡ99�˷���
 *   ���ߣ����ڹ�
 *   ʱ�䣺2023��3��9�� 11:43:44
*/


#include<stdio.h>

int main()
{
	//�����������ͱ���
	int nNum1, nNum2;
	
	//��������forѭ��,һ��forѭ����ӡ���У���һ��forѭ����ӡ��ӡ�˷�����
	//��һ��forѭ����ӡ����
	for (nNum1 = 1; nNum1 <= 9; ++nNum1)
	{
		//�ڶ���forѭ����ӡ�˷�����
		for (nNum2 = 1; nNum2 <= nNum1; ++nNum2)
		{
			printf("%d*%d=%-5d", nNum1, nNum2, nNum1*nNum2);
		}
		
		//��ӡ����
		printf("\n");
	}


	return 0;
}