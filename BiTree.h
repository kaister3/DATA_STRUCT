#pragma once
#ifndef BINARY_TREE_H_  
#define BINARY_TREE_H_  
#include <stdbool.h>  

typedef struct
{
	int num;//编号：此编号为二叉树按照从左至右从上到下的排序
	char c;//储存
}ElemType;

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *LChild, *RChild;
}BiTNode, *BiTree;//*BiTree是指向该二叉树的地址
typedef int Status;

int InitBiTree(BiTree *T);//InitBiTree
int DestoryBiTree(BiTree T);//DestoryBiTree
int CreateBiTree(BiTree *T);//CreateBiTree
int ClearBiTree(BiTree T);//BiTreeEmpty
int BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);//递归求二叉树深度
BiTNode* Root(BiTree T);
char Value(BiTree T, ElemType e);//e.num为输入的要查找的序号,返回该节点的值
ElemType Parent(BiTree T, ElemType e);
ElemType LeftChild(BiTree T, ElemType e);
ElemType RightChild(BiTree T, ElemType);
ElemType LeftSibling(BiTNode *T, ElemType e);//用户输入num，序号
ElemType RightSibling(BiTNode *T, ElemType e);
int InsertChild(BiTNode T, ElemType p, int LR, BiTree C);
int DeleteChild(BiTNode T, int LR, ElemType p);
int PreOrderTraverse(BiTree T);
int InOrderTraverse(BiTree T);
int PostOrderTraverse(BiTree T);
int LevelOrderTraverse(BiTree T);
BiTNode* Find(BiTNode *T, ElemType e);
#endif