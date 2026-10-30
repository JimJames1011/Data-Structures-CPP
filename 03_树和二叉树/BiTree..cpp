#include<iostream>
using namespace std;
typedef char ElemType;
#define maxsize 100
typedef ElemType SqBinTree[maxsize];

//二叉树节点定义
typedef struct Node {
	char data;
	struct Node* lchild, * rchild;
}BTNode;

//创建二叉树
void CreateBiTree(BTNode*& b, const char* str) {
	BTNode* Stack[maxsize], * p;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0') {
		switch (ch) {
		case '(':
			top++;
			Stack[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
				b = p;
			else {
				if (k == 1)
					Stack[top]->lchild = p;
				else
					Stack[top]->rchild = p;
			}
		}
		j++;
		ch = str[j];
	}
}

//二叉树的高度
int BTHeight(BTNode* b) {
	int lchild, rchild;
	if (b == NULL)return(0);
	else {
		lchild = BTHeight(b->lchild);
		rchild = BTHeight(b->rchild);
		return(lchild > rchild) ? (lchild + 1) : (rchild + 1);
	}
}

//输出二叉树
void DispBTree(BTNode* b) {
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild != NULL)printf(",");
			DispBTree(b->rchild);
			printf(")");
		}
	}
}

//销毁二叉树
void DestroyBTree(BTNode*& b) {
	if (b != NULL) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

//找孩子结点
BTNode* LchildNode(BTNode* p) {
	return p->lchild;
}
BTNode* RchildNode(BTNode* p) {
	return p->rchild;
}

//查找结点
BTNode* FindNode(BTNode* b, ElemType e) {
	BTNode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == e) {
		return b;
	}
	else {
		p = FindNode(b->lchild, e);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, e);
	}
}

int main() {
	BTNode* b, * p, * lp, * rp;
	int height;
	const char* str = "A(B(D,E(H(J,K(L,M((N)))))),C(F,G(,I)))";
	CreateBiTree(b,str);
	DispBTree(b);
	BTNode* pH = FindNode(b, 'H');
	cout << pH->lchild << endl;
	cout << pH->rchild << endl;
	height = BTHeight(b);
	cout << height;
	DestroyBTree(b);
	return 0;
}
