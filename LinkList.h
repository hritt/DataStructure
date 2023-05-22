/************************************************************************
*
*   Description: linked list (have head node)
*
*   Author & Data: JY Liu, 2015/12/24
*
************************************************************************/
#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* next;
};

template <class T>
class LinkList
{
	Node<T>* head;

public:
	LinkList();
	LinkList(T a[], int n);
	~LinkList();
	int ListLength();
	T Get(int pos);
	int Locate(T item);
	void PrintLinkList();
	void Insert(int i, T item);
	T Delete(int i);

	void Invert();
};

template <class T>
LinkList<T>::LinkList()
{
	head = NULL;
}

template <class T>
LinkList<T>::LinkList(T a[], int n)
{
	head = new Node<T>;
	Node<T>* rear = head;
	for (int i = 0; i < n; i++)
	{
		Node<T>* tmp = new Node<T>;
		rear->next = tmp;
		tmp->data = a[i];
		rear = tmp;
	}
	rear->next = NULL;
}

template <class T>
LinkList<T>::~LinkList()
{
	while (head != NULL)
	{
		Node<T>* r = head->next;
		delete head;
		head = r;
	}
}

template <class T>
int LinkList<T>::ListLength()
{
	int len = 0;
	Node<T>* r = head;
	while ((r = r->next) != NULL)
		len++;
	return len;
}

template <class T>
T LinkList<T>::Get(int pos)
{
	if (pos < 1 || pos > ListLength())
	{
		cerr << "pos isn't ok!" << endl;
		exit(1);
	}
	Node<T>* r = head;
	while (r != NULL && pos-- > 0)
		r = r->next;
	return r->data;
}

template <class T>
int LinkList<T>::Locate(T item)
{
	int len = 1;
	Node<T>* r = head->next;
	while (r != NULL && r->data != item)
	{
		len++;
		r = r->next;
	}
	if (r == NULL)
		return 0; //if len equals to 0, it means item is no in list
	else
		return len;
}

template <class T>
void LinkList<T>::PrintLinkList()
{
	Node<T>* r = head->next;
	while (r != NULL)
	{
		cout << r->data << " ";
		r = r->next;
	}
	cout << endl;
}

template <class T>
void LinkList<T>::Insert(int i, T item)
{
	if (i > ListLength() + 1)
	{
		cerr << "insert pos isn't ok!" << endl;
		exit(1);
	}
	Node<T>* r = head;
	while (--i != 0)
		r = r->next;
	Node<T>* tmp = new Node<T>;
	tmp->data = item;
	tmp->next = r->next;
	r->next = tmp;
}

template <class T>
T LinkList<T>::Delete(int i)
{
	if (i < 1 || i > ListLength())
	{
		cerr << "delete pos isn't ok!" << endl;
		exit(1);
	}
	T tmp;
	Node<T>* r = head;
	Node<T>* r2;
	while (i-- != 1)
		r = r->next;
	r2 = r->next;
	r->next = r2->next;
	tmp = r2->data;
	delete r2;
	return tmp;
}

template <class T>
void LinkList<T>::Invert()
{
	//adopt "inserting"
	Node<T>* p = head->next;
	head->next = NULL;
	while (p != NULL)
	{
		Node<T>* q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;
	}
}

#endif // LINKLIST_H
