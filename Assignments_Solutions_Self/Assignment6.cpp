#include <iostream>
#include <stdio.h> 
using namespace std;
struct node
{
int item;
node *next;
};
class CLL
{
private:
node *last;
public:
CLL();
void insertAtStart(int);
void insertAtEnd(int);
node* searchNode(int);
void insertAfterNode(node*,int);
void delFirstNode();
void delLastNode();
void delSpecificNode(node*);
void printNodes();
~CLL();
};
CLL::CLL()
{
    last=NULL;
}
void CLL::insertAtStart(int data)
{
node *n=new node;
n->item=data;
if(last==NULL)
{
    n->next=n;
    last=n;
}
else
{
n->next=last->next;
last->next=n;
}
}
void CLL::insertAtEnd(int data)
{
    node *n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
    n->next=last->next;
    last->next=n;
    last=n;
    }
}
node* CLL::searchNode(int data)
{
    if(last==NULL)
    {
        cout<<"Linked list is empty\n";
        return NULL;
    }
    else
    {
    int flag=-1;
    node *t;
   //SIR APPROACH://
   t=last->next;
   do
   {
    if(t->item==data)
    {
        flag=1;
        return t;
        }
    t=t->next;
   } 
   while (t!=last->next);
     /*MY APPROACH:
    t=last->next;
    while(t!=last)
    {
      if(t->item==data)
      {
        flag=1;
        return t;
      }  
      t=t->next;
      }
      if(t->item==data)
      {
flag=1;
return t;
      }*/
 if(flag==-1)
      {
        cout<<"Node not found";
        return NULL;
      }
    }
}
void CLL::insertAfterNode(node* temp,int data)
{
   if(last!=NULL)
   {
    node *n=new node;
    n->item=data;
    n->next=temp->next;
    temp->next=n;
    if(temp==last)
    {last=n;}
   }
}
void CLL::delFirstNode()
{
    if(last==NULL)
    {
        cout<<"Linked list is empty";
    }
    else if(last->next==last)
    {
        delete last;
        last=NULL;
    }
    else
    {
    node *k=last->next;
    last->next=last->next->next;
    delete k;
    }
}
void CLL::delLastNode()
{
    if(last==NULL)
    {
        cout<<"Linked list is empty";
    }
    else if(last->next==last)
    {
        delete last;
        last=NULL;
    }
    else
    {
node *t=last->next;
while(t->next!=last)
{
t=t->next;
}
t->next=last->next;
delete last;
last=t;
    }
}
void CLL::delSpecificNode(node *temp)
{
    if(temp!=NULL)
    {
    if(last==NULL)
    {
        cout<<"Linked list is empty";
    }
    else
    {
    node *t=last->next;
    while(t->next!=temp)
    {t=t->next;}
    t->next=temp->next;
    if(t==temp) //single node
    {last=NULL;}
else if(temp==last) //if given address is of last node
{last=t;}
delete temp;
    }
}
}
void CLL::printNodes()
{
node *t=last->next;
do
{
cout<<t->item<<endl;
t=t->next;
} while (t!=last->next);

}
CLL::~CLL()
{
    while(last!=NULL)
    {delFirstNode();}
}