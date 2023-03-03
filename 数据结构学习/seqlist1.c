/*
 *程序名：seqlist.c 此程序演示顺序表的静态实现，数据元素是整数。
 *作者：姜宗谷
 *日期：20230301
*/

#include<string.h>
#include<stdio.h>

#define MAXSIZE 100		//顺序表的最大长度
typedef int ElemType;	//自定义顺序表的数据元素为整数

typedef struct
{
	ElemType data[MAXSIZE];	//用数组存储顺序表中的元素
	unsigned int length;	//顺序表中元素的个数
}SeqList,*PSeqList;

//顺序表LL的初始化操作
void InitList(PSeqList LL);

//销毁顺序表LL
void DestoryList(PSeqList LL);

//在顺序表LL的第ii个位置插入元素ee,返回值：0-失败，1-成功
int InsertList(PSeqList LL, unsigned int ii, ElemType *ee);

//在顺序表LL的头节点插入元素ee,返回值：0-失败，1-成功
int PushFront(PSeqList LL, ElemType *ee);

//在顺序表LL的尾节点插入元素ee,返回值：0-失败，1-成功
int PushBack(PSeqList LL, ElemType *ee);

//求顺序表的长度，返回值：>=0-表LL元素的个数
int LengthList(PSeqList LL);

//获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败，1-成功
int GetElem(PSeqList LL, unsigned int ii, ElemType *ee);

//清空顺序表
void ClearList(PSeqList LL);

//判断顺序表是否为空，返回值：1-空，0-非空或者失败
int IsEmpty(PSeqList LL);

//打印顺序表中全部的元素
void PrintList(PSeqList LL);

//查找ee在顺序表LL中的位置，返回：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置
int LocateElem(PSeqList LL, ElemType *ee);

//删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法，1-成功
int DeleteElem(PSeqList LL,unsigned int ii);

//删除顺序表LL中头元素，返回值：0-位置ii不合法，1-成功
int PopFront(PSeqList LL);

//删除顺序表LL中尾元素，返回值：0-位置ii不合法，1-成功
PopBack(PSeqList LL);

//采用并归的方法，将两个升序的顺序表La和Lb合并成一个升序的顺序表Lc
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc);

int main()
{
	SeqList LL;	//创建顺序表

	ElemType ee;	//创建一个数据元素

	//初始化顺序表
	InitList(&LL);

	printf("在表中插入元素（1,2,3,4,5,6,7,8,9,10）。\n");
	ee = 1; InsertList(&LL, 1, &ee);
	ee = 2; InsertList(&LL, 1, &ee);
	ee = 3; InsertList(&LL, 1, &ee);
	ee = 4; InsertList(&LL, 1, &ee);
	ee = 5; InsertList(&LL, 1, &ee);
	ee = 6; InsertList(&LL, 1, &ee);
	ee = 7; InsertList(&LL, 1, &ee);
	ee = 8; InsertList(&LL, 1, &ee);
	ee = 9; InsertList(&LL, 1, &ee);
	ee = 10; InsertList(&LL, 1, &ee);

	PrintList(&LL);

	return 0;
}

//顺序表LL的初始化操作
void InitList(PSeqList LL)
{
	ClearList(LL);	//	清空顺序表
}

//销毁顺序表LL
void DestoryList(PSeqList LL)
{
	return;
}

//在顺序表LL的第ii个位置插入元素ee,返回值：0-失败，1-成功
int InsertList(PSeqList LL, unsigned int ii, ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL)) return 0;	//检查空指针

	if (LL->length >= MAXSIZE)
	{
		printf("顺序表已满，不能插入。\n");
		return 0;
	}
	
	//判断插入位置是否合法
	if ((ii < 1) || (ii > LL->length+1))
	{
		printf("插入位置(%d)不合法，应该在(%d=%d)之间。\n", ii, 1, LL->length+1);
		return 0;
	}

	//把ii和ii之后的元素后移
	int kk;
	for (kk = LL->length; kk >= ii; --kk)
	{
		memcpy(LL->data + kk, LL->data + kk - 1, sizeof(ElemType));//采用memcpy是为了支持ee结构体的情况
		//memcpy(&LL->data[kk], &LL->data[kk - 1], sizeof(ElemType));
	
	}

	memcpy(LL->data + ii - 1, ee, sizeof(ElemType));//采用memcpy是为了支持ee是结构体的情况

	LL->length++;	//表的长度加1；

	return 1;
}

