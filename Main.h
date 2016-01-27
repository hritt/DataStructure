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
int BFMatching(char * s,char * t);
void GetNext(char t[],int next[]);
void GetNextVal(char t[],int nextval[]);
int KMPMatching(char s[],char t[],int next[]);

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

/** sorting **/
//see Sort.cpp

#endif
