/************************************************************************
*
*   Description: main function
*
*   Author & Data: JY Liu, 2015/12/17
*
************************************************************************/

#include "Main.h"
#include "SeqList.h"
#include "LinkList.h"
#include "SeqStack.h"
#include "LinkStack.h"
#include "SeqQueue.h"
#include "LinkQueue.h"
#include "Array.h"
#include "GenList.h"
#include "Tree.h"
#include "BiTree.h"
#include "ThrBiTree.h"
#include "HuffmanTree.h"
#include "Graph.h"

/** linear list **/
//sequence list
void TestSeqList()
{
	int a[3]={1,2,3};
	SeqList<int ,6> seqlist(a,3);
	seqlist.PrintSeqList();
	seqlist.Insert(4,4);
	seqlist.PrintSeqList();
	seqlist.Delete(2);
	seqlist.PrintSeqList();
	cout<<seqlist.Get(2)<<endl;
	cout<<seqlist.ListLength()<<endl;
	cout<<seqlist.Locate(1)<<endl;
}

//linked list
void TestLinkList()
{
	int a[3]={1,2,3};
	LinkList<int> linklist(a,3);
	linklist.PrintLinkList();
	cout<<linklist.Delete(2)<<endl;
	linklist.PrintLinkList();
	linklist.Insert(2, 2);
	linklist.PrintLinkList();
	cout<<linklist.Get(3)<<endl;
	cout<<linklist.ListLength()<<endl;
	cout<<linklist.Locate(3)<<endl;
	cout<<linklist.Locate(4)<<endl;
	cout<<linklist.Get(4)<<endl;
	linklist.~LinkList();
	linklist.Invert();
	linklist.PrintLinkList();
}

/** stack **/
//sequence stack
void TestSeqStack()
{
	SeqStack<int,5> seqstack;
	seqstack.Push(1);
	seqstack.Push(2);
	seqstack.Push(3);
	cout<<seqstack.Pop()<<endl;
	cout<<seqstack.Empty()<<endl;
	cout<<seqstack.Top()<<endl;
}

//linked stack
void TestLinkStack()
{
	LinkStack<int> linkstack;
	linkstack.Push(1);
	linkstack.Push(2);
	linkstack.Push(3);
	cout<<linkstack.Pop()<<endl;
	cout<<linkstack.Top()<<endl;
	cout<<linkstack.Empty()<<endl;
}

/** queue **/
//Sequence queue
void TestSeqQueue()
{
	SeqQueue<int,5>  seqqueue;
	seqqueue.EnQueue(1);
	seqqueue.EnQueue(2);
	seqqueue.EnQueue(3);
	cout<<seqqueue.DeQueue()<<endl;
	cout<<seqqueue.Empty()<<endl;
}

//Linked Queue
void TestLinkQueue()
{
	LinkQueue<int> linkqueue;
	linkqueue.EnQueue(1);
	cout<<linkqueue.DeQueue()<<endl;
	cout<<linkqueue.Empty()<<endl;
	cout<<linkqueue.DeQueue()<<endl;
}

/** string **/
void TestString(int way=1)
{
	char s[20]={18,'a','a','b','c','b','a','b','c','a','a','b','c','a','a','b','a','b','c'};
	char t[20]={9,'a','b','c','a','a','b','a','b','c'};
	//char t[20]={5,'a','a','a','a','b'};
	if(way==1){
		cout<<"--BF--"<<endl;
		cout<<BFMatching(s,t)<<endl;
	}else if(way==2){
		cout<<"--KMP--"<<endl;
		int * next=new int[t[0]+1];
		GetNext(t,next);
		cout<<KMPMatching(s,t,next)<<endl;
		delete [] next;
	}else{
		cout<<"--Extended KMP--"<<endl;
		int * nextval=new int[t[0]+1];
		GetNextVal(t,nextval);
		for(int i=1;i<t[0]+1;i++)
			cout<<nextval[i]<<" ";
		cout<<endl;
		cout<<KMPMatching(s,t,nextval)<<endl;
		delete [] nextval;
	}
}

/** array **/
void TestArray()
{
	Triple<int> t[5]={
		{0,0,1},
		{1,1,2},
		{2,1,3},
		{2,2,4},
		{3,4,5}
	};
	SparseMatrix<int> sm(t,4,5,5);
	sm.Print();
	SparseMatrix<int> b;
	sm.Trans(b);
	b.Print();
	SparseMatrix<int> b2;
	sm.QuickTrans(b2);
	b2.Print();
}

/** generalized list **/


/** tree **/


/** graph **/


/** search **/


/** sorting **/

int main()
{
	//TestSeqList();
	//TestLinkList();
	//TestSeqStack();
	//TestLinkStack();
	//TestSeqQueue();
	//TestLinkQueue();
	//TestString(3);
	//TestArray();

	return 0;
}

