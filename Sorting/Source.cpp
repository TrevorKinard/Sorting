#include "Merge.h"
#include "Selection.h"
#include "Doubly_Linked_List.h"
#include <iostream>

void autoTest();

void main()
{
	autoTest();
}

void autoTest()
{
	//Selection Sort
	List<int> test1 = List<int>();
	test1.createNode(64);
	test1.createNode(25);
	test1.createNode(12);
	test1.createNode(22);
	test1.createNode(11);

	sortSelect(test1);
	std::cout << "Sorted array: \n";
	for (unsigned int c = 0; test1.location(c) != nullptr; c++)
	{
		std::cout << test1.location(c)->data << " -> ";
	}

	//Merge sort
	List<int> test2 = List<int>();
	test2.createNode(64);
	test2.createNode(25);
	test2.createNode(12);
	test2.createNode(22);
	test2.createNode(11);

	sortMerge(test2);
	std::cout << "Sorted array: \n";
	for (unsigned int c = 0; test2.location(c) != nullptr; c++)
	{
		std::cout << test2.location(c)->data << " -> ";
	}

	system("pause");
}