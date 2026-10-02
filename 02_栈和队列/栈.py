#include<iostream>
using  namespace std;
#define MaxSize 100
typedef char ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;

//初始化栈
void InitStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

//销毁栈
void DestoryStack(SqStack*& s) {
	free(s);
}

//判断栈是否为空
bool StackEmpty(SqStack* s) {
	return(s->top == -1);
}

//进栈
bool Push(SqStack*& s, ElemType e) {
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

//出栈
bool Pop(SqStack*& s, ElemType e) {
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

//取栈顶元素
bool GetTop(SqStack*& s, ElemType e) {
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

//输出栈
bool printStack(SqStack*& s) {
	if (s->top == -1)
		return false;
	for (int i = 0;i <= s->top;i++) {
		cout << s->data [i]<< endl;
	}
}

//判断是否对称串
bool symmetry(ElemType str[]) {
	int i;ElemType e;
	SqStack* st;
	InitStack(st);
	for (i = 0;str[i] != "\0";i++)
		Push(st, str[i]); 
	for (i = 0;str[i] != "\0";i++) {
		Pop(st, e);
		if (e != str[i]) {
			DestoryStack(st);
			return false;
		}
	}
	DestoryStack(st);
	return true;
}
