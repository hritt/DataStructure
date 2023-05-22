/************************************************************************
*
*   Description: what algorithms I write
*
*   Author & Data: JY Liu, 2015/12/17
*
************************************************************************/

#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
using namespace std;
#include <vector>
//#include <string>
//#include <string.h>

/** linear list **/
//sequence list，see SeqList.h ;because use class template, declaration and implement puted in one file
//linked list，see LinkList.h

/** stack **/
//sequence stack, see SeqStack.h
//linked stack, see LinkStack.h

/** queue **/
//sequence queue, see SeqQueue.h
//linked queue, see LinkQueue.h

/** string **/
//see String.cpp
int BFMatching(char* s, char* t);
void GetNext(char t[], int next[]);
void GetNextVal(char t[], int nextval[]);
int KMPMatching(char s[], char t[], int next[]);

/** array **/
//see Array.h

/** generalized list **/
//see GenList.h

/** tree **/
//binary tree, see BiTree.cpp
//threaded binary tree, see ThrBiTree.cpp
//tree, see Tree.cpp
//huffman tree, see HuffmanTree.h & HuffmanTree.cpp

/** graph **/
//see Graph.h

/** search **/
//see Search.cpp
int SeqSearch(int data[], int n, int k);
int SeqSearch2(int data[], int n, int k);
int BiSearch(int data[], int n, int k);
int BiSearch2(int data[], int low, int high, int k);

//binary sort tree
struct BiSortNode
{
    int key;
    BiSortNode *lchild, *rchild;
};

class BiSortTree
{
    BiSortNode* root;

    void Insert(BiSortNode* & ptr, int k); //must have &
    BiSortNode* Search(BiSortNode* ptr, int k);
    void Delete(BiSortNode* & ptr, int k); //must have &

    void Free(BiSortNode* ptr);

public:
    BiSortTree(int a[], int n);
    ~BiSortTree();
    BiSortNode* Search(int k); //recursion
    BiSortNode* Search2(int k); //not recursion
    void Delete(int k);

    void Output();
};

/** sorting **/
//see Sort.cpp
void Output(int a[], int start, int end);
void BubbleSort(int a[], int n);
void BubbleSort2(int a[], int n); //improve bubble sorting
void BubbleSort3(int a[], int n); //improve again bubble sorting
void SelectSort(int a[], int n);
void InsertSort(int a[], int n);
void BiInsertSort(int a[], int n);
void ShellSort(int a[], int n);
void QuickSort(int a[], int l, int h);
void HeapSort(int a[], int n);
void MergeSort(int a[], int n); //not recursion
void MergeSort2(int a[], int n); //recursion

#endif // MAIN_H_
