// Separate chaining resolves collisions

#include "HashedDictionary.h"
#include <cmath>    // For sqrt
#include <iostream> // For testing
#include <unordered_map>
#include <stdexcept>

//////////////////////////////////////////////////////////////////////
// Private helper methods
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::destroyDictionary()
{
   for (int i = 0; i < hashTableSize; i++)
   {
      // If there are hashed entries at this location,
      // we need to delete them
      while (hashTable[i] != nullptr)
      {
         hashTable[i] = hashTable[i]->getNext();
      }  // end while
   }  // end for
   
   itemCount = 0;
}  // end destroyDictionary

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& key) const
{
	
	// STEP 2
	return key% hashTableSize;
} // end getHashIndex

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNextPrime(int number) const
{
   bool foundPrime = false;
   if ((number % 2) == 0)
      number++;
   
   while (!foundPrime)
   {
      if ((number % 5 == 0) || !isPrime(number))
      {
         number = number + 2;
      }
      else
         foundPrime = true;
   }  // end
   
   return number;
}  // end getNextPrime

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isPrime(int number) const
{
   bool isPrimeNumber = true;                 // Assume prime, prove otherwise
   
   if ((number == 2) || (number == 3))        // Smallest primes
      isPrimeNumber = true;
   else
   {
      if ((number % 2 == 0) || (number < 2))  // Even number or ineligible
         isPrimeNumber = false;
      else
      {
         int root = sqrt(number);             // Limit of search
         int i = 3;
         do
         {
           if (number % i == 0)               // Not prime
              isPrimeNumber = false;
            else
               i = i + 2;

         } while ((isPrimeNumber == true) && (i <= root));
      }  // end if
   }  // endif
   
   return isPrimeNumber;
}  // end isPrime

//////////////////////////////////////////////////////////////////////
// Constructors & Destructor
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
:itemCount(0), hashTableSize(DEFAULT_CAPACITY)
{
   // All shared pointers in array initialized to nullptr & reference count zero
   hashTable = std::make_unique<hashTableType<KeyType, ItemType>>(DEFAULT_CAPACITY);
}  // end

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(int maxNumberOfEntries)
:itemCount(0)
{
   hashTableSize = getNextPrime(maxNumberOfEntries);

   // All shared pointers in array initialized to nullptr & reference count zero
   hashTable = std::make_unique<hashTableType<KeyType, ItemType>>(hashTableSize);
}  // end

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(const
                                                    HashedDictionary<KeyType, ItemType>& dict)
                  :itemCount(dict.itemCount),  hashTableSize(dict.hashTableSize)
{
   hashTable = std::make_unique<hashTableType<KeyType, ItemType>>(dict.maxItems);
   for (auto index : indices(dict.itemCount))
   {
      hashTable[index] = dict.hashTable[index];
   }  // end for
}  // end 

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary()
{
   destroyDictionary();
} // end destructor

////////////////////////////////////////////////////////////////////
// Status and public maintenance (clear) methods
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const
{
   return (itemCount == 0);
} // end isEmpty

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const
{
   return itemCount;
} // end getNumberOfItems
template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear()
{
   destroyDictionary();
} // end clear

///////////////////////////////////////////////////////////////////
// Container methods (add, remove, getItem, contains, traverse)
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
   
   // STEP 3
	auto hashPtr = std::make_shared<HashedEntry<KeyType, ItemType>>(searchKey,newItem);

	int	i = getHashIndex(searchKey);
	if (hashTable[i] == nullptr)
	{
		hashTable[i] = hashPtr;
	}
	else
	{
		hashPtr->setNext(hashTable[i]);
		hashTable[i] = hashPtr;
	}
	return true;
} // end add

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType& searchKey)
{
	//STEP 4
	int i = getHashIndex(searchKey);
	if (hashTable[i] != nullptr)
	{

		if (hashTable[i]->getKey()==searchKey)
		{
			hashTable[i] = hashTable[i]->getNext();
			return true;
		}
		else
		{
			auto travPtr = hashTable[i];
			while (travPtr->getNext()->getKey() != searchKey)
			{
				travPtr= travPtr->getNext();
			}
			auto curPtr = travPtr->getNext();
			auto prevPtr = travPtr;
			prevPtr->setNext(curPtr->getNext());
			return true;
		}
	}
	else
	{
		return false;
	}
} // end remove

template <class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const
{
   
   // STEP 5
	int i = getHashIndex(searchKey);
	if (hashTable[i] != nullptr)
	{
		auto travPtr = hashTable[i];
		while (travPtr->getKey() != searchKey && travPtr != nullptr)
		{
			travPtr = travPtr->getNext();
		}
		if (travPtr == nullptr)
		{
			throw std::logic_error("Item not found.");
		}
		return travPtr->getItem();
	}
	else
	{
		throw std::logic_error("Item not found.");
	}
} // end getItem

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const
{
	int i = getHashIndex(searchKey);
	if (hashTable[i] != nullptr)
	{
		auto travPtr = hashTable[i];
		while (travPtr->getKey() != searchKey && travPtr != nullptr)
		{
			travPtr = travPtr->getNext();
		}
		if (travPtr == nullptr)
		{
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
   // STEP 6
   
} // end contains

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{
	
   // STEP 7
	for (int i = 0; i < hashTableSize;i++)
	{
		if (hashTable[i] != nullptr)
		{
			ItemType travPtr = hashTable[i]->getItem();
			visit(travPtr);
			while (hashTable[i]->getNext() != nullptr)
			{
				hashTable[i] = hashTable[i]->getNext();
			}
		}
	}
}  //end traverse
