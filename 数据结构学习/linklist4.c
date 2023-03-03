/*
 * 程序名：linklist4.c，此程序演示带头结点的双链表的实现，数据元素是整数。
 * 作者：姜宗谷 日期：20201230
*/

#include<stdio.h>
#include<string.h>
#include<stdio.h>

typedef int ElemType;	//自定义链表的数据元素为整数

typedef struct DNode
{
	ElemType data;	//存放节点的数据元素。
	struct DNode *prior, *next;	//前驱和后继结点的指针
}DNode,*LinkList;

//初始化链表LL，返回值：失败返回NULL,成功返回头结点的地址
DNode *IintList1();

//传入指针变量的地址的方法。
//初始化链表，返回值：0-失败；1-成功
int InitList2(LinkList *LL);

//销毁链表LL
//传入指针的地址的方法
void DestroyList1(LinkList LL);

//销毁链表LL
//传入指针的地址的方法。
void DestroyList2(LinkList *LL);

//清空链表
void ClearList(LinkList LL);

//在链表LL的第ii个位置插入元素ee,返回值：0-失败；1-成功
int InsertList(LinkList LL, unsigned int ii, ElemType *ee);

//打印链表中全部的元素
void PrintList(LinkList LL);

//在链表LL的头部插入元素ee，返回值：0-失败，1-成功
int PushFront(LinkList LL, ElemType *ee);

//在链表尾部插入元素ee,返回值：0-失败，1-成功
int PushBack(LinkList LL, ElemType *ee);

//删除链表LL中的第ii个结点，返回值：0-位置ii不合法，1-成功
int DeleteNode(LinkList LL, unsigned int ii);

//删除链表LL中的第一个结点，返回值：0-位置不合法，1-成功
int PopFront(LinkList LL);

//删除链表LL中的最后一个结点，返回值：0-位置不合法，1-成功
int PopBack(LinkList LL);

//求链表的长度，返回值：>=0 -链表LL结点的个数
int LengthList(LinkList LL);

//判断链表是否为空，返回值：0-非空或者失败，1-空
int IsEmpty(LinkList LL);

//获取链表中第ii个结点，成功返回结点的地址，失败返回空
//注意：ii可以取值为0,表示头结点。
DNode *LocateNode(LinkList LL, unsigned int ii);

//查找元素ee在链表LL中的结点地址，如果没找到返回NULL,否则返回结点的地址
DNode *LocalElem(LinkList LL, ElemType *ee);

//在指定结点pp之后插入元素ee,返回值：0-失败；1-成功
int InsertNextNode(DNode *pp, ElemType *ee);

//在指定结点pp之前插入元素ee,返回值：0-失败，1-成功
int InsertFrontNode(DNode *pp, ElemType *ee);

//删除指定结点
int DeleteNode1(DNode *pp);

int main()
{


	return 0;
}

//初始化链表LL，返回值：失败返回NULL,成功返回头结点的地址
DNode *IintList1()
{
	//分配头结点
	DNode *head = (DNode *)malloc(sizeof(DNode));

	//申请内存失败，返回失败
	if (head == NULL) return NULL;

	//前驱和后继都置为空
	head->prior = head->next = NULL;

	//返回头结点
	return head;
}

//传入指针变量的地址的方法。
//初始化链表，返回值：0-失败；1-成功
int InitList2(LinkList *LL)
{
	//分配内存
	DNode* head = (DNode *)malloc(sizeof(DNode));

	//判断内存是否申请成功
	if (head == NULL) return 0;

	//把head的前驱后继都置为空
	head->prior = head->next = NULL;

	//把头结点地址赋值给LL
	*LL = head;
	return 1;
}

//销毁链表LL
//传入指针的地址的方法
void DestroyList1(LinkList LL)
{
	//销毁链表LL是指释放链表全部的结点，包括头结点
	DNode *tmp;

	while (LL != NULL)
	{
		tmp = LL->next;//tmp保存下一节点的地址
		free(LL);//释放当前结点
		LL = tmp;
	}
	return;
}

//销毁链表LL
//传入指针的地址的方法。
void DestroyList2(LinkList *LL)
{
	//如果函数的参数是指针的指针，可以启用下面代码。
	DNode *tmp1, *tmp2;
	tmp1 = *LL;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;	//tmp保存下一节点的地址
		free(tmp1);			//释放当前结点
		tmp1 = tmp2;		//LL指针移动到下一节点
	}
	*LL = NULL;//把链表指针置为空，表示链表不存在了
	return;
}

