/************************************************************************
*
*   Description: threaded binary tree
*
*   Author & Data: JY Liu, 2016/02/21
*
************************************************************************/

#include <iostream>
using namespace std;

enum BiThrNodeType{LINK,THREAD};

template<class T>
struct BiThrNode{
	BiThrNodeType ltype;
	BiThrNodeType rtype;
	T data;
	BiThrNode<T> * lchild;
	BiThrNode<T> * rchild;
};

template<class T>
class BiThrTree{
	BiThrNode<T> * root;
public:
	BiThrTree(){ root=NULL; }
};

//to be continue