#include<iostream>
#include<stdio.h>
using namespace std;
class Queue{
    private:
        int capacity;
        int front, rear;
        int* ptr;
    public:
        Queue(int);
        Queue(Queue &);
        void insert(int);
        bool isFull();
        bool isEmpty();
        int getRear();
        int getFront();
        void del();
        ~Queue();
        int count();
        Queue& operator=(Queue &);

};
Queue& Queue:: operator=(Queue &Q)
{
    capacity=Q.capacity;
    front=Q.front;
    rear=Q.rear;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
    int n=Q.count();
    int i=Q.front;
    while(n)
    {
        ptr[i]=Q.ptr[i];
        if(i==capacity-1)
            i=0;
        else
            i++;
        n--;
    }
}
int Queue::count()
{
    if(isEmpty())
        return 0;
    if(front<=rear)
        return rear-front+1;
    return capacity-front+rear+1;
}
Queue::Queue(Queue &Q)
{
    capacity=Q.capacity;
    front=Q.front;
    rear=Q.rear;
    ptr=new int[capacity];
    int n=Q.count();
    int i=Q.front;
    while(n)
    {
        ptr[i]=Q.ptr[i];
        if(i==capacity-1)
            i=0;
        else
            i++;
        n--;
    }
}
Queue::~Queue()
{
    delete []ptr;
}
void Queue::del()
{
    if(isEmpty())
        cout<<"\nQueue Underflow";
    else if(front==rear)
        front=rear=-1;
    else if(front==capacity-1)
        front=0;
    else
        front++;
}
int Queue::getFront()
{
    if(!isEmpty())
        return ptr[front];
    cout<<"\nQueue is empty";
    return -1;
}
int Queue::getRear()
{
    if(!isEmpty())
        return ptr[rear];
    cout<<"\nQueue is empty";
    return -1;
}
bool Queue::isEmpty()
{
    return rear==-1;
}
bool Queue::isFull()
{
    return front==0&&rear==capacity-1||rear+1==front;
}
void Queue::insert(int data)
{
    if(isFull())
        cout<<"\nQueue Overflow";
    else if(isEmpty())
    {
        front=rear=0;
        ptr[rear]=data;
    }
    else if(rear==capacity-1)
    {
        rear=0;
        ptr[rear]=data;
    }
    else{
        rear++;
        ptr[rear]=data;
    }
}
Queue::Queue(int cap)
{
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[cap];
}