#include "Assignment1.cpp"
class ExtendedArray :public Array
{
public:
	ExtendedArray(int);
	void sort();
	int greatestElement();
	int smallestElement();
	int search(int element);
	int sumElements();
	int average();
	void rotateArray();
	void duplicateElements();
	int secondLargestElement();
	void swapElements(int, int);


};
ExtendedArray::ExtendedArray(int capacity) :Array(capacity)
{

}
void ExtendedArray::sort()
{
	int flag = 1;
	if (array_empty_or_not() == 0)
	{
		int temp;
		while (flag > 0)
		{
			flag = 0;
			for (int i = 0; i <= numberOfElements() - 2; i++)
			{

				if (getElement(i) < getElement(i + 1))
				{
					temp = getElement(i);
					editElement(i, getElement(i + 1));
					editElement(i + 1, temp);
					flag = 1;
				}
			}
		}
	}
	else
		cout << "Array is empty";
}
//bubble sort logic see of sir that is better solution of the above sort function //
int ExtendedArray::greatestElement()
{
	int max;
	if (array_empty_or_not() == 0)
	{
		max = getElement(0);
		for (int i = 1; i <= numberOfElements() - 1; i++)
		{
			if (getElement(i) > max)
			{
				max = getElement(i);
			}
		}
		return max;
	}
	else
	{
		cout << "Array is empty";
		return -1;
	}
}
int ExtendedArray::smallestElement()
{
	int min;
	if (array_empty_or_not() == 0)
	{
		min = getElement(0);
		for (int i = 1; i <= numberOfElements() - 1; i++)
		{
			if (min < getElement(i))
			{
				min = getElement(i);
			}
		}
		return min;
	}
	else
	{
		cout << "Array is empty";
		return -1;
	}
}
int ExtendedArray::search(int element)
{
	int flag = 0;
	if (array_empty_or_not() == 0)
	{
		for (int i = 0; i <= numberOfElements() - 1; i++)
		{
			if (getElement(i) == element)
			{
				return i;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "Element not found";
			return -1;
		}
	}
	else
		cout << "Array is empty";
	return -1;
}
int ExtendedArray::sumElements()
{
	if (array_empty_or_not() == 0)
	{
		int sum = 0;
		for (int i = 0; i <= numberOfElements() - 1; i++)
		{
			sum = sum + getElement(i);
		}
		return sum;
	}
	else
	{
		cout << "Array is empty";
		return -1;
	}
}
int ExtendedArray::average()
{
	if (array_empty_or_not() == 0)
	{
		int avg;
		avg = sumElements() / (numberOfElements());
		return avg;
	}
	else
	{
		cout << "Array is empty";
		return -1;
	}
}
void ExtendedArray::rotateArray()
{
	if (array_empty_or_not() == 0)
	{
		int temp,temp1;
		temp = getElement(0);
		editElement(0, getElement(numberOfElements() - 1));
		for (int i = 1; i <= numberOfElements() - 1; i++)
		{
			temp1 = getElement(i);
			editElement(i, temp);
			temp = temp1;
		}
	}
	else
	{
		cout << "Array is empty";
		}

}
void ExtendedArray::duplicateElements()
{
	if (array_empty_or_not() == 0)
	{
		for (int i = 0; i <= numberOfElements() - 1; i++)
		{
			for (int j = i + 1; i <= numberOfElements() - 1; j++)
			{
				if (getElement(i) == getElement(j))
				{
					deleteElement(j);
					j--; //DO NOT FORGET THIS//
				}
			}
		}
	}
	else
	{
		cout << "Array is empty";
	}
}
int ExtendedArray::secondLargestElement()
{
	if (array_empty_or_not() == 0)
	{
		int max1 = greatestElement();
		int max2;
		if (getElement(0) == greatestElement())   /*We have to ensure that max2 is not equal to max1 otherwise
														   following for loop will never exexute and value of max1 will be
														   displayed instead of max2
														   (max1=greatest element of array,
														   max2=second greatest element of array)*/
		{
			max2 = getElement(1);
		}
		else
		{
			max2 = getElement(0);
		}
		for (int i = 0; i <= numberOfElements() - 1; i++)
		{
			if (max1 > getElement(i) && max2 < getElement(i))
			{
				max2 = getElement(i);
			}
		}
		return max2;
	}
	else
	{
		cout << "Array is empty";
		return -1;
	}
}//Alternative approach of second largest element is bubble sort loop two times run then second largest element will be second last //
void ExtendedArray::swapElements(int i1, int i2)
{
	if (array_empty_or_not() == 0)
	{
		int temp;
		temp = getElement(i1);
		editElement(i1, getElement(i2));
		editElement(i2, temp);
	}
	else
	{
		cout << "Array is empty";
	}
}



