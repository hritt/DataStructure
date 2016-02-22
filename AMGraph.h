/************************************************************************
*
*   Description: Graph - adjacent matrix
*
*   Author & Data: JY Liu, 2016/01/18
*
************************************************************************/

#include <limits.h>
#define INFINITY _I32_MAX

//undirected graph, directed draph, undirected network, directed network
enum graphType{UNDIGRAPH, DIGRAPH, UNDINETWORK, DINETWORK};

template<class T>
struct EdgeType{
	T head,tail;
	int cost;
	EdgeType(T h,T t,int c)
	{
		head=h;
		tail=t;
		cost=c;
	}
};

template<class T>
class AMGraph{
	int vexnum,edgenum;
	graphType kind;
	vector< vector<int> > edges; //adjacent matrix
	vector<T> vexs;
public:
	AMGraph(graphType t, T v[], int n, int e);
	int vexNum();
	int edgeNum();
	T getVexValue(int i);
	int getEdgeValue(int i,int j);
	void insertVex(T v);
	void removeVex(T v);
	void insertEdge(EdgeType<T> e);
	void deleteEdge(EdgeType<T> e);
	void DFSTraverse();
	void BFSTraverse();

	void PrintMatrix();
};

template<class T>
AMGraph<T>::AMGraph(graphType t, T v[], int n, int e)
{
	vexnum=n;
	edgenum=e;
	kind=t;
	
	//vertexs
	vexs.resize(vexnum);
	int i,j;
	for(i=0;i<vexnum;i++)
		vexs[i]=v[i];
	
	//edges
	edges.resize(vexnum);
	for(i=0;i<vexnum;i++)
		edges[i].resize(vexnum);
	for(i=0;i<vexnum;i++)
		for(j=0;j<vexnum;j++)
			edges[i][j]=INFINITY;

	T va,vb;
	if(kind==UNDIGRAPH || kind==DIGRAPH){
		for(i=0;i<edgenum;i++)
		{
			cin>>va>>vb;
			edges[va][vb]=1;
			if(kind==UNDIGRAPH)
				edges[vb][va]=1;;
		}
	}else{
		int c;
		for(i=0;i<edgenum;i++)
		{
			cin>>va>>vb>>c;
			edges[va][vb]=c;
			if(kind==UNDINETWORK)
				edges[vb][va]=c;;
		}
	}
}

template<class T>
void AMGraph<T>::PrintMatrix()
{
	for(int i=0;i<vexnum;i++){
		for(int j=0;j<vexnum;j++){
			if(edges[i][j]!=INFINITY)
				cout<<edges[i][j];
			else
				cout<<"-";
			cout<<" ";
		}
		cout<<endl;
	}
}