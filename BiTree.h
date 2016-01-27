/************************************************************************
*
*   Description: binary tree, we often use linked structure
*
*   Author & Data: JY Liu, 2016/01/18
*
************************************************************************/

template<class T>
struct BiNode{
	T data;
	BiNode<T> * lchild;
	BiNode<T> * rchild;
};

template<class T>
class BiTree{
	BiNode<T> * root;
	
	CreatByPre(vector<T> &pre,int &i);
public:
	BiTree();
	BiTree(vector<T> &pre);
	BiTree(vector<T> &pre,vector<T> &mid);
	BiTree(BiTree<T> &tree);
	~BiTree();
	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder();
	int Count();
	int Height();
	BiNode<T> * Search(T elem);
	BiNode<T> * SearchParent(BiNode<T> * child);
};

template<class T>
BiTree<T>::BiTree()
{
	root=NULL;
}

template<class T>
BiTree<T>::BiTree(vector<T> &pre)
{
	int i=0;
	root=CreatByPre(pre,i); //notice, i can't be replaced by 0
}

template<class T>
BiNode<T> * BiTree<T>::CreatByPre(vector<T> &pre,int &i)
{
}

template<class T>
BiTree<T>::BiTree(vector<T> &pre,vector<T> &mid)
{
}

template<class T>
BiTree<T>::BiTree(BiTree<T> &tree)
{
}

template<class T>
BiTree<T>::~BiTree()
{
}

template<class T>
void BiTree<T>::PreOrder()
{
}

template<class T>
void BiTree<T>::InOrder()
{
}

template<class T>
void BiTree<T>::PostOrder()
{
}

template<class T>
void BiTree<T>::LevelOrder()
{
}

template<class T>
int BiTree<T>::Count()
{
}

template<class T>
int BiTree<T>::Height()
{
}

template<class T>
BiNode<T> * BiTree<T>::Search(T elem)
{
}

template<class T>
BiNode<T> * BiTree<T>::SearchParent(BiNode<T> * child)
{
}