#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
int item;
node *prev,*next;
};
class Deque
{
private:
node *front,*rear;
public:
Deque();
void insertAtFront(int);
void insertAtRear(int);
bool dequeEmpty();
void delFront();
void delRear();
node *getFront();
node *getRear();
~Deque();
};
Deque::Deque()
{
    front=NULL;
    rear=NULL;
}
void Deque::insertAtFront(int data)
{
    node *n=new node;
    n->item=data;
    n->prev=NULL;
    if(front==NULL && rear==NULL)
    {
    n->next=NULL;
    rear=n;
    front=n;
    }
    else
    {
    n->next=front;
    front->prev=n;
    front=n;
    }
}
void Deque::insertAtRear(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(rear==NULL && front==NULL)
    {
        n->prev=NULL;
        rear=n;
        front=n;
    }
    else
    {
        n->prev=rear;
        rear->next=n;
        rear=n;
    }
}
bool Deque::dequeEmpty()
{
    return rear==NULL;
}
void Deque::delFront()
{
    if(dequeEmpty())
    {
        cout<<"Deque is empty"<<endl;
    }
    else if(front==rear and front!=NULL) //When single node is there
    {
        delete front;
        rear=NULL;
        front=NULL;
    }
    else
    {
        node *t=front;
        front=front->next;
        front->prev=NULL;
        delete t;
    }
}
void Deque::delRear()
{
    if(dequeEmpty())
    {
        cout<<"Deque is empty"<<endl;
    }
    else if(front==rear && rear!=NULL) //When single node is there
    {
        delete rear;
        rear=NULL;
        front=NULL;
    }
    else
    {
        node *t=rear;
        rear=rear->prev;
        rear->next=NULL;
        delete t;
    }
}
node* Deque::getFront()
{
    return front; //If deque is empty then front=NULL and NULL will be returned 
}
node* Deque::getRear()
{
    return rear; //If deque is empty then rear=NULL and NULL will be returned
}
Deque::~Deque()
{
    while(!dequeEmpty())
    {
        delFront();
    }
}
