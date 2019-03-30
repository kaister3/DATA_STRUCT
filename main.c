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
	BiTNode *pointer = NULL;//��������ָ��
	ElemType val;//��ֵ
	int order = 0;//���д������еı��
	int choice = 1;//ѡ��
	int h;
	ElemType *k = (ElemType*)malloc(sizeof(ElemType));
	(*k).c = ' ';
	(*k).num = 0;
	ElemType *par = (ElemType*)malloc(sizeof(ElemType));

	while (choice != 0) {
		system("cls");
		printf("\n\n");

		printf("��������ʽ���ݴ���ϵͳ\n");
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
		printf("ע�⣺��ϵͳ���ܴ���߶ȴ���12�Ķ����������������\n\n");

		printf("���������������ѡ��\n\n");
		scanf("%d", &choice);


		switch (choice)
		{
		case 1:
		{
			if (InitBiTree(&T) == 1)
			{
				printf("����ն������ɹ�\n");
			}
			else printf("����ʧ��\n");
			getchar();
			getchar();
			break;
		}//1.���������ͷ�ڵ�

		case 2:
		{
			if (DestoryBiTree(T))
			{
				printf("���ٳɹ�\n");
			}
			else printf("����ʧ��\n");
			getchar();
			getchar();
			break;
		}//2.�ݻٶ�������ͷ�ڵ�

		case 3:
		{
			printf("������������ڴ˽ڵ���ַ�\n����'#'ֹͣ\n����' '���ɿս��\n����ʱ�������������˳�������л��ýṹͼ\n");
			CreateBiTree(T);
		}//3.����������

		case 4:
		{
			if (ClearBiTree(T)) {
				printf("����ɹ�\n");
			}
			else printf("���ʧ��\n");
			getchar();
			getchar();
			break;
		}//4.��ն�����

		case 5:
		{
			if (BiTreeEmpty(T))
			{
				printf("�ö�����Ϊ��\n");
			}
			else
			{
				printf("�ö�������Ϊ��\n");
			}
			getchar();
			getchar();
			break;
		}//5.�ж��Ƿ�Ϊ��

		case 6:
		{
			h = BiTreeDepth(T);
			printf("%d", h);
			getchar();
			getchar();
			break;
		}//6.�������߶�

		case 7:
		{
			pointer = Root(T);
			if (pointer == NULL)
			{
				printf("�ѽ��������ĸ��ڵ�����ڴ�\n\n");
			}
			else
			{
				printf("��֪��Ϊʲôʧ����\n\n");
			}
			getchar();
			getchar();
			break;
		}//7.��ȡ���������ڵ�

		case 8:
		{
			printf("���������ѯ�Ľڵ��ţ�����\n");
			scanf("%d", (*k).num);
			Value(T, *k);
			printf("%s\n", (*k).c);
			getchar();
			getchar();
			break;
		}//8.���������ֵ

		case 9:
		{
			printf("���������븳��ֵ\n");
			scanf("%c", val.c);
			getchar();
			printf("���������븳ֵ��λ��\n");
			scanf("%d", &order);
			pointer->data.num = order;
			pointer->data.c = val.c;

			if (Assign(T, pointer, val))
			{
				printf("��ֵ�ɹ���\n");
			}
			else
			{
				printf("��ֵʧ�ܣ�\n");
			}
			getchar();
			getchar();
			break;
		}//9������ţ���ֵ
		case 10:
		{
			printf("������������ҵĽ��ֵ\n");
			scanf("%c", &val.c);
			*k = val;
			*par = Parent(T, *k);
			if ((*par).c == ' ')
			{
				printf("Ѱ��˫�׽��ʧ��\n");
			}
			else
			{
				printf("Ѱ�ҳɹ����ý���ֵΪ%c\n", (*par).c);
			}
			getchar();
			getchar();
			break;
		}//10.����˫�׽��

		case 11:
		{
			printf("������������ҵ�ֵ\n");
			scanf("%c", (*k).c);
			getchar();
			*par = LeftChild(T, *k);
			if ((*par).c == ' ')
			{
				printf("ʧ�ܣ�\n");
			}
			else
			{
				printf("�ɹ���������ֵΪ%c\n", (*par).c);
			}
			getchar();
			getchar();
			break;
		}//��������

		case 12:
		{

			printf("������������ҵ�ֵ\n");
			scanf("%c", (*k).c);
			getchar();
			*par = RightChild(T, *k);
			if ((*par).c == ' ')
			{
				printf("ʧ�ܣ�\n");
			}
			else
			{
				printf("�ɹ���������ֵΪ%c\n",(* par).c);
			}
			getchar();
			getchar();
			break;
		}

		case 13:
		{
			printf("������������ҵ�ֵ\n");
			scanf("%c", &val);
			getchar();
			*par = LeftSibling(T, *k);
			if ((*par).c == ' ')
			{
				printf("ʧ�ܣ�\n");
			}
			else
			{
				printf("�ɹ������ֵ�ֵΪ%c\n", (*par).c);
			}
			getchar();
			getchar();
			break;
		}//13

		case 14:
		{
			printf("������������ҵ�ֵ\n");
			scanf("%c", &val);
			getchar();
			*par = RightSibling(T, *k);
			if ((*par).c == ' ')
			{
				printf("ʧ�ܣ�\n");
			}
			else
			{
				printf("�ɹ������ֵ�ֵΪ%c\n", (*par).c);
			}
			getchar();
			getchar();
			break;
		}//14.Ѱ�����ֵ�

		case 15:
		{
			int LR = 0;
			printf("�������Ϊ��������������������0��1\n");
			scanf("%d", &LR);
			printf("���濪ʼ����������\n");
			InitBiTree(&T);
			CreateBiTree(&Son);
			printf("�������������Ľ��\n");
			scanf("%c", (*k).c);
			if (InsertChild(*T, *k, LR, Son))
			{
				printf("����ɹ���\n");
			}
			else
			{
				printf("����ʧ�ܣ�");
			}
			getchar();
			getchar();
			break;
		}//��������

		case 16:
		{
			int LR = 0;
			printf("����������ɾ���Ľ��\n");
			scanf("%c", (*k).c);
			printf("����������ɾ��������������������������0��1\n");
			scanf("%d", &LR);
			if (DeleteChild(*T, LR, *k))
			{
				printf("�ɹ���\n");
			}
			else
			{
				printf("ʧ�ܣ�\n");
			}
			getchar();
			getchar();
			break;
		}//ɾ������

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
				printf("�洢ʧ�ܣ�\n");
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
				printf("����ʧ�ܣ�\n");
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