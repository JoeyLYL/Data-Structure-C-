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
//��ʼ�����Ա�
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
//����
void DestroyList(SqList& L) {
	if (L.elem)
		delete L.elem;
}
//���
void ClearList(SqList& L) {
	if (L.elem)
		L.length = 0;
}
//����
int LocateList(SqList& L,person &p) {
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == p)
			return i + 1;
	return 0;
}
//����
void InsertList(SqList& L, person& p, int i) {
	for (int j = L.length-1; j >= i-1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i-1] = p;
	L.length++;
}
//ɾ��
void DeleteList(SqList& L,  int i) {
	for(int j=i-1;j<=L.length-1;j++)
		L.elem[j ] = L.elem[j+1];
	L.length--;
}



/****************����***********/
class LinkNode {
public:
	person data;
	LinkNode * next;
};
typedef LinkNode* LinkList;
//��ʼ��
void InitList_L(LinkList &L) {
	L = new LinkNode;
	L->next = NULL;
}
//����
void DestroyList_L(LinkList& L) {
	while (L != NULL) {
		LinkList p = L;
		p = p->next;
		delete p;
	}
}
//���
void ClearList_L(LinkList& L) {
	LinkList p = L->next;
	while (p!=NULL) {
		LinkList q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
}
//�������
int Getlength(LinkList& L) {
	LinkList p = L->next;
	int i=0;
	while (p != NULL) {
		p = p->next;
		i++;
	}
	return i;
}
//ȡ�������i��Ԫ��
void GetElem_i(LinkList& L,int i,person &per) {
	LinkList p = L->next;
	int j = 1;
	while (p!=NULL&&j <i) {
		p = p->next;
		j++;
	}
	per = p->data;
}
//����ڵ㵽��i��λ��
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
//ɾ���ڵ�
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
//ͷ�巨����
void CreateList_H(LinkList& L,int n ) {
	for (int i = 0; i < n; i++) {
		LinkNode* p = new LinkNode;
		cin >> p->data.id;
		cin >> p->data.name;
		p->next = L->next;
		L->next = p;
	}
}
//β�巨����
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
//ѭ������
void  InitCircleList(LinkList& L) {
	L = new LinkNode;
	L->next = L;
}
//�ϲ�ѭ������
LinkList Connect(LinkList& Ta, LinkList& Tb) {
	LinkNode* p = Ta->next;
	Ta->next = Tb->next->next;
	delete Tb->next;
	Tb->next = p;
	return Tb;
}
//˫��������
class DulNode {
public:
	person data;
	DulNode* prior ;
	DulNode* next;
};
typedef DulNode* DulList;
//˫�������ʼ��
void InitDulList(DulList& L)
{
	L = new DulNode;
	L->prior = NULL;
	L->next = NULL;
}
//����
void InsertDulList(DulList& L, int i,person& per) {
	DulNode* s = new DulNode;
	DulList p = L->next;
	int j = 1;
	while ( j < i) {
		p = p->next;
		j++;
	}
	s->data = per;
	s->prior = p->prior; //��һ����s��ǰ������p��ǰ��
	p->prior->next = s;  //�ڶ�������p��ǰ������nextָ�����Ԫ��s�������˵�һ����
	s->next = p;         //��������s�ĺ��ָ��p
	p->prior = s;        //���Ĳ���p��ǰ����Ϊָ��s�������˵ڶ�����
}
//ɾ��
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
