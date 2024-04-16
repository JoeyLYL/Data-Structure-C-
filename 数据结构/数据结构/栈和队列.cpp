#include<iostream>
using namespace std;
#include<string>

/******************˳��ջ**************/
class ElemType {
public:
	int data;
};

class SqStack {
public:
	ElemType * top;//ָ��ջ��Ԫ��֮�ϵĵ�ַ
	ElemType * base;
	int staksize;
};
//��ʼ��
void InitStack(SqStack &s){
	s .base= new ElemType[100];
	s.top = s.base;
	s.staksize = 100;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack& s) {
	if (s.top = s.base)
		return true;
	return false;
}
//��ջ
void Push(SqStack& s, ElemType& e) {
	if ((s.top - s.base) == s.staksize)
		cerr<<"error"<<endl;
	*s.top++ = e;
}
//��ջ
void Pop(SqStack& s, ElemType& e) {
	if(s.top == s.base)
		cerr << "error" << endl;
	e = *-- s.top;
}

/******************��ջ**************/
class StackNode {
public:
	ElemType data;
	StackNode* next;
};
typedef StackNode* LinkStack;

bool InitStack_L(LinkStack& s) {
	s = NULL;
}
//��ջ
void Push_L(LinkStack& s, ElemType& e) {
	StackNode* p = new StackNode;
	p->data= e;
	p->next = s;
	s = p;
}
//��ջ
void Pop_L(LinkStack& s, ElemType& e) {
	e = s->data;
	StackNode* p = s;
	s = s->next;
	delete p;
}

/******************˳�����**************/
#define MAXQSIZE 100
class SqQueue {
public:
	ElemType* base;
	int front;
	int rear;
};
//��ʼ��
void InitQueue(SqQueue& q) {
	q.base = new ElemType[MAXQSIZE];
	q.front = q.rear = 0;
}
//����г���
int QueueLength(SqQueue& q) {
	return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}
//���
void InQueue(SqQueue& q, ElemType& e) {
	if ((q.rear + 1) % MAXQSIZE == q.front)
		cerr << "error" << endl;
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % MAXQSIZE;
}
//����
void OutQueue(SqQueue& q, ElemType& e) {
	if(q.front==q.rear)
		cerr << "error" << endl;
	e = q.base[q.front];
	q.front = (q.front + 1) % MAXQSIZE;
}
/******************������**************/
class QNode {
public:
	ElemType data;
	QNode* next;
};
typedef QNode* QueuePtr;

class LinkQueue {
public:
	QueuePtr front;
	QueuePtr rear;
};
//��ʼ��
void InitQueue_L(LinkQueue& q) {
	q.front = q.rear = new QNode;
	q.front->next = NULL;
}
//���
void InQueue_L(LinkQueue& q, ElemType& e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
}
//����
void OutQueue_L(LinkQueue& q, ElemType& e) {
	QNode* p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	if (q.rear = p)
		q.rear = q.front;
	delete p; 
}