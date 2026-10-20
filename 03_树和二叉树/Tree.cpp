#include<iostream>
using namespace std;
typedef char ElemType;
#define maxsize 100
#define maxsons 100

//双亲存储结构
typedef struct {
	ElemType data;
	int parent;//双亲位置
}Ptree[maxsize];

//孩子链存储结构
typedef struct node {
	ElemType data;
	struct node* son[maxsons];//指向孩子的指针数组
}TSonNode;

//孩子兄弟链存储结构
typedef struct tnode {
	ElemType data;
	struct tnode* hp;//指向兄弟
	struct tnode* vp;//指向孩子结点
}TSBNode;

//孩子链求树的高度
int TreeHeight1(TSonNode* t) {
	TSonNode* p;
	int i, h, maxh = 0;
	if (t == NULL)
		return 0;
	else {
		for (i = 0;i < maxsons; i++) {
			p = t->son[i];
			if (p != NULL) {
				h = TreeHeight1(p);
				if (h > maxh)maxh = h;
			}
		}
		return(maxh + 1);
	}

}

//孩子兄弟链求树的高度
int TreeHeight2(TSBNode* t) {
	TSBNode* p;
	int h, maxh;
	if (t == NULL)
		return 0;
	else {
		p = t->vp;
		while (p != NULL) {
			h = TreeHeight2(p);
			if (h > maxh)maxh = h;
			p = t->hp;
		}
		return (maxh + 1);
	}
}
