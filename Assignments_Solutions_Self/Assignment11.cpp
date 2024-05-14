#include<iostream>
#include<stdio.h>
using namespace std;
class Queue
{
    private:
    int capacity,rear,front;
    int *ptr;
    public:
    Queue(int);
    Queue(Queue &);
    Queue& operator=(Queue &);   //copy assignment operator
    void insert(int);
    int getRear();
    int getFront();
    void del();
    ~Queue();
    bool queue_overflow();
    bool queue_underflow();
    int numberOfElements();
};
Queue::Queue(int size)
{
    capacity=size;
    front=-1;
    rear=-1;
    ptr= new int[size];
}
Queue::Queue(Queue &Q)
{
capacity=Q.capacity;
front=Q.front;
rear=Q.rear;
ptr=new int[capacity];
int count=Q.numberOfElements();
int i=front;
while(count>0)
{
    ptr[i]=Q.ptr[i];
    if(i==capacity-1)
    i=0;
    else
    i++;
    count--;
}
}
Queue& Queue::operator=(Queue &Q)
{
capacity=Q.capacity;
front=Q.front;
rear=Q.rear;
if(ptr!=NULL)  /*It may be that the object in which the given object is to be copied may not be empty and ptr 
                might be pointing to some array so first we have to delete that array and then copy in it*/
delete[]ptr;
ptr=new int[capacity];
int count=Q.numberOfElements();
int i=front;
while(count>0)
{
    ptr[i]=Q.ptr[i];
    if(i==capacity-1)
    {i=0;}
    else
    {i++;}
    count--;
}
return Q;
}
void Queue::insert(int data)
{
    if((front==0 && rear==(capacity-1) ||(front-rear)==1))
    {
    cout<<"Queue is full"<<endl;
    }
    else if(front==-1 && rear==-1)
    {
    rear=0;
    front=0;
    ptr[rear]=data;
    }
    else if(rear==capacity-1) //when queue is not full and rear is last possible index
    {
        rear=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
int Queue::getRear()
{
    if(queue_underflow())
    {
     cout<<"Queue underflow"<<endl;
    return -1;
    }
    else
    {return ptr[rear];}
}
int Queue::getFront()
{
    if(queue_underflow())
    {
     cout<<"Queue underflow"<<endl;
    return -1;
    }
    else
    {return ptr[front];}
}
void Queue::del()
{
if(front==-1 && rear==-1)
{
    cout<<"Queue is empty"<<endl;
}
else if(front==rear && front!=-1 && rear!=-1) //When only single element in queue
{
front =-1;
rear=-1;
}
else if(front==capacity-1)
{
    front=0;

}
else
{
    front++;
}
}
Queue::~Queue()
{
    delete[]ptr;
}
bool Queue::queue_overflow()
{
    int flag=0;
    if((front==0 && rear==(capacity-1) ||(front-rear)==1))
    {flag=1;}
    return flag;
}
bool Queue::queue_underflow()
{
 int flag=0;
 if(front==-1 && rear==-1)
 {flag=1;}
 return flag;
}
int Queue::numberOfElements()  /*Method 1*/
{
if(front==-1 && rear==-1)
return 0;
else if(front==rear && front!=-1 && rear!=-1)
return 1;
else
{
    int i=front;
    int count=0;
    while(i!=rear)
    {
    count++;
    if(i==capacity-1)
    i=0;
    else
    i++;
    }
    count=count+1; //That element is not counted in while loop for which i=rear so doing count+1 for that element
    return count;
}
/*int Queue::numberOfElements()     //method 2
{
if(front==-1 && rear==-1)
return 0;
if(front<=rear)
return rear-front+1;  //expression1
if(front>rear)
return capacity-front+rear+1;  //expression2
                               /take an example and you can frame these conditions
}
*/
}