//在顺序表LL的头节点插入元素ee,返回值：0-失败，1-成功
int PushFront(PSeqList LL, ElemType *ee)
{
	return InsertList(LL, 1, ee);
}

//在顺序表LL的尾节点插入元素ee,返回值：0-失败，1-成功
int PushBack(PSeqList LL, ElemType *ee)
{
	return InsertList(LL, LL->length+1, ee);
}
//求顺序表的长度，返回值：>=0-表LL元素的个数
int LengthList(PSeqList LL)
{
	if (LL == NULL) return 0;	//	检查空指针
	
	return LL->length;	

}

//获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败，1-成功
int GetElem(PSeqList LL, unsigned int ii, ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL)) return 0;	//检查空指针

	//判断ii位置是否合法
	if ((ii < 1) || (ii > LL->length)) return 0;

	memcpy(ee, LL->data + ii - 1, sizeof(ElemType));	//采用memcpy是为了支持结构体
}



//清空顺序表
void ClearList(PSeqList LL)
{
	if (LL == NULL) return;

	LL->length = 0;	//表长置为0
	memset(LL->data,0,sizeof(ElemType)*MAXSIZE);	//对顺序表LL->data数据进行数组清零，长度为MAXSIZE
}

//判断顺序表是否为空，返回值：1-空，0-非空或者失败
int IsEmpty(PSeqList LL)
{
	if (LL == NULL)	return 0;	//检查空指针

	if (LL->length == 0) return 1;

	return 0;
}

//打印顺序表中全部的元素
void PrintList(PSeqList LL)
{
	if (LL == NULL) return;	//判断空指针

	if (LL->length == 0)
	{
		printf("表为空。\n");
		return;
	}
	
	for (int kk = 0; kk < LL->length; ++kk)
	{
		printf("%-3d", *(LL->data + kk));
	}
	printf("\n");
}

//查找ee在顺序表LL中的位置，返回：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置
int LocateElem(PSeqList LL, ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL)) return 0;	//判断空指针

	int kk;
	for (kk = 0; kk < LL->length; kk++)
	{
		if (*(LL->data + kk) == (*ee)) return kk + 1;	//在表中对应序号为kk+1
	}

	return 0;
}
//删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法，1-成功
int DeleteElem(PSeqList LL, unsigned int ii)
{
	if (LL == NULL) return 0;	//	检查空指针

	//判断删除位置是否合法
	if ((ii < 1) || (ii > LL->length))
	{
		printf("删除位置(%d)不合法，应该在(%d-%d)之间。\n", ii, LL->length);
	}

	//把ii之后的元素前移
	int k;
	for (int k = ii; k <= LL->length; ++k)
	{
		memcpy(LL->data + k - 1, LL->data + k, sizeof(ElemType));
	}
	LL->length--;	//	表的长度减一
}

//删除顺序表LL中头元素，返回值：0-位置ii不合法，1-成功
int PopFront(PSeqList LL)
{
	return DeleteElem(LL, 1);

}

//删除顺序表LL中尾元素，返回值：0-位置ii不合法，1-成功
PopBack(PSeqList LL)
{
	return DeleteElem(LL, LL->length);
}

//采用并归的方法，将两个升序的顺序表La和Lb合并成一个升序的顺序表Lc
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc)
{
	if ((La == NULL) || (Lb == NULL) || (Lc == NULL)) return 0;//检查空指针

	if (Lc->length < La->length + Lb->length)
	{
		printf("表Lc的长度不够。\n");
		return 0;
	}
	
	int istartla = 0;	//表La第一个元素的位置
	int istartlb = 0;	//表Lb第一个元素的位置
	int istartlc = 0;	//表Lc第一个元素的位置
	
	//把La和Lb合并到Lc中
	while (istartla < La->length && istartlb < Lb->length)
		Lc->data[istartlc++] = La->data[istartla] < Lb->data[istartlb] ? La->data[istartla++] : Lb->data[istartlb++];

	//把Lb其他的元素追加到Lc中
	while (istartla < La->length)
		Lc->data[istartlc++] = La->data[istartla++];

	//把Lc其他的元素追加到Lc中
	while (istartlb < Lb->length)
		Lc->data[istartlc++] = Lb->data[istartlb++];
	


}



