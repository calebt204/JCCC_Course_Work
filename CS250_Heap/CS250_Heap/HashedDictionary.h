#ifndef HASHED_DICTIONARY_
#define HASHED_DICTIONARY_

#include "HashedEntry.h"
#include <memory>

template <class KeyType, class ItemType>
using hashTableType = std::shared_ptr<HashedEntry<KeyType, ItemType>>[];

template <class KeyType, class ItemType>
class HashedDictionary
{
private:
	// creates a unique pointer to an array of shared HashedEntry pointers
	std::unique_ptr<hashTableType<KeyType, ItemType>> hashTable;  // Array of pointers to entries
	int itemCount;                               // Count of dictionary entries
	int hashTableSize;                           // Table size must be prime
	static const int DEFAULT_CAPACITY = 101;

	void destroyDictionary();
	int getHashIndex(const KeyType& itemKey) const;
	int getNextPrime(int number) const;
	bool isPrime(int number) const;

public:
	HashedDictionary();
	HashedDictionary(int maxNumberOfEntries);
	HashedDictionary(const HashedDictionary<KeyType, ItemType>& dict);

	virtual ~HashedDictionary();

	bool isEmpty() const;
	int getNumberOfItems() const;
	void clear();
	bool add(const KeyType& itemKey, const ItemType& newItem);
	bool remove(const KeyType& itemKey);
	ItemType getItem(const KeyType& itemKey) const;
	bool contains(const KeyType& itemKey) const;
	void traverse(void visit(ItemType&)) const;
}; // end HashedDictionary

#include "HashedDictionary.cpp"
#endif
