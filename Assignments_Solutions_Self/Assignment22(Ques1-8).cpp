#include <iostream>
#include "Assignment9.cpp"
using namespace std;
void bubbleSort(int A[],int size) 
{
    int temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
        if(A[j]>A[j+1])
        {
        temp=A[j];
        A[j]=A[j+1];
        A[j+1]=temp;
        }
        }
    }
}
void modifiedBubbleSort(int A[],int size)
{
    int temp;
    int check=0;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
        if(A[j]>A[j+1])
        {
        temp=A[j];
        A[j]=A[j+1];
        A[j+1]=temp;
        check=1;
        }
        }
        if(check==0)
        {break;}
        check=0;
    }  
}
void insertionSort(int A[],int size)    //Method 1
{
    int temp,swap;
    for(int i=1;i<size;i++)
    {
    temp=A[i];
    for(int j=i-1;j>=0;j--)
    {
        if(temp<A[j])
        {
            swap=A[j+1];
            A[j+1]=A[j];
            A[j]=swap;
        }
    }
    }
}

/*void insertionSort(int A[],int size)        //Method 2
{
    int temp;
    for(int i=1;i<size;i++)
    {
        temp=A[i];
        for(int j=i-1;j>=0;j++)
        {
            if(temp<A[j])
            {
                A[j+1]=A[j];
            }
            else
            break;
        }
        A[j+1]=temp;
    }
}*/
void selectionSort(int A[],int size)
{
    int smallestIndex,swap;
    for(int i=0;i<size;i++)
    {
        smallestIndex=i;
        for(int j=i;j<size;j++)
        {
            if(A[j]<A[smallestIndex])
            {
                smallestIndex=j;
            }
        }
        swap=A[smallestIndex];
        A[smallestIndex]=A[i];
        A[i]=swap;
    }
}
int quick(int A[],int left,int right) //quick procedure to be used in quick sort algorithm
{
    int loc=left,t;
    while(left<right)
    {
        while(left<right && A[loc]<=A[right])
            right--;
        if(left==right)
            break;
        t=A[loc];
        A[loc]=A[right];
        A[right]=t;
        loc=right;
        while(left<right && A[left]<=A[loc])
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
void quickSort(int A[],int l,int u)  //Quicksort through recursion
{
    int loc;
    loc=quick(A,l,u);
    if(loc>l+1) //condition for checking if left sublist exists
        quickSort(A,l,loc-1);
    if(loc<u-1) //condition for checking if right sublist exists
        quickSort(A,loc+1,u);
}
void quickSortLoop(int A[],int l,int u)  //Quicksort through iteration
{
    int loc,i,j;
    Stack lower(u+1),upper(u+1);  //creating Stacks lower and upper of capacity u+1
    lower.push(l);
    upper.push(u);
    while(!lower.stackUnderflow())
    {
        i=lower.peek();
        j=upper.peek();
        loc=quick(A,i,j);
        lower.pop();
        upper.pop();
        if(loc>i+1)
        {
            lower.push(i);
            upper.push(loc-1);
        }
        if(loc<j-1)
        {
            lower.push(loc+1);
            upper.push(j);
        }
    }
}
void merge(int a[],int n1,int i1,int b[],int n2,int i2,int c[],int i3) //used in merge sort through iteration
{
    int i,j,k;
    for(i=0,j=0,k=0;i<n1&&j<n2;k++)
    {
        if(a[i+i1]<b[j+i2])
        {
            c[k+i3]=a[i+i1];
            i++;
        }
        else
        {
            c[k+i3]=b[j+i2];
            j++;
        }
    }
    while(i<n1)
    {
        c[k+i3]=a[i+i1];
        i++;
        k++;
    }
    while(j<n2)
    {
        c[k+i3]=b[j+i2];
        j++;
        k++;
    }
}
void mergepass(int SRC[],int size,int L,int DEST[]) //used in merge sort through iteration
{
    int j,mergeCount,index,R,S;
    mergeCount=size/(2*L);
    S=mergeCount*2*L;
    R=size-S;
    
    for(j=0;j<mergeCount;j++)
    {
        index=j*2*L;
        merge(SRC,L,index,SRC,L,index+L,DEST,index);
    }
    if(R<=L)
    {
        for(int i=0;i<R;i++)
            DEST[S+i]=SRC[S+i];
    }
    else
        merge(SRC,L,S,SRC,R-L,S+L,DEST,S);

}
void mergeSortIteration(int A[], int size) //merge sort through iteration
{
    int L=1,B[size];
    while(L<size)
    {
        mergepass(A,size,L,B);
        mergepass(B,size,2*L,A);
        L=L*4;
    }
}
void merging(int A[],int l,int m,int u) //used in merge sort through recursion
{
    int L[m-l+1],R[u-m],i,j,k;
    for(i=0;i<m-l+1;i++)
        L[i]=A[l+i];
    for(j=0;j<u-m;j++)
        R[j]=A[m+1+j];
    for(i=0,j=0,k=l;i<m-l+1 &&j<u-m;k++)
    {   //The elements of the arrays to be merged are compared so that the merged array is sorted  
        if(L[i]<R[j])   
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
    while(i<m-l+1)  //If the right array is exhausted and left array is there then the elements of the left array will be copied as it is
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<u-m)   //If the left array is exhausted and right array is there then the elements of the right array will be copied as it is
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int A[],int l,int u) //Merge sort through recursion
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

int main()
{
    int A[5]={5,6,9,3,1};
    selectionSort(A,5);
    cout<<"the elements of array in sorted order quick are:\n";
    for(int i=0;i<5;i++)
    {
    cout<<A[i]<<endl;
    } 
}