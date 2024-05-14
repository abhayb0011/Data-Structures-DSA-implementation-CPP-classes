#include <iostream>
#include "Assignment11.cpp"
#include "Assignment9.cpp"
#include "Assignment20.cpp"
using namespace std;
void BFS_GraphList(Graph &G,int s)
{
int n,u; 
bool V[G.getV_count()];
for(int i=0;i<G.getV_count();i++)
{
    V[i]=false;
}
Queue Q(G.getV_count());
Q.insert(s);
V[s]=true;
while(!Q.queue_underflow())
{
n=Q.getFront();
cout<<" V"<<n;
Q.del();
int adjacent[G.countAdjacentNodes(n)];
for(int i=0;i<G.countAdjacentNodes(n);i++)
{
    adjacent[i]=G.getVerticesAdjacentNodes(n).getElement(i);
}
for(int i=0;i<G.countAdjacentNodes(n);i++)
{
    u=adjacent[i];
    if(V[u]==false)
    {
        Q.insert(u);
        V[u]=true;
    }
}
}
}
void DFS_GraphList(Graph &G,int s)
{
int n,u; 
bool V[G.getV_count()];
for(int i=0;i<G.getV_count();i++)
{
    V[i]=false;
}
Stack S(G.getV_count());
S.push(s);
V[s]=true;
while(!S.stackUnderflow())
{
n=S.peek();
cout<<" V"<<n;
S.pop();
int adjacent[G.countAdjacentNodes(n)];
for(int i=0;i<G.countAdjacentNodes(n);i++)
{
    adjacent[i]=G.getVerticesAdjacentNodes(n).getElement(i);
}
for(int i=0;i<G.countAdjacentNodes(n);i++)
{
    u=adjacent[i];
    if(V[u]==false)
    {
        S.push(u);
        V[u]=true;
    }
}
}
}
int main()
{
    Graph G;
    G.createGraph(6);
    G.printGraph();
    cout<<endl;
    DFS_GraphList(G,0);
}