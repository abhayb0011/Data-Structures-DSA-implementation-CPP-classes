#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
int item;
node *next;
};
class Queue
{
    private:
    node *front,*rear;
    public:
    Queue();
    Queue(Queue &);
    void insert(int);
    node* getRear();
    node* getFront();
    void del();
    ~Queue();
    int numberOfElements();
    bool queue_underflow();
    Queue& operator=(Queue &);
};
Queue::Queue()
{
    front=NULL;
    rear=NULL;
}
Queue::Queue(Queue &Q)
{
    front=NULL;
    rear=NULL;
    node *t=Q.front;
    while(t!=NULL)
    {
    insert(t->item);
    t=t->next;
    }
}
Queue& Queue::operator=(Queue &Q)
{
    while(front!=NULL && rear!=NULL)    /*We have to delete the nodes of calling object in which the given object is to be 
                                          copied if it is not empty*/
    {
        del();
    }
   node *t=Q.front;
    while(t!=NULL)
    {
    insert(t->item);
    t=t->next;
    } 
}
void Queue::insert(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=n;
        rear=n;
    }
    else
    {
    rear->next=n;
    rear=n;
    }
}
node* Queue::getRear()
{
    if(front==NULL && rear==NULL)
    {
    cout<<"Queue underflow"<<endl;
    return NULL;
    }
else
{
    return rear;
}
}
node* Queue::getFront()
{
    if(rear==NULL && front==NULL)
    {
        cout<<"Queue undeflow"<<endl;
        return NULL;
    }
    else
    {
        return front;
    }
}
void Queue::del()
{
    if(rear==front && rear==NULL)
    {
        cout<<"Queue underflow"<<endl;
    }
    else if(rear==front && rear!=NULL) //When Queue has only one node
    {
        delete front;
        rear=NULL;
        front=NULL;
    }
    else
    {
    node *t;
    t=front;
    front=front->next;
    delete t;
    }
}
Queue::~Queue()
{
    while(front!=NULL && rear!=NULL)
    {
        del();
    }
}
int Queue::numberOfElements()
{
    int count=0;
    node *t=front;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}
bool Queue::queue_underflow()
{
    return front==NULL;
}
void sort(Queue &Q)
{
if(Q.queue_underflow())
cout<<"Queue underflow"<<endl;
else if (Q.getFront()==Q.getRear() && Q.getFront()!=NULL) //When single node is there then we have to do nothing
{}
else
{
Queue Q1=Q;
Queue Q2;
Queue Q3;
while(!Q1.queue_underflow())
{
    if(Q2.queue_underflow())
    {
        Q2.insert(Q1.getFront()->item);
    }
    else if((Q2.getRear()->item)<=(Q1.getFront()->item))
    {
      Q2.insert(Q1.getFront()->item);  
    }
    else
    {
    while((Q1.getFront()->item)>(Q2.getFront()->item))
    {
    Q3.insert(Q2.getFront()->item);
    Q2.del();   
    }
    Q3.insert(Q1.getFront()->item);
    while(!Q2.queue_underflow())
    {
        Q3.insert(Q2.getFront()->item);
        Q2.del();
    }
    while(!Q3.queue_underflow())
    {
        Q2.insert(Q3.getFront()->item);
        Q3.del();
    }
    }
    Q1.del();
    }
    Q=Q2;        
}
}
void sortDescending(Queue &Q)
{
if(Q.queue_underflow())
cout<<"Queue underflow"<<endl;
else if (Q.getFront()==Q.getRear() && Q.getFront()!=NULL) //When single node is there then we have to do nothing
{}
else
{
Queue Q1=Q;
Queue Q2;
Queue Q3;
while(!Q1.queue_underflow())
{
    if(Q2.queue_underflow())
    {
        Q2.insert(Q1.getFront()->item);
    }
    else if((Q2.getRear()->item)>=(Q1.getFront()->item))
    {
      Q2.insert(Q1.getFront()->item);  
    }
    else
    {
    while((Q1.getFront()->item)<(Q2.getFront()->item))
    {
    Q3.insert(Q2.getFront()->item);
    Q2.del();   
    }
    Q3.insert(Q1.getFront()->item);
    while(!Q2.queue_underflow())
    {
        Q3.insert(Q2.getFront()->item);
        Q2.del();
    }
    while(!Q3.queue_underflow())
    {
        Q2.insert(Q3.getFront()->item);
        Q3.del();
    }
    }
    Q1.del();
    }
    Q=Q2;        
}
}

int main()
{
    Queue obj;
    obj.insert(10);
    obj.insert(30);
    obj.insert(20);
    obj.insert(10);
    obj.insert(40);
    sortDescending(obj);
    while(!obj.queue_underflow())
    {
    cout<<(obj.getFront())->item<<endl;
    obj.del();
    }
    return 0;
}
