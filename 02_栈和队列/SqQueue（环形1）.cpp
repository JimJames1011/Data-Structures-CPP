#include<iostream>
using namespace std;

//环形队列
#define maxsize 100
typedef int ElemType;
typedef struct {
	int data[maxsize];
	int front;
	int rear;
} SqQueue;

//初始化队列
void InitQueue(SqQueue*& q) {
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

//判断队列是否为空
bool QueueEmpty(SqQueue* q) {
	return q->front == q->rear;
}

//销毁队列
void DestroyQueue(SqQueue*& q) {
	free(q);
}

//入队
bool enQueue(SqQueue*& q, ElemType e) {
	if ((q->rear + 1) % maxsize == q->front)
		return false;
	q->rear = (q->rear + 1) % maxsize;
	q->data[q->rear] = e;
	return true;
}

//出队
bool deQueue(SqQueue*& q, ElemType* e) {
	if (q->front == q->rear)
		return false;
	q->front = (q->front + 1) % maxsize;
	*e = q->data[q->front];
	return true;
}
