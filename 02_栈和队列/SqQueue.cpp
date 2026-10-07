#include<iostream>
using namespace std;

#define maxsize 100

typedef int ElemType;
typedef struct{
	ElemType data[maxsize];
	int front, rear;
}SqQueue;

//初始化队列
void InitQueue(SqQueue*& Q) {
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	Q->front = Q->rear = -1;
}

//销毁队列
void DestroyQueue(SqQueue*& q) {
	free(q);
}

//判断队列是否为空
bool QueueEmpty(SqQueue* q) {
	return(q->front == q->rear);
}

//入队
bool enQueue(SqQueue*& q, ElemType e) {
	if (q->rear == maxsize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

//出队
bool deQueue(SqQueue*& q, ElemType& e) {
	if (QueueEmpty(q))
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

int main() {

}
