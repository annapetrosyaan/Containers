#include <iostream>

#include "QueueList.h"

bool QueueList::isEmpty()const
{
	return front==nullptr && end==nullptr;
}


bool QueueList::enqueue(int elem)
{
	Node* NodePtr = new Node();
	NodePtr->data = elem;
	NodePtr->ptr = nullptr;

	if (front==nullptr)
	{
		front = NodePtr;  //queue was empty
		end = NodePtr;
	}
	end->ptr = NodePtr;
	end = NodePtr;
	return true;
}


bool QueueList::dequeue()
{
	bool result = false;
	if(!isEmpty())
	{
		if (front == end)    //special case only one node in queue
		{
			front = nullptr;
			end = nullptr;
	   }
		else
		{
			Node* ToDelete = front;
			front = front->ptr;

		}
	result = true;
	}
	return result;
}

int QueueList::headOf()const
{
	if (!isEmpty())
	{
		return front->data;
	}
}

