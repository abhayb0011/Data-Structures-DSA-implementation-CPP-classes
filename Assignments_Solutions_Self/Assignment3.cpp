#include <iostream>
using namespace std;
class DynArray
{
private:
	int capacity;
	int lastIndex;
	int* ptr;
	public:
	DynArray(int);
	DynArray(DynArray&);
	void doubleArray();
	void halfArray();
	int cap();
	bool isEmpty();
	void append(int);
	void insertElement(int,int);
	void editElement(int, int);
	void deleteElement(int);
	bool isFull();
	int getElement(int);
	int noOfElements();
	int findElement(int element);
	DynArray& operator=(DynArray&);
	~DynArray();
};
DynArray::DynArray(int size)
{
	capacity = size;
	ptr = new int[size];
	lastIndex = -1;
}
DynArray::DynArray(DynArray &D)
{
for(int i=0;i<D.noOfElements();i++)
		{
			append(D.getElement(i));
		}
}
void DynArray::doubleArray()
{
	capacity = 2 * capacity;
	int* temp = new int[capacity];
	for (int i = 0; i <= lastIndex; i++)
	{
		temp[i] = ptr[i];
	}
	delete []ptr;
	ptr = temp;
}
void DynArray::halfArray()
{
	capacity = capacity / 2;
	int* temp = new int[capacity];
	for (int i = 0; i <= lastIndex; i++)
	{
		temp[i] = ptr[i];
	}
	delete []ptr;
	ptr = temp;
}
int DynArray::cap()
{
	return capacity;
}
bool DynArray::isEmpty()
{
	return lastIndex == -1;
}
void DynArray::append(int element)
{
	if (lastIndex == capacity - 1)
	{
		doubleArray();
	}
	lastIndex++;
	ptr[lastIndex] = element;
}
void DynArray::insertElement(int index, int element)
{
	if (index > lastIndex + 1 || index<0)
		cout << endl << "Invalid Index";
	else if (index == lastIndex + 1)
	{
		if (lastIndex == capacity - 1)
		{
			doubleArray();
		}
		lastIndex++;
		ptr[lastIndex] = element;
	}
	else
	{
		for (int i = lastIndex; i >= index; i--)
		{
			ptr[i + 1] = ptr[i];
		}
		ptr[index] = element;
		lastIndex++;
	}
}
	void DynArray::editElement(int index, int element)
	{
		ptr[index] = element;
	}
	void DynArray::deleteElement(int index)
	{
		if (isEmpty())
			cout << endl << "Array is empty";
else if (index >= 0 && index <= lastIndex)
		{
			for (int i = index; i < lastIndex; i++)
			{
				ptr[i] = ptr[i + 1];
			}
			lastIndex--;
			if (lastIndex < (capacity / 2)  && capacity>1)
			{
				halfArray();
			}
		}
		else
			cout << endl << "invalid index";
	}
	bool DynArray::isFull()
	{
		return lastIndex == capacity - 1;
	}
	int DynArray::getElement(int index)
	{
		if (index >= 0 && index <= lastIndex)
		{
			return ptr[index];
		}
		else
			cout <<endl<< "Invalid index";
	}
	int DynArray::noOfElements()
	{
		return lastIndex + 1;
	}
	int DynArray::findElement(int element)
	{
		int flag = -1;
		for (int i = 0; i <= lastIndex; i++)
		{
			if (ptr[i] == element)
				flag = i;
				}
		return flag;
	}
	DynArray& DynArray::operator=(DynArray &D)
	{
		int k=0;
		while(!isEmpty())
		{
			deleteElement(k);
			k++;
		}
        for(int i=0;i<D.noOfElements();i++)
		{
			append(D.getElement(i));
		}
	}
	DynArray::~DynArray()
	{
		delete[]ptr;
	}
	






	
















