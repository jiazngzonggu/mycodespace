/*
 * 程序名：seqlist3.c，此程序演示顺序表的动态实现，数据元素是整数。
 * 作者：姜宗谷 日期：20230302
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define INITSIZE	10		//顺序表的初始长度
#define EXTSIZE		5		//每次扩展元素的个数

typedef int ElemType;		//自定义顺序表的元素为整数

typedef struct
{
	ElemType *data;			//存储顺序表中元素的首地址
	unsigned int maxsize;	//顺序表元素的最大长度
	unsigned int length;	//顺序表中元素的个数
}SeqList,*PSeqList;

//顺序表LL的初始化操作
void InitList(PSeqList LL);

//销毁顺序表LL
void DestroyList(PSeqList LL);

//拓展顺序表的内存空间,返回值：0-失败；1-成功
int ExtList(PSeqList LL);

//在顺序表LL的第ii个位置插入元素ee,返回值：0-失败；1-成功
int InsertList(PSeqList LL, unsigned int ii, ElemType *ee);

//在顺序表LL的头结点插入元素ee,返回值0-失败，1-成功
int PushFront(PSeqList LL, ElemType *ee);

//在顺序表LL的尾结点插入元素ee,返回值0-失败，1-成功
int PushBack(PSeqList LL, ElemType *ee);

//求顺序表的长度，返回值：>=0 -表LL元素的个数
int LengthList(PSeqList LL);

//获取顺序表第ii个元素的值，存放在ee中，返回值：0-失败；1-成功
int GetElem(PSeqList LL, unsigned int ii, ElemType *ee);

//清空顺序表
void ClearList(PSeqList LL);

//判断顺序表是否为空，返回值：1-空；0-非空或失败
int IsEmpty(PSeqList LL);

//打印顺序表中全部的元素
void PrintList(PSeqList LL);

//查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中
int LocateElem(PSeqList LL, ElemType *ee);

//删除顺序表LL中的位置，返回值：0-位置ii不合法；1-成功
int DeleteElem(PSeqList LL, unsigned int ii);

//删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功
int PopFront(PSeqList LL);

//删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功
int PopBack(PSeqList LL);



int main()
{


	return 0;
}


//顺序表LL的初始化操作
void InitList(PSeqList LL)
{
	LL->data = (ElemType *)malloc(sizeof(ElemType)*INITSIZE);//申请内存空间
	LL->maxsize = INITSIZE;

	//清空顺序表
	ClearList(LL);
}

//销毁顺序表LL
void DestroyList(PSeqList LL)
{
	free(LL->data);
	LL->length = 0;
	LL->maxsize = 0;
}

//拓展顺序表的内存空间,返回值：0-失败；1-成功
int ExtList(PSeqList LL)
{
	//申请堆内存空间
	ElemType *newdata = (ElemType*)malloc(sizeof(ElemType)*(LL->length + EXTSIZE));

	//如果分配失败，返回0
	if (newdata == NULL) return 0;
	
	//初始化mewdata空间
	memset(newdata, 0, sizeof(ElemType)*(LL->length + EXTSIZE));

	//把顺序表中原来的内容复制到新分配的内存空间中
	memcpy(newdata, LL->data, sizeof(ElemType)*LL->maxsize);
	
	//释放原来的内存空间
	free(LL->data);

	//把顺序表元素的指针指向新分配的内存空间地址
	LL->data = newdata;

	//重置顺序表的maxsize变量
	LL->maxsize = LL->maxsize + EXTSIZE;

	return 1;
}

//在顺序表LL的第ii个位置插入元素ee,返回值：0-失败；1-成功
int InsertList(PSeqList LL, unsigned int ii, ElemType *ee)
{
	//检查空指针
	if (LL == NULL) return 0;
	//判断ii是否越界
	if ((ii < 1) || (ii > LL->length + 1))
	{
		printf("插入位置(%d)不合法，应该在(%d-%d)之间。\n", ii, 1, LL->length + 1);
		return 0;
	}
	//第ii位置和之后的元素往后移动1个位置
	for (unsigned int kk = LL->length; kk >= ii; --kk)
	{
		memcpy(LL->data + kk, LL->data + kk - 1, sizeof(ElemType));
	}
	//把元素ee写到顺序表第ii个位置处
	memcpy(LL->data + ii - 1, ee, sizeof(ElemType));
	//顺序表LL的长度加1
	LL->length + 1;

	return 1;
}

//在顺序表LL的头结点插入元素ee,返回值0-失败，1-成功
int PushFront(PSeqList LL, ElemType *ee)
{
	return InsertList(LL, 1, ee);
}

//在顺序表LL的尾结点插入元素ee,返回值0-失败，1-成功
int PushBack(PSeqList LL, ElemType *ee)
{
	return InsertList(LL, LL->length + 1, ee);
}

//求顺序表的长度，返回值：>=0 -表LL元素的个数
int LengthList(PSeqList LL)
{
	//检查空指针
	if (LL == NULL) return 0;
	//返回顺序表LL长度
	return LL->length;
}

//获取顺序表第ii个元素的值，存放在ee中，返回值：0-失败；1-成功
int GetElem(PSeqList LL, unsigned int ii, ElemType *ee)
{
	//检查空指针
	if (LL == NULL) return 0;
	//判断ii是否越界
	if ((ii < 1) || (ii > LL->length)) return 0;
	
	//获取ii个元素的值
	memcpy(ee, LL->data + ii - 1, sizeof(ElemType));
	return;
}

//清空顺序表
void ClearList(PSeqList LL)
{
	//检查空指针
	if (LL == NULL) return;

	LL->length = 0;
	memset(LL->data, 0, sizeof(ElemType)*LL->maxsize);

}

//判断顺序表是否为空，返回值：1-空；0-非空或失败
int IsEmpty(PSeqList LL)
{
	//检查空指针
	if (LL == NULL) return 0;

	if (LL->length == 0) return 1;

	return 0;
}

//打印顺序表中全部的元素
void PrintList(PSeqList LL)
{
	//检查空指针
	if (LL == NULL) return;

	if (LL->length == 0)
	{
		printf("表为空。\n");
		return;
	}

	for (unsigned int kk = 0; kk < LL->length; ++kk)
	{
		printf("%-3d", *(LL->data + kk));
	}
	printf("\n");
}

//查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中
int LocateElem(PSeqList LL, ElemType *ee)
{
	//检查空指针
	if (LL == NULL) return;

	for (unsigned int kk = 0; kk < LL->length; ++kk)
	{
		if (*(LL->data + kk) == *ee) return kk + 1;
	}
	return 0;

}

//删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功
int DeleteElem(PSeqList LL, unsigned int ii)
{
	//检查空指针
	if (LL == NULL) return;

	//把ii之后的元素前移
	for (unsigned int kk = ii; kk <= LL->length; ++kk)
	{
		memcpy(LL->data + kk - 1, LL->data + kk, sizeof(ElemType));
	}
	LL->length--;
	return 1;

}

//删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功
int PopFront(PSeqList LL)
{
	return DeleteElem(LL, 1);
}

//删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功
int PopBack(PSeqList LL)
{
	return DeleteElem(LL,LL->length);
}

