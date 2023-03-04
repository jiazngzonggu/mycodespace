/*
 * ��������seqqueue2.c,�˳�����ʾѭ�����е�����ʵ�֣���βָ��ָ���β����һ��Ԫ�أ�������length�ĸ�������
 * ���ߣ����ڹ�
 * ʱ�䣺2023��3��4�� 11:29:29
*/

#include<stdio.h>
#include<string.h>

#define MAXSIZE 10

typedef ElemType;	//�Զ���ѭ�����е�����Ԫ��Ϊ����

typedef struct 
{
	ElemType data[MAXSIZE];//������
	int front;	//���е�ͷָ��
	int rear;	//���е�βָ��
	int length;	//���е�ʵ�ʳ���

}SeqQueue,*PSeqQueue;	//�ṹ��������

//ѭ������QQ�ĳ�ʼ������
void InitQueue(PSeqQueue QQ);

//����ѭ������QQ
void DestroyQueue(PSeqQueue QQ);

//Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ�
int InQueue(PSeqQueue QQ, ElemType *ee);

//Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ�
int OutQueue(PSeqQueue QQ, ElemType *ee);

//��ѭ�����еĳ��ȣ�����ֵ��>=0 -����QQԪ�صĸ���
int Length(PSeqQueue QQ);

//���ѭ������
void Clear(PSeqQueue QQ);

//�ж�ѭ�������Ƿ�Ϊ��,����ֵ��1-�գ�0-�ǿջ���ʧ��
int IsEmpty(PSeqQueue QQ);

//�ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ��
int IsFull(PSeqQueue QQ);

//��ӡѭ��������ȫ����Ԫ��
void PrintQueue(PSeqQueue QQ);

//��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ�
//ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز�����
int GetHead(PSeqQueue QQ, ElemType *ee);

int main()
{
	SeqQueue QQ;     // ����ѭ�����С�

	InitQueue(&QQ);  // ��ʼ��ѭ�����С�

	ElemType ee;     // ����һ������Ԫ�ء�

	printf("Ԫ�أ�1��2��3��4��5��6��7��8��9��10��11����ӡ�\n");
	ee = 1;  InQueue(&QQ, &ee);
	ee = 2;  InQueue(&QQ, &ee);
	ee = 3;  InQueue(&QQ, &ee);
	ee = 4;  InQueue(&QQ, &ee);
	ee = 5;  InQueue(&QQ, &ee);
	ee = 6;  InQueue(&QQ, &ee);
	ee = 7;  InQueue(&QQ, &ee);
	ee = 8;  InQueue(&QQ, &ee);
	ee = 9;  InQueue(&QQ, &ee);
	ee = 10; InQueue(&QQ, &ee);
	ee = 11; InQueue(&QQ, &ee);

	printf("���еĳ�����%d\n", Length(&QQ));
	PrintQueue(&QQ);

	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);

	printf("���еĳ�����%d\n", Length(&QQ));
	PrintQueue(&QQ);

	printf("Ԫ�أ�11��12��13��14��15����ӡ�\n");
	ee = 11;  InQueue(&QQ, &ee);
	ee = 12;  InQueue(&QQ, &ee);
	ee = 13;  InQueue(&QQ, &ee);
	ee = 14;  InQueue(&QQ, &ee);
	ee = 15;  InQueue(&QQ, &ee);

	printf("���еĳ�����%d\n", Length(&QQ));

	PrintQueue(&QQ);

	// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
	if (GetHead(&QQ, &ee) == 1)  printf("��ͷ��Ԫ��ֵΪ%d\n", ee);

	return 0;

}

//ѭ������QQ�ĳ�ʼ������
void InitQueue(PSeqQueue QQ)
{
	Clear(QQ);
}

//���ѭ������
void Clear(PSeqQueue QQ)
{
	//����ָ��
	if (QQ == NULL) return;

	//��0
	QQ->front = QQ->rear = QQ->length = 0;
	//����Ԫ������
	memset(QQ->data, 0, sizeof(ElemType)*MAXSIZE);
}

//����ѭ������QQ
void DestroyQueue(PSeqQueue QQ)
{
	//��̬ѭ�����������ͷ��ڴ棬����Ҫ���ٲ���
	Clear(QQ);
}

//Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ�
int InQueue(PSeqQueue QQ, ElemType *ee)
{
	//����ָ��
	if ((QQ == NULL) || (ee == NULL)) return 0;
	//�ж϶����Ƿ�����
	if (IsFull(QQ) == 1) return 0;
	//�������
	memcpy(QQ->data + QQ->rear, ee, sizeof(ElemType));
	//��βָ�����
	/*QQ->rear = QQ->rear + 1;
	if (QQ->rear >= MAXSIZE) QQ->rear = QQ->rear - MAXSIZE;*/
	QQ->rear = (QQ->rear + 1) % MAXSIZE;

	//���г��ȼ�1
	QQ->length++;

}

//Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ�
int OutQueue(PSeqQueue QQ, ElemType *ee)
{
	//����ָ��
	if ((QQ == NULL) || (ee == NULL)) return 0;
	//�����Ƿ�Ϊ��
	if (IsEmpty(QQ) == 1) return 0;
	//���ݳ�ջ
	memcpy(ee, QQ->data + QQ->front, sizeof(ElemType));
	//���׺���
	QQ->front = (QQ->front + 1) % MAXSIZE;
	//�ӳ���1
	QQ->length--;
	return 1;
}

//��ѭ�����еĳ��ȣ�����ֵ��>=0 -����QQԪ�صĸ���
int Length(PSeqQueue QQ)
{
	if (QQ == NULL) return 0;
	return QQ->length;
}

//�ж�ѭ�������Ƿ�Ϊ��,����ֵ��1-�գ�0-�ǿջ���ʧ��
int IsEmpty(PSeqQueue QQ)
{
	//����ָ��
	if (QQ == NULL)return 0;
	//�ж��Ƿ�Ϊ��
	if (QQ->length != 0) return 1;
	
	return 0;
}

//�ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ��
int IsFull(PSeqQueue QQ)
{
	//����ָ��
	if (QQ == NULL)return 0;
	//�ж��Ƿ�Ϊ��
	if (QQ->length == MAXSIZE) return 1;

	return 0;
}

//��ӡѭ��������ȫ����Ԫ��
void PrintQueue(PSeqQueue QQ)
{
	//����ָ��
	//����ָ��
	if (QQ == NULL)return;
	//����Ƿ�ն���
	if (QQ->length == 0) return;
	//ѭ����ӡ����
	for (int ii = 0; ii < QQ->length; ++ii)
	{
		printf("data[%d]=%d\n", (QQ->front + ii) % MAXSIZE, QQ->data[(QQ->front + ii) % MAXSIZE]);
	}
}

//��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ�
//ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز�����
int GetHead(PSeqQueue QQ, ElemType *ee)
{
	if ((QQ == NULL) || (ee == NULL)) return 0;   // ����ָ�롣

	if (IsEmpty(QQ) == 1) { printf("����Ϊ�ա�\n"); return 0; }

	memcpy(ee, &QQ->data[QQ->front], sizeof(ElemType));  // ��������±���ʡ�
	// memcpy(ee,QQ->data+QQ->front,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

	return 1;
}
