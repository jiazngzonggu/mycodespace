/*
 * ��������linklist4.c���˳�����ʾ��ͷ����˫�����ʵ�֣�����Ԫ����������
 * ���ߣ����ڹ� ���ڣ�20201230
*/

#include<stdio.h>
#include<string.h>
#include<stdio.h>

typedef int ElemType;	//�Զ������������Ԫ��Ϊ����

typedef struct DNode
{
	ElemType data;	//��Žڵ������Ԫ�ء�
	struct DNode *prior, *next;	//ǰ���ͺ�̽���ָ��
}DNode,*LinkList;

//��ʼ������LL������ֵ��ʧ�ܷ���NULL,�ɹ�����ͷ���ĵ�ַ
DNode *IintList1();

//����ָ������ĵ�ַ�ķ�����
//��ʼ����������ֵ��0-ʧ�ܣ�1-�ɹ�
int InitList2(LinkList *LL);

//��������LL
//����ָ��ĵ�ַ�ķ���
void DestroyList1(LinkList LL);

//��������LL
//����ָ��ĵ�ַ�ķ�����
void DestroyList2(LinkList *LL);

//�������
void ClearList(LinkList LL);

//������LL�ĵ�ii��λ�ò���Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertList(LinkList LL, unsigned int ii, ElemType *ee);

//��ӡ������ȫ����Ԫ��
void PrintList(LinkList LL);

//������LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ�
int PushFront(LinkList LL, ElemType *ee);

//������β������Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int PushBack(LinkList LL, ElemType *ee);

//ɾ������LL�еĵ�ii����㣬����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int DeleteNode(LinkList LL, unsigned int ii);

//ɾ������LL�еĵ�һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ�
int PopFront(LinkList LL);

//ɾ������LL�е����һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ�
int PopBack(LinkList LL);

//������ĳ��ȣ�����ֵ��>=0 -����LL���ĸ���
int LengthList(LinkList LL);

//�ж������Ƿ�Ϊ�գ�����ֵ��0-�ǿջ���ʧ�ܣ�1-��
int IsEmpty(LinkList LL);

//��ȡ�����е�ii����㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ��ؿ�
//ע�⣺ii����ȡֵΪ0,��ʾͷ��㡣
DNode *LocateNode(LinkList LL, unsigned int ii);

//����Ԫ��ee������LL�еĽ���ַ�����û�ҵ�����NULL,���򷵻ؽ��ĵ�ַ
DNode *LocalElem(LinkList LL, ElemType *ee);

//��ָ�����pp֮�����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertNextNode(DNode *pp, ElemType *ee);

//��ָ�����pp֮ǰ����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertFrontNode(DNode *pp, ElemType *ee);

//ɾ��ָ�����
int DeleteNode1(DNode *pp);

int main()
{


	return 0;
}

//��ʼ������LL������ֵ��ʧ�ܷ���NULL,�ɹ�����ͷ���ĵ�ַ
DNode *IintList1()
{
	//����ͷ���
	DNode *head = (DNode *)malloc(sizeof(DNode));

	//�����ڴ�ʧ�ܣ�����ʧ��
	if (head == NULL) return NULL;

	//ǰ���ͺ�̶���Ϊ��
	head->prior = head->next = NULL;

	//����ͷ���
	return head;
}

//����ָ������ĵ�ַ�ķ�����
//��ʼ����������ֵ��0-ʧ�ܣ�1-�ɹ�
int InitList2(LinkList *LL)
{
	//�����ڴ�
	DNode* head = (DNode *)malloc(sizeof(DNode));

	//�ж��ڴ��Ƿ�����ɹ�
	if (head == NULL) return 0;

	//��head��ǰ����̶���Ϊ��
	head->prior = head->next = NULL;

	//��ͷ����ַ��ֵ��LL
	*LL = head;
	return 1;
}

//��������LL
//����ָ��ĵ�ַ�ķ���
void DestroyList1(LinkList LL)
{
	//��������LL��ָ�ͷ�����ȫ���Ľ�㣬����ͷ���
	DNode *tmp;

	while (LL != NULL)
	{
		tmp = LL->next;//tmp������һ�ڵ�ĵ�ַ
		free(LL);//�ͷŵ�ǰ���
		LL = tmp;
	}
	return;
}

//��������LL
//����ָ��ĵ�ַ�ķ�����
void DestroyList2(LinkList *LL)
{
	//��������Ĳ�����ָ���ָ�룬��������������롣
	DNode *tmp1, *tmp2;
	tmp1 = *LL;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;	//tmp������һ�ڵ�ĵ�ַ
		free(tmp1);			//�ͷŵ�ǰ���
		tmp1 = tmp2;		//LLָ���ƶ�����һ�ڵ�
	}
	*LL = NULL;//������ָ����Ϊ�գ���ʾ����������
	return;
}

