#include <iostream>
#include "Assignment3.cpp"
#include <stdio.h>
using namespace std;
struct node
{
    int vertex;
    int item;
    node *next;
};
class AdjList
{
private:
node *start;
int ver;   //ver is vertex
public:
AdjList();
AdjList(int);
void addNode(int,int);
void setVertex(int);
void printList();
void delFirstNode();
int countListNode();
DynArray& getVerticesListNodes();
~AdjList();
};
AdjList::AdjList()
{
    start=NULL;
}
AdjList::AdjList(int v)
{
    start=NULL;
    ver=v;
}
void AdjList::addNode(int vert,int data)
{
    node *n=new node;
    n->item=data;
    n->vertex=vert;
    n->next=start;
    start=n;
}
void AdjList::setVertex(int v)
{
    ver=v;
}    
void AdjList::printList()
{
    cout<<endl;
    node *t=start;
    while(t!=NULL)
    {
        cout<<"("<<t->vertex<<","<<t->item<<") ";
        t=t->next;
    }
}
void AdjList::delFirstNode()
{
if(start!=NULL)
{
node *t=start;
start=start->next;
delete t;   
}
}
int AdjList::countListNode()
{
    int count=0;
    node *t=start;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}
DynArray& AdjList::getVerticesListNodes()
{
    DynArray *p=new DynArray(1); //Create object dynamically because if you create the object locally 
                                 //then it will be destroyed once the function ends 
    if(start!=NULL)
    {
    node *t=start;
    while(t!=NULL)
    {
    p->append(t->vertex);
    t=t->next;
    }
    }
    return *p;
}
AdjList::~AdjList()
{
while(start!=NULL)
{
    delFirstNode();
}
}
class Graph
{
    private:
    int V_count;
    AdjList *arr;
    public:
    Graph();
    void createGraph(int);
    ~Graph();
    void printGraph();
    int countAdjacentNodes(int);
    int getV_count();
    DynArray& getVerticesAdjacentNodes(int);
};
Graph::Graph()
{
V_count=0;
arr=NULL;
}
void Graph::createGraph(int vno)
{
    int n,v,data;
    V_count=vno;
    arr=new AdjList[V_count];
    for(int i=0;i<V_count;i++)
    {
        arr[i].setVertex(i);
        cout<<"\nHow many adjacent nodes of V"<<i<<":";
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cout<<"\nEnter vertex number: ";
            cin>>v;
            cout<<"\nEnter data to store: ";
            cin>>data;
            arr[i].addNode(v,data);
        }
    }
}
Graph::~Graph()
{
    delete []arr;
}
void Graph::printGraph()
{
    for(int i=0;i<V_count;i++)
    {
        arr[i].printList();
    }
}
int Graph::countAdjacentNodes(int v)
{
   return arr[v].countListNode();
}
int Graph::getV_count()
{
    return V_count;
}
DynArray& Graph::getVerticesAdjacentNodes(int v)
{
return arr[v].getVerticesListNodes();
}
void testFunction(Graph &G,int v)
{
for(int i=0;i<G.countAdjacentNodes(v);i++)    
{cout<<" V"<<G.getVerticesAdjacentNodes(v).getElement(i);}
}
