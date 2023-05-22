/************************************************************************
*
*   Description: array
*
*   Author & Data: JY Liu, 2016/01/08
*
************************************************************************/
#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct Triple
{
	int r, c;
	T elem;
};

template <class T>
class SparseMatrix
{
	//row first
	vector<Triple<T>> triList;
	int rows, cols, num;

public:
	SparseMatrix();
	SparseMatrix(Triple<T>* tlist, int rs, int cs, int n);
	void Trans(SparseMatrix& B);
	void QuickTrans(SparseMatrix& B);
	void Print();
};

template <class T>
SparseMatrix<T>::SparseMatrix()
{
	rows = 0;
	cols = 0;
	num = 0;
}

template <class T>
SparseMatrix<T>::SparseMatrix(Triple<T>* tlist, int rs, int cs, int n)
{
	rows = rs;
	cols = cs;
	num = n;
	triList.resize(n);
	for (int i = 0; i < n; i++)
	{
		triList[i].r = tlist[i].r;
		triList[i].c = tlist[i].c;
		triList[i].elem = tlist[i].elem;
	}
}

template <class T>
void SparseMatrix<T>::Trans(SparseMatrix& B)
{
	B.rows = cols;
	B.cols = rows;
	B.num = num;
	B.triList.resize(num);
	int q = 0;
	for (int j = 0; j < cols; j++)
	{
		for (int k = 0; k < num; k++)
		{
			if (triList[k].c == j)
			{
				B.triList[q].r = triList[k].c;
				B.triList[q].c = triList[k].r;
				B.triList[q].elem = triList[k].elem;
				q++;
			}
		}
	}
}

template <class T>
void SparseMatrix<T>::QuickTrans(SparseMatrix& B)
{
	B.rows = cols;
	B.cols = rows;
	B.num = num;
	B.triList.resize(num);

	int i;
	int* cnum = new int [cols];
	for (i = 0; i < cols; i++)
		cnum[i] = 0;
	int* cpot = new int [cols];
	for (i = 0; i < num; i++)
		cnum[triList[i].c]++;
	cpot[0] = 0;
	for (i = 1; i < cols; i++)
		cpot[i] = cpot[i - 1] + cnum[i - 1];

	for (i = 0; i < num; i++)
	{
		int w = cpot[triList[i].c];
		B.triList[w].r = triList[i].c;
		B.triList[w].c = triList[i].r;
		B.triList[w].elem = triList[i].elem;
		cpot[triList[i].c]++;
	}
}

template <class T>
void SparseMatrix<T>::Print()
{
	//output triList
	int i, j, k;
	for (k = 0; k < num; k++)
		cout << "(" << triList[k].r << " " << triList[k].c << " " << triList[k].elem << ")" << endl;

	//output like matrix
	T** matrix = new T*[rows];
	for (i = 0; i < rows; i++)
	{
		matrix[i] = new T[cols];
		memset(matrix[i], 0, cols * sizeof(T));
	}

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			matrix[i][j] = T(0);
	for (i = 0; i < num; i++)
		matrix[triList[i].r][triList[i].c] = triList[i].elem;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

#endif
