#include <iostream>
#include "Assignment3.cpp"
using namespace std;
class Graph
{
private:    
int V_count;
int E_count;
int **adj;
public:
void createGraph(int,int);
void printMatrix();
bool checkIsolated(int);
void printAdjacentNodes(int);
int getV_count();
DynArray& adjacentNodes(int);
int countAdjacentNodes(int);
~Graph();
};
void Graph::createGraph(int vno,int eno)
{
    int u,v;
    V_count=vno;
    E_count=eno;
    adj=new int*[vno];
    for(int i=0;i<vno;i++)
    {adj[i]=new int[vno];}
    /*Firstly, 0 is assigned at all enteries of matrix then later 1 is assigned at those enteries 
    for which edge is there between the nodes*/
    for(int i=0;i<V_count;i++) 
    {
        for(int j=0;j<V_count;j++)
        {
        adj[i][j]=0;
        }
    }
    for(int k=1;k<=E_count;k++)
    {
        cout<<"\nEnter node numbers connected by the edge "<<k<<": ";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
}
void Graph::printMatrix()
{
    cout<<endl;
    for(int i=0;i<V_count;i++)
    {
        for(int j=0;j<V_count;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool Graph::checkIsolated(int v)
{
    int flag=1;
if(v>=0 && v<V_count)
{
for(int i=0;i<V_count;i++)
{
    if(adj[v][i]!=0)
    {
        flag=0;
        break;
    }
}
if(flag==1)
return true;
else
return false;
}
}
void Graph::printAdjacentNodes(int v)
{
if(v>=0 && v<V_count)
{
for(int i=0;i<V_count;i++)
{
    if(adj[v][i]==1)
    cout<<"V"<<i<<" ";
}
}
}
int Graph::getV_count()
{
    return V_count;
}
DynArray& Graph::adjacentNodes(int v)
{
    DynArray *p=new DynArray(1); //Create the object dynamically otherwise local object will be created and the local object 
                                 //will be destroyed once the function ends 
    if(v<V_count && v>=0)
    {
    for(int i=0;i<V_count;i++)
    {
        if(adj[v][i]==1)
        {
            p->append(i);
        }
    }
    }
    return *p;
}
int Graph::countAdjacentNodes(int v)
{
    int count=0;
    for(int i=0;i<V_count;i++)
    {
      if(adj[v][i]==1)
      {
        count++;
      }
    }
    return count;
}
Graph::~Graph()
{
    for(int i=0;i<V_count;i++)
    {delete []adj[i];}
    delete []adj;
}


