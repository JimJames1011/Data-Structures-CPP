#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct qnode{
	ElemType data;
	struct qnode* next;
}DataNode;
typedef struct {
	DataNode* front;
	DataNode* rear;
}LinkQuNode;

//初始化队列
void InitQueue(LinkQuNode*& q) {
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}

//销毁队列 
void DestroyQueue(LinkQuNode*& q) {
	DataNode* pre = q->front, * p;
	if (pre != NULL) {
		p = pre->next;
		while (p != NULL) {
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(p);
}

//入队
bool enQueue(LinkQuNode*& q, ElemType e) {
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)
		q->front = q->rear = p;
	else {
		q->rear->next = p;
		q->rear = p;
	}
}

//出队
bool deQueue(LinkQuNode*& q, ElemType& e) {
	DataNode* t;
	if (q->rear == NULL)
		return false;
	t = q->front;
	if(q->front==q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}
