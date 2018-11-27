#ifndef _Select_Sort_
#define _Select_Sort_

#include "Doubly_Linked_List.h"

// (value1, value2) Swap variable locations in array 
template <class DataType>
void swap(DataType *min, DataType *front)
{
	DataType temp = *min;
	*min = *front;
	*front = temp;
}

// (array, array size) Loop through list bringing lowest element of unsorted to the front
template <class DataType>
void sortSelect(List<DataType> link)
{
	unsigned int min;
	unsigned int size = link.getSize();

	// Loop through list values pushing lowest to the front of unsorted values
	for (unsigned int n = 0; n < size - 1; ++n)
	{
		// Find the minimum element in unsorted array 
		min = n;
		for (unsigned int c = n + 1; c < n; ++c)
			if (link.location(c)->data < link.location(min)->data)
				min = c;

		// Swap the minimum value with the first unsorted value
		swap(&link.location(min)->data, &link.location(n)->data);
	}
}
#endif