#include <iostream>
#include<stdio.h>
using namespace std;
struct node
    {
    int coeff;
    int deg;
    node *next;
    };
class Polynomial
{
    node *start;
    public:
    Polynomial();
    void insert(int,int);
    node* firstNode();
};
Polynomial::Polynomial()
{
    start=NULL;
}
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
node* Polynomial::firstNode()
{
    return start;
}
void addPoly(Polynomial &obj1,Polynomial &obj2)
{
    node *t=obj2.firstNode();
   while(t!=NULL)
   {
   obj1.insert(t->coeff,t->deg);
   t=t->next;
   }
}
