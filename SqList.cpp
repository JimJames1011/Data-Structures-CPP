#include <iostream>
#include <cstdlib>
#define MaxSize 100

using namespace std;

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

// 建立顺序表
void CreatList(SqList*& L, ElemType a[], int n) {
    int k = 0, i = 0;

    L = (SqList*)malloc(sizeof(SqList));

    while (i < n) {
        L->data[k] = a[i];
        k++;
        i++;
    }

    L->length = k;
}

// 尾部添加元素
bool Append(SqList*& L, ElemType e) {
    if (L->length >= MaxSize)
        return false;

    L->data[L->length] = e;
    L->length++;

    return true;
}

// 求顺序表长度
int GetLength(SqList* L) {
    return L->length;
}

// 求第 i 个元素
bool GetElem(SqList* L, int i, ElemType& e) {
    if (i < 1 || i > L->length)
        return false;

    e = L->data[i - 1];

    return true;
}

// 设置第 i 个元素
bool SetElem(SqList* L, int i, ElemType e) {
    if (i < 1 || i > L->length)
        return false;

    L->data[i - 1] = e;

    return true;
}

// 查找第一个值为 e 的元素
int LocateElem(SqList* L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e)
            return i + 1;
    }

    return 0;
}

// 在第 i 个位置插入元素
bool ListInsert(SqList* L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1 || L->length >= MaxSize)
        return false;

    // 从后往前移动元素
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }

    L->data[i - 1] = e;
    L->length++;

    return true;
}

// 删除第 i 个元素
bool ListDelete(SqList* L, int i) {
    if (i < 1 || i > L->length)
        return false;

    // 从前往后移动元素
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }

    L->length--;

    return true;
}

// 输出顺序表
void PrintList(SqList* L) {
    for (int i = 0; i < L->length; i++) {
        cout << L->data[i] << " ";
    }

    cout << endl;
}

int main() {
    SqList* L;

    ElemType a[] = {1, 2, 2, 3, 4, 5, 7, 8, 10};

    CreatList(L, a, 9);

    cout << "1.建立顺序表" << endl;
    PrintList(L);

    cout << "2.尾部加上 11" << endl;
    Append(L, 11);
    PrintList(L);

    cout << "3.顺序表长度" << endl;
    cout << "length=" << GetLength(L) << endl;

    cout << "4.求第三个元素" << endl;
    ElemType e;

    if (GetElem(L, 3, e)) {
        cout << "第三个元素是" << e << endl;
    }

    cout << "5.设置第 2 个元素是 20" << endl;
    SetElem(L, 2, 20);
    PrintList(L);

    cout << "6.求第一个值是 2 的序号" << endl;
    cout << LocateElem(L, 2) << endl;

    cout << "7.在第四位加上 8" << endl;
    ListInsert(L, 4, 8);
    PrintList(L);

    cout << "8.删除第五个元素" << endl;
    ListDelete(L, 5);
    PrintList(L);

    cout << "9.输出所有元素" << endl;
    PrintList(L);

    return 0;
}