//�������
void ClearList(LinkList LL)
{
	//�������LL��ָ�ͷ�����ȫ���ĵ㣬��������ͷ��㡣
	if (LL == NULL) return;

	DNode *tmp1;
	DNode *tmp2 = LL->next;	//����ͷ��㣬��ͷ������һ����㿪ʼ�ͷ�

	while (tmp2 != NULL)
	{
		tmp1 = tmp2->next;
		free(tmp2);
		tmp2 = tmp1;
	}

	LL->next = NULL;	//���д���һ�������٣����������Ұָ��
	return;
}

//������LL�ĵ�ii��λ�ò���Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertList(LinkList LL, unsigned int ii, ElemType *ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		printf("����LL��Ԫ��ee�����ڡ�\n");
		return 0;
	}
	//�жϲ���λ���Ƿ�Ϸ�
	if (ii < 1)
	{
		printf("����λ��(%d)���Ϸ���Ӧ���ڴ���0.", ii);
		return 0;
	}

	//Ҫ��λ��ii�����㣬�����ҵ�ii-1���
	DNode *pp = LL;	//ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ��ûû�н��
	int kk = 0;		//kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk��1
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

	//�����ڴ�
	DNode *tmp = (DNode *)malloc(sizeof(DNode));//����һ�����
	if (tmp == NULL) return 0;//�ڴ治�㣬����ʧ��

	//����Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ
	memcpy(&(tmp->data), ee, sizeof(ElemType));

	//����ǰ����������ָ��
	tmp->next = pp->next;
	tmp->prior = pp;
	//���⴦���������β�����룬tmp->next����������
	if (tmp->next != NULL) tmp->next->prior = tmp;
	pp->next = tmp;
	return 1;
}

//��ӡ������ȫ����Ԫ��
void PrintList(LinkList LL)
{
	//�ж�����LL�Ƿ���ڣ��������򷵻�
	if (LL == NULL)
	{
		printf("�ı�LL�����ڡ�\n");
		return;
	}
	//�ӵ�һ����㿪ʼ
	DNode *pp = LL->next;
	while (pp != NULL)
	{
		printf("%-3d", pp->data);
		pp = pp->next;
	}
	printf("\n");
}

//������LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ�
int PushFront(LinkList LL, ElemType *ee)
{
	return InsertList(LL, 1, ee);
}

//������β������Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int PushBack(LinkList LL, ElemType *ee)
{
	//�ж�����LL�ͽ��ee�Ƿ�Ϊ��
	if ((LL == NULL) || (ee == NULL))
	{
		printf("����LL��Ԫ��ee������.\n");
		return 0;
	}
	//��ͷ��㿪ʼ
	DNode *pp = LL;	
	
	//�ҵ����һ�����
	while (pp->next != NULL)
	{
		pp = pp->next;
	}
	
	//����һ�����
	DNode *tmp = (DNode *)malloc(sizeof(DNode));
	//�ڴ治�㣬����ʧ��
	if (tmp == NULL) return 0;

	//��������Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ
	memcpy(&(tmp->data), ee, sizeof(ElemType));

	//����ǰ����̽���ָ��
	tmp->next = pp->next;
	tmp->prior = pp;
	//���⴦���������β�����룬tmp->next����������
	pp->next = tmp;
	return 1;
}

//ɾ������LL�еĵ�ii����㣬����ֵ��0-λ��ii���Ϸ���1-�ɹ�
int DeleteNode(LinkList LL, unsigned int ii)
{
	if (LL == NULL)
	{
		printf("����LL�����ڡ�\n");
		return 0;
	}
	//�ж�ɾ��λ���Ƿ�Ϸ�
	if (ii < 1)
	{
		printf("ɾ��λ��(%d)���Ϸ���Ӧ�ô���0��\n");
		return 0;
	}
	//Ҫɾ��λ��ii��㣬�����ҵ�ii-1���
	DNode *pp = LL;	//ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ��û�����
	int kk = 0;	//	kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1
	while ((pp != NULL) && (kk < ii - 1))
	{
		pp = pp->next;
		++kk;
	}
	//�ж�λ���Ƿ񳬹���
	if (pp->next == NULL)
	{
		printf("λ��(%d)���Ϸ��������˱���\n", ii);
		return 0;
	}
	DNode *tmp = pp->next;	//tmpΪ��Ҫɾ���Ľ��

	//����ǰȥ��������ָ��
	pp->next = tmp->next;
	//���⴦�����tmp��β�ڵ㣬tmp->next����������
	if (tmp->next != NULL) tmp->next->prior = pp;	
	//�ͷŽ��
	free(tmp);
	return 1;

}

