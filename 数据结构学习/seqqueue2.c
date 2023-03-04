/*
 * 程序名：seqqueue2.c,此程序演示循环队列的数组实现，队尾指针指向队尾的下一个元素，增加了length的辅助变量
 * 作者：姜宗谷
 * 时间：2023年3月4日 11:29:29
*/

#include<stdio.h>
#include<string.h>

#define MAXSIZE 10

typedef ElemType;	//自定义循环队列的数据元素为整数

typedef struct 
{
	ElemType data[MAXSIZE];//数据区
	int front;	//队列的头指针
	int rear;	//队列的尾指针
	int length;	//队列的实际长度

}SeqQueue,*PSeqQueue;	//结构体类型名

//循环队列QQ的初始化操作
void InitQueue(PSeqQueue QQ);

//销毁循环队列QQ
void DestroyQueue(PSeqQueue QQ);

//元素入队，返回值：0-失败；1-成功
int InQueue(PSeqQueue QQ, ElemType *ee);

//元素出队，返回值：0-失败；1-成功
int OutQueue(PSeqQueue QQ, ElemType *ee);

//求循环队列的长度，返回值：>=0 -队列QQ元素的个数
int Length(PSeqQueue QQ);

//清空循环队列
void Clear(PSeqQueue QQ);

//判断循环队列是否为空,返回值：1-空；0-非空或者失败
int IsEmpty(PSeqQueue QQ);

//判断循环队列是否已满，返回值：1-已满，0-未满或失败
int IsFull(PSeqQueue QQ);

//打印循环队列中全部的元素
void PrintQueue(PSeqQueue QQ);

//获取对头元素，返回值：0-失败；1-成功
//只查看队头元素的值，元素不出队
int GetHead(PSeqQueue QQ, ElemType *ee);

int main()
{
	SeqQueue QQ;     // 创建循环队列。

	InitQueue(&QQ);  // 初始化循环队列。

	ElemType ee;     // 创建一个数据元素。

	printf("元素（1、2、3、4、5、6、7、8、9、10、11）入队。\n");
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

	printf("队列的长度是%d\n", Length(&QQ));
	PrintQueue(&QQ);

	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);

	printf("队列的长度是%d\n", Length(&QQ));
	PrintQueue(&QQ);

	printf("元素（11、12、13、14、15）入队。\n");
	ee = 11;  InQueue(&QQ, &ee);
	ee = 12;  InQueue(&QQ, &ee);
	ee = 13;  InQueue(&QQ, &ee);
	ee = 14;  InQueue(&QQ, &ee);
	ee = 15;  InQueue(&QQ, &ee);

	printf("队列的长度是%d\n", Length(&QQ));

	PrintQueue(&QQ);

	// 只查看队头元素的值，元素不出队。
	if (GetHead(&QQ, &ee) == 1)  printf("队头的元素值为%d\n", ee);

	return 0;

}

//循环队列QQ的初始化操作
void InitQueue(PSeqQueue QQ)
{
	Clear(QQ);
}

//清空循环队列
void Clear(PSeqQueue QQ)
{
	//检查空指针
	if (QQ == NULL) return;

	//置0
	QQ->front = QQ->rear = QQ->length = 0;
	//数组元素清零
	memset(QQ->data, 0, sizeof(ElemType)*MAXSIZE);
}

//销毁循环队列QQ
void DestroyQueue(PSeqQueue QQ)
{
	//静态循环队列无需释放内存，不需要销毁操作
	Clear(QQ);
}

//元素入队，返回值：0-失败；1-成功
int InQueue(PSeqQueue QQ, ElemType *ee)
{
	//检查空指针
	if ((QQ == NULL) || (ee == NULL)) return 0;
	//判断队列是否已满
	if (IsFull(QQ) == 1) return 0;
	//插入队列
	memcpy(QQ->data + QQ->rear, ee, sizeof(ElemType));
	//队尾指针后移
	/*QQ->rear = QQ->rear + 1;
	if (QQ->rear >= MAXSIZE) QQ->rear = QQ->rear - MAXSIZE;*/
	QQ->rear = (QQ->rear + 1) % MAXSIZE;

	//队列长度加1
	QQ->length++;

}

//元素出队，返回值：0-失败；1-成功
int OutQueue(PSeqQueue QQ, ElemType *ee)
{
	//检查空指针
	if ((QQ == NULL) || (ee == NULL)) return 0;
	//队列是否为空
	if (IsEmpty(QQ) == 1) return 0;
	//数据出栈
	memcpy(ee, QQ->data + QQ->front, sizeof(ElemType));
	//队首后移
	QQ->front = (QQ->front + 1) % MAXSIZE;
	//队长减1
	QQ->length--;
	return 1;
}

//求循环队列的长度，返回值：>=0 -队列QQ元素的个数
int Length(PSeqQueue QQ)
{
	if (QQ == NULL) return 0;
	return QQ->length;
}

//判断循环队列是否为空,返回值：1-空；0-非空或者失败
int IsEmpty(PSeqQueue QQ)
{
	//检查空指针
	if (QQ == NULL)return 0;
	//判断是否为空
	if (QQ->length != 0) return 1;
	
	return 0;
}

//判断循环队列是否已满，返回值：1-已满，0-未满或失败
int IsFull(PSeqQueue QQ)
{
	//检查空指针
	if (QQ == NULL)return 0;
	//判断是否为空
	if (QQ->length == MAXSIZE) return 1;

	return 0;
}

//打印循环队列中全部的元素
void PrintQueue(PSeqQueue QQ)
{
	//检查空指针
	//检查空指针
	if (QQ == NULL)return;
	//检查是否空队列
	if (QQ->length == 0) return;
	//循环打印队列
	for (int ii = 0; ii < QQ->length; ++ii)
	{
		printf("data[%d]=%d\n", (QQ->front + ii) % MAXSIZE, QQ->data[(QQ->front + ii) % MAXSIZE]);
	}
}

//获取对头元素，返回值：0-失败；1-成功
//只查看队头元素的值，元素不出队
int GetHead(PSeqQueue QQ, ElemType *ee)
{
	if ((QQ == NULL) || (ee == NULL)) return 0;   // 检查空指针。

	if (IsEmpty(QQ) == 1) { printf("队列为空。\n"); return 0; }

	memcpy(ee, &QQ->data[QQ->front], sizeof(ElemType));  // 用数组的下标访问。
	// memcpy(ee,QQ->data+QQ->front,sizeof(ElemType));    // 采用指针运算也可以。

	return 1;
}
