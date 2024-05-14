#include <iostream>
using namespace std;
class Heap
{
private:
int capacity;
int lastIndex;
int *ptr;
public:
Heap(int);
Heap(Heap &);
int getCapacity();
int count();
int getElement(int);
void halfArray();
void doubleArray();
void insert(int);
bool isEmpty();
int max();
void del();
~Heap();
Heap& operator=(Heap&);
};
Heap::Heap(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
Heap::Heap(Heap &H)
{
    capacity=H.getCapacity();
    lastIndex=H.lastIndex;
    ptr=new int[H.getCapacity()];
    for(int i=0;i<H.capacity;i++)
    {ptr[i]=H.getElement(i);}
}
int Heap::getCapacity()
{
    return capacity;
}
int Heap::count()
{
    return lastIndex+1;
}
int Heap::getElement(int index)
{
    if(!isEmpty())
    {
        return ptr[index];
    }
}
void Heap::halfArray()
{
    capacity=capacity/2;
    int *ptr2=new int [capacity];
    for(int i=0;i<=lastIndex;i++)
    {
        ptr2[i]=ptr[i];
    }
    delete []ptr;
    ptr=ptr2;
}
void Heap::doubleArray()
{
    capacity=2*capacity;
    int *ptr2=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
    {
        ptr2[i]=ptr[i];
    }
    delete []ptr;
    ptr=ptr2;
}
void Heap::insert(int data)
{
     int i,index,parIndex;
    if(lastIndex+1==capacity)
        doubleArray();
    for(index=lastIndex+1;index>0;index=parIndex)
    {
        parIndex=(index-1)/2;
        if(ptr[parIndex]<data)
            ptr[index]=ptr[parIndex];
        else
            break;
    }    
    ptr[index]=data;
    lastIndex++;
}
bool Heap::isEmpty()
{
    return lastIndex==-1;
}
int Heap::max()
{
    if(lastIndex!=-1)
    return ptr[0];
}
void Heap::del()
{
    int i,item,temp,index,leftIndex,rightIndex;
    if(isEmpty())
        cout<<"Heap is empty\n";
    else
    {
        item=ptr[0];
        temp=ptr[lastIndex];
        lastIndex--;
        index=0;
        leftIndex=1;
        rightIndex=2;
        while(leftIndex<lastIndex)
        {
            
            if(ptr[leftIndex]>ptr[rightIndex])
            {
                if(temp<ptr[leftIndex])
                {
                    ptr[index]=ptr[leftIndex];
                    index=leftIndex;
                }
                else    
                    break;
            }
            else
            {
                if(temp<ptr[rightIndex])
                {
                    ptr[index]=ptr[rightIndex];
                    index=rightIndex;
                }
                else
                    break;
            }
            leftIndex=2*index+1;
            rightIndex=2*index+2;
        }
        if(leftIndex==lastIndex && temp<ptr[leftIndex])
        {
            ptr[index]=ptr[leftIndex];
            index=leftIndex;
        }

        ptr[index]=temp;
        
        if(capacity/2>=lastIndex+1 && capacity>1)
            halfArray();
    }
}
Heap::~Heap()
{
    delete []ptr;
}
Heap& Heap::operator=(Heap &H)
{
if(!isEmpty())
{
    delete []ptr;
}
capacity=H.getCapacity();
lastIndex=H.lastIndex;
ptr=new int[H.getCapacity()];
for(int i=0;i<H.capacity;i++)
{ptr[i]=H.getElement(i);}
return *this;
}
void heapSort(int A[],int size)
{ 
Heap H(size);
for(int i=0;i<size;i++)
{
    H.insert(A[i]);
}
for(int i=size-1;i>=0;i--)
{
    A[i]=H.getElement(0);
    H.del();
}
}
int main()
{
int a[10]={1,3,5,7,9,2,4,6,8,10};
heapSort(a,10);
for(int i=0;i<10;i++)
cout<<" "<<a[i];
return 0;
}

    
