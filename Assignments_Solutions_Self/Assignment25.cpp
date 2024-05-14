#include <iostream>
#include <array>
using namespace std;
class Complex
{
    private:
    int a,b;
    public:
    void setData(int x,int y)
    {
        a=x;
        b=y;
    }
    void displayData()
    {
        if(b<0)
            cout<<a<<"-i"<<(-b);
        else
            cout<<a<<"+i"<<b;
    }
    int getReal()
    {
        return a;
    }
    int getImaginary()
    {
        return b;
    }
};
int main()
{
   //Question 1
    array <int,5> a1={1,2,3,4,5};
    array <int,5>::reverse_iterator it1;
    for(it1=a1.rbegin();it1!=a1.rend();it1++)
        cout<<*it1<<" ";
    cout<<endl;
    
    //Question 2
    float sum=0,avg;
    array <float,5> a2={1.1,2.3,6.78,9.83,9.31};
    array <float,5>::iterator it2;
    for(it2=a2.begin();it2!=a2.end();it2++)
        sum=sum+(*it2);  
    avg=sum/(5.0);
    cout<<"The average of the given values is "<<avg<<endl;

    //Question 3
    int max;
    array <int,10> a3;
    array <int,10>::iterator it3;
    cout<<"Enter the array elements"<<endl;
    for(it3=a3.begin();it3!=a3.end();it3++)
    {    
        cin>>*it3;
    }
    it3=a3.begin();
    max=*it3;
    for(it3=a3.begin();it3!=a3.end();it3++)
    {
        if(max<(*it3))
            max=*it3;
    }
    cout<<"The maximum value of the array is "<<max<<endl;

    //Question 4
    int count=1,x,y;
    array <Complex,5> a4;
    array <Complex,5>::iterator it4;
    for(it4=a4.begin();it4!=a4.end();it4++)
    {
        cout<<"Enter the real part and imaginary part of complex number "<<count<<endl;
        cin>>x>>y;
        it4->setData(x,y);
        count++;
    }
    cout<<endl;
    for(it4=a4.begin();it4!=a4.end();it4++)
    {
        it4->displayData();
        cout<<" ";
    }
    //To calculate sum of complex numbers
    int sumReal=0,sumImaginary=0;
    for(int i=0;i<a4.size();i++)
    {
        sumReal=sumReal+a4[i].getReal();
        sumImaginary=sumImaginary+a4[i].getImaginary();
    }
    Complex sumComplex;
    sumComplex.setData(sumReal,sumImaginary);
    cout<<"The sum of complex numbers is ";
    sumComplex.displayData();

    //Question 5
    int temp;
    array <int,10> a5{10,9,8,7,6,5,4,3,2,1};
    for(int i=0;i<a5.size()-1;i++)
    {
        for(int j=0;j<a5.size()-i-1;j++)
        {
            if(a5[j+1]<a5[j])
            {
                temp=a5[j+1];
                a5[j+1]=a5[j];
                a5[j]=temp;
            }
        }
    }
    cout<<"The sorted array is: "<<endl;
    for(int x:a5)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}