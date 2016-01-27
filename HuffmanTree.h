/************************************************************************
*
*   Description: huffman tree
*
*   Author & Data: JY Liu, 2016/01/27
*
************************************************************************/

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