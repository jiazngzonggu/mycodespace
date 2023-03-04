/*
 * ��������seqqueue2.c,�˳�����ʾ˳��ջ��ʵ�֣�����Ԫ����������
 * ���ߣ����ڹ�
 * ʱ�䣺2023��3��4�� 16:01:17
*/

#include<stdio.h>
#include<string.h>

#define MAXSIZE 10		//˳��ջ����󳤶�

typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int top;
}SeqStack,*PSeqStack;

//˳��ջSS�ĳ�ʼ������
void InitStack(PSeqStack SS);

//����˳��ջSS
void DestroyStack(PSeqStack SS);

//Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ�
int Push(PSeqStack SS, ElemType *ee);

//Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ�
int Pop(PSeqStack SS, ElemType *ee);

//��˳��ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ���
int Length(PSeqStack SS);

//���˳��ջ
void Clear(PSeqStack SS);

//�ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ��
int IsEmpty(PSeqStack SS);

//�ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-������0-δ����ʧ��
int IsFull(PSeqStack SS);

//��ӡ˳��ջ��ȫ����Ԫ��
void PrintStack(PSeqStack SS);

//��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ�
//ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ
int GetTop(PSeqStack SS, ElemType *ee);

int main()
{
	SeqStack SS;     // ����˳��ջ��

	InitStack(&SS);  // ��ʼ��˳��ջ��

	printf("ջ�ĳ�����%d\n", Length(&SS));

	ElemType ee;     // ����һ������Ԫ�ء�

	printf("Ԫ�أ�1��2��3��4��5��6��7��8��9��10����ջ��\n");
	ee = 1;  Push(&SS, &ee);
	ee = 2;  Push(&SS, &ee);
	ee = 3;  Push(&SS, &ee);
	ee = 4;  Push(&SS, &ee);
	ee = 5;  Push(&SS, &ee);
	ee = 6;  Push(&SS, &ee);
	ee = 7;  Push(&SS, &ee);
	ee = 8;  Push(&SS, &ee);
	ee = 9;  Push(&SS, &ee);
	ee = 10; Push(&SS, &ee);

	printf("ջ�ĳ�����%d\n", Length(&SS));

	// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
	if (GetTop(&SS, &ee) == 1)  printf("ջ����Ԫ��ֵΪ%d\n", ee);

	PrintStack(&SS);

	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);

	return 0;
}

//˳��ջSS�ĳ�ʼ������
void InitStack(PSeqStack SS)
{
	Clear(SS);
}

//���˳��ջ
void Clear(PSeqStack SS)
{
	//����ָ��
	if (SS == NULL) return;
	//ջ��ָ����Ϊ-1
	SS->top = -1;
	//����Ԫ������
	memset(SS->data, 0, sizeof(ElemType)*MAXSIZE);
}

//����˳��ջSS
void DestroyStack(PSeqStack SS)
{
	//��̬˳��ջ�����ͷ��ڴ棬����Ҫ���ٲ���
	Clear(SS);	//���˳��ջ
}

//Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ�
int Push(PSeqStack SS, ElemType *ee)
{
	//����ָ��
	if ((SS == NULL) || (ee == NULL)) return 0;
	//����Ƿ���ջ
	if (IsFull(SS) == 1) return 0;
	//ָ���ȼ�1
	SS->top++;
	//��ջ
	memcpy(SS->data + SS->top, ee, sizeof(ElemType));
	return 1;
}

//Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ�
int Pop(PSeqStack SS, ElemType *ee)
{
	//����Ƿ��ָ��
	if ((SS == NULL) || (ee == NULL)) return 0;
	//����Ƿ��ջ
	if (IsEmpty(SS) == 1) return 0;
	//��ջ
	memcpy(ee, SS->data + SS->top, sizeof(ElemType));
	//ָ���1
	SS->top--;
	return 1;

}

//��˳��ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ���
int Length(PSeqStack SS)
{
	//����ָ��
	if ((SS == NULL)) return 0;
	//����ջ��
	return SS->top + 1;
}

//�ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ��
int IsEmpty(PSeqStack SS)
{
	//����ָ��
	if (SS == NULL) return 0;
	//�ж��Ƿ�Ϊ��
	if (SS->top == -1) return 1;
	return 0;
}

//�ж�˳��ջ�Ƿ�Ϊ��������ֵ��1-������0-δ����ʧ��
int IsFull(PSeqStack SS)
{
	//����ָ��
	if (SS == NULL) return 0;
	//�ж��Ƿ���
	if (SS->top + 1 == MAXSIZE) return 1;
	return 0;
}

//��ӡ˳��ջ��ȫ����Ԫ��
void PrintStack(PSeqStack SS)
{
	//����ָ��
	if (SS == NULL) return;
	//����Ƿ��ջ
	if (IsEmpty(SS) == 1) return;
	
	//��ӡջԪ��
	for (int ii = 0; ii <= SS->top; ++ii)
	{
		printf("data[%d]=%d\n", ii, *(SS->data + ii));
	}
}

//��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ�
//ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ
int GetTop(PSeqStack SS, ElemType *ee)
{
	//����ָ��
	if ((SS == NULL) ||(ee==NULL)) return 0;
	//����Ƿ��ջ
	if (IsEmpty(SS) == 1) return 0;
	//ȡֵ
	memcpy(ee, SS->data + SS->top, sizeof(ElemType));
	return 1;
 
}