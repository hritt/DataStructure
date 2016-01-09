/************************************************************************
*
*   Description: linked queue
*
*   Author & Data: JY Liu, 2016/01/06
*
************************************************************************/

#include <iostream>
using namespace std;

template<class T>
struct NodeQueue{
	T data;
	NodeQueue<T> * next;
 };

template<class T>
class LinkQueue{
	Node<T> * front,* rear;
public:
	LinkQueue();
	~LinkQueue();
	void EnQueue(T item);
	T DeQueue();
	bool Empty();
};

template<class T>
LinkQueue<T>::LinkQueue()
{
	Node<T> * p=new Node<T>;
	p->next=NULL;
	front=rear=p;
}

template<class T>
LinkQueue<T>::~LinkQueue()
{
	while(rear!=front){
		Node<T> * p=front;
		front=front->next;
		delete p;
	}
	delete front;
}

template<class T>
void LinkQueue<T>::EnQueue(T item)
{
	Node<T> * p=new Node<T>;
	p->data=item;
	p->next=NULL;
	rear->next=p;
	rear=p;
}

template<class T>
T LinkQueue<T>::DeQueue()
{
	if(front==rear){
		cerr<<"queue is empty!"<<endl;
		exit(1);
	}
	Node<T> * p=front->next;
	T t=p->data;
	front->next=p->next;
	if(p==rear)
		rear=front;
	delete p;
	return t;
}

template<class T>
bool LinkQueue<T>::Empty()
{
	return front==rear;
}
