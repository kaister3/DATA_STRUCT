#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "BiTree.h"
#include "LinkQueue.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

/*

Status InitQueue(LinkQueue Q);
Status DestoryQueue(LinkQueue Q);
Status EnQueue(LinkQueue Q, QElemType e);
Status DeQueue(LinkQueue Q, QElemType *e);
Status QueueEmpty(LinkQueue Q);
int SaveData(BiTree T, FILE *pf);
int LoadData(BiTree *T, FILE *pf);*/


int main()
{
	BiTree T = NULL;
	BiTree Son = NULL;
	BiTNode *pointer = NULL;//用来储存指针
	ElemType val;//数值
	int order = 0;//以行次序排列的编号
	int choice = 1;//选项
	int h;
	ElemType *k = (ElemType*)malloc(sizeof(ElemType));
	(*k).c = ' ';
	(*k).num = 0;
	ElemType *par = (ElemType*)malloc(sizeof(ElemType));

	while (choice != 0) {
		system("cls");
		printf("\n\n");

		printf("二叉树形式数据储存系统\n");
		printf("---------------------------------------------------\n");
		printf("       1.InitBiTree           12.RightChild         \n");
		printf("       2.DestoryBiTree        13.LeftSibling        \n");
		printf("       3.CreateBiTree         14.RightSibling       \n");
		printf("       4.ClearBiTree          15.InsertChild        \n");
		printf("       5.BiTreeEmpty          16.DeleteChild        \n");
		printf("       6.BiTreeDepth          17.PreOrderTraverse   \n");
		printf("       7.Root                 18.InOrderTraverse    \n");
		printf("       8.Value                19.PostOrderTraverse  \n");
		printf("       9.Assign               20.LevelOrderTraverse \n");
		printf("       10.Parent              21.SaveData           \n");
		printf("       11.LeftChild           22.LoadData           \n");
		printf("       0.Exit\n");
		printf("---------------------------------------------------\n\n");
		printf("注意：本系统不能处理高度大于12的二叉树，请谨慎操作\n\n");

		printf("请输入您想操作的选项\n\n");
		scanf("%d", &choice);


		switch (choice)
		{
		case 1:
		{
			if (InitBiTree(&T) == 1)
			{
				printf("构造空二叉树成功\n");
			}
			else printf("构造失败\n");
			getchar();
			getchar();
			break;
		}//1.创造二叉树头节点

		case 2:
		{
			if (DestoryBiTree(T))
			{
				printf("销毁成功\n");
			}
			else printf("销毁失败\n");
			getchar();
			getchar();
			break;
		}//2.摧毁二叉树及头节点

		case 3:
		{
			printf("请输入您想放在此节点的字符\n输入'#'停止\n输入' '生成空结点\n输入时按照先序遍历的顺序，请自行画好结构图\n");
			CreateBiTree(T);
		}//3.创建二叉树

		case 4:
		{
			if (ClearBiTree(T)) {
				printf("清除成功\n");
			}
			else printf("清除失败\n");
			getchar();
			getchar();
			break;
		}//4.清空二叉树

		case 5:
		{
			if (BiTreeEmpty(T))
			{
				printf("该二叉树为空\n");
			}
			else
			{
				printf("该二叉树不为空\n");
			}
			getchar();
			getchar();
			break;
		}//5.判断是否为空

		case 6:
		{
			h = BiTreeDepth(T);
			printf("%d", h);
			getchar();
			getchar();
			break;
		}//6.二叉树高度

		case 7:
		{
			pointer = Root(T);
			if (pointer == NULL)
			{
				printf("已将二叉树的根节点存入内存\n\n");
			}
			else
			{
				printf("不知道为什么失败了\n\n");
			}
			getchar();
			getchar();
			break;
		}//7.提取二叉树根节点

		case 8:
		{
			printf("输入您想查询的节点编号（行序）\n");
			scanf("%d", (*k).num);
			Value(T, *k);
			printf("%s\n", (*k).c);
			getchar();
			getchar();
			break;
		}//8.输入序号求值

		case 9:
		{
			printf("请输入您想赋的值\n");
			scanf("%c", val.c);
			getchar();
			printf("请输入您想赋值的位置\n");
			scanf("%d", &order);
			pointer->data.num = order;
			pointer->data.c = val.c;

			if (Assign(T, pointer, val))
			{
				printf("赋值成功！\n");
			}
			else
			{
				printf("赋值失败！\n");
			}
			getchar();
			getchar();
			break;
		}//9输入序号，赋值
		case 10:
		{
			printf("请输入您想查找的结点值\n");
			scanf("%c", &val.c);
			*k = val;
			*par = Parent(T, *k);
			if ((*par).c == ' ')
			{
				printf("寻找双亲结点失败\n");
			}
			else
			{
				printf("寻找成功，该结点的值为%c\n", (*par).c);
			}
			getchar();
			getchar();
			break;
		}//10.储存双亲结点

		case 11:
		{
			printf("请输入您想查找的值\n");
			scanf("%c", (*k).c);
			getchar();
			*par = LeftChild(T, *k);
			if ((*par).c == ' ')
			{
				printf("失败！\n");
			}
			else
			{
				printf("成功！左子树值为%c\n", (*par).c);
			}
			getchar();
			getchar();
			break;
		}//储存左孩子

		case 12:
		{

			printf("请输入您想查找的值\n");
			scanf("%c", (*k).c);
			getchar();
			*par = RightChild(T, *k);
			if ((*par).c == ' ')
			{
				printf("失败！\n");
			}
			else
			{
				printf("成功！右子树值为%c\n",(* par).c);
			}
			getchar();
			getchar();
			break;
		}

		case 13:
		{
			printf("请输入您想查找的值\n");
			scanf("%c", &val);
			getchar();
			*par = LeftSibling(T, *k);
			if ((*par).c == ' ')
			{
				printf("失败！\n");
			}
			else
			{
				printf("成功！左兄弟值为%c\n", (*par).c);
			}
			getchar();
			getchar();
			break;
		}//13

		case 14:
		{
			printf("请输入您想查找的值\n");
			scanf("%c", &val);
			getchar();
			*par = RightSibling(T, *k);
			if ((*par).c == ' ')
			{
				printf("失败！\n");
			}
			else
			{
				printf("成功！右兄弟值为%c\n", (*par).c);
			}
			getchar();
			getchar();
			break;
		}//14.寻找右兄弟

		case 15:
		{
			int LR = 0;
			printf("您想插入为左子树还是右子树？左0右1\n");
			scanf("%d", &LR);
			printf("下面开始创建子树：\n");
			InitBiTree(&T);
			CreateBiTree(&Son);
			printf("请输入您想插入的结点\n");
			scanf("%c", (*k).c);
			if (InsertChild(*T, *k, LR, Son))
			{
				printf("插入成功！\n");
			}
			else
			{
				printf("插入失败！");
			}
			getchar();
			getchar();
			break;
		}//插入子树

		case 16:
		{
			int LR = 0;
			printf("请输入您想删除的结点\n");
			scanf("%c", (*k).c);
			printf("请输入您想删除的是左子树还是右子树？左0右1\n");
			scanf("%d", &LR);
			if (DeleteChild(*T, LR, *k))
			{
				printf("成功！\n");
			}
			else
			{
				printf("失败！\n");
			}
			getchar();
			getchar();
			break;
		}//删除子树

		case 17:
		{
			PreOrderTraverse(T);
			getchar();
			getchar();
			break;
		}

		case 18:
		{
			InOrderTraverse(T);
			getchar();
			getchar();
			break;
		}

		case 19:
		{
			PostOrderTraverse(T);
			getchar();
			getchar();
			break;
		}

		case 20:
		{
			LevelOrderTraverse(T);
			getchar();
			getchar();
			break;
		}

		case 21:
		{
			FILE *fsave = NULL;
			if ((fsave = fopen("Input.dat", "w")) == NULL)
			{
				printf("存储失败！\n");
			}
			SaveData(T, fsave);
			getchar();
			getchar();
			break;
		}

		case 22:
		{
			FILE *fload = NULL;
			if ((fload = fopen("Output.dat", "r")) == NULL)
			{
				printf("加载失败！\n");
			}
			LoadData(&T, fload);
			getchar();
			getchar();
			break;
		}
		case 0:
		{
			return 1;
		}
		}//switch
	}//while

}//main

int SaveData(BiTree T, FILE *pf)
{
	char c = '#';
	if (T == NULL)
	{
		fwrite(&c, sizeof(char), 1, pf);
	}
	else
	{
		fwrite(&(T->data.c), sizeof(char), 1, pf);
		SaveData(T->LChild, pf);
		SaveData(T->RChild, pf);
	}
	return 1;
}

int LoadData(BiTree *T, FILE *pf)
{
	char c;
	fread(&c, sizeof(char), 1, pf);
	if (c == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data.c = c;
		LoadData(&((*T)->LChild), pf);
		LoadData(&((*T)->RChild), pf);
	}
	return 1;
}