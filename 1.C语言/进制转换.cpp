/*
*������:ʮ����ת�����ơ�ʮ����תʮ�����ơ�
*  ����:���ڹ�
*  ʱ��:2023��3��9�� 11:54:34
*/
#include<stdio.h>

//ʮ����תʮ������
void inteTohex(int interger)
{
	static int i = 0;//�����ݹ��˼���
	static int j = 0;//��ʱ����
	static int k = 0;//�������ĵݹ����

	//�ж�interger�Ƿ����0��С���򷵻�
	if (interger >= 1)
	{
		//��������
		++i;
		inteTohex(interger / 16);
		//����
		interger %= 16;
	
	}
	else
	{
		k = i;	//���ݹ鵽��������ʱ�򣬱������
		return;
	}
	
	//����ֻ��Ҫ�ж�һ�Σ���֤����ĸ�ʽ�����磺 0008 9D36   k���������ж��Ƿ������һ�εĵݹ顣
	if ((0!=i % 4) && (i==k) &&(k>4))
	{
		j = (4 - i % 4);
		for (; j > 0; j--)
		{
			printf("%d", 0);
		}
		--i;//��һ��Ŀ������ݹ�������������Ŀ����ʹ�䲻�ٽ����һ���жϣ���һ�ξ͹��ˡ�
	}
	//�ж����4��ʱ�����һ���ո� //�ݹ鷵�صĵ�һ�β���Ҫ���
	if ((0 == i % 4) && ((i != k)))
	{
		printf(" ");
	}

	//��ӡ����
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

//ʮ����ת������
void interTobin(int interger)
{
	//�ж�interger�Ƿ����0
	if (interger < 0)
		return;
	char c[32] = { 0 };
	char i = 0;//������
	
	//������
	while (interger>0)
	{
		//���ಢ����������
		c[i] = interger % 2;
		//��������2
		interger /= 2;
		//��������1
		++i;
	}
	//����4λ��ʹ�������ܹ�����λΪһ����� ���磺0101 0101 0110 1111 0100 0010 1111
	if((i % 4) > 0 && (i>4))
	{
		char ii = 4 - (i % 4);
		for (; ii > 0; ii--)
			printf("%d",0);
	}
	//��ӡ����,������i�����1,���������±�Ҫ��1.
	char ntmp = i;
	while(i>0)
	{
		if ((0 == (i % 4)) && (ntmp != i))	//��һ���жϣ�ÿ���4�δ�ӡһ���ո�	�ڶ����жϣ���һ�������ʱ����Ҫ��ո�
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
	printf("������һ������0������:");
	//�ӿ���̨��ȡһ����������ŵ�����n
	scanf_s("%d", &n);
	printf("  ʮ��������: %d\n", n);
	
	//ʮ����ת16����
	printf("ʮ����������: ");
	inteTohex(n);
	putchar('\n');

	//ʮ����ת������
	printf("  ����������: ");
	interTobin(n);

	return 0;
}

