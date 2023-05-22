/************************************************************************
*
*   Description: binary tree, we often use linked structure
*
*   Author & Data: JY Liu, 2016/01/18
*
************************************************************************/
#ifndef BITREE_H
#define BITREE_H

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

template <class T>
struct BiNode
{
	T data;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
};

template <class T>
class BiTree
{
	BiNode<T>* root;

	BiNode<T>* CreatByPre(vector<T>& pre, int& i);
	BiNode<T>* CreatByPreMid(vector<T>& pre, vector<T>& mid, int ipre, int imid, int n);
	BiNode<T>* Copy(BiNode<T>* p);
	void Free(BiNode<T>* p);

	void PreOrder(BiNode<T>* p);
	void InOrder(BiNode<T>* p);
	void PostOrder(BiNode<T>* p);

	int Count(BiNode<T>* p);
	int Height(BiNode<T>* p);
	BiNode<T>* Search(T elem, BiNode<T>* p);
	BiNode<T>* SearchParent(BiNode<T>* child, BiNode<T>* p);

public:
	BiTree();
	BiTree(vector<T>& pre);
	BiTree(vector<T>& pre, vector<T>& mid);
	BiTree(BiTree<T>& tree);
	~BiTree();

	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder();

	int Count();
	int Height();
	BiNode<T>* Search(T elem);
	BiNode<T>* SearchParent(BiNode<T>* child);
};

template <class T>
BiTree<T>::BiTree()
{
	root = NULL;
}

template <class T>
BiTree<T>::BiTree(vector<T>& pre)
{
	int i = 0;
	root = CreatByPre(pre, i); //notice, i can't be replaced by 0
}

template <class T>
BiNode<T>* BiTree<T>::CreatByPre(vector<T>& pre, int& i)
{
	T e = pre[i];
	i++;
	if (e == '*')
		return NULL;
	BiNode<T>* p = new BiNode<T>;
	p->data = e;
	p->lchild = CreatByPre(pre, i);
	p->rchild = CreatByPre(pre, i);
	return p;
}

template <class T>
BiTree<T>::BiTree(vector<T>& pre, vector<T>& mid)
{
	root = CreatByPreMid(pre, mid, 0, 0, pre.size());
}

template <class T>
BiNode<T>* BiTree<T>::CreatByPreMid(vector<T>& pre, vector<T>& mid, int ipre, int imid, int n)
{
	if (n == 0)
		return NULL;
	BiNode<T>* p = new BiNode<T>;
	p->data = pre[ipre];
	int i;
	for (i = 0; i < n; i++)
	{
		if (pre[ipre] == mid[imid + i])
			break;
	}
	p->lchild = CreatByPreMid(pre, mid, ipre + 1, imid, i);
	p->rchild = CreatByPreMid(pre, mid, ipre + i + 1, imid + i + 1, n - i - 1);
	return p;
}

template <class T>
BiTree<T>::BiTree(BiTree<T>& tree)
{
	root = Copy(tree.root); //can get private tree.root
}

template <class T>
BiNode<T>* BiTree<T>::Copy(BiNode<T>* p)
{
	if (p == NULL)
		return NULL;
	BiNode<T>* q = new BiNode<T>;
	q->data = p->data;
	q->lchild = Copy(p->lchild);
	q->rchild = Copy(p->rchild);
	return q;
}

template <class T>
BiTree<T>::~BiTree()
{
	Free(root);
}

template <class T>
void BiTree<T>::Free(BiNode<T>* p)
{
	if (p == NULL)
		return;
	Free(p->lchild);
	Free(p->rchild);
	delete p;
}

template <class T>
void BiTree<T>::PreOrder()
{
	PreOrder(root);
	cout << endl;
}

template <class T>
void BiTree<T>::PreOrder(BiNode<T>* p)
{
	if (p == NULL)
		return;
	cout << p->data;
	PreOrder(p->lchild);
	PreOrder(p->rchild);
}

template <class T>
void BiTree<T>::InOrder()
{
	InOrder(root);
	cout << endl;
}

template <class T>
void BiTree<T>::InOrder(BiNode<T>* p)
{
	if (p == NULL)
		return;
	InOrder(p->lchild);
	cout << p->data;
	InOrder(p->rchild);
}

template <class T>
void BiTree<T>::PostOrder()
{
	PostOrder(root);
	cout << endl;
}

template <class T>
void BiTree<T>::PostOrder(BiNode<T>* p)
{
	if (p == NULL)
		return;
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout << p->data;
}

template <class T>
void BiTree<T>::LevelOrder()
{
	if (root == NULL)
		return;
	queue<BiNode<T>*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		BiNode<T>* p = Q.front();
		Q.pop();
		cout << p->data;
		if (p->lchild)
			Q.push(p->lchild);
		if (p->rchild)
			Q.push(p->rchild);
	}
	cout << endl;
}

template <class T>
int BiTree<T>::Count()
{
	return Count(root);
}

template <class T>
int BiTree<T>::Count(BiNode<T>* p)
{
	if (p == NULL)
		return 0;
	else
		return Count(p->lchild) + Count(p->rchild) + 1;
}

template <class T>
int BiTree<T>::Height()
{
	return Height(root);
}

template <class T>
int BiTree<T>::Height(BiNode<T>* p)
{
	if (p == NULL)
		return 0;
	return Height(p->lchild) > Height(p->rchild) ? (Height(p->lchild) + 1) : (Height(p->rchild) + 1);
}

template <class T>
BiNode<T>* BiTree<T>::Search(T elem)
{
	return Search(elem, root);
}

template <class T>
BiNode<T>* BiTree<T>::Search(T elem, BiNode<T>* p)
{
	if (p == NULL)
		return NULL;
	if (p->data == elem)
		return p;
	BiNode<T>* q = Search(elem, p->lchild);
	if (q)
		return q;
	else
		return Search(elem, p->rchild);
}

template <class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* child)
{
	if (child == NULL)
		return NULL;
	return SearchParent(child, root);
}

template <class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* child, BiNode<T>* p)
{
	if (p == NULL)
		return NULL;
	if (p->lchild == child || p->rchild == child)
		return p;
	BiNode<T>* q = SearchParent(child, p->lchild);
	if (q)
		return q;
	else
		return SearchParent(child, p->rchild);
}

#endif // BITREE_H
