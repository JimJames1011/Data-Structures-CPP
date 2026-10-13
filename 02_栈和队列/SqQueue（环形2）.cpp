#include<iostream>
using namespace std;

//环形队列
#define maxsize 100
typedef int ElemType;
typedef struct {
	ElemType data[maxsize];
	int front;
	int count;
} QuType;

//初始化队列
void InitQueue(QuType*& q) {
	q = (QuType*)malloc(sizeof(QuType));
	q->front = 0;
	q->count = 0;
}

//入队
bool enQueue(QuType*& q, ElemType e) {
	int rear;
	if (q->count == maxsize)
		return false;
	else {
		rear = (q->front + q->count) % maxsize;
		rear = (rear + 1) % maxsize;
		q->data[rear] = e;
		q->count++;
		return true;
	}
}

//出队
bool deQueue(QuType*& q, ElemType& e) {
	if (q->count == 0)
		return false;
	else {
		e = q->data[q->front];
		q->front = (q->front + 1) % maxsize;
		q->count--;
		return true;
	}
}

//判断空算法
bool EmptyQueue(QuType* q) {
	return q->count == 0;
}
