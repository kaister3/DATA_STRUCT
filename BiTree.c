#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "BiTree.h"
#include "LinkQueue.h"

int InitBiTree(BiTree *T)
{
	if (*T = (BiTree*)malloc(sizeof(BiTNode)))
	{

		(*T)->data.c = ' ';
		(*T)->LChild = NULL;
		(*T)->RChild = NULL;//�յ�ͷ���
		return 1;
	}
	else return 0;
}//InitBiTree

int DestoryBiTree(BiTree T)
{
	if (!T)
	{
		return 0;//��ͷ��T->Child�����ڣ�֮��ֹͣ
	}
	else
	{
		if ((!T->LChild))
		{
			DestoryBiTree(T->LChild);
		}
		if (!(T->RChild))
		{
			DestoryBiTree(T->RChild);
		}
		free(T);//�õݹ鷽���������ÿ�����
		return 1;
	}
}//DestoryBiTree

int CreateBiTree(BiTree *T)
{
	char ch;
	getchar();
	scanf("%c", &ch);
	if (ch != '\n')
	{
		if (ch == '#')
		{
			*T = NULL;
			return 0;
		}
		else
		{
			if (!((*T) = (BiTNode *)malloc(sizeof(BiTNode))))exit(0);
			(*T)->data.c = ch;//��ֵ
			printf("����%c�����ӽڵ㣺\n", ch);
			CreateBiTree(&(*T)->LChild);
			printf("����%c�����ӽڵ㣺\n", ch);
			CreateBiTree(&(*T)->RChild);
			return 1;
		}
	}
	
}//

int ClearBiTree(BiTree T)
{
	DestoryBiTree(T);
	InitBiTree(&T); //��ͬ��Destroy����֮���ָ�ͷ������ռ��ÿ�
	return 1;
}

int BiTreeEmpty(BiTree T)
{
	if (T->LChild == NULL&&T->RChild == NULL) 
		return 1;
	else       
		return 0;
}

int BiTreeDepth(BiTNode *T)
{
	int depth = 0;
	if (T)
	{
		int LeftDepth = BiTreeDepth(T->LChild);
		int RightDepth = BiTreeDepth(T->RChild);
		depth = LeftDepth >= RightDepth ? (LeftDepth + 1) : (RightDepth + 1);
	}

	return depth;
}//�ݹ�����������

BiTNode* Root(BiTree T)
{
	if (BiTreeEmpty(T)) {
		return NULL;
	}
	else return T;
}

char Value(BiTree T, ElemType e)//e.numΪ�����Ҫ���ҵ����,���ظýڵ��ֵ
{
	if (!T)return 0;
	if (T->data.num == e.num)
	{
		e.c = T->data.c;
		return 1;
	}
	if (Value(T->LChild, e))return 1;
	if (Value(T->RChild, e))return 1;
	return 0;
}

int Assign(BiTree T, BiTNode *e, ElemType value)//��ţ�ֵ��e->data.numΪ�û������Ҫ��ֵ�����
{
	if (Value(T, value))//��if�ж��ý�����
	{

		(*e).data.c = value.c;
		return 1;
	}

	else//����
	{
		return 0;
	}
}

ElemType Parent(BiTree T, ElemType e)
{
	LinkQueue q;
	BiTNode *a;
	if (T)
	{
		InitQueue(q);
		EnQueue(&q, T);
		BiTNode *p, *r;
		while (!QueueEmpty(q))
		{
			DeQueue(&q, *a);
			*p = *a->LChild;
			*r = *a->RChild;
			if (a->LChild&&p->data.c == e.c || a->RChild&&r->data.c == e.c)
			{
				//e������Һ���
				return a->data;
			}
			else//�����ǣ��ݹ����������Һ���
			{
				if (a->LChild)
				{
					EnQueue(&q, a->LChild);
				}
				if (a->RChild)
				{
					EnQueue(&q, a->RChild);
				}
			}

		}
	}
	ElemType s;
	s.c = ' ';
	return s;//�ջ򲻴���ʱ����' '
}

ElemType LeftChild(BiTree T, ElemType e)
{
	ElemType s;
	s.c = ' ';
	BiTNode *p;
	if (T == NULL)
		return s;
	if (T->data.c == e.c)
	{
		p = T->LChild;
		if (p)
			return p->data;
		else
			return s;
	}

	else
	{
		LeftChild(T->LChild, e);
		LeftChild(T->RChild, e);
	}
}

