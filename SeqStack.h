/************************************************************************
*
*   Description: sequence stack
*
*   Author & Data: JY Liu, 2016/01/06
*
************************************************************************/

#include <iostream>
using namespace std;

template<class T, int MaxSize>
class SeqStack{
	T data[MaxSize];
	int top; //array subscript
public:
	SeqStack();
	void Push(T item);
	T Pop();
	T Top();
	bool Empty(); //judge empty or not
};

template<class T, int MaxSize>
SeqStack<T,MaxSize>::SeqStack()
{
	top=-1;
}

template<class T, int MaxSize>
void SeqStack<T,MaxSize>::Push(T item)
{
	if(top>=MaxSize-1){
		cerr<<"stack is full!"<<endl;
		exit(1);
	}
	data[++top]=item;
}

template<class T, int MaxSize>
T SeqStack<T,MaxSize>::Pop()
{
	if(top<0){
		cerr<<"stack is empty!"<<endl;
		exit(1);
	}
	return data[top--];
}

template<class T, int MaxSize>
T SeqStack<T,MaxSize>::Top()
{
	if(top<0){
		cerr<<"stack is empty!"<<endl;
		exit(1);
	}
	return data[top];
}

template<class T, int MaxSize>
bool SeqStack<T,MaxSize>::Empty()
{
	return top<0;
}
