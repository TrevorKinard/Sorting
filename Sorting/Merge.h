#ifndef _Merge_Sort_
#define _Merge_Sort_

#include "Doubly_Linked_List.h"

// (array, segment 1 begin, segment 2 begin, segment 2 end) Sort and merge two arrays
template <class DataType>
void merge(List<DataType> &link, unsigned int begin, unsigned int center, unsigned int end)
{
	//segment 1 index, segment 2 index, combined index
	unsigned int i1 = 0, i2 = 0, iC = begin;
	unsigned int size1 = center - begin + 1;
	unsigned int size2 = end - center;

	//Temp lists
	List<DataType> beginTemp, endTemp;

	// Duplicate data into temp arrays
	for (unsigned int c = 0; c < size1; ++c)
		beginTemp.createNode(link.location(begin+c)->data);
	for (unsigned int c = 0; c < size2; ++c)
		endTemp.createNode(link.location(center+1+c)->data);

	//Merge segment 1 and segment 2
	while (i1 < size1 && i2 < size2)
	{
		if (beginTemp.location(i1)->data <= endTemp.location(i2)->data)
		{
			link.location(iC)->data = beginTemp.location(i1)->data;
			++i1;
		}
		else
		{
			link.location(iC)->data = endTemp.location(i2)->data;
			++i2;
		}
		++iC;
	}
}

// (array, begin range, end range) Sort segments of array
template <class DataType>
void sortMerge(List<DataType> &link, unsigned int begin, unsigned int end)
{
	if (begin < end)
	{
		unsigned int center = begin + (end - begin) / 2;

		// Sort first and second halves 
		sortMerge(link, begin, center);
		sortMerge(link, center + 1, end);

		merge(link, begin, center, end);
	}
}

// (array, size) initialize merge sort of an array
template <class DataType>
void sortMerge(List<DataType> &link)
{
	unsigned int size = link.getSize();

	if (size > 1)
	{
		unsigned int center = size / 2;

		// Sort first and second halves 
		sortMerge(link, 0, center);
		sortMerge(link, center + 1, size - 1);

		merge(link, 0, center, size - 1);
	}
}
#endif