/*
 * ��������seqlist3.c���˳�����ʾ˳���Ķ�̬ʵ�֣�����Ԫ����������
 * ���ߣ����ڹ� ���ڣ�20230302
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define INITSIZE	10		//˳���ĳ�ʼ����
#define EXTSIZE		5		//ÿ����չԪ�صĸ���

typedef int ElemType;		//�Զ���˳����Ԫ��Ϊ����

typedef struct
{
	ElemType *data;			//�洢˳�����Ԫ�ص��׵�ַ
	unsigned int maxsize;	//˳���Ԫ�ص���󳤶�
	unsigned int length;	//˳�����Ԫ�صĸ���
}SeqList,*PSeqList;

//˳���LL�ĳ�ʼ������
void InitList(PSeqList LL);

//����˳���LL
void DestroyList(PSeqList LL);

//��չ˳�����ڴ�ռ�,����ֵ��0-ʧ�ܣ�1-�ɹ�
int ExtList(PSeqList LL);

//��˳���LL�ĵ�ii��λ�ò���Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertList(PSeqList LL, unsigned int ii, ElemType *ee);

//��˳���LL��ͷ������Ԫ��ee,����ֵ0-ʧ�ܣ�1-�ɹ�
int PushFront(PSeqList LL, ElemType *ee);

//��˳���LL��β������Ԫ��ee,����ֵ0-ʧ�ܣ�1-�ɹ�
int PushBack(PSeqList LL, ElemType *ee);

//��˳���ĳ��ȣ�����ֵ��>=0 -��LLԪ�صĸ���
int LengthList(PSeqList LL);

//��ȡ˳����ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�ܣ�1-�ɹ�
int GetElem(PSeqList LL, unsigned int ii, ElemType *ee);

//���˳���
void ClearList(PSeqList LL);

//�ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ��
int IsEmpty(PSeqList LL);

//��ӡ˳�����ȫ����Ԫ��
void PrintList(PSeqList LL);

//����ee��˳���LL�е�λ�ã�����ֵ��0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL��
int LocateElem(PSeqList LL, ElemType *ee);

//ɾ��˳���LL�е�λ�ã�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int DeleteElem(PSeqList LL, unsigned int ii);

//ɾ��˳���LL��ͷԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int PopFront(PSeqList LL);

//ɾ��˳���LL��βԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int PopBack(PSeqList LL);



int main()
{


	return 0;
}


//˳���LL�ĳ�ʼ������
void InitList(PSeqList LL)
{
	LL->data = (ElemType *)malloc(sizeof(ElemType)*INITSIZE);//�����ڴ�ռ�
	LL->maxsize = INITSIZE;

	//���˳���
	ClearList(LL);
}

//����˳���LL
void DestroyList(PSeqList LL)
{
	free(LL->data);
	LL->length = 0;
	LL->maxsize = 0;
}

//��չ˳�����ڴ�ռ�,����ֵ��0-ʧ�ܣ�1-�ɹ�
int ExtList(PSeqList LL)
{
	//������ڴ�ռ�
	ElemType *newdata = (ElemType*)malloc(sizeof(ElemType)*(LL->length + EXTSIZE));

	//�������ʧ�ܣ�����0
	if (newdata == NULL) return 0;
	
	//��ʼ��mewdata�ռ�
	memset(newdata, 0, sizeof(ElemType)*(LL->length + EXTSIZE));

	//��˳�����ԭ�������ݸ��Ƶ��·�����ڴ�ռ���
	memcpy(newdata, LL->data, sizeof(ElemType)*LL->maxsize);
	
	//�ͷ�ԭ�����ڴ�ռ�
	free(LL->data);

	//��˳���Ԫ�ص�ָ��ָ���·�����ڴ�ռ��ַ
	LL->data = newdata;

	//����˳����maxsize����
	LL->maxsize = LL->maxsize + EXTSIZE;

	return 1;
}

//��˳���LL�ĵ�ii��λ�ò���Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertList(PSeqList LL, unsigned int ii, ElemType *ee)
{
	//����ָ��
	if (LL == NULL) return 0;
	//�ж�ii�Ƿ�Խ��
	if ((ii < 1) || (ii > LL->length + 1))
	{
		printf("����λ��(%d)���Ϸ���Ӧ����(%d-%d)֮�䡣\n", ii, 1, LL->length + 1);
		return 0;
	}
	//��iiλ�ú�֮���Ԫ�������ƶ�1��λ��
	for (unsigned int kk = LL->length; kk >= ii; --kk)
	{
		memcpy(LL->data + kk, LL->data + kk - 1, sizeof(ElemType));
	}
	//��Ԫ��eeд��˳����ii��λ�ô�
	memcpy(LL->data + ii - 1, ee, sizeof(ElemType));
	//˳���LL�ĳ��ȼ�1
	LL->length + 1;

	return 1;
}

//��˳���LL��ͷ������Ԫ��ee,����ֵ0-ʧ�ܣ�1-�ɹ�
int PushFront(PSeqList LL, ElemType *ee)
{
	return InsertList(LL, 1, ee);
}

//��˳���LL��β������Ԫ��ee,����ֵ0-ʧ�ܣ�1-�ɹ�
int PushBack(PSeqList LL, ElemType *ee)
{
	return InsertList(LL, LL->length + 1, ee);
}

//��˳���ĳ��ȣ�����ֵ��>=0 -��LLԪ�صĸ���
int LengthList(PSeqList LL)
{
	//����ָ��
	if (LL == NULL) return 0;
	//����˳���LL����
	return LL->length;
}

//��ȡ˳����ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�ܣ�1-�ɹ�
int GetElem(PSeqList LL, unsigned int ii, ElemType *ee)
{
	//����ָ��
	if (LL == NULL) return 0;
	//�ж�ii�Ƿ�Խ��
	if ((ii < 1) || (ii > LL->length)) return 0;
	
	//��ȡii��Ԫ�ص�ֵ
	memcpy(ee, LL->data + ii - 1, sizeof(ElemType));
	return;
}

//���˳���
void ClearList(PSeqList LL)
{
	//����ָ��
	if (LL == NULL) return;

	LL->length = 0;
	memset(LL->data, 0, sizeof(ElemType)*LL->maxsize);

}

//�ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ��
int IsEmpty(PSeqList LL)
{
	//����ָ��
	if (LL == NULL) return 0;

	if (LL->length == 0) return 1;

	return 0;
}

//��ӡ˳�����ȫ����Ԫ��
void PrintList(PSeqList LL)
{
	//����ָ��
	if (LL == NULL) return;

	if (LL->length == 0)
	{
		printf("��Ϊ�ա�\n");
		return;
	}

	for (unsigned int kk = 0; kk < LL->length; ++kk)
	{
		printf("%-3d", *(LL->data + kk));
	}
	printf("\n");
}

//����ee��˳���LL�е�λ�ã�����ֵ��0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL��
int LocateElem(PSeqList LL, ElemType *ee)
{
	//����ָ��
	if (LL == NULL) return;

	for (unsigned int kk = 0; kk < LL->length; ++kk)
	{
		if (*(LL->data + kk) == *ee) return kk + 1;
	}
	return 0;

}

//ɾ��˳���LL�еĵ�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int DeleteElem(PSeqList LL, unsigned int ii)
{
	//����ָ��
	if (LL == NULL) return;

	//��ii֮���Ԫ��ǰ��
	for (unsigned int kk = ii; kk <= LL->length; ++kk)
	{
		memcpy(LL->data + kk - 1, LL->data + kk, sizeof(ElemType));
	}
	LL->length--;
	return 1;

}

//ɾ��˳���LL��ͷԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int PopFront(PSeqList LL)
{
	return DeleteElem(LL, 1);
}

//ɾ��˳���LL��βԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int PopBack(PSeqList LL)
{
	return DeleteElem(LL,LL->length);
}

