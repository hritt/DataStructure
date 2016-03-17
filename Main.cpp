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
#include "AMGraph.h"

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
//sequence queue
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
//... maybe i will write it future

/** tree **/
//binary tree
void TestBiTree()
{
	char s[]="abd**e**cf***";
	/**
	*          a
	*       ¨L   ¨K
	*       b      c
	*     ¨L ¨K  ¨L
	*     d   e  f
	**/
	vector<char> pre;
	pre.assign(s,s+13);
	BiTree<char> bitree(pre);
	bitree.PreOrder();
	bitree.InOrder();
	bitree.PostOrder();
	bitree.LevelOrder();
	cout<<bitree.Count()<<endl;
	cout<<bitree.Height()<<endl;
	BiNode<char> * p=bitree.Search('d');
	if(p)
		cout<<p->data<<endl;
	else
		cout<<"not exist."<<endl;
	BiNode<char> * pp=bitree.SearchParent(p);
	if(pp)
		cout<<pp->data<<endl;
	else
		cout<<"parent not exist."<<endl;

	char sp[]="ABHFDECKG";
	char si[]="HBDFAEKCG";
	vector<char> vp, vi;
	vp.assign(sp,sp+9);
	vi.assign(si,si+9);
	BiTree<char> bitree2(vp,vi);
	bitree2.LevelOrder();
	cout<<bitree2.Height()<<endl;

	BiTree<char> bitree3(bitree);
	bitree3.LevelOrder();

	BiTree<char> bitree4;
	bitree4.LevelOrder();
	cout<<bitree4.Count()<<endl;
	cout<<bitree4.Height()<<endl;
}

//threaded binary tree
void TestBiThrTree()
{
}

//tree
void TestTree()
{
}

//huffman tree
void TestHuffmanTree()
{
}

/** graph **/
//adjacent matrix graph
void TestAMGraph()
{
	int vexnum=5;
	int edgenum=7;
	int vexs[5]={0,1,2,3,4};
	AMGraph<int> amgraph(DINETWORK,vexs,vexnum,edgenum);
	//0 3 6  1 0 2  1 2 7  2 3 2  3 1 9  3 4 5  4 0 3
	amgraph.PrintMatrix();

	int vexnum2=7;
	int edgenum2=10;
	char vexs2[7]={'A','B','C','D','E','F','G'};
	AMGraph<char> amgraph2(UNDIGRAPH,vexs2,vexnum2,edgenum2);
	//0 2  0 4  1 2  1 5  1 6  2 3  2 5  3 5  4 5  5 6
	amgraph2.PrintMatrix();
	cout<<"deep first search:"<<endl;
	amgraph2.DFSTraverse();
	cout<<"breadth first search:"<<endl;
	amgraph2.BFSTraverse();

	int vexnum3=6;
	int edgenum3=10;
	string vexs3[7]={"v1","v2","v3","v4","v5","v6"};
	AMGraph<string> amgraph3(UNDINETWORK,vexs3,vexnum3,edgenum3);
	//0 1 2  0 2 5  0 3 4  1 2 4  1 4 5  2 3 6  2 4 3  2 5 4  3 5 7  4 5 1
	amgraph3.PrintMatrix();
	cout<<"-Prim-"<<endl;
	amgraph3.Prim(0);
	cout<<endl<<"-Kruskal-"<<endl;
	amgraph3.Kruskal();
	cout<<endl;

	int vexnum4=5;
	int edgenum4=7;
	string vexs4[7]={"v0","v1","v2","v3","v4"};
	AMGraph<string> amgraph4(DINETWORK,vexs4,vexnum4,edgenum4);
	//0 1 10  0 3 30  0 4 100  1 2 50  2 4 10  3 2 20  3 4 60
	amgraph4.PrintMatrix();
	cout<<"-Dijkstra-"<<endl;
	amgraph4.Dijkstra();
	cout<<"-Floyd-"<<endl;
	amgraph4.Floyd();
}

/** search **/
void TestSearch()
{
	int data[6]={45,34,26,75,38};
	cout<<SeqSearch(data,5,75)<<endl;
	cout<<SeqSearch2(data,5,38)<<endl;
	int data2[13]={5,13,19,21,23,29,32,35,37,42,46,49,56};
	cout<<BiSearch(data2,13,21)<<endl;
	cout<<BiSearch2(data2,0,12,19)<<endl;

	int a[11]={63,45,90,24,58,74,99,16,35,64,85};
	BiSortTree bisorttree(a,11);
	BiSortNode * r=bisorttree.Search(24);
	if(r!=NULL)
		cout<<r->key<<endl;
	else
		cout<<"not exist."<<endl;
	r=bisorttree.Search2(24);
	if(r!=NULL)
		cout<<r->key<<endl;
	else
		cout<<"not exist."<<endl;
	bisorttree.Output();
	bisorttree.Delete(45);
	bisorttree.Output();
}

/** sort **/
void TestSort()
{
	//int a[7]={51,38,49,27,62,5,16};
	int a[7]={60,20,10,50,15,30,55};
	//BubbleSort(a,7);
	//BubbleSort2(a,7);
	//BubbleSort3(a,7);
	//SelectSort(a,7);
	//InsertSort(a,7);
	//BiInsertSort(a,7);
	//ShellSort(a,7);
	//QuickSort(a,0,6);
	//MergeSort(a,7);
	MergeSort2(a,7);
	Output(a,0,6);
	
	//heap sort array store from [1]
	/*int b[9]={0,36,30,18,40,32,45,22,50};
	HeapSort(b,8);
	Output(b,1,8);*/
}

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
	//TestBiTree();
	//TestAMGraph();
	//TestSearch();
	TestSort();

	return 0;
}

