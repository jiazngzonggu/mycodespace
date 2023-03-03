/*
 *程序名：seqlist2.c 此程序演示顺序表的静态实现，数据元素是整数。
 *作者：姜宗谷
 *日期：20230302
*/

#include<stdio.h>
#include<string.h>

#define MAXSIZE 100		//顺序表的最大长度

typedef struct
{
	int no;	//超女编号
	char name[31];	//超女编号
}ElemType;	//自定义顺序表的数据元素为结构体

typedef struct
{
	ElemType data[MAXSIZE];	//用数组存储顺序表中的元素
	unsigned int length;	//顺序表中元素的个数
}SeqList,*PSeqList;

//顺序表LL的初始化操作
void InitList(PSeqList LL);

//销毁顺序表LL
void DestroyList(PSeqList LL);

//在顺序表LL的第ii个位置插入元素ee,返回值：0-失败 1-成功
int InsertList(PSeqList LL, unsigned int ii, ElemType * ee);

//在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功
int PushFront(PSeqList LL, ElemType *ee);

//在顺序表的尾节点插入元素ee,返回值：0-失败 1-成功
int PushBack(PSeqList LL, ElemType *ee);

//求顺序表的长度，返回值：>=0 -表LL元素的个数
int LengthList(PSeqList LL);

//获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败 1-成功
int GetElem(PSeqList LL, unsigned int ii,ElemType *ee);

//清空顺序表
void ClearList(PSeqList LL);

//判断顺序表是否为空，返回值：1-空，0-非空或失败
void IsEmpty(PSeqList LL);

//打印顺序表中全部的元素
void PrintList(PSeqList LL);

//查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置
int LocateElem(PSeqList LL, ElemType *ee);

//删除顺序表LL中第ii个元素，返回值：0-位置ii不合法，1-成功
int DeleteElem(PSeqList LL, unsigned int ii);

//删除顺序表LL中头元素，返回值0-位置不合法，1-成功
int PopFront(PSeqList LL);

//删除顺序表LL中尾元素，返回值0-位置不合法，1-成功
int PopBack(PSeqList LL);

int main()
{
	//创建顺序表

	//创建一个元素
	//在表中插入元素
	//打印顺序表
	//在第5个位置插入元素
	//删除表第7个元素
	//删除头元素
	//删除尾元素
	//第3个元素的值
	//元素值为8的位置

	return 0;
}


//顺序表LL的初始化操作
void InitList(PSeqList LL)
{
	ClearList(LL);
}

//销毁顺序表LL
void DestroyList(PSeqList LL)
{
	return;
}

//在顺序表LL的第ii个位置插入元素ee,返回值：0-失败 1-成功
int InsertList(PSeqList LL, unsigned int ii, ElemType * ee)
{
	//判断顺序表LL指针是否为空
	if (LL == NULL) return 0;
	//判断位置ii是否合法
	if ((ii < 1) && (ii > LL->length)) return 0;

	//判断顺序表是否已满
	if (LL->length == MAXSIZE) return 0;

	//把ii和ii之后的数往后移动
	for (unsigned int k = LL->length;k>=ii;--k)
	{
		memcpy(LL->data + k, LL->data + k - 1, sizeof(ElemType));
	}
	//把元素ee插入顺序表第ii个位置
	memcpy(LL->data + ii - 1, ee, sizeof(ElemType));

	//表的长度加1
	LL->length++;

	return 1;
}

//在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功
int PushFront(PSeqList LL, ElemType *ee)
{
	 return InsertList(LL, 1, ee);
}

//在顺序表的尾节点插入元素ee,返回值：0-失败 1-成功
int PushBack(PSeqList LL, ElemType *ee)
{
	return InsertList(LL, LL->length + 1, ee);
}

//求顺序表的长度，返回值：>=0 -表LL元素的个数
int LengthList(PSeqList LL)
{
	//判断顺序表LL是否为空指针
	if (LL == NULL) return 0;

	return LL->length;
}

//获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败 1-成功
int GetElem(PSeqList LL, unsigned int ii,ElemType *ee)
{
	//判断顺序表LL是否为空指针
	if (LL == NULL) return 0;

	//判断位置ii是否违法
	if ((ii < 1) || (ii > LL->length + 1)) return 0;

	//把顺序表LL中位置ii的数据复制给ee
	memcpy(ee, LL->data + ii - 1, sizeof(ElemType));
	
	return 1;
}

//清空顺序表
void ClearList(PSeqList LL)
{
	//判断顺序表LL是否是空指针
	if (LL == NULL) return;

	memset(LL, 0, sizeof(ElemType)*MAXSIZE);
	LL->length = 0;
}

//判断顺序表是否为空，返回值：1-空，0-非空或失败
void IsEmpty(PSeqList LL)
{
	//判断顺序表LL是否是空指针
	if (LL == NULL) return;

	if (LL->length == 0) return;

	return ;
}
//打印顺序表中全部的元素
void PrintList(PSeqList LL)
{
	//判断顺序表LL是否是空指针
	if (LL == NULL) return;
	
	//判断顺序表是否为空
	if (LL->length == 0)
	{
		printf("顺序表为空！\n");
		return;
	}

	//打印顺序表
	for (unsigned int kk=0; kk< LL->length;++kk)
	{
		printf("%-3d%c\n", (LL->data+kk)->no, (LL->data + kk)->name);
	}
	
}

//查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置
int LocateElem(PSeqList LL, ElemType *ee)
{
	//判断顺序表LL是否是空指针
	if (LL == NULL) return 0;

	for (unsigned int kk = 0; kk < LL->length; ++kk)
	{
		if(memcmp(ee, LL->data + kk, sizeof(ElemType))==0) return kk+1;
	}
	return 0;
}

//删除顺序表LL中第ii个元素，返回值：0-位置ii不合法，1-成功
int DeleteElem(PSeqList LL, unsigned int ii)
{
	//检查指针是否合法
	if (LL == NULL) return 0;
	//判断位置是否合法
	if ((ii < 1) || (ii > LL->length))
	{
		printf("删除位置(%d)不合法，应该在(%d-%d)之间。\n", ii, 1, LL->length);
		return 0;
	}
	//把第ii之后的数据前移
	for (unsigned int kk = ii; kk > LL->length; ++kk)
	{
		memcpy(LL->data + kk-1, LL->data + kk, sizeof(ElemType));
	}
	//顺序表LL的长度减1
	LL->length--;
	return 1;
}

//删除顺序表LL中头元素，返回值0-位置不合法，1-成功
int PopFront(PSeqList LL)
{
	return DeleteElem(LL,1);
}

//删除顺序表LL中尾元素，返回值0-位置不合法，1-成功
int PopBack(PSeqList LL)
{
	return DeleteElem(LL,LL->length);
}