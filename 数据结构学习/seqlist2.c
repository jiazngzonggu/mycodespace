/*
 *��������seqlist2.c �˳�����ʾ˳���ľ�̬ʵ�֣�����Ԫ����������
 *���ߣ����ڹ�
 *���ڣ�20230302
*/

#include<stdio.h>
#include<string.h>

#define MAXSIZE 100		//˳������󳤶�

typedef struct
{
	int no;	//��Ů���
	char name[31];	//��Ů���
}ElemType;	//�Զ���˳��������Ԫ��Ϊ�ṹ��

typedef struct
{
	ElemType data[MAXSIZE];	//������洢˳����е�Ԫ��
	unsigned int length;	//˳�����Ԫ�صĸ���
}SeqList,*PSeqList;

//˳���LL�ĳ�ʼ������
void InitList(PSeqList LL);

//����˳���LL
void DestroyList(PSeqList LL);

//��˳���LL�ĵ�ii��λ�ò���Ԫ��ee,����ֵ��0-ʧ�� 1-�ɹ�
int InsertList(PSeqList LL, unsigned int ii, ElemType * ee);

//��˳���LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ�
int PushFront(PSeqList LL, ElemType *ee);

//��˳����β�ڵ����Ԫ��ee,����ֵ��0-ʧ�� 1-�ɹ�
int PushBack(PSeqList LL, ElemType *ee);

//��˳���ĳ��ȣ�����ֵ��>=0 -��LLԪ�صĸ���
int LengthList(PSeqList LL);

//��ȡ˳����е�ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�� 1-�ɹ�
int GetElem(PSeqList LL, unsigned int ii,ElemType *ee);

//���˳���
void ClearList(PSeqList LL);

//�ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ��
void IsEmpty(PSeqList LL);

//��ӡ˳�����ȫ����Ԫ��
void PrintList(PSeqList LL);

//����ee��˳���LL�е�λ�ã�����ֵ��0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL�е�λ��
int LocateElem(PSeqList LL, ElemType *ee);

//ɾ��˳���LL�е�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int DeleteElem(PSeqList LL, unsigned int ii);

//ɾ��˳���LL��ͷԪ�أ�����ֵ0-λ�ò��Ϸ���1-�ɹ�
int PopFront(PSeqList LL);

//ɾ��˳���LL��βԪ�أ�����ֵ0-λ�ò��Ϸ���1-�ɹ�
int PopBack(PSeqList LL);

int main()
{
	//����˳���

	//����һ��Ԫ��
	//�ڱ��в���Ԫ��
	//��ӡ˳���
	//�ڵ�5��λ�ò���Ԫ��
	//ɾ�����7��Ԫ��
	//ɾ��ͷԪ��
	//ɾ��βԪ��
	//��3��Ԫ�ص�ֵ
	//Ԫ��ֵΪ8��λ��

	return 0;
}


//˳���LL�ĳ�ʼ������
void InitList(PSeqList LL)
{
	ClearList(LL);
}

//����˳���LL
void DestroyList(PSeqList LL)
{
	return;
}

//��˳���LL�ĵ�ii��λ�ò���Ԫ��ee,����ֵ��0-ʧ�� 1-�ɹ�
int InsertList(PSeqList LL, unsigned int ii, ElemType * ee)
{
	//�ж�˳���LLָ���Ƿ�Ϊ��
	if (LL == NULL) return 0;
	//�ж�λ��ii�Ƿ�Ϸ�
	if ((ii < 1) && (ii > LL->length)) return 0;

	//�ж�˳����Ƿ�����
	if (LL->length == MAXSIZE) return 0;

	//��ii��ii֮����������ƶ�
	for (unsigned int k = LL->length;k>=ii;--k)
	{
		memcpy(LL->data + k, LL->data + k - 1, sizeof(ElemType));
	}
	//��Ԫ��ee����˳����ii��λ��
	memcpy(LL->data + ii - 1, ee, sizeof(ElemType));

	//��ĳ��ȼ�1
	LL->length++;

	return 1;
}

