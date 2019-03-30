#pragma once
#include "BiTree.h"  

/** 链队列的节点定义，包含一个数据域和下一个节点的指针 */
typedef struct QueueNode {
	BiTNode* data;
	struct QueueNode* next;
}QueueNode;

/**  链队列的定义，包含队头和队尾指针*/
typedef struct {
	QueueNode* front;
	QueueNode* rear;
}LinkQueue;

LinkQueue* InitQueue();/** 链队列的初始化 */
void DestoryQueue(LinkQueue*);/** 销毁队列 */
void EnQueue(LinkQueue*, BiTNode*);/** 入队 */
BiTNode* DeQueue(LinkQueue*);/** 出队 */