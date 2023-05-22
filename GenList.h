/************************************************************************
*
*   Description: generalized list
*
*   Author & Data: JY Liu, 2016/01/20
*
************************************************************************/
#ifndef GENLIST_H
#define GENLIST_H

enum GListNodeType { ATOM, LIST };

template <class T>
struct GListNode
{
	GListNodeType type;

	union
	{
		T data;
		GListNode<T>* sublist;
	};

	GListNode<T>* next;
};

template <class T>
class GList
{
	GListNode<T>* head;

public:
	GList() = default;
	~GList() = default;
	//... maybe i will write it future
};

#endif // GENLIST_H