//��˳���LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ�
int PushFront(PSeqList LL, ElemType *ee)
{
	 return InsertList(LL, 1, ee);
}

//��˳����β�ڵ����Ԫ��ee,����ֵ��0-ʧ�� 1-�ɹ�
int PushBack(PSeqList LL, ElemType *ee)
{
	return InsertList(LL, LL->length + 1, ee);
}

//��˳���ĳ��ȣ�����ֵ��>=0 -��LLԪ�صĸ���
int LengthList(PSeqList LL)
{
	//�ж�˳���LL�Ƿ�Ϊ��ָ��
	if (LL == NULL) return 0;

	return LL->length;
}

//��ȡ˳����е�ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�� 1-�ɹ�
int GetElem(PSeqList LL, unsigned int ii,ElemType *ee)
{
	//�ж�˳���LL�Ƿ�Ϊ��ָ��
	if (LL == NULL) return 0;

	//�ж�λ��ii�Ƿ�Υ��
	if ((ii < 1) || (ii > LL->length + 1)) return 0;

	//��˳���LL��λ��ii�����ݸ��Ƹ�ee
	memcpy(ee, LL->data + ii - 1, sizeof(ElemType));
	
	return 1;
}

//���˳���
void ClearList(PSeqList LL)
{
	//�ж�˳���LL�Ƿ��ǿ�ָ��
	if (LL == NULL) return;

	memset(LL, 0, sizeof(ElemType)*MAXSIZE);
	LL->length = 0;
}

//�ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ��
void IsEmpty(PSeqList LL)
{
	//�ж�˳���LL�Ƿ��ǿ�ָ��
	if (LL == NULL) return;

	if (LL->length == 0) return;

	return ;
}
//��ӡ˳�����ȫ����Ԫ��
void PrintList(PSeqList LL)
{
	//�ж�˳���LL�Ƿ��ǿ�ָ��
	if (LL == NULL) return;
	
	//�ж�˳����Ƿ�Ϊ��
	if (LL->length == 0)
	{
		printf("˳���Ϊ�գ�\n");
		return;
	}

	//��ӡ˳���
	for (unsigned int kk=0; kk< LL->length;++kk)
	{
		printf("%-3d%c\n", (LL->data+kk)->no, (LL->data + kk)->name);
	}
	
}

//����ee��˳���LL�е�λ�ã�����ֵ��0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL�е�λ��
int LocateElem(PSeqList LL, ElemType *ee)
{
	//�ж�˳���LL�Ƿ��ǿ�ָ��
	if (LL == NULL) return 0;

	for (unsigned int kk = 0; kk < LL->length; ++kk)
	{
		if(memcmp(ee, LL->data + kk, sizeof(ElemType))==0) return kk+1;
	}
	return 0;
}

//ɾ��˳���LL�е�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int DeleteElem(PSeqList LL, unsigned int ii)
{
	//���ָ���Ƿ�Ϸ�
	if (LL == NULL) return 0;
	//�ж�λ���Ƿ�Ϸ�
	if ((ii < 1) || (ii > LL->length))
	{
		printf("ɾ��λ��(%d)���Ϸ���Ӧ����(%d-%d)֮�䡣\n", ii, 1, LL->length);
		return 0;
	}
	//�ѵ�ii֮�������ǰ��
	for (unsigned int kk = ii; kk > LL->length; ++kk)
	{
		memcpy(LL->data + kk-1, LL->data + kk, sizeof(ElemType));
	}
	//˳���LL�ĳ��ȼ�1
	LL->length--;
	return 1;
}

//ɾ��˳���LL��ͷԪ�أ�����ֵ0-λ�ò��Ϸ���1-�ɹ�
int PopFront(PSeqList LL)
{
	return DeleteElem(LL,1);
}

//ɾ��˳���LL��βԪ�أ�����ֵ0-λ�ò��Ϸ���1-�ɹ�
int PopBack(PSeqList LL)
{
	return DeleteElem(LL,LL->length);
}