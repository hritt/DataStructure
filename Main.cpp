/************************************************************************
*
*   Description: main function
*
*   Author & Data: JY Liu, 2015/12/17
*
************************************************************************/

#include "main.h"
#include "SeqList.h"
#include "LinkList.h"
#include "SeqStack.h"
#include "SeqQueue.h"
#include "LinkStack.h"
#include "LinkQueue.h"
//#include "String.cpp"
//#include "Array.cpp"

int main()
{
	/** linear list **/
	//sequence list
	/* int a[3]={1,2,3};
	 SeqList<int ,6> seqlist(a,3);
	 seqlist.PrintSeqList();
	 seqlist.Insert(4,4);
	 seqlist.PrintSeqList();
	 seqlist.Delete(2);
	 seqlist.PrintSeqList();
	 cout<<seqlist.Get(2)<<endl;
	 cout<<seqlist.ListLength()<<endl;
	 cout<<seqlist.Locate(1)<<endl;*/

	//linked list
	/*int a[3]={1,2,3};
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
	linklist.PrintLinkList();*/

	/** stack **/
	//sequence stack
	/*SeqStack<int,5> seqstack;
	seqstack.Push(1);
	seqstack.Push(2);
	seqstack.Push(3);
	cout<<seqstack.Pop()<<endl;
	cout<<seqstack.Empty()<<endl;
	cout<<seqstack.Top()<<endl;*/

	//linked stack
	/*LinkStack<int> linkstack;
	linkstack.Push(1);
	linkstack.Push(2);
	linkstack.Push(3);
	cout<<linkstack.Pop()<<endl;
	cout<<linkstack.Top()<<endl;
	cout<<linkstack.Empty()<<endl;*/

	/** queue **/
	//Sequence queue
	/*SeqQueue<int,5>  seqqueue;
	seqqueue.EnQueue(1);
	seqqueue.EnQueue(2);
	seqqueue.EnQueue(3);
	cout<<seqqueue.DeQueue()<<endl;
	cout<<seqqueue.Empty()<<endl;*/

	//Linked Queue
	/*LinkQueue<int> linkqueue;
	linkqueue.EnQueue(1);
	cout<<linkqueue.DeQueue()<<endl;
	cout<<linkqueue.Empty()<<endl;
	cout<<linkqueue.DeQueue()<<endl;*/

	/** string **/
	char s[20]={18,'a','a','b','c','b','a','b','c','a','a','b','c','a','a','b','a','b','c'};
	char t[20]={9,'a','b','c','a','a','b','a','b','c'};
	cout<<BFMatching(s,t)<<endl;

	/** array **/


	/** generalized list **/


	/** tree **/


	/** graph **/


	/** search **/


	/** sorting **/


	return 0;
}

