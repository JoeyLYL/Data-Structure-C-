#include<iostream>
using namespace std;
#include<string>

class person{
public:
	string name;
	int id;
	bool operator==(person& p)
	{
		if (this->name == p.name && this->id == p.id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class SqList {
public:
	person* elem;
	int length;
};
//初始化线性表
bool InitList(SqList &L) {
	L.elem = new person[100];
	if (!L.elem) 
	{
		cerr << "error" << endl;
		return false;
	}
	L.length = 0;
	return 1;
}
//销毁
void DestroyList(SqList& L) {
	if (L.elem)
		delete L.elem;
}
//清空
void ClearList(SqList& L) {
	if (L.elem)
		L.length = 0;
}
//查找
int LocateList(SqList& L,person &p) {
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == p)
			return i + 1;
	return 0;
}
//插入
void InsertList(SqList& L, person& p, int i) {
	for (int j = L.length-1; j >= i-1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i-1] = p;
	L.length++;
}
//删除
void DeleteList(SqList& L,  int i) {
	for(int j=i-1;j<=L.length-1;j++)
		L.elem[j ] = L.elem[j+1];
	L.length--;
}



/****************链表***********/
class LinkNode {
public:
	person data;
	LinkNode * next;
};
typedef LinkNode* LinkList;
//初始化
void InitList_L(LinkList &L) {
	L = new LinkNode;
	L->next = NULL;
}
//销毁
void DestroyList_L(LinkList& L) {
	while (L != NULL) {
		LinkList p = L;
		p = p->next;
		delete p;
	}
}
//清空
void ClearList_L(LinkList& L) {
	LinkList p = L->next;
	while (p!=NULL) {
		LinkList q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
}
//求单链表表长
int Getlength(LinkList& L) {
	LinkList p = L->next;
	int i=0;
	while (p != NULL) {
		p = p->next;
		i++;
	}
	return i;
}
//取单链表第i个元素
void GetElem_i(LinkList& L,int i,person &per) {
	LinkList p = L->next;
	int j = 1;
	while (p!=NULL&&j <i) {
		p = p->next;
		j++;
	}
	per = p->data;
}
//插入节点到第i个位置
void InsertList_L(LinkList& L, int i, person& per) {
	LinkNode * p = L->next;
	LinkNode *s = new LinkNode;
	s->data = per;
	int j = 1;
	while (j < i-1) {
		p = p->next;
		j++;
	}
	s->next = p->next;
	p->next = s;
}
//删除节点
void DeleteList_L(LinkList& L, int i, person& per) {
	LinkNode* p = L->next;
	LinkNode* q;
	int j = 1;
	while (j < i-1) {
		p = p->next;
		j++;
	}
	q = p->next;
	per = q->data;
	p->next = p->next->next;
	delete q;
}
//头插法创建
void CreateList_H(LinkList& L,int n ) {
	for (int i = 0; i < n; i++) {
		LinkNode* p = new LinkNode;
		cin >> p->data.id;
		cin >> p->data.name;
		p->next = L->next;
		L->next = p;
	}
}
//尾插法创建
void CreateList_R(LinkList& L, int n) {
	LinkNode* r = L;
	for (int i = 0; i < n; i++) {
		LinkNode* p = new LinkNode;
		cin >> p->data.id;
		cin >> p->data.name;
		p->next = NULL;
		r->next = p;
		r = r->next;
	}
}
//循环链表
void  InitCircleList(LinkList& L) {
	L = new LinkNode;
	L->next = L;
}
//合并循环链表
LinkList Connect(LinkList& Ta, LinkList& Tb) {
	LinkNode* p = Ta->next;
	Ta->next = Tb->next->next;
	delete Tb->next;
	Tb->next = p;
	return Tb;
}
//双向链表定义
class DulNode {
public:
	person data;
	DulNode* prior ;
	DulNode* next;
};
typedef DulNode* DulList;
//双向链表初始化
void InitDulList(DulList& L)
{
	L = new DulNode;
	L->prior = NULL;
	L->next = NULL;
}
//插入
void InsertDulList(DulList& L, int i,person& per) {
	DulNode* s = new DulNode;
	DulList p = L->next;
	int j = 1;
	while ( j < i) {
		p = p->next;
		j++;
	}
	s->data = per;
	s->prior = p->prior; //第一步：s的前趋等于p的前趋
	p->prior->next = s;  //第二步，用p的前趋结点的next指向插入元素s，更改了第一条链
	s->next = p;         //第三步：s的后继指向p
	p->prior = s;        //第四步：p的前趋改为指向s，更改了第二条链
}
//删除
void DeleteDulList(DulList& L, int i) {
	DulList p = L->next;
	int j = 1;
	while (j < i) {
		p = p->next;
		j++;
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
}
