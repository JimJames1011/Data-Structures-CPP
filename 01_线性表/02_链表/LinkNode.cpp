#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LinkNode;

//头插法
void creatListF(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

//尾插法
void creatListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
}

//初始化线性表
void InitList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

//销毁线性表
void DestoryList(LinkNode*& L) {
	LinkNode* pre = L, * p = L->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

//判断线性表是否为空
bool ListEmpty(LinkNode* L) {
	return(L->next == NULL);
}

//求线性表长度
int LengthList(LinkNode*& L) {
	int len = 0;
	LinkNode* p = L->next;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	return(len);
}

//输出线性表
void DispList(LinkNode*& L) {
	LinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data;
		p = p->next;
	}
	printf("\n");
}

//求线性表中的某个数据元素值
bool GetElem(LinkNode*& L, int i, ElemType& e) {
	int j = 0;
	LinkNode* p = L;
	if (i <= 0)
		return false;
	while (j < i && p != NULL) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	else {
		e = p->data;
		return true;
	}
}


//求线性表中某个数据元素的位序
int LocateList(LinkNode*& L, ElemType e, int i) {
	int j = 0;
	LinkNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
		i++;
	}
	if (p == NULL)
		return(0);
	else
		return(i);
}

//在第i个位置插入数据元素e
bool ListInsert(LinkNode*& L, int i, ElemType e) {
	int j = 0;
	LinkNode* s, * p = L;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

//删除第i个位置的数据元素
bool ListDelete(LinkNode*& L, int i, ElemType& e) {
	int j = 0;
	LinkNode* s, * p = L;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		s = p->next;
		if (p == NULL)
			return false;
		s->data = e;
		p->next = s->next;
		free(s);
		return true;
	}
}

//删除最大值
void maxdelete(LinkNode*& L) {
	LinkNode* p = L->next
		, * pre = L, * max = p, * maxpre = pre;
	while (p != NULL) {
		if (max->data < p->data) {
			max = p;
			maxpre = pre;
		}
		pre = p;
		p = p->next;
	}
	maxpre->next = max->next;
	free(max);
}
//主函数
int main() {
	LinkNode* L;
	ElemType e;
	InitList(L);
	ElemType a[] = { 'a','b','c','d','e' };
	creatListF(L, a, 5);
	DispList(L);
	cout << LengthList(L) << endl;
	ListEmpty(L) ? cout << "链表为空" << endl : cout << "链表不为空" << endl;
	GetElem(L, 3, e) ? cout << "第3个元素为：" << e << endl : cout << "第3个元素不存在" << endl;
	cout << LocateList(L, 'a', 1) << endl;
	ListInsert(L, 4, 'f');
	DispList(L);
	ListDelete(L, 3, e);
	DispList(L);
	DestoryList(L);
}