ElemType RightChild(BiTree T, ElemType e)
{
	ElemType s;
	s.c = ' ';
	BiTNode *p;
	if (T == NULL)
		return s;
	if (T->data.c == e.c)
	{
		p = T->RChild;
		if (p)
			return p->data;
		else
			return s;
	}

	LeftChild(T->LChild, e);
	LeftChild(T->RChild, e);
}

ElemType LeftSibling(BiTNode *T, ElemType e)//�û�����num�����
{
	ElemType a;
	BiTree p;
	BiTree q, r;
	ElemType s;
	s.c = ' ';

	if (T)
	{
		a = Parent(T, e);//aΪe��˫�׽��
		p = Find(T, a);
		if (p == NULL)
		{
			return s;//���ؿ�
		}
		q = p->LChild;
		r = p->RChild;
		if (p->LChild&&p->RChild&&q->data.c == e.c)
		{
			return q->data;
		}

	}
	return s;
}

ElemType RightSibling(BiTNode *T, ElemType e)
{
	ElemType a;
	BiTree p;
	BiTree q, r;
	ElemType s;
	s.c = ' ';

	if (T)
	{
		a = Parent(T, e);//aΪe��˫�׽��
		p = Find(T, a);
		if (p == NULL)
		{
			return s;//���ؿ�
		}
		q = p->LChild;
		r = p->RChild;
		if (p->LChild&&p->RChild&&q->data.c == e.c)
		{
			return r->data;
		}

	}
	return s;
}

int InsertChild(BiTNode T, ElemType p, int LR, BiTree C)
{

	BiTNode *t, *c, *m, *n;
	*t = T;
	c = C;
	if (t == NULL || c == NULL)
	{
		return 0;
	}
	if (c->RChild != NULL)
	{
		printf("������C������������\n");
		return 0;
	}
	m = Find(t, p);
	if (LR)
	{
		n = m->RChild;
		m->RChild = c;
		c->RChild = n;
	}//����Ϊ������
	else
	{
		n = m->LChild;
		m->LChild = c;
		c->RChild = n;
	}//ͬ��

	return 1;
}

int DeleteChild(BiTNode T, int LR, ElemType p)
{
	BiTNode *temp;
	*temp = T;
	if (temp == NULL)
	{
		return 0;
	}

	temp = Find(temp, p);
	if (LR)
	{
		temp->RChild = NULL;
	}
	else
	{
		temp->LChild = NULL;//ɾ��������
	}
	return 1;
}

int PreOrderTraverse(BiTNode *T)
{
	if (T)
	{
		printf("%c\n", T->data.c);//���ʸ��ڵ�
		PreOrderTraverse(T->LChild);
		PreOrderTraverse(T->RChild);
	}
	return 1;
}

int InOrderTraverse(BiTree T)
{
	if (T)
	{
		InOrderTraverse(T->LChild);
		printf("%c\n", T->data.c);
		InOrderTraverse(T->RChild);
	}

	return 1;
}

int PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->LChild);
		PostOrderTraverse(T->RChild);
		printf("%c\n", T->data.c);
	}


	return 1;
}

int LevelOrderTraverse(BiTree T)
{
	int curLayerCount = 0; //��ǰ���еĽڵ���  
	int nextLayerCount = 0; //��һ���еĽڵ���  
	struct Queue* queue = InitQueue();
	EnQueue(queue, T);
	curLayerCount++;
	struct BiTNode* p;
	while (p = DeQueue(queue))
	{
		curLayerCount--;
		printf("%c ", p->data.c);
		if (p->LChild)
		{
			EnQueue(queue, p->LChild);
			nextLayerCount++;
		}
		if (p->RChild)
		{
			EnQueue(queue, p->RChild);
			nextLayerCount++;
		}
		if (curLayerCount == 0)//һ���Ѿ��������  
		{
			curLayerCount = nextLayerCount;
			nextLayerCount = 0;
			printf("\n");
		}
	}
}

BiTNode* Find(BiTNode *T, ElemType e)//�ҵ���Ԫ��ָ��Ľ��
{
	if (T == NULL)
	{
		return NULL;
	}
	else
	{
		if (T->data.num == e.num)
		{
			return T;
		}
		BiTNode *p = Find(T->LChild, e);
		if (p != NULL)
		{
			return p;
		}
		return Find(T->RChild, e);
	}
}