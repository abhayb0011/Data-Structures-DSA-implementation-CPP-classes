#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class SLL
{
private:
node *start;
public:
SLL();
void insertAtStart(int);
node* getFirstNode();
void insertAtEnd(int);
node* searchNode(int);
void insertAfterNode(node*,int);
void delFirstNode();
void delLastNode();
void delSpecificNode(node*);
void printNodes();
void setStartPointer(node*);
bool LinkedListEmpty();
~SLL();
};
SLL::SLL()
{
    start=NULL;
}
void SLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
void SLL::insertAtEnd(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
   if(start==NULL)
   {
    start=n;
   }
   else
   {
    node *t;
    t=start;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=n;
   }
}
node* SLL::searchNode(int data)
{
     int flag=-1;
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
    cout<<"Searched item not found"<<endl;
    return NULL;
}
}
void SLL::insertAfterNode(node *ptr,int data) 
{
  node* n=new node;
  n->item=data;
  n->next=ptr->next;
  ptr->next=n;
}
void SLL::delFirstNode()
{
    if(start!=NULL)
    {
        node *n;
n=start->next;
delete start;
start=n;
    }
    else
    {
        cout<<"Linked list is empty"<<endl;
    }
}
void SLL::delLastNode()
{
    if(start==NULL)
   { cout<<"Linked list is empty";}
   else if(start->next==NULL)
   {
    delete start;
    start=NULL;
   }
    else 
    {
    node *t;
    node *n;
    t=start;
    while(t->next!=NULL)
    {
        n=t;
        t=t->next;
    }
    n->next=NULL;
    delete t;
    }
}
  void SLL::delSpecificNode(node *temp)
   {
    if(start==NULL)
    {
        cout<<"Linked list is empty "<<endl;
    }
    else if(start==temp)
    {
start=temp->next;
delete temp;
    }
    else
    {
        node *t=start;
        while(t->next!=temp)
        {
t=t->next;
        }
        t->next=temp->next;
        delete temp;
    }
}

void SLL::printNodes()
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
node* SLL::getFirstNode()
{
    return start;
}
void SLL::setStartPointer(node *first)
{
    start=first;
}
bool SLL::LinkedListEmpty()
   {return start==NULL;}
SLL::~SLL()
{
    while(start)
   { delFirstNode();}
}
