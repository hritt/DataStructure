/************************************************************************
*
*   Description: generalized list
*
*   Author & Data: JY Liu, 2016/01/20
*
************************************************************************/

enum GListNodeType{ATOM, LIST};

template<calss T>
struct GListNode{
	GListNodeType type;
	union{
		T data;
		GListNode<T> * sublist;
	};
	GListNode<T> * next;
};

template<calss T>
class GList{
	GListNode<T> * head;
public:
	GList();
	~GList();
	//... maybe i will write it future
};
