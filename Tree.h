/************************************************************************
*
*   Description: tree, use 'left-child, right-sibling representation'
*
*   Author & Data: JY Liu, 2016/02/21
*
************************************************************************/

template<class T>
struct CSNode{
	T data;
	CSNode<T> * child;
	CSNode<T> * sibling;
};

template<class T>
class CSTree{
	CSNode<T> * root;
public:
	CSTree();
	~CSTree();
};

//to be continue