//清空链表
void ClearList(LinkList LL)
{
	//清空链表LL是指释放链表全部的点，但不包括头结点。
	if (LL == NULL) return;

	DNode *tmp1;
	DNode *tmp2 = LL->next;	//保留头结点，从头结点的下一个结点开始释放

	while (tmp2 != NULL)
	{
		tmp1 = tmp2->next;
		free(tmp2);
		tmp2 = tmp1;
	}

	LL->next = NULL;	//这行代码一定不能少，否则会留下野指针
	return;
}

//在链表LL的第ii个位置插入元素ee,返回值：0-失败；1-成功
int InsertList(LinkList LL, unsigned int ii, ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		printf("链表LL或元素ee不存在。\n");
		return 0;
	}
	//判断插入位置是否合法
	if (ii < 1)
	{
		printf("插入位置(%d)不合法，应该在大于0.", ii);
		return 0;
	}

	//要在位序ii插入结点，必须找到ii-1结点
	DNode *pp = LL;	//指针pp指向头结点，逐步往后移动，如果为空，表示后没没有结点
	int kk = 0;		//kk指向的是第几个结点，从头结点0开始，pp每向后移动一次，kk加1
	while ((pp != NULL) && (kk < ii - 1))
	{
		pp = pp->next;
		++kk;
	}
	if (pp == NULL)
	{
		printf("位置(%d)不合法，超过了表长。\n", ii);
		return 0;
	}

	//申请内存
	DNode *tmp = (DNode *)malloc(sizeof(DNode));//分配一个结点
	if (tmp == NULL) return 0;//内存不足，返回失败

	//考虑元素为结构体的情况，这里采用了memcpy的方法而不是直接赋值
	memcpy(&(tmp->data), ee, sizeof(ElemType));

	//处理前驱后续结点的指针
	tmp->next = pp->next;
	tmp->prior = pp;
	//特殊处理，如果是在尾部插入，tmp->next根本不存在
	if (tmp->next != NULL) tmp->next->prior = tmp;
	pp->next = tmp;
	return 1;
}

//打印链表中全部的元素
void PrintList(LinkList LL)
{
	//判断链表LL是否存在，不存在则返回
	if (LL == NULL)
	{
		printf("聊表LL不存在。\n");
		return;
	}
	//从第一个结点开始
	DNode *pp = LL->next;
	while (pp != NULL)
	{
		printf("%-3d", pp->data);
		pp = pp->next;
	}
	printf("\n");
}

//在链表LL的头部插入元素ee，返回值：0-失败，1-成功
int PushFront(LinkList LL, ElemType *ee)
{
	return InsertList(LL, 1, ee);
}

//在链表尾部插入元素ee,返回值：0-失败，1-成功
int PushBack(LinkList LL, ElemType *ee)
{
	//判断链表LL和结点ee是否为空
	if ((LL == NULL) || (ee == NULL))
	{
		printf("链表LL或元素ee不存在.\n");
		return 0;
	}
	//从头结点开始
	DNode *pp = LL;	
	
	//找到最后一个结点
	while (pp->next != NULL)
	{
		pp = pp->next;
	}
	
	//分配一个结点
	DNode *tmp = (DNode *)malloc(sizeof(DNode));
	//内存不足，返回失败
	if (tmp == NULL) return 0;

	//考虑数据元素为结构体的情况，这里采用了memcpy的方法而不是直接赋值
	memcpy(&(tmp->data), ee, sizeof(ElemType));

	//处理前驱后继结点的指针
	tmp->next = pp->next;
	tmp->prior = pp;
	//特殊处理，如果是在尾部插入，tmp->next根本不存在
	pp->next = tmp;
	return 1;
}

//删除链表LL中的第ii个结点，返回值：0-位置ii不合法，1-成功
int DeleteNode(LinkList LL, unsigned int ii)
{
	if (LL == NULL)
	{
		printf("链表LL不存在。\n");
		return 0;
	}
	//判断删除位置是否合法
	if (ii < 1)
	{
		printf("删除位置(%d)不合法，应该大于0。\n");
		return 0;
	}
	//要删除位序ii结点，必须找到ii-1结点
	DNode *pp = LL;	//指针pp指向头结点，逐步往后移动，如果为空，表示后没结点了
	int kk = 0;	//	kk指向的是第几个结点，从头结点0开始，pp每向后移动一次，kk就加1
	while ((pp != NULL) && (kk < ii - 1))
	{
		pp = pp->next;
		++kk;
	}
	//判断位置是否超过表长
	if (pp->next == NULL)
	{
		printf("位置(%d)不合法，超过了表长。\n", ii);
		return 0;
	}
	DNode *tmp = pp->next;	//tmp为将要删除的结点

	//处理前去后续结点的指针
	pp->next = tmp->next;
	//特殊处理，如果tmp是尾节点，tmp->next根本不存在
	if (tmp->next != NULL) tmp->next->prior = pp;	
	//释放结点
	free(tmp);
	return 1;

}

