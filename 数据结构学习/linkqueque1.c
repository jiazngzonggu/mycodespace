/*
 * 程序名：btree1.c 此程序演示二叉树的层次遍历
 * 作者：姜宗谷
 * 日期：2023年3月4日 19:04:07
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//二叉树的数据结构
typedef struct BiTNode
{
	char data;		//存放结点的数据元素
	struct BiTNode *lchild;	//指向左子结点地址的指针
	struct BiTNode *rchild;	//指向右子节点地址的指针
}BiTNode,*BiTree;


//队列的数据结构
#define MAXSIZE 30	//循环队列的最大长度，最多可以存放MAXSIZE-1个元素

typedef BiTree ElemType;	//自定义队列的元素为二叉树

typedef struct
{
	ElemType data[MAXSIZE];	//用数组存储循环队列中的元素
	int front;	//队列的头指针
	int rear;	//队列尾指针，指向队尾的下一个元素
}SeqQueue,*PSeqQueue;


//队列的操作函数
//循环队列QQ的初始化操作
void InitQueue(PSeqQueue QQ);

//元素入队，返回值：0-失败；1-成功
void InQueue(PSeqQueue QQ, ElemType *ee);

//元素出队，返回值：0-失败；1-成功
int OutQueue(PSeqQueue QQ, ElemType *ee);

//求循环队列的长度，返回值：>=0-队列QQ元素的个数
int Length(PSeqQueue QQ);

//清空循环队列
void Clear(PSeqQueue QQ);

//判断循环队列是否为空，返回值：1-空；0-非空或失败
int IsEmpty(PSeqQueue QQ);

//判断循环队列是否已满，返回值：1-已满，0-未满或失败
int IsFull(PSeqQueue QQ);

//二叉树的层次遍历
void LovelOrder(BiTree TT);

int main()
{


	return 0;
}

//队列的操作函数
//循环队列QQ的初始化操作
void InitQueue(PSeqQueue QQ)
{
	Clear(QQ);
}

//清空循环队列
void Clear(PSeqQueue QQ)
{
	if (QQ == NULL) return;	//检查空指针
	QQ->front = QQ->rear = 0;	//指针置为空
	memset(QQ->data, 0, sizeof(ElemType)*MAXSIZE);
}

//元素入队，返回值：0-失败；1-成功
void InQueue(PSeqQueue QQ, ElemType *ee)
{
	if ((QQ == NULL) || (ee == NULL)) return 0;	//检查空指针

	if (IsFull(QQ) == 1)
	{
		printf("循环队列已满，不能插入。\n");
		return 0;
	}
	memcpy(QQ->data + QQ->rear, ee, sizeof(ElemType));



}

//元素出队，返回值：0-失败；1-成功
int OutQueue(PSeqQueue QQ, ElemType *ee);

//求循环队列的长度，返回值：>=0-队列QQ元素的个数
int Length(PSeqQueue QQ);

//判断循环队列是否为空，返回值：1-空；0-非空或失败
int IsEmpty(PSeqQueue QQ);

//判断循环队列是否已满，返回值：1-已满，0-未满或失败
int IsFull(PSeqQueue QQ);

//二叉树的层次遍历
void LovelOrder(BiTree TT);