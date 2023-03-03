/*
 *��������seqlist.c �˳�����ʾ˳���ľ�̬ʵ�֣�����Ԫ����������
 *���ߣ����ڹ�
 *���ڣ�20230301
*/

#include<string.h>
#include<stdio.h>

#define MAXSIZE 100		//˳������󳤶�
typedef int ElemType;	//�Զ���˳��������Ԫ��Ϊ����

typedef struct
{
	ElemType data[MAXSIZE];	//������洢˳����е�Ԫ��
	unsigned int length;	//˳�����Ԫ�صĸ���
}SeqList,*PSeqList;

//˳���LL�ĳ�ʼ������
void InitList(PSeqList LL);

//����˳���LL
void DestoryList(PSeqList LL);

//��˳���LL�ĵ�ii��λ�ò���Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertList(PSeqList LL, unsigned int ii, ElemType *ee);

//��˳���LL��ͷ�ڵ����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int PushFront(PSeqList LL, ElemType *ee);

//��˳���LL��β�ڵ����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int PushBack(PSeqList LL, ElemType *ee);

//��˳���ĳ��ȣ�����ֵ��>=0-��LLԪ�صĸ���
int LengthList(PSeqList LL);

//��ȡ˳����е�ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�ܣ�1-�ɹ�
int GetElem(PSeqList LL, unsigned int ii, ElemType *ee);

//���˳���
void ClearList(PSeqList LL);

//�ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ���ʧ��
int IsEmpty(PSeqList LL);

//��ӡ˳�����ȫ����Ԫ��
void PrintList(PSeqList LL);

//����ee��˳���LL�е�λ�ã����أ�0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL�е�λ��
int LocateElem(PSeqList LL, ElemType *ee);

//ɾ��˳���LL�еĵ�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int DeleteElem(PSeqList LL,unsigned int ii);

//ɾ��˳���LL��ͷԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int PopFront(PSeqList LL);

//ɾ��˳���LL��βԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
PopBack(PSeqList LL);

//���ò���ķ����������������˳���La��Lb�ϲ���һ�������˳���Lc
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc);

int main()
{
	SeqList LL;	//����˳���

	ElemType ee;	//����һ������Ԫ��

	//��ʼ��˳���
	InitList(&LL);

	printf("�ڱ��в���Ԫ�أ�1,2,3,4,5,6,7,8,9,10����\n");
	ee = 1; InsertList(&LL, 1, &ee);
	ee = 2; InsertList(&LL, 1, &ee);
	ee = 3; InsertList(&LL, 1, &ee);
	ee = 4; InsertList(&LL, 1, &ee);
	ee = 5; InsertList(&LL, 1, &ee);
	ee = 6; InsertList(&LL, 1, &ee);
	ee = 7; InsertList(&LL, 1, &ee);
	ee = 8; InsertList(&LL, 1, &ee);
	ee = 9; InsertList(&LL, 1, &ee);
	ee = 10; InsertList(&LL, 1, &ee);

	PrintList(&LL);

	return 0;
}

//˳���LL�ĳ�ʼ������
void InitList(PSeqList LL)
{
	ClearList(LL);	//	���˳���
}

//����˳���LL
void DestoryList(PSeqList LL)
{
	return;
}

//��˳���LL�ĵ�ii��λ�ò���Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertList(PSeqList LL, unsigned int ii, ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL)) return 0;	//����ָ��

	if (LL->length >= MAXSIZE)
	{
		printf("˳������������ܲ��롣\n");
		return 0;
	}
	
	//�жϲ���λ���Ƿ�Ϸ�
	if ((ii < 1) || (ii > LL->length+1))
	{
		printf("����λ��(%d)���Ϸ���Ӧ����(%d=%d)֮�䡣\n", ii, 1, LL->length+1);
		return 0;
	}

	//��ii��ii֮���Ԫ�غ���
	int kk;
	for (kk = LL->length; kk >= ii; --kk)
	{
		memcpy(LL->data + kk, LL->data + kk - 1, sizeof(ElemType));//����memcpy��Ϊ��֧��ee�ṹ������
		//memcpy(&LL->data[kk], &LL->data[kk - 1], sizeof(ElemType));
	
	}

	memcpy(LL->data + ii - 1, ee, sizeof(ElemType));//����memcpy��Ϊ��֧��ee�ǽṹ������

	LL->length++;	//��ĳ��ȼ�1��

	return 1;
}

