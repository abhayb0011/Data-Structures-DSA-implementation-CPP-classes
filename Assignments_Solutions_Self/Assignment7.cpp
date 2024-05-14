#include <iostream>
#include <math.h>
#include "Assignment4.cpp"
using namespace std;
int noOfitems(SLL &obj)
{
    int count=0;
    node *t=obj.getFirstNode();
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}
//SIR APPROACH:-
void reverseSLL(SLL &obj)
{
    node *temp;
    node *t1=obj.getFirstNode();
    node *t2=t1->next;
    t1->next=NULL;
    while(t2!=NULL)
    {
        temp=t2->next;
        t2->next=t1;
        t1=t2;
        t2=temp;
    }
    obj.setStartPointer(t1);
}
/*   MY APPROACH:-
void reverseSLL(SLL &obj)
{
    node *t1=obj.getFirstNode();
    node *t2=obj.getFirstNode();
    while(t1->next!=NULL)
    {
        t1=t1->next;
    }
    while(t2->next!=NULL)
    {
        obj.insertAfterNode(t1,t2->item);
        t2=t2->next;
    }
    for(int i=0;i<(noOfitems(obj)-1);i++)
    {
obj.delFirstNode();
    }
}
node *middleNode(SLL &obj)
{
    int m;
    if((noOfitems(obj)%2)==0)
{m=noOfitems(obj)/2;}
else
{m=noOfitems(obj)+1;}
node *t=obj.getFirstNode();
for(int i=1;i<=m-1;i++)
{
    t=t->next;
}
return t;
}*/
node *middleNode(SLL &obj)
{
    node *t1=obj.getFirstNode();
    node *t2=t1;
    while(t2->next!=NULL || t2!=NULL)
    {
    t1=t1->next;
    t2=t2->next->next;
    }
    return t1;
}
/*Linked list is called cyclic if the next pointer of any node points to any previous node of the list*/
//In this below function Floyd's detection algorithm is used//
int isCycle(SLL &obj)
{
    node *t1,*t2;
    t1=obj.getFirstNode();
    t2=t1;
    do
    {
    if(t1==NULL)
    {return 0;}
    if(t1->next!=NULL)
    {t1=t1->next->next;}
    else
    {return 0;}
    t2=t2->next;
    } while (t1!=t2);
    return 1;
}
int lengthOfcycle(SLL &obj)
{
    int count=1;
    node *t1,*t2;
   if(isCycle(obj))
   {
    t1=t2=obj.getFirstNode();
    do
    {
        t1=t1->next->next;
        t2=t2->next;
    } while (t1!=t2);
    while(t1->next!=t2)
    {
        count++;
        t1=t1->next;
    }
    return count;
   }
   return 0;
}

void sortSLL(SLL &obj)
{
    int temp;
    node *t1=obj.getFirstNode();
    node *t2=t1->next;
for(int i=1;i<=noOfitems(obj)-1;i++)
{
while(t1->next!=NULL)
{
    if((t1->item)>(t2->item))
    {
temp=t1->item;
t1->item=t2->item;
t2->item=temp;
    }
    t1=t1->next;
    t2=t2->next;
}
}
}
void mergeSLL(SLL &obj1,SLL &obj2)
{
    node *t1=obj1.getFirstNode();
    node *t2=obj2.getFirstNode();
    while(t2!=NULL)
    {
        obj1.insertAtEnd(t2->item);
        t2=t2->next;
    }
}
void addSLL(SLL &obj1,SLL &obj2,SLL &sum)
{
    int num1=0;
    int num2=0;
    int s;
    int i=0;
    int j=0;
    node *t1=obj1.getFirstNode();
    node *t2=obj2.getFirstNode();
    while(t1!=NULL)
    {
        num1=num1+(t1->item)*pow(10,i);
        i++;
        t1=t1->next;
    }
    while(t2!=NULL)
    {
        num1=num1+(t2->item)*pow(10,j);
        j++;
        t2=t2->next;
    }
    s=num1+num2;
    while(s>0)
    {
    sum.insertAtEnd(s%10);    /*As the digits are stored in reverse order in given number linked list so in sum linked list also
                               digits are stored in reverse order*/
    s=s/10;                    
    }
}




