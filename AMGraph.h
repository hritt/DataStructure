/************************************************************************
*
*   Description: Graph - adjacent matrix
*
*   Author & Data: JY Liu, 2016/01/18
*
************************************************************************/
#ifndef AMGRAPH_H_
#define AMGRAPH_H_

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <string>
//#include <limits.h>
#define INFINITY_VALUE 0x7fffffff //_I32_MAX just can used on windows

//undirected graph, directed draph, undirected network, directed network
enum graphType { UNDIGRAPH, DIGRAPH, UNDINETWORK, DINETWORK };

template <class T>
struct Edge
{
	T head, tail;
	int cost;

	Edge(T h, T t, int c)
	{
		head = h;
		tail = t;
		cost = c;
	}
};

template <class T>
class AMGraph
{
	int vexnum, edgenum;
	graphType kind;
	vector<vector<int>> edges; //adjacent matrix
	vector<T> vexs;

	void DFS(int v, bool* visited);

public:
	AMGraph(graphType t, T v[], int n, int e);
	//int vexNum();
	//int edgeNum();
	//T getVexValue(int i);
	//int getEdgeValue(int i,int j);
	//void insertVex(T v);
	//void removeVex(T v);
	//void insertEdge(Edge<T> e);
	//void deleteEdge(Edge<T> e);

	void DFSTraverse(); //deep first search    (UNDIGRAPH)
	void BFSTraverse(); //breadth first search (UNDIGRAPH)

	void Prim(int v); // start from v          (UNDINETWORK)
	void Kruskal();
	void Dijkstra(); //source is the first vertex
	void Floyd();

	void PrintMatrix();
};

template <class T>
AMGraph<T>::AMGraph(graphType t, T v[], int n, int e)
{
	vexnum = n;
	edgenum = e;
	kind = t;

	//vertexs
	vexs.resize(vexnum);
	int i, j;
	for (i = 0; i < vexnum; i++)
		vexs[i] = v[i];

	//edges
	edges.resize(vexnum);
	for (i = 0; i < vexnum; i++)
		edges[i].resize(vexnum);
	for (i = 0; i < vexnum; i++)
		for (j = 0; j < vexnum; j++)
			edges[i][j] = INFINITY_VALUE;

	int va, vb;
	if (kind == UNDIGRAPH || kind == DIGRAPH)
	{
		cout << "Input <head tail>:";
		for (i = 0; i < edgenum; i++)
		{
			cin >> va >> vb;
			edges[va][vb] = 1;
			if (kind == UNDIGRAPH)
				edges[vb][va] = 1;
		}
	}
	else
	{
		int c;
		cout << "Input <head tail cost>:";
		for (i = 0; i < edgenum; i++)
		{
			cin >> va >> vb >> c;
			edges[va][vb] = c;
			if (kind == UNDINETWORK)
				edges[vb][va] = c;
		}
	}
}

