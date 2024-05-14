#include <iostream>
#include <stdio.h>
using namespace std;
 struct node
 {
    int item;
    node *next;
 };
 class Stack
 {
    private:
    node *top;
    public:
    Stack();
    Stack(Stack &);
    void push(int);
    bool Stackunderflow();
    int peek();
    void pop();
    ~Stack();
    void reverseStack();
    Stack& operator=(Stack &); //Overloading of assignment operator
 };
 Stack::Stack()
 {
    top=NULL;
 }
Stack::Stack(Stack &S)
{
    Stack S1;
    node *t=S.top;
    while(t!=NULL)
    {
        S1.push(t->item);
        t=t->next;
    }
    while(!S1.Stackunderflow())
    {
        push(S1.peek());
        S1.pop();
    }
}
 Stack& Stack::operator=(Stack &S)
{
    while(!Stackunderflow())   /*We have to delete the nodes of calling object in which the given object is to be 
                                copied if it is not empty*/
    {pop();}           

    node *t,*n,*p=NULL;
    t=S.top;
    while(t)
    {
        n=new node;
        n->item=t->item;
        if(top==NULL)
            top=n;
        else
            p->next=n;
        t=t->next;
        p=n;
    }
    if(p!=NULL)
        p->next=NULL;
}
void Stack::push(int data) /*We can insert the new element as first node as well as last node but we will insert it as first 
                              node because if we insert it as last node then traversing would be required in deletion */
 {
    node *n=new node;
    n->item=data;
    n->next=top;
    top=n;
 }
 bool Stack::Stackunderflow()
 {
    return top==NULL;
 }
int Stack::peek()
{
    if(Stackunderflow())
    {
        cout<<"Stack underflow\n";
        return 0;
        }
    else
    return top->item;
}
void Stack::pop()
{
    if(Stackunderflow())
    {cout<<"Stack underflow\n";}
    else
    {
        node *t=top;
        top=top->next;
        delete t;
    }
}
Stack::~Stack()
{
    while(!Stackunderflow())
    {pop();}
}
/*There are two methods of making reverseStack first as a member function and second one as a non member function*/
void Stack::reverseStack()  //reverseStack as a member function
{
node *t1,*t2;
if(top!=NULL && top->next!=NULL) //When Stack is empty and when only single node is there then do nothing
{
    t2=NULL;
    do
    {
    t1=top;
    top=top->next;
    t1->next=t2;
    t2=t1;
    } while (top->next!=NULL);
    top->next=t1;
}
}
void reverseStack(Stack &S) //reverseStack not as a member function
{
Stack S1(S);
while(!S.Stackunderflow())
{
    S.pop();
}
while(!S1.Stackunderflow())
{
    S.push(S1.peek());
    S1.pop();
}
}
int len(int x)
{
    int count=0;
    while(x)
    {
        x/=10;
        count++;
    }
    return count;
}
bool isPalindrome(int x)
{
    Stack s;
    int l=len(x);
    int i=l/2;
    while(i)
    {
        s.push(x%10);
        x/=10;
        i--;
    }
    if(l%2)
        x/=10;
    while(x)
    {
        if(x%10==s.peek())
        {
            s.pop();
            x/=10;
        }
        else
            return false;
    }
    return true;
}
int main()
{
    Stack obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    cout<<obj.Stackunderflow()<<endl;
    return 0;
}