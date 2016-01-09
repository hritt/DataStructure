/************************************************************************
*
*   Description: sequence list
*
*   Author & Data: JY Liu, 2015/12/24
*
************************************************************************/

#include <iostream> //if you want compile it by clang, these two lines are needed.
using namespace std;

template<class T,int MaxSize>
class SeqList
{
	T data[MaxSize];
	int length;
public:
	SeqList();
	SeqList(T a[],int n);
	int ListLength();
	T Get(int pos);
	int Locate(T item);
	void PrintSeqList();
	void Insert(int i,T item);
	T Delete(int i);
	//overload "="?
};

template<class T,int MaxSize>
SeqList<T,MaxSize>::SeqList()
{
	length=0;
}

template<class T,int MaxSize>
SeqList<T,MaxSize>::SeqList(T a[],int n)
{
	if(n>MaxSize){
		cerr<<"err:the parameter isn't ok!"<<endl;
		exit(1);
	}
	for(int i=0;i<n;i++)
		data[i]=a[i];
	length=n;
}

template<class T,int MaxSize>
int SeqList<T,MaxSize>::ListLength()
{
	return length;
}

template<class T,int MaxSize>
T SeqList<T,MaxSize>::Get(int pos)
{
	if(pos<1 || pos>length){
		cerr<<"err:pos isn't ok!"<<endl;
		exit(1);
	}
	return data[pos-1];
}


template<class T,int MaxSize>
int SeqList<T,MaxSize>::Locate(T item)
{
	for(int i=0;i<length;i++){
		if(data[i]==item)
			return i+1;
	}
	return 0;
}

template<class T,int MaxSize>
void SeqList<T,MaxSize>::PrintSeqList()
{
	for(int i=0;i<length;i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
}

template<class T,int MaxSize>
void SeqList<T,MaxSize>::Insert(int i,T item)
{
	if(length>=MaxSize || i<1 || i>length+1){
		cerr<<"err:cann't insert!"<<endl;
		exit(1);
	}
	for(int t=length;t>=i;t--)
		data[t]=data[t-1];
	data[i-1]=item;
	length++;
}

template<class T,int MaxSize>
T SeqList<T,MaxSize>::Delete(int i)
{
	if(length<1 || i<1 || i>length){
		cerr<<"err:cann't delete!"<<endl;
		exit(1);
	}
	T tmp=data[i-1];
	for(int t=i-1;t<length-1;t++)
		data[t]=data[t+1];
	length--;
	return tmp;
}
