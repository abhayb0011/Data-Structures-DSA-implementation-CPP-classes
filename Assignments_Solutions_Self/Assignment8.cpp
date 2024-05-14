#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
node *prev;
int item;
node *next;
};
class CDLL
{
private:
node *start;
public:
CDLL();
void insertAtStart(int);
void insertAtEnd(int);
node* searchNode(int);
void insertAfterNode(node*,int);
void delFirstNode();
void delLastNode();
void delSpecificNode(node*);
void printNodes();
~CDLL();
};
CDLL::CDLL()
{
    start=NULL;
}
void CDLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->next=n;
        n->prev=n;
        start=n;
    }
    else
    {
    n->next=start;
    n->prev=start->prev;
    start->prev->next=n;
    start->prev=n;
    start=n;
    }
}
void CDLL::insertAtEnd(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
    n->prev=start->prev;
    n->next=start;
    start->prev->next=n;
    start->prev=n;
    }
}
node* CDLL::searchNode(int data)
{
    int flag=-1;
    if(start!=NULL)
    {
        node *t=start;
        do
        {
           if(t->item==data)
           {
            flag=1;
            return t;
           }
           t=t->next;
        } 
        while(t!=start);
        if(flag==-1)
        {
            cout<<"Node not found\n";
            return NULL;
        }
    }
    else
    {
        cout<<"Linked list is empty\n";
    return NULL;
    }
}
void CDLL::insertAfterNode(node *temp,int data)
{
    if(temp!=NULL)
    {
node *n=new node;
n->item=data;
n->prev=temp;
n->next=temp->next;
temp->next->prev=n;
temp->next=n;
    }
}
void CDLL::delFirstNode()
{
    if(start!=NULL)
    {
    node *k=start;
    {
    k->prev->next=k->next;
    k->next->prev=k->prev;
   if(start->next==start) //When only single node is there//
    {
        delete k;
        start=NULL;
    }
    else
    {
    start=k->next;
    delete k;
    }
    }
    }
    else if(start==NULL)
    cout<<"Linked list is empty\n";
}
void CDLL::delLastNode()
{
    if(start!=NULL)
    {
    node *k=start->prev;
    if(start->next==start)  //When only single node is there//
    {
        delete k;
        start=NULL;
    }
    else
    {
    start->prev=k->prev;
    k->prev->next=start;
    delete k;
    }
}
else
cout<<"Linked list is empty\n";   
}
void CDLL::delSpecificNode(node* temp)
{
    if(start==NULL)
    {cout<<"Linked list is empty\n";}
else
{
    if(temp!=NULL)
    {
        if(start->next!=start)  //Checking that single node is not there// 
        {
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
if(temp==start)        //if first node is to be deleted//
{start=temp->next;}
delete temp;    
}
else if(start->next==start)  //Checking that single node is there//
{
    if(temp==start)     //If single node is there and that is to be deleted//
    {
        delete temp;
        start=NULL;
    }
}
    }
    else
    cout<<"wrong node entered\n";
}
}
void CDLL::printNodes()
{
    cout<<"Linked list is:\n";
    node *t=start;
    do
    {
    cout<<t->item<<endl;
    t=t->next;
    } 
    while (t!=start);
}
CDLL::~CDLL()
{
    while(start!=NULL)
    {
        delFirstNode();
    }
}