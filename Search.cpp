/************************************************************************
*
*   Description: search
*
*   Author & Data: JY Liu, 2016/02/26
*
************************************************************************/

#include "Main.h"
#include <queue>

//sequence search
int SeqSearch(int data[], int n, int k)
{
	int i = 0;
	while (i < n && data[i] != k)
		i++;
	if (i == n)
		return -1;
	else
		return i;
}

//sequence search with lookout
int SeqSearch2(int data[], int n, int k)
{
	int i = 0;
	data[n] = k;
	while (data[i] != k)
		i++;
	if (i == n)
		return -1;
	else
		return i;
}

//binary search, not recursion
int BiSearch(int data[], int n, int k)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (data[mid] == k)
			return mid;
		else if (data[mid] > k)
			high = mid - 1;
		else if (data[mid] < k)
			low = mid + 1;
	}
	return -1;
}

//binary search, recursion
int BiSearch2(int data[], int low, int high, int k)
{
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (data[mid] == k)
		return mid;
	else if (data[mid] > k)
		return BiSearch2(data, low, mid - 1, k);
	else //if(data[mid]<k)
		return BiSearch2(data, mid + 1, high, k);
}

BiSortTree::BiSortTree(int a[], int n)
{
	root = NULL;
	for (int i = 0; i < n; i++)
		Insert(root, a[i]);
}

void BiSortTree::Free(BiSortNode* ptr)
{
	if (ptr == NULL)
		return;
	Free(ptr->lchild);
	Free(ptr->rchild);
	delete ptr;
}

BiSortTree::~BiSortTree()
{
	Free(root);
}

void BiSortTree::Insert(BiSortNode* & ptr, int k)
{
	if (ptr == NULL)
	{
		ptr = new BiSortNode;
		ptr->key = k;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
	}
	else
	{
		if (k < ptr->key)
			Insert(ptr->lchild, k);
		else if (k == ptr->key)
			return; //do nothing
		else if (k > ptr->key)
			Insert(ptr->rchild, k);
	}
}

BiSortNode* BiSortTree::Search(BiSortNode* ptr, int k)
{
	if (ptr == NULL)
		return NULL;
	if (ptr->key == k)
		return ptr;
	else if (ptr->key > k)
		return Search(ptr->lchild, k);
	else //if(ptr->key < k)
		return Search(ptr->rchild, k);
}

BiSortNode* BiSortTree::Search(int k)
{
	return Search(root, k);
}

BiSortNode* BiSortTree::Search2(int k)
{
	BiSortNode* ptr = root;
	while (ptr != NULL)
	{
		if (ptr->key == k)
			return ptr;
		else if (ptr->key > k)
			ptr = ptr->lchild;
		else if (ptr->key < k)
			ptr = ptr->rchild;
	}
	return NULL;
}

void BiSortTree::Delete(BiSortNode* & ptr, int k)
{
	if (ptr != NULL)
	{
		if (ptr->key > k)
			Delete(ptr->lchild, k);
		else if (ptr->key < k)
			Delete(ptr->rchild, k);
		else
		{
			BiSortNode* tmp;
			if (ptr->lchild == NULL)
			{
				tmp = ptr;
				ptr = ptr->rchild; //ptr int the Delete() need use &, ptr is <it's father node>->child
				delete tmp;
			}
			else if (ptr->rchild == NULL)
			{
				tmp = ptr;
				ptr = ptr->lchild;
				delete tmp;
			}
			else
			{
				tmp = ptr->lchild;
				while (tmp->rchild != NULL)
					tmp = tmp->rchild;
				ptr->key = tmp->key;
				Delete(ptr->lchild, tmp->key);
			}
		}
	}
}

void BiSortTree::Delete(int k)
{
	Delete(root, k);
}

void BiSortTree::Output() //see BiTree.LevelOrder()
{
	if (root == NULL)
		return;
	queue<BiSortNode*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		BiSortNode* p = Q.front();
		Q.pop();
		cout << p->key << " ";
		if (p->lchild)
			Q.push(p->lchild);
		if (p->rchild)
			Q.push(p->rchild);
	}
	cout << endl;
}
