#pragma once
#include "BiTree.h"  

/** �����еĽڵ㶨�壬����һ�����������һ���ڵ��ָ�� */
typedef struct QueueNode {
	BiTNode* data;
	struct QueueNode* next;
}QueueNode;

/**  �����еĶ��壬������ͷ�Ͷ�βָ��*/
typedef struct {
	QueueNode* front;
	QueueNode* rear;
}LinkQueue;

LinkQueue* InitQueue();/** �����еĳ�ʼ�� */
void DestoryQueue(LinkQueue*);/** ���ٶ��� */
void EnQueue(LinkQueue*, BiTNode*);/** ��� */
BiTNode* DeQueue(LinkQueue*);/** ���� */