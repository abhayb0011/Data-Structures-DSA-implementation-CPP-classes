#include <iostream>
#include "Assignment9.cpp"
using namespace std;
int main()
{
   Stack obj(5);
   obj.push(10);
   obj.push(20);
   obj.push(30);
   cout<<obj.peek()<<endl;
   reverseStack(obj);
cout<<obj.peek();
return 0;
}