#include "Assignment1.cpp"
#include <iostream>
using namespace std;
class Stack:private Array
{
/*We do not have to create any member variable in stack because capacity and ptr are already there in array and top is also 
there as lastIndex*/    
public:
Stack(int);
Stack(Stack &);
void push(int);
int peek();
void pop();
~Stack();
bool stackOverflow();
bool stackUnderflow();
virtual int getCapacity();
int numberOfElementsInStack();
};
int Stack::numberOfElementsInStack()
{
    return numberOfElements();
}
int Stack::getCapacity()
{
    return Array::getCapacity();
}
Stack::Stack(Stack &S):Array(S)
{}
Stack::Stack(int capacity) :Array(capacity)
{
}
void Stack::push(int data)
{
    if(check_Array_full_or_not())
    {cout<<"Stack overflow\n";}
    else
    {
append(data);
  }
}
int Stack::peek()
{
   if(array_empty_or_not()==0)
   {return (getElement(numberOfElements()-1));}
   else
  { cout<<"Stack underflow\n";
   return 0;}
}
void Stack::pop()
{
    if(array_empty_or_not())
    {cout<<"Stack underflow\n";}
    else
   {deleteElement(numberOfElements()-1);}
   } 
Stack::~Stack()
{/*We have to do nothing because in this class we have not created any variable and parent class destructor will be called by default*/
}
bool Stack::stackOverflow()
{
    return check_Array_full_or_not();
}
bool Stack::stackUnderflow()
{
    return array_empty_or_not();
}
void reverseStack(Stack &S)
{
Stack S1=S; //Copy Constructor will be called
while(!S.stackUnderflow())
{S.pop();}
while(!S1.stackUnderflow())
{
    S.push(S1.peek());
    S1.pop();
}
}
/*We have to keep track of minimum value so minstack is a stack in which the top value will contain minimum value of stack.The top 
element of minstack will always contain the minimum value and it will be updated automatically if you push and pop elements.
Now if we want to use this then use pushInStack() and popFromStack() function for pushing and popping values.*/
void pushInStack(Stack &s, Stack &minStack,int data)
{
    s.push(data);
    if(minStack.stackUnderflow())
        minStack.push(data);
    else
    {
        if(data> minStack.peek())
            minStack.push(minStack.peek());
        else
            minStack.push(data);
    }
}
void popFromStack(Stack &s, Stack &minStack)
{
    s.pop();
    minStack.pop();
}


