#ifndef _Select_Sort_
#define _Select_Sort_

#include "Doubly_Linked_List.h"

// (value1, value2) Swap variable locations in array 
template <class DataType>
void swap(DataType &min, DataType &front)
{
	DataType temp = min;
	min = front;
	front = temp;
}

// (array, array size) Loop through list bringing lowest element of unsorted to the front
template <class DataType>
void sortSelect(List<DataType> &link)
{
	auto min = link.getHead();
	unsigned int size = link.getSize();
	auto front = link.getHead();

	// Loop through list values pushing lowest to the front of unsorted values
	while (front->nextNode != nullptr)
	{
		// Find the minimum element in unsorted array 
		min = front; 
		auto current = front->nextNode;
		while (current != nullptr)
		{
			if (current->data < min->data)
				min = current;
			current = current->nextNode;
		}

		// Swap the minimum value with the first unsorted value
		swap(min->data, front->data);
		front = front->nextNode;
	}
}
#endif