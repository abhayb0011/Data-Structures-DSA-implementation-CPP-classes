#include <iostream>
#include <stdio.h>
using namespace std;
void printNumbers(int n)
{
    if(n==0)
    {
        return; 
    }
    printNumbers(n-1);
    cout<<n<<" ";
}
void printNumbersReverse(int n)
{
    if(n==0)
    {
        return; 
    }
    cout<<n<<" ";
    printNumbersReverse(n-1);
}
void printnoddNumbers(int n)
{
if(n==0)
{return;}    
printnoddNumbers(n-1);
cout<<(2*n-1)<<" ";
}
void printnoddNumbersReverse(int n)
{
if(n==0)
{return;}    
cout<<(2*n-1)<<" ";
printnoddNumbersReverse(n-1);
}
void printnevenNumbers(int n)
{
if(n==0)
{return;}    
printnevenNumbers(n-1);
cout<<(2*n)<<" ";
}
void printnevenNumbersReverse(int n)
{
if(n==0)
{return;}    
cout<<(2*n)<<" ";
printnevenNumbersReverse(n-1);
}
void printSquares(int n)
{
    if(n==0)
    {
        return;
    }
    printSquares(n-1);
    cout<<(n*n)<<" ";
}
void printSquaresReverse(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<(n*n)<<" ";
    printSquaresReverse(n-1);
}
void printCubes(int n)
{
    if(n==0)
    {
        return;
    }
    printCubes(n-1);
    cout<<(n*n*n)<<" ";
}
void printCubesReverse(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<(n*n*n)<<" ";
    printCubesReverse(n-1);
}
int main()
{
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    cout<<endl;
    printCubesReverse(n);
    return 0;
}