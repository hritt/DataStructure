/************************************************************************
*
*   Description: tree, use 'left-child, right-sibling representation'
*
*   Author & Data: JY Liu, 2016/02/21
*
************************************************************************/
#ifndef TREE_H
#define TREE_H

template <class T>
struct CSNode
{
	T data;
	CSNode<T>* child;
	CSNode<T>* sibling;
};

template <class T>
class CSTree
{
	CSNode<T>* root;

public:
	CSTree() = default;
	~CSTree() = default;
};

//to be continue

#endif // TREE_H
