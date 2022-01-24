#ifndef _QUEUELIST_
#define _QUEUELIST_

#include "QueueImpl.h"

	struct Node
	{
		int data;
		Node* ptr;
	};


class QueueList:public QueueInterface
{
public:
	QueueList()=default;
	QueueList(const QueueList&)=default;
	~QueueList()=default;
public:
	bool isEmpty()const;
	int headOf()const;
	bool enqueue(int);
	bool dequeue();

private:
    Node* front = nullptr;
	Node* end = nullptr;
};

#endif // !_QUEUELIST_
