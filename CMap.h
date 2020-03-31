#ifndef CMAP_H
#define CMAP_H

#define DEFAULT_DATA 0


template <class K, class D>
class NODE
{
	K key;
	D data;
public:
	NODE(NODE<K, D>* p, K tK, D tD) : prev(p), key(tK), data(tD), nGreater(nullptr), nLess(nullptr) {};
	~NODE() {};
	// Parent of current node
	NODE<K, D>* prev;
	// Down to the right
	NODE<K, D>* nGreater;
	// Down to the left
	NODE<K, D>* nLess;
	// For checking if a newNode->data is < this->data
	bool operator < (const NODE<K, D>& toCheck);
};
// CMap class that the user will interact with
template <class K, class D>
class CMap
{
public:
	CMap() : Root(nullptr) {};
	~CMap() {};

	D& operator[](const K& searchKey);

	//void(void(*find)())

private:
	NODE<K, D>* Root;

	NODE<K, D>* find(const K& toFin);
	void insert(NODE<K, D> toInesrt);

};
#endif // !CMAP_H

template<class K, class D>
inline D& CMap<K, D>::operator[](const K& searchKey)
{
	if (find(K))
	{

	}
}
