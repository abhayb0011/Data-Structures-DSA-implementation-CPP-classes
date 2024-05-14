#include <iostream>
using namespace std;
class Array
{
private:
	int capacity, lastIndex;
	int* ptr;
public:
	Array(int);
	Array(Array &);
	int getCapacity();
	bool array_empty_or_not();
	void append(int);
	void insertElement(int, int);
	void editElement(int, int);
	void deleteElement(int);
	bool check_Array_full_or_not();
	int getElement(int);
	int numberOfElements();
	int findElement(int);
	~Array();
};
int Array::getCapacity()
{
	return capacity;
}
Array::Array(Array &arr)
{
	capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new int[capacity];
	for(int i=0;i<=lastIndex;i++)
	ptr[i]=arr.ptr[i];
}
Array::Array(int size)
{
	capacity = size;
	lastIndex = -1;
	ptr = new int[size];
}
bool Array::array_empty_or_not()
{
	return lastIndex == -1;
}
void Array::append(int app)
{
	if (lastIndex == capacity - 1)
		cout << endl << "Array is full";
	else
	{
		lastIndex++;
		ptr[lastIndex] = app;
	}
}
void Array::insertElement(int index, int element)
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
void Array::editElement(int index, int element)
{
	if (index >= 0 && index <= lastIndex)
		ptr[index] = element;
	else
		cout << "Invalid index";
}
void Array::deleteElement(int index)
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
bool Array::check_Array_full_or_not()
{
	return lastIndex == capacity - 1;
}
int Array::getElement(int index)
{
	int element;
	if (index >= 0 && index <= lastIndex)
	{
		element = ptr[index];
		return element;
	}
	else
		cout << "Invalid index";
}
int Array::numberOfElements()
{
	return lastIndex + 1;
}
int Array::findElement(int element)
{
	int flag = -1;
	for (int i = 0; i < capacity; i++)
	{

		if (ptr[i] == element)
			flag = i;
	}
	return flag;

}
Array::~Array()
{
	delete[]ptr;
}
