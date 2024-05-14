#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class Deque
{
        node *front;
        node *rear;
    public:
        Deque();
        void insertFront(int);
        void insertRear(int);
        void deleteFront();
        void deleteRear();
        node* getFront();
        node* getRear();
        ~Deque();
        bool isEmpty();
};
bool Deque::isEmpty()
{
    if(front)
        return false;
    else
        return true;
}
Deque::~Deque()
{
    while(front)
        deleteFront();
}
node* Deque::getFront()
{
    return front;
}
node* Deque::getRear()
{
    return rear;
}
void Deque::deleteRear()
{
    node *r;
    if(rear)
    {
        r=rear;
        if(front==rear)
            rear=front=NULL;
        else
        {
            rear=rear->prev;
            rear->next=NULL;
        }
        delete r;
    }
}
void Deque::deleteFront()
{
    node *r;
    if(front)
    {
        r=front;
        if(front==rear)
            front=rear=NULL;
        else
        {
            front=front->next;
            front->prev=NULL;
        }
        delete r;       

    }
}
void Deque::insertRear(int data)
{
    node *n=new node;
    n->item=data;
    n->prev=rear;
    n->next=NULL;
    if(rear)
        rear->next=n;
    else
        front=n;
    rear=n;
}
void Deque::insertFront(int data)
{
    node *n=new node;
    n->item=data;
    n->prev=NULL;
    n->next=front;
    if(front)
        front->prev=n;
    else
        rear=n;
    front=n;
}
Deque::Deque()
{
    rear=front=NULL;
}
