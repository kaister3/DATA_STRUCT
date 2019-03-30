#include <stdio.h>  
#include <stdlib.h>  
#include "LinkQueue.h"  

/** �����еĳ�ʼ�� */
LinkQueue* InitQueue()
{
	LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	if (!queue)
	{
		printf("init queue error!\n");
		exit(0);
	}
	queue->front = (QueueNode*)malloc(sizeof(QueueNode));
	queue->front->next = NULL;
	queue->rear = queue->front;
	return queue;
}

/** �����е����٣�ע���Ƚ�ȥ���Ƕ���ͷ�����ȥ���Ƕ���β */
void DestoryQueue(LinkQueue* queue)
{
	while (queue->front)
	{
		queue->rear = queue->front->next;
		free(queue->front);
		queue->front = queue->rear;
	}
}

/** ��� */
void EnQueue(LinkQueue* queue, BiTNode* node)
{
	QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode));
	queueNode->data = node;
	queueNode->next = NULL;
	queue->rear->next = queueNode;
	queue->rear = queueNode;
}

/** ���� */
BiTNode* DeQueue(LinkQueue* queue)
{
	if (queue->front == queue->rear)//����Ϊ��  
		return NULL;
	QueueNode* p = queue->front->next;
	BiTNode* node = p->data;
	queue->front = p;
	return node;
}

int QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		return 1;
	}
	else return 0;
}