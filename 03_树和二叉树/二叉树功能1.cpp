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

//二叉树的遍历
//先序遍历
void PreOrder(BTNode* b) {
	if (b != NULL) {
		printf("%c", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

//中序遍历
void InOrder(BTNode* b) {
	if (b != NULL) {
		InOrder(b->lchild);
		printf("%c", b->data);
		InOrder(b->rchild);
	}
}

//后序遍历
void PostOrder(BTNode* b) {
	if (b != NULL) {
		PostOrder(b->lchild);
		PostOrder(b->rchild);
	}
}

//计算所有结点个数
int Nodes(BTNode* b) {
	if (b == NULL)
		return 0;
	else
		return Nodes(b->lchild) + Nodes(b->rchild) + 1;
}

//计算所有叶子节点
void DispLeaf(BTNode* b) {
	if (b != NULL) {
		if (b->lchild == NULL && b->rchild == NULL) {
			printf("%c", b->data);
		}
		DispLeaf(b->lchild);
		DispLeaf(b->rchild);
	}
}

//查找结点值为x所在的层次
int Level(BTNode* b, ElemType x, int h) {
	int l;
	if (b == NULL)
		return 0;
	else if (b->data == x)
		return(h);
	else {
		l = Level(b->lchild, x, h + 1);
		if (l != 0)
			return(l);
		else
			return(Level(b->rchild, x, h + 1));
	}
}


//求二叉树第k层的节点个数
void Lnodenum(BTNode* b, int h, int k, int& n) {
	if (b == NULL)
		return;
	else {
		if (h == k)n++;
		else if (h < k) {
			Lnodenum(b->lchild, h + 1, k,n);
			Lnodenum(b->rchild, h + 1, k, n);
		}
	}
}
