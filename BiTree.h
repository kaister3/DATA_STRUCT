#pragma once
#ifndef BINARY_TREE_H_  
#define BINARY_TREE_H_  
#include <stdbool.h>  

typedef struct
{
	int num;//��ţ��˱��Ϊ���������մ������Ҵ��ϵ��µ�����
	char c;//����
}ElemType;

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *LChild, *RChild;
}BiTNode, *BiTree;//*BiTree��ָ��ö������ĵ�ַ
typedef int Status;

int InitBiTree(BiTree *T);//InitBiTree
int DestoryBiTree(BiTree T);//DestoryBiTree
int CreateBiTree(BiTree *T);//CreateBiTree
int ClearBiTree(BiTree T);//BiTreeEmpty
int BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);//�ݹ�����������
BiTNode* Root(BiTree T);
char Value(BiTree T, ElemType e);//e.numΪ�����Ҫ���ҵ����,���ظýڵ��ֵ
ElemType Parent(BiTree T, ElemType e);
ElemType LeftChild(BiTree T, ElemType e);
ElemType RightChild(BiTree T, ElemType);
ElemType LeftSibling(BiTNode *T, ElemType e);//�û�����num�����
ElemType RightSibling(BiTNode *T, ElemType e);
int InsertChild(BiTNode T, ElemType p, int LR, BiTree C);
int DeleteChild(BiTNode T, int LR, ElemType p);
int PreOrderTraverse(BiTree T);
int InOrderTraverse(BiTree T);
int PostOrderTraverse(BiTree T);
int LevelOrderTraverse(BiTree T);
BiTNode* Find(BiTNode *T, ElemType e);
#endif