/*
 * ��������btree1.c �˳�����ʾ�������Ĳ�α���
 * ���ߣ����ڹ�
 * ���ڣ�2023��3��4�� 19:04:07
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�����������ݽṹ
typedef struct BiTNode
{
	char data;		//��Ž�������Ԫ��
	struct BiTNode *lchild;	//ָ�����ӽ���ַ��ָ��
	struct BiTNode *rchild;	//ָ�����ӽڵ��ַ��ָ��
}BiTNode,*BiTree;


//���е����ݽṹ
#define MAXSIZE 30	//ѭ�����е���󳤶ȣ������Դ��MAXSIZE-1��Ԫ��

typedef BiTree ElemType;	//�Զ�����е�Ԫ��Ϊ������

typedef struct
{
	ElemType data[MAXSIZE];	//������洢ѭ�������е�Ԫ��
	int front;	//���е�ͷָ��
	int rear;	//����βָ�룬ָ���β����һ��Ԫ��
}SeqQueue,*PSeqQueue;


//���еĲ�������
//ѭ������QQ�ĳ�ʼ������
void InitQueue(PSeqQueue QQ);

//Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ�
void InQueue(PSeqQueue QQ, ElemType *ee);

//Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ�
int OutQueue(PSeqQueue QQ, ElemType *ee);

//��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ���
int Length(PSeqQueue QQ);

//���ѭ������
void Clear(PSeqQueue QQ);

//�ж�ѭ�������Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ��
int IsEmpty(PSeqQueue QQ);

//�ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ��
int IsFull(PSeqQueue QQ);

//�������Ĳ�α���
void LovelOrder(BiTree TT);

int main()
{


	return 0;
}

//���еĲ�������
//ѭ������QQ�ĳ�ʼ������
void InitQueue(PSeqQueue QQ)
{
	Clear(QQ);
}

//���ѭ������
void Clear(PSeqQueue QQ)
{
	if (QQ == NULL) return;	//����ָ��
	QQ->front = QQ->rear = 0;	//ָ����Ϊ��
	memset(QQ->data, 0, sizeof(ElemType)*MAXSIZE);
}

//Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ�
void InQueue(PSeqQueue QQ, ElemType *ee)
{
	if ((QQ == NULL) || (ee == NULL)) return 0;	//����ָ��

	if (IsFull(QQ) == 1)
	{
		printf("ѭ���������������ܲ��롣\n");
		return 0;
	}
	memcpy(QQ->data + QQ->rear, ee, sizeof(ElemType));



}

//Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ�
int OutQueue(PSeqQueue QQ, ElemType *ee);

//��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ���
int Length(PSeqQueue QQ);

//�ж�ѭ�������Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ��
int IsEmpty(PSeqQueue QQ);

//�ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ��
int IsFull(PSeqQueue QQ);

//�������Ĳ�α���
void LovelOrder(BiTree TT);