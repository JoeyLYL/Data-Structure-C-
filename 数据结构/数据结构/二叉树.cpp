#include<iostream>
using namespace std;
#include<string>

class TElemType {
public:
	int data;
};
/******************˳��洢������**************/
typedef TElemType SqBiTree[100];
SqBiTree bt;
/******************��ʽ�洢������**************/
//��������洢�ṹ
class BiNode {
public:
	TElemType data;
	BiNode * lchild ,*rchild;
};
typedef BiNode* BiTree;
//��������㷨����������
void PreOrderTraverse(BiTree T) {
	if(T == NULL) return;
	else {
		cout<<T->data.data;    //���ʸ��ڵ� 
		PreOrderTraverse(T->lchild); 
		PreOrderTraverse(T->rchild);
	}
}