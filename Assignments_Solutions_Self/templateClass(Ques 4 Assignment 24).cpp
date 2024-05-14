#include <iostream>
using namespace std;
template <typename X>
class Array
{
private:
	int capacity, lastIndex;
	X* ptr;
public:
	Array(int);
	Array(Array &);
	int getCapacity();
	bool array_empty_or_not();
	void append(X);
	void insertElement(int, X);
	void editElement(int, X);
	void deleteElement(int);
	bool check_Array_full_or_not();
	X getElement(int);
	int numberOfElements();
	int findElement(X);
	~Array();
};
template <typename X> int Array<X>::getCapacity()
{
	return capacity;
}
template <typename X> Array<X>::Array(Array &arr)
{
	capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new int[capacity];
	for(int i=0;i<=lastIndex;i++)
	ptr[i]=arr.ptr[i];
}
template <typename X>Array<X>::Array(int size)
{
	capacity = size;
	lastIndex = -1;
	ptr = new X[size];
}
template <typename X> bool Array<X>::array_empty_or_not()
{
	return lastIndex == -1;
}
template <typename X> void Array<X>::append(X app)
{
	if (lastIndex == capacity - 1)
		cout << endl << "Array is full";
	else
	{
		lastIndex++;
		ptr[lastIndex] = app;
	}
}
template <typename X> void Array<X>::insertElement(int index, X element)
{
	if (lastIndex == capacity - 1)
		cout << "Array is full";
	else if (index<0 || index>lastIndex + 1)
	{
		cout << "Invalid Index";
	}
	else
	{
		for (int i = lastIndex; i > index; i--)
		{
			ptr[i + 1] = ptr[i];
		}
		ptr[index] = element;
	}
	lastIndex++;
}
template <typename X> void Array<X>::editElement(int index, X element)
{
	if (index >= 0 && index <= lastIndex)
		ptr[index] = element;
	else
		cout << "Invalid index";
}
template <typename X> void Array<X>::deleteElement(int index)
{
	if (lastIndex == -1)
		cout << "Array is empty";
	else if (index > lastIndex)
		cout << "Invalid Index";
	else
	{
		for (int i = index; i < lastIndex; i++)
		{
			ptr[i] = ptr[i + 1];
		}
		lastIndex--;
	}
}
template <typename X> bool Array<X>::check_Array_full_or_not()
{
	return lastIndex == capacity - 1;
}
template <typename X> X Array<X>::getElement(int index)
{
	X element;
	if (index >= 0 && index <= lastIndex)
	{
		element = ptr[index];
		return element;
	}
	else
		cout << "Invalid index";
}
template <typename X> int Array<X>::numberOfElements()
{
	return lastIndex + 1;
}
template <typename X> int Array<X>::findElement(X element)
{
	int flag = -1;
	for (int i = 0; i < capacity; i++)
	{

		if (ptr[i] == element)
			flag = i;
	}
	return flag;

}
template <typename X> Array<X>::~Array()
{
	delete[]ptr;
}
int main()
{
    Array <double> arr(10);
    arr.append(1.2);
    arr.append(5.8);
    arr.append(6.4);
    arr.append(4.9);
    arr.append(9);
    arr.append(6.0);
    for(int i=0;i<6;i++)
    cout<<" "<<arr.getElement(i);
    return 0;
}