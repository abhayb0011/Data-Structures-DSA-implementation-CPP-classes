#include<iostream>
#include "SLL.cpp"
using namespace std;

class Polynomial
{
    struct node
    {
        int coeff;
        int deg;
        node *next;
    };
    node *start;
    public:
    Polynomial();
    void insert(int c,int d);

};
void Polynomial:: insert(int c,int d)
{
    node *n=new node;
    node *t,*p;
    n->coeff=c;
    n->deg=d;
    if(start==NULL)
    {
        n->next=NULL;
        start=n;
    }
    else
    {
        t=start;
        p=NULL;
        if(t->deg<d)
        {
            n->next=t;
            start=n;
        }
        else
        {
            p=t;
            t=t->next;
            while(t!=NULL)
            {
                if(t->deg < d)
                {
                    n->next=t;
                    p->next=n;
                    break;
                }
                p=t;
                t=t->next;

            }
            if(t==NULL)
            {
                n->next=NULL;
                p->next=n;
            }
        }
    }
}
Polynomial::Polynomial()
{
    start=NULL;
}


int is_cycle(SLL &obj)
{
    node *t1,*t2;
    t1=obj.getFirstNode();
    t2=t1;
    do
    {
        if(t1==NULL)
            return 0;
        if(t1->next!=NULL)
            t1=t1->next->next;
        else
            return 0;
        t2=t2->next;
        
    }while(t1!=t2);
    return 1;
    
}
int length_of_cycle(SLL &obj) 
{
    int count=1;
    node *t1,*t2;
    if(is_cycle(obj))
    {
        t2=t1=obj.getFirstNode();
        do
        {
            t1=t1->next->next;
            t2=t2->next;
        }while(t1!=t2);
        while(t1->next!=t2)
        {
            count++;
            t1=t1->next;
        }
        return count;
    }
    return 0;
}