//ɾ������LL�еĵ�һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ�
int PopFront(LinkList LL)
{
	return DeleteNode(LL, 1);
}

//ɾ������LL�е����һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ�
int PopBack(LinkList LL)
{
	if (LL == NULL)
	{
		printf("����LL�����ڡ�\n");
		return 0;
	}

	//�����������жϣ�������ɾ��ͷ���
	if (LL->next == NULL)
	{
		printf("����LLΪ�գ�û��β�ڵ㡣\n");
		return 0;
	}
	//����ǵ�����Ҫɾ�����һ����㣬�����ҵ����һ������ǰһ�����
	//�����˫����Ҫɾ�����һ����㣬�ҵ����һ���������һ������ǰһ����㶼����
	DNode *pp = LL;	//�ӵ�0����㿪ʼ

	//�ҵ����һ�����
	while (pp->next != NULL)
		pp = pp->next;

	//�����һ������ǰһ�ڵ��nextָ����Ϊ��
	pp->prior->next = NULL;

	//�ͷ����һ�����
	free(pp);
	return 1;

}

//������ĳ��ȣ�����ֵ��>=0 -����LL���ĸ���
int LengthList(LinkList LL)
{
	//�������ָ���Ƿ�Ϊ��
	if (LL == NULL)
	{
		printf("����LL�����ڡ�\n");
		return 0;
	}

	//�ӵ�һ����㿪ʼ
	DNode *tmp = LL;
	int length = 0;
	while (tmp->next != NULL)
	{
		tmp=tmp->next;
		++length;
	}
	return length;

}

//�ж������Ƿ�Ϊ�գ�����ֵ��0-�ǿջ���ʧ�ܣ�1-��
int IsEmpty(LinkList LL)
{
	if (LL == NULL) return 0;
	if (LL->next == NULL)return 1;

	return 0;
}

//��ȡ�����е�ii����㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ��ؿ�
//ע�⣺ii����ȡֵΪ0,��ʾͷ��㡣
DNode *LocateNode(LinkList LL, unsigned int ii)
{
	if (LL == NULL)
	{
		printf("����LL�����ڡ�\n");
		return LL;
	}
	DNode *pp = LL;	//ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ��ûû�����
	int kk = 0;		//kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1
	while ((pp != NULL) && (kk < ii))
	{
		pp = pp->next;
		++kk;
	}
	if (pp == NULL)
	{
		printf("λ��(%d)���Ϸ��������˱���\n.", ii);
		return NULL;
	}
	return pp;
}

//����Ԫ��ee������LL�еĽ���ַ�����û�ҵ�����NULL,���򷵻ؽ��ĵ�ַ
DNode *LocalElem(LinkList LL, ElemType *ee)
{
	DNode *pp = LL->next;	//�ӵ�1�����ݽ�㿪ʼ
	while (pp != NULL)
	{
		//�������Ԫ���ǽṹ�壬���´���Ҫ�޸�
		if (pp->data == *ee) return pp;

		pp = pp->next;
	}
	return NULL;
}

//��ָ�����pp֮�����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertNextNode(DNode *pp, ElemType *ee)
{
	if (pp == NULL) 
	{	
		printf("���pp������.\n"); 
		return 0; 
	}

	DNode *tmp = (DNode *)malloc(sizeof(DNode));
	if (tmp == NULL) return 0;
	memcpy(&tmp->data, ee, sizeof(ElemType));

	//����ǰȥ��������ָ��
	tmp->next = pp->next;
	tmp->prior = pp;
	if (tmp->next != NULL)
	{
		tmp->next->prior = tmp;
	}

	pp->next = tmp;
	return 1;
}

//��ָ�����pp֮ǰ����Ԫ��ee,����ֵ��0-ʧ�ܣ�1-�ɹ�
int InsertFrontNode(DNode *pp, ElemType *ee)
{
	if (pp == NULL)
	{
		printf("���pp�����ڡ�\n");
		return 0;
	}

	DNode *tmp = (DNode *)malloc(sizeof(DNode));
	if (tmp == NULL) return 0;

	//�Ѵ������Ԫ�ش���tmp��
	memcpy(&tmp->data, ee, sizeof(ElemType));

	//����ǰ����̵�ָ��
	tmp->prior = pp->prior;
	pp->prior->next = tmp;
	tmp->next = pp;
	pp->prior = tmp;
	return 1;
}

//ɾ��ָ�����
int DeleteNode1(DNode *pp)
{
	if (pp == NULL)
	{
		printf("���pp�����ڡ�\n");
		return 0;
	}
	pp->prior->prior = pp->next;
	if (pp->next != NULL) pp->next->prior = pp->prior;
	return 1;
}

