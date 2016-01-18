/************************************************************************
*
*   Description: array
*
*   Author & Data: JY Liu, 2016/01/08
*
************************************************************************/

template<class T>
struct Triple{
	int r,c;
	T elem;
};

template<class T>
class SparseMatrix{
	vector<Triple<T>> triList;
	int rows,clos,num;
public:
	SparseMatrix();
	SparseMatrix(Triple<T> *tlist, int rs, int cs, int n);
	void Trans(SparseMatrix & B);
};

template<class T>
SparseMatrix<T>::SparseMatrix()
{
	rows=0;
	clos=0;
	num=0;
}

template<class T>
SparseMatrix<T>::SparseMatrix(Triple<T> *tlist, int rs, int cs, int n)
{
}

template<class T>
void SparseMatrix<T>::Trans(SparseMatrix & B)
{
}