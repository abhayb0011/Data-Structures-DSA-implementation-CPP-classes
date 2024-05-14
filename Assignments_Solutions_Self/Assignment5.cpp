#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
    int item;
    node *next;
    node *prev;
};
class DLL
{
    private:
    node *start;
    public:
DLL();
void insertAtStart(int);
void insertAtEnd(int);
node* searchNode(int);
void insertAfterNode(node*,int);
void delFirstNode();
void delLastNode();
void delSpecificNode(node*);
void printNodes();
~DLL();
};
DLL::DLL()
{
    start=NULL;
}
void DLL::insertAtStart(int data)
{
   if(start!=NULL)
  {
    node *n=new node;
    n->item=data;
    n->prev=NULL;
    n->next=start;
    start->prev=n;
    start=n;
  }
  else
  {
        node *n=new node;
        n->item=data;
        n->prev=NULL;
        n->next=NULL;
        start=n;
    }
}
void DLL::insertAtEnd(int data)
{
    if(start==NULL)
    {
        node *n=new node;
        n->item=data;
        n->next=NULL;
        n->prev=NULL;
        start=n;
    }
else
{
node *n=new node;
n->item=data;
n->next=NULL;
node *t;
t=start;
while(t->next!=NULL)
{
    t=t->next;
}
n->prev=t;
t->next=n;
}
}
node* DLL::searchNode(int data)
{
    int flag=-1;
    if (start==NULL)
    {
        cout<<"Linked list is empty";
        return NULL;
        }
        else
        {
    node *t;
    t=start;
    while(t!=NULL)
    {
        if(t->item==data)
        {
            flag=1;
            return t;
            }
        t=t->next;
    }
    if(flag==-1)
    {
        cout<<"Node not found";
        return NULL;
    }
        }
}
void DLL::insertAfterNode(node *temp,int data)
{
    if(temp->next==NULL)
    {
        insertAtEnd(data);
    }
    else
    {
    node *n =new node;
    n->item=data;
   n->prev=temp;
   n->next=temp->next;
   temp->next->prev=n;
   temp->next=n;
}
}
void DLL::delFirstNode()
{
    if(start==NULL)
    {cout<<"Linked list is empty";}
    else if(start->next==NULL)
    {
        node *k=start;
        start=NULL;
        delete k;
    }
    else
    {
    node *k;
    k=start->next;
    k->prev=NULL;
     delete start;
    start=k;
    }
}
void DLL::delLastNode()
{
    if(start==NULL)
    {cout<<"Linked list is empty";}
    else if(start->next==NULL)
    {
        delete start;
        start=NULL;
    }
    else
    {
        node *t;
        t=start;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->prev->next=NULL;
        delete t;
    }
}
void DLL::delSpecificNode(node *temp)
{
    if(start==NULL)
    {cout<<"Linked list is empty";}
    else if(temp->prev==NULL)
    {
        start=temp->next;
        temp->next->prev=NULL;
        delete temp;
    }
else
{
    temp->prev->next=temp->next;
   if(temp->next!=NULL)
    {temp->next->prev=temp->prev;}
    delete temp;
}
}
void DLL::printNodes()
{
    node *t;
    t=start;
    while(t->next!=NULL)
    {
    cout<<t->item<<endl;
    t=t->next;
    }
    cout<<t->item<<endl;
}
DLL::~DLL()
{
    while(start)
    {
        delFirstNode();
    }
}
