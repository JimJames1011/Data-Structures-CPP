#include<iosream>
using namespace std;

typedef int ElemType;
typedef struct DNode {
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
}DLinkNode;


//头插法
void CreateListF(DLinkNode*& L, ElemType a[], int n) {
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode*));
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode*));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL) {
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
	}
}

//尾插法
void createListR(DLinkNode * &L,ElemType a[],int n ){
	DLinkNode* s, * r;
	L = (DLinkNode*)malloc(sizeof(DLinkNode*));
	r = L;
	for (int i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode*));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

//双链表的插入
bool LinstInsert(DLinkNode*& L, int i, ElemType e) {
	DLinkNode* p = L, * s;
	int j = 0;
	if (i <= 0)
		return false;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return falsew;
	else {
		s = (DLinkNode*)malloc(sizeof(DLinkNode*));
		s->data = e;
		s->next = p->next;
		if (p->next != NULL) {
			p->next->prior = s;
		}
		s->prior = p;
		p->next = s;

	}
}

//双链表的删除
bool Listdelete(DLinkNode*& L, int i, ElemType& e) {
	DLinkNode* p = L, * q;
	int j = 0;
	if (i <= 0)
		return false;
	while (p != NULL && j < i - 1) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		q = p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		if (p->next != NULL)
			p->next->prior = p;
		free(q);
	}
}

//双链表的输出
void printList(DLinkNode*& L) {
	DLinkNode* p = ->next;
	while (p != NULL) {
		cout << p->data << "";
		p = p->next;
	}
}

//双链表的销毁
void DestroyList(DLinkNode*& L, int i, ElemType* e) {
	DLinKNode* p = L, * q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
}

//双链表的查找位序
int LocateList(DLinkNode*& L, ElemType e,int i) {
	int j = 0;
	DlinkNode* p = L->next;
	if (i<=0)
		return false;
	while (p != NULL && p->data != e) {
		p = p->next;
		i++;
	}
	if (p == NULL)
		return false;
	else
		return i;
}

//双链表的查找元素
bool GetElem(DLinkNode*& L, int i, ElemType& e) {
	int j = 0;
	DLinkNode* p=L->next;
	if (i <= 0)
		return false;
	while (j < i && p != NULL) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	else {
		e = p->next;
	}
}

//双链表结点倒置算法
void reverse(DLinkNode*& L) {
	DLinkNode* p = L->next, * q;
	L->next = NULL;
	while (p != NULL) {
		q = p->next;
		p->next = L ->next;
		if (L->next != NULL)
			L->next->prior = p;
	}
	L->next = p;
	p->prior = L;
	p = q;
}

//双链表结点递增
void sorr(DLinkNode*& L) {
	DLinkNode* p, * pre, * q;
	p = L->next->next;
	L->next->next = NULL;
	while (p != NULL) {
		q = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		if (pre->next != NULL)
			pre->next->prior = p;
		pre->next = p;
		p->prior = pre;
		p = q;
	}
}


int main() {
	
}
