/*
 * 程序名：linklist2.c，此程序演示带头结点的单链表的实现，数据元素是结构体。
 * 作者：姜宗谷 日期：20230302
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int no;		//编号
	char name[31];	//姓名
}ElemType;	//自定义顺序表的数据元素为结构体

typedef struct LNODE
{
	ElemType data;	//存放节点的数据元素
	struct LNODE* next;	//指向下一个节点的指针
}LNode,*LinkList;

//初始化链表LL,返回值：失败返回NULL,成功返回头结点的地址。
LNode *InitList1();

//传入指针变量的地址的方法
//初始化链表，返回值：0-失败；1-成功
int InitList2(LinkList *LL);

//销毁链表LL
int DestroyList1(LinkList LL);

//销毁链表
//传入指针地址的方法
void DestroyList2(LinkList *LL);

//清空链表
void ClearList(LinkList LL);

//在链表LL的第ii个位置插入元素ee,返回值：0-失败，1-成功
int InsertList(LinkList LL, unsigned int ii, ElemType *ee);

//打印链表中全部元素的元素
void PrintList(LinkList LL);

//打印链表中全部的元素,包括超女编号和姓名
void PrintList1(LinkList LL);

//在链表LL的头部插入元素ee,返回值：0-失败；1-成功
int PushFront(LinkList LL, const ElemType *ee);

//在链表LL的尾部插入元素ee,返回值：0-失败；1-成功
int PushBack(LinkList LL, const ElemType *ee);

//删除链表LL中第一个结点，返回值：0-位置ii不合法；1-成功
int DeleteNode(LinkList LL, unsigned int ii);

//删除链表LL中第一个结点，返回值：0-位置不合法；1-成功
int PopFront(LinkList LL);

//删除链表LL中最后一个结点，返回值：0-位置不合法；1-成功
int PopBack(LinkList LL);

//求链表的长度，返回值：>=0-表LL结点的个数
int LengthList(LinkList LL);

//判断链表是否为空，返回值：0-非空或失败，1-空
int IsEmpty(LinkList LL);

//获取链表第ii个结点，成功返回结点的地址，失败返回空
//注意，ii可以取值为0，表示头结点
LNode *LocateNode(LinkList LL, unsigned int ii);

//查找元素ee在链表LL中的结点地址，如果没有找到返回NULL,否则返回结点的地址
LNode *LocateElem(LinkList LL, ElemType *ee);

//在指定结点pp之后插入元素ee,返回值：0-失败；1-成功
int InsertNextNode(LNode *pp, ElemType *ee);

//在指定结点pp之前插入元素ee,返回值：0-失败；1-成功
int InsertPriorNode(LNode *pp, ElemType *ee);

//删除指定结点
int DeleteNode1(LNode *pp);


int main()
{
	

	return 0;
}

//初始化链表LL,返回值：失败返回NULL,成功返回头结点的地址。
LNode *InitList1()
{
	LNode *head = (LNode *)malloc(sizeof(LNode));	//分配头结点

	//分配内存失败，返回空
	if (head == NULL) return NULL;

	//头结点的下一节点暂时不存在，置为空
	return head;
}

//传入指针变量的地址的方法
//初始化链表，返回值：0-失败；1-成功
int InitList2(LinkList *LL)
{
	//在本函数中，LL是指针的指针，用于存放指针的地址。
	if (*LL != NULL)
	{
		printf("链表LL已存在，在初始化之前请先释放它。\n");
	}

	LNode *head = (LNode *)malloc(sizeof(LNode));//分配头结点

	//内存不足，返回失败
	if (head == NULL) return 0;

	//头结点的下一节点暂时不存在，置空
	*LL = head;
	return 1;

}

//销毁链表LL
int DestroyList1(LinkList LL)
{
	//销毁链表LL是指释放链表全部的结点，包括头结点
	LNode *tmp;
	while (LL != NULL)
	{
		tmp = LL->next;//tmp保存下一节点的地址
		free(LL);
		LL = tmp;
	}
	return;
}

//销毁链表
//传入指针地址的方法
void DestroyList2(LinkList *LL)
{
	//如果函数的参数是指针的指针，可以启用以下代码
	LNode *tmp1, *tmp2;
	tmp1 = *LL;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;	//tmp保存下一节点的地址
		free(tmp1);		//释放当前结点
		tmp1 = tmp2;
	}
	*LL = NULL;	//把链表的指针置为空，表示链表不存在了
	return;

}

//清空链表
void ClearList(LinkList LL)
{
	//清空链表LL是指释放链表全部的结点，但不包括头结点
	if (LL == NULL)
	{
		printf("链表LL不存在。\n");
		return;
	}
	LNode *tmp1; 
	LNode *tmp2 = LL->next;//保留头结点，从头结点的下一个节点开始释放

	while (tmp2 != NULL)
	{
		tmp1 = tmp2->next;
		free(tmp2);
		tmp2 = tmp1;
	}
	LL->next = NULL;//这行代码代码不能少，否则留下野指针
	return;
}

//在链表LL的第ii个位置插入元素ee,返回值：0-失败，1-成功
int InsertList(LinkList LL, unsigned int ii, ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		printf("链表LL或元素ee不存在。\n");
	}
	//判断插入位置是否合法
	if (ii < 1)
	{
		printf("插入位置(%d)不合法，应该在大于0.\n", ii);
	}

	//要在位序ii插入结点，必须找到ii-1结点
	LNode *pp = LL;//指针pp指向头结点，逐步往后移动，如果为空，表示后没有结点
	int kk = 0;	//kk指向的是第几个结点，从头结点0开始，pp每向后移动一次，kk加1
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
	LNode *tmp = (LNode *)malloc(sizeof(LNode));	//分配一个结点
	if (tmp == NULL) return 0;
	if (tmp == NULL) return 0;
	//考虑数据元素为结构体的情况，这里采用memcpy的方法而不是直接赋值。
	memcpy(&tmp->data, ee, sizeof(ElemType));

	//处理next指针
	tmp->next = pp->next;
	pp->next = tmp;

	return 1;
}
//打印链表中全部元素的元素
void PrintList(LinkList LL)
{
	if (LL == NULL)
	{
		printf("链表LL不存在。\n");
		return;
	}
	LNode *pp = LL->next;	//从第一个结点开始
	while (pp != NULL)
	{
		printf("%-3d", pp->data.no);
		pp = pp->next;
	}
	printf("\n");
}

//打印链表中全部的元素,包括超女编号和姓名
void PrintList1(LinkList LL)
{
	if (LL == NULL)
	{
		printf("链表LL不存在。\n");
		return;
	}
	LNode *pp = LL->next;	//从第一个结点开始
	while (pp != NULL)
	{
		printf("no=%-3d,name=%s", pp->data.no,pp->data.name);
		pp = pp->next;
	}
	printf("\n");


}

//在链表LL的头部插入元素ee,返回值：0-失败；1-成功
int PushFront(LinkList LL, const ElemType *ee)
{
	return InsertList(LL, 1, ee);
}
//在链表LL的尾部插入元素ee,返回值：0-失败；1-成功
int PushBack(LinkList LL, const ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		printf("链表LL或元素ee不存在。\n"); 
		return 0;
	}
	LNode *pp = LL;	//从头结点开始

	//找到最后一个结点
	while (pp->next != NULL)
		pp = pp->next;

	//分配结点
	LNode *tmp = (LNode*)malloc(sizeof(LNode));
	//内存不足，返回失败
	if (tmp == NULL) return 0;

	//考虑数据元素为结构体的情况，这里采用了memcpy的方法而不是直接赋值
	memcpy(&tmp->data, ee, sizeof(ElemType));

	//处理next指针
	tmp->next = NULL;
	pp->next = tmp;

	return 1;
}

//删除链表LL中第一个结点，返回值：0-位置ii不合法；1-成功
int DeleteNode(LinkList LL, unsigned int ii)
{
	//判断链表是否存在
	if (LL == NULL)
	{
		printf("链表L不存在。\n");
		return 0;
	}
	//判断删除位置是否合法
	if (ii < 1)
	{
		printf("删除位置(%d)不合法，应该在大于0.\n");
		return 0;
	}

	//要删除位序ii结点，必须找到ii-1结点
	LNode *pp = LL;//指针pp指向头结点，逐步往后移动，如果为空，表示后面没结点
	int kk = 0;	//kk指向的是第几个结点，从头结点0开始，pp每向后移动一次，kk就加1
	while ((pp != NULL) && (kk < ii - 1))
	{
		pp = pp->next;
		++kk;
	}
	
	if (pp->next == NULL)
	{
		printf("位置(%d)不合法，超过了表长。\n", ii);
		return 0;
	}
		
	LNode *tmp = pp->next;		
	pp->next = tmp->next;		
	free(tmp);	
	return 1;

}

//删除链表LL中第一个结点，返回值：0-位置不合法；1-成功
int PopFront(LinkList LL)
{
	return DeleteNode(LL, 1);
}

//删除链表LL中最后一个结点，返回值：0-位置不合法；1-成功
int PopBack(LinkList LL)
{
	if (LL == NULL)
	{
		printf("链表LL不存在.\n");
		return 0;
	}
	if (LL->next == NULL)
	{
		printf("链表LL为空，没有尾结点。\n");
		return 0;
	}
	//要删除最后一个结点，必须找到最后一个结点的前一个结点
	LNode *pp = LL;//从第0个结点开始
	//找到倒数第二个结点（包括头结点）
	while (pp->next->next != NULL)
		pp = pp->next;

	//释放最后一个结点
	free(pp->next);
	pp->next = NULL;

	return 1;

}

//求链表的长度，返回值：>=0-表LL结点的个数
int LengthList(LinkList LL)
{
	if (LL == NULL)
	{
		printf("链表LL不存在。\n");
		return 0;
	}

	LNode *pp = LL->next;//头结点不算，从第一个结点开始
	int length = 0;
	while (pp != NULL)
	{
		pp = pp->next;
		length++;
	}
	return length;
}

//判断链表是否为空，返回值：0-非空或失败，1-空
int IsEmpty(LinkList LL)
{
	if (LL == NULL) return 0;

	if (LL->next == NULL) return 1;

	return 0;
}

//获取链表第ii个结点，成功返回结点的地址，失败返回空
//注意，ii可以取值为0，表示头结点
LNode *LocateNode(LinkList LL, unsigned int ii)
{
	//判断链表和元素是否存在
	if (LL == NULL)
	{
		priintf("链表LL不存在。\n");
		return NULL;
	}
	LNode *pp = LL;
	int kk = 0;
	while ((pp != NULL) && (kk < ii))
	{
		pp = pp->next;
		++kk;
	}
	if (pp == NULL)
	{
		printf("位置(%d)不合法，超过了表长.\n", ii);
		return NULL;
	}
	return pp;
}

//查找元素ee在链表LL中的结点地址，如果没有找到返回NULL,否则返回结点的地址
LNode *LocateElem(LinkList LL, ElemType *ee)
{
	LNode *pp = LL->next;	//从第一个数据结点开始
	while (pp != NULL)
	{
		if (pp->data.no == ee->no)	return pp;
		pp = pp->next;
	}
	return NULL;
}

//在指定结点pp之后插入元素ee,返回值：0-失败；1-成功
int InsertNextNode(LNode *pp, ElemType *ee)
{
	if (pp == NULL) 
	{ printf("结点pp不存在.\n"); 
	return 0;
	}

	LNode *tmp = (LNode *)malloc(sizeof(LNode));
	
	if (tmp == NULL)
		return 0;
	memcpy(&tmp->data, ee, sizeof(ElemType));
	tmp->next = pp->next;
	pp->next = tmp;
	return 1;
}

//在指定结点pp之前插入元素ee,返回值：0-失败；1-成功
int InsertPriorNode(LNode *pp, ElemType *ee)
{
	//检查结点是否存在
	if (pp == NULL)
	{
		printf("结点pp不存在.\n");
		return 0;
	}
	LNode *tmp = (LNode*)malloc(sizeof(LNode));
	if (tmp == NULL)
		return 0;
	//把pp结点的数据和指针复制到tmp中
	memcpy(&tmp->data, ee, sizeof(ElemType));
	tmp->next = pp->next;

	//把待插入的元素存入pp中
	memcpy(&pp->data, ee, sizeof(ElemType));
	pp->next = tmp;
	return 1;
}

//删除指定结点
int DeleteNode1(LNode *pp)
{

}

