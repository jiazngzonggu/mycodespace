/*
 * ��������linklist2.c���˳�����ʾ��ͷ���ĵ������ʵ�֣�����Ԫ���ǽṹ�塣
 * ���ߣ����ڹ� ���ڣ�20230302
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int no;		//���
	char name[31];	//����
}ElemType;	//�Զ���˳��������Ԫ��Ϊ�ṹ��

typedef struct LNODE
{
	ElemType data;	//��Žڵ������Ԫ��
	struct LNODE* next;	//ָ����һ���ڵ��ָ��
}LNode,*LinkList;

//��ʼ������LL,����ֵ��ʧ�ܷ���NULL,�ɹ�����ͷ���ĵ�ַ��
LNode *InitList1();

//����ָ������ĵ�ַ�ķ���
//��ʼ����������ֵ��0-ʧ�ܣ�1-�ɹ�
int InitList2(LinkList *LL);

//��������LL
int DestroyList1(LinkList LL);

//��������
//����ָ���ַ�ķ���
void DestroyList2(LinkList *LL);

//�������
void ClearList(LinkList LL);

//������LL�ĵ�ii��λ�ò���Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertList(LinkList LL, unsigned int ii, ElemType *ee);

//��ӡ������ȫ��Ԫ�ص�Ԫ��
void PrintList(LinkList LL);

//��ӡ������ȫ����Ԫ��,������Ů��ź�����
void PrintList1(LinkList LL);

//������LL��ͷ������Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int PushFront(LinkList LL, const ElemType *ee);

//������LL��β������Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int PushBack(LinkList LL, const ElemType *ee);

//ɾ������LL�е�һ����㣬����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int DeleteNode(LinkList LL, unsigned int ii);

//ɾ������LL�е�һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ�
int PopFront(LinkList LL);

//ɾ������LL�����һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ�
int PopBack(LinkList LL);

//������ĳ��ȣ�����ֵ��>=0-��LL���ĸ���
int LengthList(LinkList LL);

//�ж������Ƿ�Ϊ�գ�����ֵ��0-�ǿջ�ʧ�ܣ�1-��
int IsEmpty(LinkList LL);

//��ȡ�����ii����㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ��ؿ�
//ע�⣬ii����ȡֵΪ0����ʾͷ���
LNode *LocateNode(LinkList LL, unsigned int ii);

//����Ԫ��ee������LL�еĽ���ַ�����û���ҵ�����NULL,���򷵻ؽ��ĵ�ַ
LNode *LocateElem(LinkList LL, ElemType *ee);

//��ָ�����pp֮�����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertNextNode(LNode *pp, ElemType *ee);

//��ָ�����pp֮ǰ����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertPriorNode(LNode *pp, ElemType *ee);

//ɾ��ָ�����
int DeleteNode1(LNode *pp);


int main()
{
	

	return 0;
}

//��ʼ������LL,����ֵ��ʧ�ܷ���NULL,�ɹ�����ͷ���ĵ�ַ��
LNode *InitList1()
{
	LNode *head = (LNode *)malloc(sizeof(LNode));	//����ͷ���

	//�����ڴ�ʧ�ܣ����ؿ�
	if (head == NULL) return NULL;

	//ͷ������һ�ڵ���ʱ�����ڣ���Ϊ��
	return head;
}

//����ָ������ĵ�ַ�ķ���
//��ʼ����������ֵ��0-ʧ�ܣ�1-�ɹ�
int InitList2(LinkList *LL)
{
	//�ڱ������У�LL��ָ���ָ�룬���ڴ��ָ��ĵ�ַ��
	if (*LL != NULL)
	{
		printf("����LL�Ѵ��ڣ��ڳ�ʼ��֮ǰ�����ͷ�����\n");
	}

	LNode *head = (LNode *)malloc(sizeof(LNode));//����ͷ���

	//�ڴ治�㣬����ʧ��
	if (head == NULL) return 0;

	//ͷ������һ�ڵ���ʱ�����ڣ��ÿ�
	*LL = head;
	return 1;

}

//��������LL
int DestroyList1(LinkList LL)
{
	//��������LL��ָ�ͷ�����ȫ���Ľ�㣬����ͷ���
	LNode *tmp;
	while (LL != NULL)
	{
		tmp = LL->next;//tmp������һ�ڵ�ĵ�ַ
		free(LL);
		LL = tmp;
	}
	return;
}

//��������
//����ָ���ַ�ķ���
void DestroyList2(LinkList *LL)
{
	//��������Ĳ�����ָ���ָ�룬�����������´���
	LNode *tmp1, *tmp2;
	tmp1 = *LL;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;	//tmp������һ�ڵ�ĵ�ַ
		free(tmp1);		//�ͷŵ�ǰ���
		tmp1 = tmp2;
	}
	*LL = NULL;	//�������ָ����Ϊ�գ���ʾ����������
	return;

}

//�������
void ClearList(LinkList LL)
{
	//�������LL��ָ�ͷ�����ȫ���Ľ�㣬��������ͷ���
	if (LL == NULL)
	{
		printf("����LL�����ڡ�\n");
		return;
	}
	LNode *tmp1; 
	LNode *tmp2 = LL->next;//����ͷ��㣬��ͷ������һ���ڵ㿪ʼ�ͷ�

	while (tmp2 != NULL)
	{
		tmp1 = tmp2->next;
		free(tmp2);
		tmp2 = tmp1;
	}
	LL->next = NULL;//���д�����벻���٣���������Ұָ��
	return;
}

//������LL�ĵ�ii��λ�ò���Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertList(LinkList LL, unsigned int ii, ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		printf("����LL��Ԫ��ee�����ڡ�\n");
	}
	//�жϲ���λ���Ƿ�Ϸ�
	if (ii < 1)
	{
		printf("����λ��(%d)���Ϸ���Ӧ���ڴ���0.\n", ii);
	}

	//Ҫ��λ��ii�����㣬�����ҵ�ii-1���
	LNode *pp = LL;//ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ��û�н��
	int kk = 0;	//kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk��1
	while ((pp != NULL) && (kk < ii - 1))
	{
		pp = pp->next;
		++kk;
	}
	if (pp == NULL)
	{
		printf("λ��(%d)���Ϸ��������˱���\n", ii);
		return 0;
	}
	LNode *tmp = (LNode *)malloc(sizeof(LNode));	//����һ�����
	if (tmp == NULL) return 0;
	if (tmp == NULL) return 0;
	//��������Ԫ��Ϊ�ṹ���������������memcpy�ķ���������ֱ�Ӹ�ֵ��
	memcpy(&tmp->data, ee, sizeof(ElemType));

	//����nextָ��
	tmp->next = pp->next;
	pp->next = tmp;

	return 1;
}
//��ӡ������ȫ��Ԫ�ص�Ԫ��
void PrintList(LinkList LL)
{
	if (LL == NULL)
	{
		printf("����LL�����ڡ�\n");
		return;
	}
	LNode *pp = LL->next;	//�ӵ�һ����㿪ʼ
	while (pp != NULL)
	{
		printf("%-3d", pp->data.no);
		pp = pp->next;
	}
	printf("\n");
}

//��ӡ������ȫ����Ԫ��,������Ů��ź�����
void PrintList1(LinkList LL)
{
	if (LL == NULL)
	{
		printf("����LL�����ڡ�\n");
		return;
	}
	LNode *pp = LL->next;	//�ӵ�һ����㿪ʼ
	while (pp != NULL)
	{
		printf("no=%-3d,name=%s", pp->data.no,pp->data.name);
		pp = pp->next;
	}
	printf("\n");


}

//������LL��ͷ������Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int PushFront(LinkList LL, const ElemType *ee)
{
	return InsertList(LL, 1, ee);
}
//������LL��β������Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int PushBack(LinkList LL, const ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		printf("����LL��Ԫ��ee�����ڡ�\n"); 
		return 0;
	}
	LNode *pp = LL;	//��ͷ��㿪ʼ

	//�ҵ����һ�����
	while (pp->next != NULL)
		pp = pp->next;

	//������
	LNode *tmp = (LNode*)malloc(sizeof(LNode));
	//�ڴ治�㣬����ʧ��
	if (tmp == NULL) return 0;

	//��������Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ
	memcpy(&tmp->data, ee, sizeof(ElemType));

	//����nextָ��
	tmp->next = NULL;
	pp->next = tmp;

	return 1;
}

//ɾ������LL�е�һ����㣬����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int DeleteNode(LinkList LL, unsigned int ii)
{
	//�ж������Ƿ����
	if (LL == NULL)
	{
		printf("����L�����ڡ�\n");
		return 0;
	}
	//�ж�ɾ��λ���Ƿ�Ϸ�
	if (ii < 1)
	{
		printf("ɾ��λ��(%d)���Ϸ���Ӧ���ڴ���0.\n");
		return 0;
	}

	//Ҫɾ��λ��ii��㣬�����ҵ�ii-1���
	LNode *pp = LL;//ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ����û���
	int kk = 0;	//kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1
	while ((pp != NULL) && (kk < ii - 1))
	{
		pp = pp->next;
		++kk;
	}
	
	if (pp->next == NULL)
	{
		printf("λ��(%d)���Ϸ��������˱���\n", ii);
		return 0;
	}
		
	LNode *tmp = pp->next;		
	pp->next = tmp->next;		
	free(tmp);	
	return 1;

}

//ɾ������LL�е�һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ�
int PopFront(LinkList LL)
{
	return DeleteNode(LL, 1);
}

//ɾ������LL�����һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ�
int PopBack(LinkList LL)
{
	if (LL == NULL)
	{
		printf("����LL������.\n");
		return 0;
	}
	if (LL->next == NULL)
	{
		printf("����LLΪ�գ�û��β��㡣\n");
		return 0;
	}
	//Ҫɾ�����һ����㣬�����ҵ����һ������ǰһ�����
	LNode *pp = LL;//�ӵ�0����㿪ʼ
	//�ҵ������ڶ�����㣨����ͷ��㣩
	while (pp->next->next != NULL)
		pp = pp->next;

	//�ͷ����һ�����
	free(pp->next);
	pp->next = NULL;

	return 1;

}

//������ĳ��ȣ�����ֵ��>=0-��LL���ĸ���
int LengthList(LinkList LL)
{
	if (LL == NULL)
	{
		printf("����LL�����ڡ�\n");
		return 0;
	}

	LNode *pp = LL->next;//ͷ��㲻�㣬�ӵ�һ����㿪ʼ
	int length = 0;
	while (pp != NULL)
	{
		pp = pp->next;
		length++;
	}
	return length;
}

//�ж������Ƿ�Ϊ�գ�����ֵ��0-�ǿջ�ʧ�ܣ�1-��
int IsEmpty(LinkList LL)
{
	if (LL == NULL) return 0;

	if (LL->next == NULL) return 1;

	return 0;
}

//��ȡ�����ii����㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ��ؿ�
//ע�⣬ii����ȡֵΪ0����ʾͷ���
LNode *LocateNode(LinkList LL, unsigned int ii)
{
	//�ж������Ԫ���Ƿ����
	if (LL == NULL)
	{
		priintf("����LL�����ڡ�\n");
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
		printf("λ��(%d)���Ϸ��������˱�.\n", ii);
		return NULL;
	}
	return pp;
}

//����Ԫ��ee������LL�еĽ���ַ�����û���ҵ�����NULL,���򷵻ؽ��ĵ�ַ
LNode *LocateElem(LinkList LL, ElemType *ee)
{
	LNode *pp = LL->next;	//�ӵ�һ�����ݽ�㿪ʼ
	while (pp != NULL)
	{
		if (pp->data.no == ee->no)	return pp;
		pp = pp->next;
	}
	return NULL;
}

//��ָ�����pp֮�����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertNextNode(LNode *pp, ElemType *ee)
{
	if (pp == NULL) 
	{ printf("���pp������.\n"); 
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

//��ָ�����pp֮ǰ����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertPriorNode(LNode *pp, ElemType *ee)
{
	//������Ƿ����
	if (pp == NULL)
	{
		printf("���pp������.\n");
		return 0;
	}
	LNode *tmp = (LNode*)malloc(sizeof(LNode));
	if (tmp == NULL)
		return 0;
	//��pp�������ݺ�ָ�븴�Ƶ�tmp��
	memcpy(&tmp->data, ee, sizeof(ElemType));
	tmp->next = pp->next;

	//�Ѵ������Ԫ�ش���pp��
	memcpy(&pp->data, ee, sizeof(ElemType));
	pp->next = tmp;
	return 1;
}

//ɾ��ָ�����
int DeleteNode1(LNode *pp)
{

}

