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
		(*T)->RChild = NULL;//空的头结点
		return 1;
	}
	else return 0;
}//InitBiTree

int DestoryBiTree(BiTree T)
{
	if (!T)
	{
		return 0;//到头（T->Child不存在）之后停止
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
		free(T);//用递归方法依次清除每个结点
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
			(*T)->data.c = ch;//赋值
			printf("输入%c的左子节点：\n", ch);
			CreateBiTree(&(*T)->LChild);
			printf("输入%c的右子节点：\n", ch);
			CreateBiTree(&(*T)->RChild);
			return 1;
		}
	}
	
}//

int ClearBiTree(BiTree T)
{
	DestoryBiTree(T);
	InitBiTree(&T); //不同于Destroy的是之后又给头结点分配空间置空
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
}//递归求二叉树深度

BiTNode* Root(BiTree T)
{
	if (BiTreeEmpty(T)) {
		return NULL;
	}
	else return T;
}

char Value(BiTree T, ElemType e)//e.num为输入的要查找的序号,返回该节点的值
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

int Assign(BiTree T, BiTNode *e, ElemType value)//序号，值，e->data.num为用户输入的要赋值的序号
{
	if (Value(T, value))//用if判定该结点存在
	{

		(*e).data.c = value.c;
		return 1;
	}

	else//存在
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
				//e是左或右孩子
				return a->data;
			}
			else//若不是，递归检验其左和右孩子
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
	return s;//空或不存在时返回' '
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

ElemType LeftSibling(BiTNode *T, ElemType e)//用户输入num，序号
{
	ElemType a;
	BiTree p;
	BiTree q, r;
	ElemType s;
	s.c = ' ';

	if (T)
	{
		a = Parent(T, e);//a为e的双亲结点
		p = Find(T, a);
		if (p == NULL)
		{
			return s;//返回空
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
		a = Parent(T, e);//a为e的双亲结点
		p = Find(T, a);
		if (p == NULL)
		{
			return s;//返回空
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
		printf("二叉树C含有右子树！\n");
		return 0;
	}
	m = Find(t, p);
	if (LR)
	{
		n = m->RChild;
		m->RChild = c;
		c->RChild = n;
	}//插入为右子树
	else
	{
		n = m->LChild;
		m->LChild = c;
		c->RChild = n;
	}//同上

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
		temp->LChild = NULL;//删除左子树
	}
	return 1;
}

int PreOrderTraverse(BiTNode *T)
{
	if (T)
	{
		printf("%c\n", T->data.c);//访问根节点
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
	int curLayerCount = 0; //当前层中的节点数  
	int nextLayerCount = 0; //下一层中的节点数  
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
		if (curLayerCount == 0)//一层已经遍历完毕  
		{
			curLayerCount = nextLayerCount;
			nextLayerCount = 0;
			printf("\n");
		}
	}
}

BiTNode* Find(BiTNode *T, ElemType e)//找到该元素指向的结点
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