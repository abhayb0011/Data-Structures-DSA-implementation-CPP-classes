#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
int item;
int pno;
node *next;
};
class PriorityQueue
{
private:
node *start;
public:
PriorityQueue();
void insert(int,int);
bool isEmpty();
void del();
int getElement();
int getHighestPriorityNumber();
~PriorityQueue();
};
PriorityQueue::PriorityQueue()
{
    start=NULL;
}
bool PriorityQueue::isEmpty()
{
    return start==NULL;
}
void PriorityQueue::insert(int data,int priority)
{
    node *n=new node;
    n->item=data;
    n->pno=priority;
    if(isEmpty())
    {
        n->next=NULL;
        start=n;
    }
    else 
    {
        int flag=0;
        node *t=start;
        if(priority>=(start->pno)) /*highest priority is in first node so if entered priority is greater than that then we have to insert 
                                    the element as first node*/
            {
            n->next=start;
            start=n;
            }
        else if(priority<(start->pno)) //If entered priority is less than first node priority
        {
            while(t->next!=NULL)
            {
                if(priority<=(t->next->pno))
                {
                    t=t->next;
                }
                else
                {
                    break;
                }
            }
            n->next=t->next;    // If entered priority is least priority then we have to insert it as last node then also code will work
            t->next=n;
        }        
                    
    }
}
void PriorityQueue::del()
{
    if(isEmpty())
    {
        cout<<"Priority queue is empty"<<endl;
    }
    else
    {
        node *t1=start->next;    
        delete start;           
        start=t1;  //If there is single node also then also code will work
    }
}
int PriorityQueue::getElement()
{
    if(isEmpty())
    {
        cout<<"Priority Queue is empty"<<endl;
        return -1;
    }
    else
    {
    return start->item;
    }
}
int PriorityQueue::getHighestPriorityNumber()
{
    if(isEmpty())
    {
        cout<<"Priority Queue is empty"<<endl;
        return -1;
    }
    else
    {
    return start->pno;
    }
}
PriorityQueue::~PriorityQueue()
{
    while(!isEmpty())
    {
        del();
    }
}

