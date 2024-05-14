#include <iostream>
#include <math.h>
using namespace std;
int sumFirstnNatural(int n)
{
   if(n==1)
   {
    return 1;
   }
   return n+sumFirstnNatural(n-1);
}
int sumFirstnOddNatural(int n)
{
    if(n==1)
    {
        return 1;
    }
    return sumFirstnOddNatural(n-1)+(2*n-1);
}
int sumFirstnEvenNatural(int n)
{
    if(n==1)
    {
        return 2;
    }
    return sumFirstnEvenNatural(n-1)+(2*n);
}
int sumOfSquaresFirstnNatural(int n)
{
   if(n==1)
   {
    return 1;
   } 
   return (n*n)+sumOfSquaresFirstnNatural(n-1);
}
int Factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*Factorial(n-1); 
}
int sumOfDigits(int n)
{
if(n==0)
{return 0;}
return (n%10)+sumOfDigits(n/10);
}
int p=-1;
int binary(int n)
{
    if(n==0)
    {
     return 0;
    }
    p++;
    return (n%2)*(pow(10,p))+binary(n/2);
}
int Fibonacci(int n)
{
    if(n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return 1;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}
int HCF(int x,int y)
{
    if(x>=y)
    {
        if((x%y)==0)
        {
            return y;
        }
        HCF(y,(x%y));
    }
    else
    {
        if((y%x)==0)
        {
            return x;
        }
        HCF(x,(y%x));
    }
}
double power(double x,double y)
{
    if(y==0)
    {return 1;}
    if(y>0)
    {
        return x*power(x,y-1);
    }
    else if(y<0)
    {
        return (1/x)*power(x,y+1);
    }
}
int main()
{
    int x,y;
    cout<<"Enter x,y"<<endl;
    cin>>x>>y;
    cout<<endl<<power(x,y);
    return 0;
}