//��˳���LL��ͷ�ڵ����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int PushFront(PSeqList LL, ElemType *ee)
{
	return InsertList(LL, 1, ee);
}

//��˳���LL��β�ڵ����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int PushBack(PSeqList LL, ElemType *ee)
{
	return InsertList(LL, LL->length+1, ee);
}
//��˳���ĳ��ȣ�����ֵ��>=0-��LLԪ�صĸ���
int LengthList(PSeqList LL)
{
	if (LL == NULL) return 0;	//	����ָ��
	
	return LL->length;	

}

//��ȡ˳����е�ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�ܣ�1-�ɹ�
int GetElem(PSeqList LL, unsigned int ii, ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL)) return 0;	//����ָ��

	//�ж�iiλ���Ƿ�Ϸ�
	if ((ii < 1) || (ii > LL->length)) return 0;

	memcpy(ee, LL->data + ii - 1, sizeof(ElemType));	//����memcpy��Ϊ��֧�ֽṹ��
}



//���˳���
void ClearList(PSeqList LL)
{
	if (LL == NULL) return;

	LL->length = 0;	//����Ϊ0
	memset(LL->data,0,sizeof(ElemType)*MAXSIZE);	//��˳���LL->data���ݽ����������㣬����ΪMAXSIZE
}

//�ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ���ʧ��
int IsEmpty(PSeqList LL)
{
	if (LL == NULL)	return 0;	//����ָ��

	if (LL->length == 0) return 1;

	return 0;
}

//��ӡ˳�����ȫ����Ԫ��
void PrintList(PSeqList LL)
{
	if (LL == NULL) return;	//�жϿ�ָ��

	if (LL->length == 0)
	{
		printf("��Ϊ�ա�\n");
		return;
	}
	
	for (int kk = 0; kk < LL->length; ++kk)
	{
		printf("%-3d", *(LL->data + kk));
	}
	printf("\n");
}

//����ee��˳���LL�е�λ�ã����أ�0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL�е�λ��
int LocateElem(PSeqList LL, ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL)) return 0;	//�жϿ�ָ��

	int kk;
	for (kk = 0; kk < LL->length; kk++)
	{
		if (*(LL->data + kk) == (*ee)) return kk + 1;	//�ڱ��ж�Ӧ���Ϊkk+1
	}

	return 0;
}
//ɾ��˳���LL�еĵ�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int DeleteElem(PSeqList LL, unsigned int ii)
{
	if (LL == NULL) return 0;	//	����ָ��

	//�ж�ɾ��λ���Ƿ�Ϸ�
	if ((ii < 1) || (ii > LL->length))
	{
		printf("ɾ��λ��(%d)���Ϸ���Ӧ����(%d-%d)֮�䡣\n", ii, LL->length);
	}

	//��ii֮���Ԫ��ǰ��
	int k;
	for (int k = ii; k <= LL->length; ++k)
	{
		memcpy(LL->data + k - 1, LL->data + k, sizeof(ElemType));
	}
	LL->length--;	//	��ĳ��ȼ�һ
}

//ɾ��˳���LL��ͷԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int PopFront(PSeqList LL)
{
	return DeleteElem(LL, 1);

}

//ɾ��˳���LL��βԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
PopBack(PSeqList LL)
{
	return DeleteElem(LL, LL->length);
}

//���ò���ķ����������������˳���La��Lb�ϲ���һ�������˳���Lc
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc)
{
	if ((La == NULL) || (Lb == NULL) || (Lc == NULL)) return 0;//����ָ��

	if (Lc->length < La->length + Lb->length)
	{
		printf("��Lc�ĳ��Ȳ�����\n");
		return 0;
	}
	
	int istartla = 0;	//��La��һ��Ԫ�ص�λ��
	int istartlb = 0;	//��Lb��һ��Ԫ�ص�λ��
	int istartlc = 0;	//��Lc��һ��Ԫ�ص�λ��
	
	//��La��Lb�ϲ���Lc��
	while (istartla < La->length && istartlb < Lb->length)
		Lc->data[istartlc++] = La->data[istartla] < Lb->data[istartlb] ? La->data[istartla++] : Lb->data[istartlb++];

	//��Lb������Ԫ��׷�ӵ�Lc��
	while (istartla < La->length)
		Lc->data[istartlc++] = La->data[istartla++];

	//��Lc������Ԫ��׷�ӵ�Lc��
	while (istartlb < Lb->length)
		Lc->data[istartlc++] = Lb->data[istartlb++];
	


}



