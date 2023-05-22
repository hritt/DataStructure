/************************************************************************
*
*   Description: linked stack
*
*   Author & Data: JY Liu, 2016/01/06
*
************************************************************************/
#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <iostream>
using namespace std;

template <class T>
struct NodeStack
{
	T data;
	NodeStack<T>* next;
};

template <class T>
class LinkStack
{
	NodeStack<T>* top;

public:
	LinkStack();
	~LinkStack();
	void Push(T item);
	T Pop();
	bool Empty();
	T Top();
};

template <class T>
LinkStack<T>::LinkStack()
{
	top = NULL;
}

template <class T>
LinkStack<T>::~LinkStack()
{
	while (top != NULL)
	{
		NodeStack<T>* p = top;
		top = top->next;
		delete p;
	}
}

template <class T>
void LinkStack<T>::Push(T item)
{
	NodeStack<T>* tmp = new NodeStack<T>; //cann't use NodeStack<T> tmp, otherwise will be release
	tmp->data = item;
	tmp->next = top;
	top = tmp;
}

template <class T>
T LinkStack<T>::Pop()
{
	if (top == NULL)
	{
		cerr << "stack is empty!" << endl;
		exit(1);
	}
	NodeStack<T>* p = top;
	top = top->next;
	T d = p->data;
	delete p;
	return d;
}

template <class T>
bool LinkStack<T>::Empty()
{
	return top == NULL;
}

template <class T>
T LinkStack<T>::Top()
{
	if (top == NULL)
	{
		cerr << "stack is empty!" << endl;
		exit(1);
	}
	return top->data;
}

#endif // LINKSTACK_H