//删除链表LL中的第一个结点，返回值：0-位置不合法，1-成功
int PopFront(LinkList LL)
{
	return DeleteNode(LL, 1);
}

//删除链表LL中的最后一个结点，返回值：0-位置不合法，1-成功
int PopBack(LinkList LL)
{
	if (LL == NULL)
	{
		printf("链表LL不存在。\n");
		return 0;
	}

	//必须加上这个判断，不用误删了头结点
	if (LL->next == NULL)
	{
		printf("链表LL为空，没有尾节点。\n");
		return 0;
	}
	//如果是单链表，要删除最后一个结点，必须找到最后一个结点的前一个结点
	//如果是双链表，要删除最后一个结点，找到最后一个结点或最后一个结点的前一个结点都可以
	DNode *pp = LL;	//从第0个结点开始

	//找到最后一个结点
	while (pp->next != NULL)
		pp = pp->next;

	//把最后一个结点的前一节点的next指针置为空
	pp->prior->next = NULL;

	//释放最后一个结点
	free(pp);
	return 1;

}

//求链表的长度，返回值：>=0 -链表LL结点的个数
int LengthList(LinkList LL)
{
	//检查链表指针是否为空
	if (LL == NULL)
	{
		printf("链表LL不存在。\n");
		return 0;
	}

	//从第一个结点开始
	DNode *tmp = LL;
	int length = 0;
	while (tmp->next != NULL)
	{
		tmp=tmp->next;
		++length;
	}
	return length;

}

//判断链表是否为空，返回值：0-非空或者失败，1-空
int IsEmpty(LinkList LL)
{
	if (LL == NULL) return 0;
	if (LL->next == NULL)return 1;

	return 0;
}

//获取链表中第ii个结点，成功返回结点的地址，失败返回空
//注意：ii可以取值为0,表示头结点。
DNode *LocateNode(LinkList LL, unsigned int ii)
{
	if (LL == NULL)
	{
		printf("链表LL不存在。\n");
		return LL;
	}
	DNode *pp = LL;	//指针pp指向头结点，逐步往后移动，如果为空，表示后没没结点了
	int kk = 0;		//kk指向的是第几个结点，从头结点0开始，pp每向后移动一次，kk就加1
	while ((pp != NULL) && (kk < ii))
	{
		pp = pp->next;
		++kk;
	}
	if (pp == NULL)
	{
		printf("位置(%d)不合法，超过了表长。\n.", ii);
		return NULL;
	}
	return pp;
}

//查找元素ee在链表LL中的结点地址，如果没找到返回NULL,否则返回结点的地址
DNode *LocalElem(LinkList LL, ElemType *ee)
{
	DNode *pp = LL->next;	//从第1个数据结点开始
	while (pp != NULL)
	{
		//如果数据元素是结构体，以下代码要修改
		if (pp->data == *ee) return pp;

		pp = pp->next;
	}
	return NULL;
}

//在指定结点pp之后插入元素ee,返回值：0-失败；1-成功
int InsertNextNode(DNode *pp, ElemType *ee)
{
	if (pp == NULL) 
	{	
		printf("结点pp不存在.\n"); 
		return 0; 
	}

	DNode *tmp = (DNode *)malloc(sizeof(DNode));
	if (tmp == NULL) return 0;
	memcpy(&tmp->data, ee, sizeof(ElemType));

	//处理前去后续结点的指针
	tmp->next = pp->next;
	tmp->prior = pp;
	if (tmp->next != NULL)
	{
		tmp->next->prior = tmp;
	}

	pp->next = tmp;
	return 1;
}

//在指定结点pp之前插入元素ee,返回值：0-失败，1-成功
int InsertFrontNode(DNode *pp, ElemType *ee)
{
	if (pp == NULL)
	{
		printf("结点pp不存在。\n");
		return 0;
	}

	DNode *tmp = (DNode *)malloc(sizeof(DNode));
	if (tmp == NULL) return 0;

	//把待插入的元素存入tmp中
	memcpy(&tmp->data, ee, sizeof(ElemType));

	//处理前驱后继的指针
	tmp->prior = pp->prior;
	pp->prior->next = tmp;
	tmp->next = pp;
	pp->prior = tmp;
	return 1;
}

//删除指定结点
int DeleteNode1(DNode *pp)
{
	if (pp == NULL)
	{
		printf("结点pp不存在。\n");
		return 0;
	}
	pp->prior->prior = pp->next;
	if (pp->next != NULL) pp->next->prior = pp->prior;
	return 1;
}

