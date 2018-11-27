#ifndef _Linked_List_
#define _Linked_List_

//Doubly Linked List class which uses a template to allow the List to be used with any datatype
template <class DataType>
class List
{
private:
	//Node Structure
	struct Node
	{
		DataType data;
		Node* prevNode;
		Node* nextNode;
	};
public:
	//Constructor
	List()
	{
		//Set the last node in the linked list
		tail = nullptr;
		//Set the first node in the linked list
		head = nullptr;
		//Set size
		size = 0;
	}
	//Destructor
	~List()
	{
		Node* current = head;
		//Loop through all nodes and delete
		while (current != nullptr) 
		{
			Node* next = current->nextNode;
			delete current;
			current = next;
		}
	}

	//Create next node in list that points to its previous node
	void createNode(DataType iData)
	{
		//Set start and end Node if it has no connecting node
		if (head == nullptr && tail == nullptr)
		{
			head = new Node{ iData, nullptr, nullptr };
			tail = head;
		}
		else
		{
			//Create the new node after the tail node and set it as the tail.
			tail->nextNode = new Node{ iData, tail, nullptr };
			//Set the new tail node;
			tail = tail->nextNode;
		}
		++size;
	}
	//Insert Node inside desired location of list
	void insert(unsigned int iter, DataType iData)
	{
		unsigned int n = 0;
		Node* current = head;
		while (current != nullptr)
		{
			//Create node at end if given number is out of scope
			if (current->nextNode == nullptr && iter != n) createNode(iData);
			//Add Node in desired location
			if (iter == n)
			{
				//Save previous node
				Node* prev = current->prevNode;
				//Put new node at currents position pushing current forward
				current->prevNode = new Node{ iData, prev, current};
				//Set previous nodes next to new node
				prev->nextNode = current->prevNode;
				++size;
				return;
			}
			current = current->nextNode;
			++n;
		}
	}
	//Remove Node at desired position
	void remove(unsigned int iter)
	{
		if (head != nullptr)
		{
			unsigned int n = 0;
			Node* current = head;
			//Loop through until node location is met
			while (current != nullptr)
			{
				if (iter == n)
				{
					//Set link between previous and next node
					if (current->prevNode != nullptr) current->prevNode->nextNode = current->nextNode;
					if (current->nextNode != nullptr) current->nextNode->prevNode = current->prevNode;
					//Set head if removal is head
					if (current == head)
					{
						head = current->nextNode;
					}
					//Set tail if removal is tail
					if (current == tail)
					{
						tail = current->prevNode;
					}
					//delete node
					delete current;
					return;
				}
				current = current->nextNode;
				++n;
			}
		}
		return;
	}
	//Delete passed node
	void remove(Node* iNode)
	{
		if (iNode != nullptr)
		{
			//Set link between previous and next node
			if (iNode->prevNode != nullptr) iNode->prevNode->nextNode = iNode->nextNode;
			if (iNode->nextNode != nullptr) iNode->nextNode->prevNode = iNode->prevNode;
			//Set head if removal is head
			if (iNode == head)
			{
				head = iNode->nextNode;
			}
			//Set tail if remvoal is tail
			if (iNode == tail)
			{
				tail = iNode->prevNode;
			}
			//Remove node
			delete iNode;
			--size;
		}
		return;
	}
	//Delete last node
	void remove()
	{
		//Node going to be purged
		Node* purge = tail;

		if (head == nullptr) return;
		if (tail == head)
		{
			tail = nullptr;
			head = nullptr;
		}
		else
		{
			//Set node before tail's next node to null
			tail->prevNode->nextNode = nullptr;
			//Set previous node to tail the tail
			tail = tail->prevNode;
		}
		//Remove the previous tail
		delete purge;
		--size;
		return;
	}
	//Find first node in the list that has the desired data
	Node* find(DataType iData)
	{
		Node* current = head;
		while (true)
		{
			if (current == nullptr) return nullptr;
			if (iData == current->data) return current;
			current = current->nextNode;
		}
	}
	//Return minimum valued node
	Node* min()
	{
		Node* min = head;
		Node* current = head;
		while (head != nullptr)
		{
			if (current->data < min->data) min = current;
			if (current->nextNode == nullptr) return min;
			current = current->nextNode;
		}
	}
	//Return maximum valued node
	Node* max()
	{
		Node* max = head;
		Node* current = head;
		while (head != nullptr)
		{
			if (current == nullptr) return max;
			if (current->data > max->data) max = current;
			current = current->nextNode;
		}
	}
	//Display node at location
	Node* location(int loc)
	{
		if (head != nullptr)
		{
			unsigned int n = 0;
			Node* current = head;
			//Loop through until node location is met
			while (current != nullptr)
			{
				if (loc == n)
				{
					return current;
				}
				current = current->nextNode;
				++n;
			}
		}
		return nullptr;
	}

	//Set the variables to the passed argument: setters
	void setHead(Node* iHead)
	{
		head = iHead;
	}
	void setTail(Node* iTail)
	{
		tail = iTail;
	}

	//return the variables from the class: getters
	Node* getHead()
	{
		return head;
	}
	Node* getTail()
	{
		return tail;
	}
	unsigned int getSize()
	{
		return size;
	}

private:
	//Class variables
	Node* head;
	Node* tail;
	unsigned int size;

};
#endif