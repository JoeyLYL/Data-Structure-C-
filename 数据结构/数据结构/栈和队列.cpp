#include<iostream>
using namespace std;
#include<string>

/******************顺序栈**************/
class ElemType {
public:
	int data;
};

class SqStack {
public:
	ElemType * top;//指向栈顶元素之上的地址
	ElemType * base;
	int staksize;
};
//初始化
void InitStack(SqStack &s){
	s .base= new ElemType[100];
	s.top = s.base;
	s.staksize = 100;
}
//判断栈是否为空
bool StackEmpty(SqStack& s) {
	if (s.top = s.base)
		return true;
	return false;
}
//入栈
void Push(SqStack& s, ElemType& e) {
	if ((s.top - s.base) == s.staksize)
		cerr<<"error"<<endl;
	*s.top++ = e;
}
//出栈
void Pop(SqStack& s, ElemType& e) {
	if(s.top == s.base)
		cerr << "error" << endl;
	e = *-- s.top;
}

/******************链栈**************/
class StackNode {
public:
	ElemType data;
	StackNode* next;
};
typedef StackNode* LinkStack;

bool InitStack_L(LinkStack& s) {
	s = NULL;
}
//入栈
void Push_L(LinkStack& s, ElemType& e) {
	StackNode* p = new StackNode;
	p->data= e;
	p->next = s;
	s = p;
}
//出栈
void Pop_L(LinkStack& s, ElemType& e) {
	e = s->data;
	StackNode* p = s;
	s = s->next;
	delete p;
}

/******************顺序队列**************/
#define MAXQSIZE 100
class SqQueue {
public:
	ElemType* base;
	int front;
	int rear;
};
//初始化
void InitQueue(SqQueue& q) {
	q.base = new ElemType[MAXQSIZE];
	q.front = q.rear = 0;
}
//求队列长度
int QueueLength(SqQueue& q) {
	return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}
//入队
void InQueue(SqQueue& q, ElemType& e) {
	if ((q.rear + 1) % MAXQSIZE == q.front)
		cerr << "error" << endl;
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % MAXQSIZE;
}
//出队
void OutQueue(SqQueue& q, ElemType& e) {
	if(q.front==q.rear)
		cerr << "error" << endl;
	e = q.base[q.front];
	q.front = (q.front + 1) % MAXQSIZE;
}
/******************链队列**************/
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
//初始化
void InitQueue_L(LinkQueue& q) {
	q.front = q.rear = new QNode;
	q.front->next = NULL;
}
//入队
void InQueue_L(LinkQueue& q, ElemType& e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
}
//出队
void OutQueue_L(LinkQueue& q, ElemType& e) {
	QNode* p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	if (q.rear = p)
		q.rear = q.front;
	delete p; 
}