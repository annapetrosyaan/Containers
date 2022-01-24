#ifndef _QUEUEIMPL_
#define _QUEUEIMPL_


class QueueInterface
{
public:
	QueueInterface() = default;
	virtual ~QueueInterface() = default;
public:
	virtual bool enqueue(int)=0;
	virtual bool dequeue()=0;
	virtual int headOf()const=0;
	virtual bool isEmpty()const=0;
};

#endif //_QUEUEIMPL_
