#include<iostream>
#include<string.h>
using namespace std;
class Employee
{
    private:
        int emp_id;
        char name[20];
        float salary;
    public:
        void setEmpid(int id) { emp_id=id;}
        void setName(char n[]) { strcpy(name,n);}
        void setSalary(float s) { salary=s;}
        int getEmpid(){return emp_id;}
        char* getName() {return name;}
        float getSalary(){return salary;}

};
void merging(Employee A[],int l,int m,int u)
{
    Employee L[m-l+1],R[u-m];
    int i,j,k;
    for(i=0;i<m-l+1;i++)
        L[i]=A[l+i];
    for(j=0;j<u-m;j++)
        R[j]=A[m+1+j];
    for(i=0,j=0,k=l;i<m-l+1 &&j<u-m;k++)
    {
        if(L[i].getSalary()<R[j].getSalary())
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
    while(i<m-l+1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<u-m)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(Employee A[],int l,int u)
{
    int m;
    if(l<u)
    {
        m=(l+u)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,u);
        merging(A,l,m,u);
    }
}
void setEmployee(Employee &e,int id,char n[],float s)
{
    e.setEmpid(id);
    e.setName(n);
    e.setSalary(s);
}
void showEmployee(Employee e)
{
    cout<<endl;
    cout<<e.getEmpid()<<"  "<<e.getName()<<"  "<<e.getSalary();
}
void sortBySalary(Employee e[],int size)
{
    mergeSort(e,0,size-1);
}

int quick(Employee A[],int left,int right)
{
    int loc=left;
    Employee t;
    while(left<right)
    {
        while(left<right && (strcmp(A[loc].getName(),A[right].getName())<=0))
            right--;
        if(left==right)
            break;
        t=A[loc];
        A[loc]=A[right];
        A[right]=t;
        loc=right;
        while(left<right && (strcmp(A[left].getName(),A[loc].getName())<=0))
            left++;
        if(left==right)
            break;
        t=A[left];
        A[left]=A[loc];
        A[loc]=t;
        loc=left;
    }
    return loc;
}
void quickSort(Employee A[],int l,int u)
{
    int loc;
    loc=quick(A,l,u);
    if(loc>l+1)
        quickSort(A,l,loc-1);
    if(loc<u-1)
        quickSort(A,loc+1,u);
}



void sortByName(Employee e[],int size)
{
    quickSort(e,0,size-1);
}
int main()
{
    Employee e[10];
    setEmployee(e[0],1,"Rahul",30000);
    setEmployee(e[1],2,"Dilip",40000);
    setEmployee(e[2],3,"Gajendra",50000);
    setEmployee(e[3],4,"Anjan",10000);
    setEmployee(e[4],5,"Hitesh",20000);
    setEmployee(e[5],6,"Rajesh",25000);
    setEmployee(e[6],7,"Jay",70000);
    setEmployee(e[7],8,"Jitendra",50000);
    setEmployee(e[8],9,"Sandeep",35000);
    setEmployee(e[9],10,"Aalok",5000);
    sortBySalary(e,10);
    for(int i=0;i<=9;i++)
        showEmployee(e[i]);
    cout<<endl;
    sortByName(e,10);
    for(int i=0;i<=9;i++)
        showEmployee(e[i]);
    cout<<endl;
    return 0;
}