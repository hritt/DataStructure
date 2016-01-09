/************************************************************************
*
*   Description: sequence queue
*
*   Author & Data: JY Liu, 2016/01/06
*
************************************************************************/

#include <iostream>
using namespace std;

template<class T,int MaxSize>
class SeqQueue{
	T data[MaxSize];
	int front,rear;
public:
	SeqQueue();
	void EnQueue(T item);
	T DeQueue();
	bool Empty();
};

template<class T,int MaxSize>
SeqQueue<T,MaxSize>::SeqQueue()
{
	front=0;
	rear=0;
}

template<class T,int MaxSize>
void SeqQueue<T,MaxSize>::EnQueue(T item)
{
	if( (rear+1)%MaxSize== front ){
		cerr<<"queue is full!"<<endl;
		exit(1);
	}
	rear=(rear+1)%MaxSize;
	data[rear]=item;
}

template<class T,int MaxSize>
T SeqQueue<T,MaxSize>::DeQueue()
{
	if( (front+1)%MaxSize==rear ){
		cerr<<"queue is empty!"<<endl;
		exit(1);
	}
	front=(front+1)%MaxSize;
	return data[front];
}

template<class T,int MaxSize>
bool SeqQueue<T,MaxSize>::Empty()
{
	return front==rear;
}
