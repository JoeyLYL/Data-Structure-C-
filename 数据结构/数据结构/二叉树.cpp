#include<iostream>
using namespace std;
#include<string>

class TElemType {
public:
	int data;
};
/******************顺序存储二叉树**************/
typedef TElemType SqBiTree[100];
SqBiTree bt;
/******************链式存储二叉树**************/
//二叉链表存储结构
class BiNode {
public:
	TElemType data;
	BiNode * lchild ,*rchild;
};
typedef BiNode* BiTree;
//先序遍历算法（二叉链表）
void PreOrderTraverse(BiTree T) {
	if(T == NULL) return;
	else {
		cout<<T->data.data;    //访问根节点 
		PreOrderTraverse(T->lchild); 
		PreOrderTraverse(T->rchild);
	}
}