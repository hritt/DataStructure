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
//#include <string>
//#include <string.h>
//#include <vector>

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
int KMPMatching(char * s,char * t);

/** array **/
//see Array.h


/** generalized list **/
//see GenList.h

/** tree **/
//see Tree.h

/** graph **/
//see Graph.h

/** search **/
//see Search.cpp

/** sorting **/
//see Sort.cpp

#endif
