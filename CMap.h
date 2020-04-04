#ifndef CMAP_H
#define CMAP_H

#define DEFAULT_DATA 0

// I/O
#include <iostream>

template<class K, class D> class CMap;

template <class K, class D>
class NODE
{
	friend class CMap<K, D>;
	K key;
	D data;
public:
	NODE(NODE<K, D>* p, K tK, D tD) : prev(p), key(tK), data(tD), nGreater(nullptr), nLess(nullptr) {};
	virtual ~NODE() { if (nGreater) delete nGreater; if (nLess) delete nLess; };
	// Parent of current node
	NODE<K, D>* prev;
	// Down to the right
	NODE<K, D>* nGreater;
	// Down to the left
	NODE<K, D>* nLess;
	// For checking if a newNode->data is < this->data
	bool operator < (const K& toCheck) { return key < toCheck; };
};
// CMap class that the user will interact with
template <class K, class D>
class CMap
{
public:
	CMap() : Root(nullptr) {};
	~CMap() { delete Root; };

	D& operator[](const K& searchKey);

	//void(void(*find)())

private:
	NODE<K, D>* Root;
	NODE<K, D>* find(const K& toFind);
	void insert(NODE<K, D> toInesrt);

};
#include "./CMap.cc"
#endif // !CMAP_H

template<class K, class D>
inline D& CMap<K, D>::operator[](const K& searchKey)
{
	NODE<K, D>* tempNode = find(searchKey);
	if (tempNode)
	{
		return tempNode->data;
	}
	tempNode = new NODE<K, D>(nullptr, searchKey, DEFAULT_DATA);
	Root = tempNode;
	return Root->data;
}

template<class K, class D>
inline NODE<K, D>* CMap<K, D>::find(const K& toFind)
{
	// If the root of the map is null, don't search the map
	if (!Root) return Root;

	NODE<K, D>* tempNode = Root;

//	std::cout << "TempNode Data: " << tempNode->data << std::endl;

	while (tempNode->key != toFind)
	{
		// If the current nodes data is less than the searched key
		// move the pointer to the next less node (down left)
		if (tempNode->key < toFind && tempNode->nLess)
		{
			tempNode = tempNode->nLess;
		}
		// if the tempNode is >= the searched key
		// set the tempNode* to the next greater node (down right)
		else if (tempNode->nGreater)
		{
			tempNode = tempNode->nGreater;
		}
		// If both of the next nodes are nullptr's
		// return the current node
		else if (!tempNode->nGreater && !tempNode->nLess)
		{
			tempNode->nGreater = new NODE<K, D>(tempNode, toFind, DEFAULT_DATA);
			tempNode = tempNode->nGreater;
	//		std::cout << "new node in find" << std::endl;
			return tempNode;
		}
		else if (tempNode->key == toFind)
			break;
	}
	return tempNode;
}