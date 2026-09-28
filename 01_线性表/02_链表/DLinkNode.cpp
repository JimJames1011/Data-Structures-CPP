#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct DNode {
    ElemType data;
    struct DNode* prior;
    struct DNode* next;
} DLinkNode;

// 初始化
void InitList(DLinkNode*& L) {
    L = (DLinkNode*)malloc(sizeof(DLinkNode));   
    L->prior = NULL;
    L->next = NULL;
}

// 判断是否空
bool emptyList(DLinkNode* L) {
    return (L->next == NULL);
}

// 头插法
void CreateListF(DLinkNode*& L, ElemType a[], int n) {
    DLinkNode* s;
    L->prior = L->next = NULL;
    for (int i = 0; i < n; i++) {
        s = (DLinkNode*)malloc(sizeof(DLinkNode)); 
        s->data = a[i];
        s->next = L->next;
        s->prior = L;
        if (L->next != NULL)
            L->next->prior = s;
        L->next = s;
    }
}

// 尾插法
void CreateListR(DLinkNode*& L, ElemType a[], int n) {
    DLinkNode* s, * r;
    r = L;                                        
    for (int i = 0; i < n; i++) {
        s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}

// 插入
bool ListInsert(DLinkNode*& L, int i, ElemType e) {
    DLinkNode* p = L, * s;
    int j = 0;
    if (i <= 0) return false;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) return false;
    s = (DLinkNode*)malloc(sizeof(DLinkNode));
    s->data = e;
    s->next = p->next;
    s->prior = p;
    if (p->next != NULL)
        p->next->prior = s;
    p->next = s;
    return true;
}

// 删除
bool Listdelete(DLinkNode*& L, int i, ElemType& e) {
    DLinkNode* p = L, * q;
    int j = 0;
    if (i <= 0) return false;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL) return false;
    q = p->next;
    e = q->data;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;                                
}

// 输出
void printList(DLinkNode* L) {
    DLinkNode* p = L->next;
    while (p != NULL) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

// 销毁
void DestroyList(DLinkNode*& L) {
    DLinkNode* p = L, * q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    L = NULL;                                    
}

// 长度
int LengthList(DLinkNode* L) {
    DLinkNode* p = L->next;
    int i = 0;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

// 按值查找位序
int LocateList(DLinkNode* L, ElemType e) {
    int i = 1;                                    
    DLinkNode* p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
        i++;
    }
    if (p == NULL) return 0;
    return i;
}

// 按位序取值
bool GetElem(DLinkNode* L, int i, ElemType& e) {
    int j = 1;
    DLinkNode* p = L->next;
    if (i <= 0) return false;
    while (j < i && p != NULL) {                  
        p = p->next;
        j++;
    }
    if (p == NULL) return false;
    e = p->data;
    return true;
}

// 递增排序
void sortAsc(DLinkNode*& L) {
    if (L->next == NULL || L->next->next == NULL)
        return;                                  
    DLinkNode* p, * pre, * q;
    p = L->next->next;                           
    L->next->next = NULL;                         
    while (p != NULL) {
        q = p->next;                              
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;                     
        p->next = pre->next;
        p->prior = pre;
        if (pre->next != NULL)
            pre->next->prior = p;
        pre->next = p;
        p = q;
    }
}

int main() {
    DLinkNode* h;
    ElemType e;
    InitList(h);
    ElemType a[] = { 'a','b','c','d','e' };

    CreateListF(h, a, 5);
    printList(h);                                
    cout << LengthList(h) << endl;               
    emptyList(h) ? cout << "链表为空" << endl : cout << "链表不为空" << endl;
    GetElem(h, 3, e) ? cout << e << endl : cout << "不存在" << endl;  
    cout << LocateList(h, 'a') << endl;          
    ListInsert(h, 4, 'f');
    printList(h);                                 
    Listdelete(h, 3, e);
    printList(h);                                
    cout << "被删元素: " << e << endl;            
    DestroyList(h);
    return 0;
}