template <class T>
void AMGraph<T>::PrintMatrix()
{
	for (int i = 0; i < vexnum; i++)
	{
		for (int j = 0; j < vexnum; j++)
		{
			if (edges[i][j] != INFINITY_VALUE)
				cout << edges[i][j];
			else
				cout << "-";
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template <class T>
void AMGraph<T>::DFS(int v, bool* visited)
{
	cout << vexs[v] << " ";
	visited[v] = true;
	for (int i = 0; i < vexnum; i++)
	{
		if (!visited[i] && edges[v][i] == 1)
			DFS(i, visited);
	}
}

template <class T>
void AMGraph<T>::DFSTraverse()
{
	bool* visited = new bool[vexnum];
	int i;
	for (i = 0; i < vexnum; i++)
		visited[i] = false;
	for (i = 0; i < vexnum; i++)
	{
		if (!visited[i])
		{
			DFS(i, visited);
		}
	}
	delete []visited;
	cout << endl;
}

template <class T>
void AMGraph<T>::BFSTraverse()
{
	bool* visited = new bool[vexnum];
	int i, j;
	for (i = 0; i < vexnum; i++)
		visited[i] = false;
	queue<int> q;
	for (i = 0; i < vexnum; i++)
	{
		if (!visited[i])
		{
			q.push(i);
			visited[i] = true;
			cout << vexs[i] << " ";
			while (!q.empty())
			{
				int tmp = q.front();
				q.pop();
				for (j = 0; j < vexnum; j++)
				{
					if (!visited[j] && edges[tmp][j] == 1)
					{
						q.push(j);
						visited[j] = true;
						cout << vexs[j] << " ";
					}
				}
			}
		}
	}
	delete []visited;
	cout << endl;
}

template <class T>
struct EdgeNode
{
	T adjvex;
	int lowcost;
};

template <class T>
void AMGraph<T>::Prim(int v)
{
	EdgeNode<T>* miniedges = new EdgeNode<T>[vexnum];
	int i, j;
	for (i = 0; i < vexnum; i++)
	{
		miniedges[i].adjvex = vexs[v];
		miniedges[i].lowcost = edges[v][i];
	}
	miniedges[v].lowcost = 0;

	for (i = 1; i < vexnum; i++)
	{
		//time:vexnum-1
		//find the minimun edge
		int miniIdx = -1;
		int mini = INFINITY_VALUE;
		for (j = 1; j < vexnum; j++)
			if (miniedges[j].lowcost != 0 && mini > miniedges[j].lowcost)
			{
				miniIdx = j;
				mini = miniedges[j].lowcost;
			}
		cout << miniedges[miniIdx].adjvex << " -> " << vexs[miniIdx] << endl;
		miniedges[miniIdx].lowcost = 0;

		//update miniedges
		for (j = 0; j < vexnum; j++)
		{
			if (edges[miniIdx][j] < miniedges[j].lowcost)
			{
				miniedges[j].adjvex = vexs[miniIdx];
				miniedges[j].lowcost = edges[miniIdx][j];
			}
		}
	}

	delete []miniedges;
}

struct Edge2
{
	int head, tail;
	int cost;
};

template <class T>
void AMGraph<T>::Kruskal()
{
	Edge2* edge2 = new Edge2[edgenum];
	int i, j, k;
	k = 0;
	for (i = 0; i < vexnum; i++)
	{
		for (j = i; j < vexnum; j++)
		{
			//upper triangle
			if (edges[i][j] != INFINITY_VALUE)
			{
				edge2[k].head = i;
				edge2[k].tail = j;
				edge2[k].cost = edges[i][j];
				k++;
			}
		}
	}

	//sort
	for (i = 0; i < edgenum - 1; i++)
	{
		for (j = i + 1; j < edgenum; j++)
		{
			if (edge2[i].cost > edge2[j].cost)
			{
				//swap
				Edge2 tmp = edge2[i];
				edge2[i] = edge2[j];
				edge2[j] = tmp;
			}
		}
	}
	/*for(k=0;k<edgenum;k++)
		cout<<edge2[k].head<<" "<<edge2[k].tail<<" "<<edge2[k].cost<<endl;*/

	//select
	int* components = new int[vexnum]; //Union-Find Sets
	for (i = 0; i < vexnum; i++)
		components[i] = i;
	j = 0;
	for (i = 1; i < vexnum;)
	{
		//time:vexnum-1
		int h = edge2[j].head;
		int t = edge2[j].tail;
		if (components[h] != components[t])
		{
			cout << vexs[edge2[j].head] << " -> " << vexs[edge2[j].tail] << endl;
			for (k = 0; k < vexnum; k++)
				if (components[k] == t)
					components[k] = h;
			i++;
		}
		j++;
	}

	delete []edge2;
	delete []components;
}

template <class T>
void AMGraph<T>::Dijkstra()
{
	bool* set = new bool[vexnum]; //the set of selected vexnum
	int* dist = new int[vexnum];
	int* path = new int[vexnum];
	int i, j;
	for (i = 0; i < vexnum; i++)
	{
		set[i] = false;
		dist[i] = INFINITY_VALUE;
		path[i] = -1;
	}
	set[0] = true;
	dist[0] = 0;
	int v = 0;
	for (i = 1; i < vexnum; i++)
	{
		//time:vexnum-1
		//update distences
		for (j = 0; j < vexnum; j++)
		{
			if (set[j] == false && edges[v][j] != INFINITY_VALUE && dist[v] + edges[v][j] <= dist[j])
			{
				dist[j] = dist[v] + edges[v][j];
				path[j] = v;
			}
		}

		//select minimun distence
		int mini = INFINITY_VALUE;
		for (j = 0; j < vexnum; j++)
		{
			if (set[j] == false && dist[j] < mini)
			{
				mini = dist[j];
				v = j;
			}
		}
		set[v] = true;
	}

	/*for(i=0;i<vexnum;i++)
	{
		cout<<path[i]<<" ";
	}
	cout<<endl;*/

	//output path
	for (i = 1; i < vexnum; i++)
	{
		int k = i;
		while (k != 0)
		{
			cout << vexs[k] << " <- ";
			k = path[k];
		}
		cout << vexs[0] << endl;
	}

	delete []set;
	delete []dist;
	delete []path;
}

template <class T>
void AMGraph<T>::Floyd()
{
	int i, j;
	int** dist = new int*[vexnum];
	int** path = new int*[vexnum];
	for (i = 0; i < vexnum; i++)
	{
		dist[i] = new int[vexnum];
		path[i] = new int[vexnum];
	}

	for (i = 0; i < vexnum; i++)
	{
		for (j = 0; j < vexnum; j++)
		{
			dist[i][j] = edges[i][j];
			if (dist[i][j] < INFINITY_VALUE)
				path[i][j] = j;
			else
				path[i][j] = -1;
		}
		//diagonal, zero
		//dist[i][i]=0;
	}

	for (int k = 0; k < vexnum; k++)
	{
		for (i = 0; i < vexnum; i++)
		{
			for (j = 0; j < vexnum; j++)
			{
				if (dist[i][k] != INFINITY_VALUE && dist[k][j] != INFINITY_VALUE && dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}

	/*for(i=0;i<vexnum;i++){
		for(j=0;j<vexnum;j++)
			cout<<path[i][j]<<" ";
		cout<<endl;
	}*/

	//output path
	for (i = 0; i < vexnum; i++)
	{
		for (j = 0; j < vexnum; j++)
		{
			cout << "from " << vexs[i] << " to " << vexs[j] << ": ";
			int v = path[i][j];
			while (v != j)
			{
				if (v == -1)
				{
					cout << "no-path.";
					break;
				}
				cout << vexs[v] << " -> ";
				v = path[v][j];
			}
			if (v == j)
				cout << vexs[j];
			cout << endl;
		}
	}

	for (i = 0; i < vexnum; i++)
	{
		delete [] dist[i];
		delete [] path[i];
	}
	delete [] dist;
	delete [] path;
}

#endif
