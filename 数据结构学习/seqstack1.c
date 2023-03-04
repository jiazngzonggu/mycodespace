/*
 * 程序名：seqqueue2.c,此程序演示顺序栈的实现，数据元素是整数。
 * 作者：姜宗谷
 * 时间：2023年3月4日 16:01:17
*/

#include<stdio.h>
#include<string.h>

#define MAXSIZE 10		//顺序栈的最大长度

typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int top;
}SeqStack,*PSeqStack;

//顺序栈SS的初始化操作
void InitStack(PSeqStack SS);

//销毁顺序栈SS
void DestroyStack(PSeqStack SS);

//元素入栈，返回值：0-失败；1-成功
int Push(PSeqStack SS, ElemType *ee);

//元素出栈，返回值：0-失败；1-成功
int Pop(PSeqStack SS, ElemType *ee);

//求顺序栈的长度，返回值：栈SS中元素的个数
int Length(PSeqStack SS);

//清空顺序栈
void Clear(PSeqStack SS);

//判断顺序栈是否为空，返回值：1-空；0-非空或失败
int IsEmpty(PSeqStack SS);

//判断顺序栈是否为空，返回值：1-已满；0-未满或失败
int IsFull(PSeqStack SS);

//打印顺序栈中全部的元素
void PrintStack(PSeqStack SS);

//获取栈顶元素，返回值：0-失败；1-成功
//只查看栈顶元素的值，元素不出栈
int GetTop(PSeqStack SS, ElemType *ee);

int main()
{
	SeqStack SS;     // 创建顺序栈。

	InitStack(&SS);  // 初始化顺序栈。

	printf("栈的长度是%d\n", Length(&SS));

	ElemType ee;     // 创建一个数据元素。

	printf("元素（1、2、3、4、5、6、7、8、9、10）入栈。\n");
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

	printf("栈的长度是%d\n", Length(&SS));

	// 只查看栈顶元素的值，元素不出栈。
	if (GetTop(&SS, &ee) == 1)  printf("栈顶的元素值为%d\n", ee);

	PrintStack(&SS);

	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);

	return 0;
}

//顺序栈SS的初始化操作
void InitStack(PSeqStack SS)
{
	Clear(SS);
}

//清空顺序栈
void Clear(PSeqStack SS)
{
	//检查空指针
	if (SS == NULL) return;
	//栈顶指针置为-1
	SS->top = -1;
	//数组元素清零
	memset(SS->data, 0, sizeof(ElemType)*MAXSIZE);
}

//销毁顺序栈SS
void DestroyStack(PSeqStack SS)
{
	//静态顺序栈无需释放内存，不需要销毁操作
	Clear(SS);	//清空顺序栈
}

//元素入栈，返回值：0-失败；1-成功
int Push(PSeqStack SS, ElemType *ee)
{
	//检查空指针
	if ((SS == NULL) || (ee == NULL)) return 0;
	//检查是否满栈
	if (IsFull(SS) == 1) return 0;
	//指针先加1
	SS->top++;
	//入栈
	memcpy(SS->data + SS->top, ee, sizeof(ElemType));
	return 1;
}

//元素出栈，返回值：0-失败；1-成功
int Pop(PSeqStack SS, ElemType *ee)
{
	//检查是否空指针
	if ((SS == NULL) || (ee == NULL)) return 0;
	//检查是否空栈
	if (IsEmpty(SS) == 1) return 0;
	//出栈
	memcpy(ee, SS->data + SS->top, sizeof(ElemType));
	//指针减1
	SS->top--;
	return 1;

}

//求顺序栈的长度，返回值：栈SS中元素的个数
int Length(PSeqStack SS)
{
	//检查空指针
	if ((SS == NULL)) return 0;
	//返回栈长
	return SS->top + 1;
}

//判断顺序栈是否为空，返回值：1-空；0-非空或失败
int IsEmpty(PSeqStack SS)
{
	//检查空指针
	if (SS == NULL) return 0;
	//判断是否为空
	if (SS->top == -1) return 1;
	return 0;
}

//判断顺序栈是否为满，返回值：1-已满；0-未满或失败
int IsFull(PSeqStack SS)
{
	//检查空指针
	if (SS == NULL) return 0;
	//判断是否满
	if (SS->top + 1 == MAXSIZE) return 1;
	return 0;
}

//打印顺序栈中全部的元素
void PrintStack(PSeqStack SS)
{
	//检查空指针
	if (SS == NULL) return;
	//检查是否空栈
	if (IsEmpty(SS) == 1) return;
	
	//打印栈元素
	for (int ii = 0; ii <= SS->top; ++ii)
	{
		printf("data[%d]=%d\n", ii, *(SS->data + ii));
	}
}

//获取栈顶元素，返回值：0-失败；1-成功
//只查看栈顶元素的值，元素不出栈
int GetTop(PSeqStack SS, ElemType *ee)
{
	//检查空指针
	if ((SS == NULL) ||(ee==NULL)) return 0;
	//检查是否空栈
	if (IsEmpty(SS) == 1) return 0;
	//取值
	memcpy(ee, SS->data + SS->top, sizeof(ElemType));
	return 1;
 
}