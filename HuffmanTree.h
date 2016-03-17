/************************************************************************
*
*   Description: huffman tree
*
*   Author & Data: JY Liu, 2016/02/21
*
************************************************************************/

#include <iostream>
using namespace std;
#include <vector>

class HuffmanNode{
	char data;
	double weight;
	int parent,lchild,rchild;
};

class HuffmanTree{
	vector<HuffmanNode> hufftree;
public:
	HuffmanTree(vector<HuffmanNode> & leaves);
	~HuffmanTree();
};

//to be continue