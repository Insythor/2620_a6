#ifndef CSTACK_H
#define CSTACK_H

template <typename N> class CStack;

template <typename N>
class NODE
{
	friend class CStack<N>;
public:
	NODE(NODE<N>* p, N d) : prev(p), data(d), next(nullptr) {};
	~NODE() {};
private:
	N data;
	NODE<N>* prev;
	NODE<N>* next;
};

template <typename N>
class CStack
{
public:
	CStack() : HEAD(nullptr), TAIL(nullptr), stackSize(0) {};
	CStack(const CStack<N>& toCopy);
	~CStack() {};

	void operator = (const CStack<N>& toCopy);
	
	bool isEmpty();
	N top();
	void push(N toAdd);
	void pop();
	void empty();
	int size();

private:
	// Points to the first node
	NODE<N>* HEAD;
	// Points to the last node
	NODE<N>* TAIL;
	int stackSize;

};
#include "./CStack.cc"
#endif // !CSTACK_H

#include <iostream>

template<typename N>
inline CStack<N>::CStack(const CStack<N>& toCopy) : HEAD(nullptr), TAIL(nullptr), stackSize(0)
{
	NODE<N>* temp;
	if (toCopy.HEAD)
	{
		// Set current stack head & tail to new node with toCopy data
		HEAD = TAIL = new NODE<N>(nullptr, toCopy.HEAD->data);
		stackSize++;
		// temp pointer to move through toCopy stack
		temp = toCopy.HEAD;
		// While there are more nodes, keep moving forward
		while (temp->next)
		{
			temp = temp->next;
			TAIL = TAIL->next = new NODE<N>(TAIL, temp->data);
			stackSize++;
		}
	}
}

template<typename N>
inline void CStack<N>::operator=(const CStack<N>& toCopy)
{
	empty();
	NODE<N>* temp;
	if (toCopy.HEAD)
	{
		// Set current stack head & tail to new node with toCopy data
		HEAD = TAIL = new NODE<N>(nullptr, toCopy.HEAD->data);
		stackSize++;
		// temp pointer to move through toCopy stack
		temp = toCopy.HEAD;
		// While there are more nodes, keep moving forward
		while (temp->next)
		{
			temp = temp->next;
			TAIL = TAIL->next = new NODE<N>(TAIL, temp->data);
			stackSize++;
		}
	}
}

template<typename N>
inline bool CStack<N>::isEmpty()
{
	return stackSize == 0;
}

template<typename N>
inline N CStack<N>::top()
{
	return TAIL ? TAIL->data : 0;
}

template<typename N>
inline void CStack<N>::push(N toAdd)
{
	if (HEAD) 
		TAIL = TAIL->next = new NODE<N>(TAIL, toAdd);
	else
		HEAD = TAIL = new NODE<N>(nullptr, toAdd);
	stackSize++;
}

template<typename N>
inline void CStack<N>::pop()
{
	if (stackSize > 1)
	{
		TAIL = TAIL->prev;
		delete TAIL->next;
		stackSize--;
	}
	else if (stackSize == 1)
	{
		HEAD = TAIL;
		delete HEAD, TAIL;
		stackSize = 0;
	}
}

template<typename N>
inline void CStack<N>::empty()
{
	while (!isEmpty())
		pop();
}

template<typename N>
inline int CStack<N>::size()
{
	return stackSize;
}
