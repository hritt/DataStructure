/************************************************************************
*
*   Description: threaded binary tree
*
*   Author & Data: JY Liu, 2016/01/27
*
************************************************************************/

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