#include <iostream>
#include <string>
#include "HashedDictionary.h"

void display(std::string& anItem);
void dictionaryTest(HashedDictionary<int, std::string>* testDictionary);


int main()
{
	HashedDictionary<int, std::string>* dict1 = new HashedDictionary<int, std::string>();

	std::cout << "===========================" << std::endl
		<< "Testing HashedDictionary" << std::endl
		<< "===========================" << std::endl;
	dictionaryTest(dict1);

	std::cin.ignore();
	std::cin.get();

	return 0;
}  // end main

void display(std::string& anItem)
{
	std::cout << "Displaying item - " << anItem << std::endl;
}  // end display


void dictionaryTest(HashedDictionary<int, std::string>* testDictionary)
{
	testDictionary->add(15, "F");
	testDictionary->add(16, "G");
	testDictionary->add(13, "D");
	testDictionary->add(17, "H");
	testDictionary->add(12, "C");
	testDictionary->add(14, "E");
	testDictionary->add(10, "A");
	testDictionary->add(11, "B");
	testDictionary->add(18, "I");
	testDictionary->add(19, "J");
	testDictionary->add(20, "K");
	testDictionary->add(21, "L");

	std::cout << "Traversing data items in sorted search-key order:\n";
	testDictionary->traverse(display);

	testDictionary->remove(10);
	testDictionary->remove(13);
	testDictionary->remove(17);

	std::cout << "\nAfter Removing 10/A, 13/D & 17/H, traverse data items in sorted search-key order:\n";
	testDictionary->traverse(display);

	std::cout << "\nTrying to remove 13/D again\n";
	if (testDictionary->remove(13))
		std::cout << "Removed second 13 :-(\n\n";
	else
		std::cout << "Could not remove second 13 :-)\n\n";

	std::cout << "Getting key/item 11/B: " << testDictionary->getItem(11) << std::endl;

	std::cout << "Getting key/item 16/G: " << testDictionary->getItem(16) << std::endl;

	std::cout << "Getting key/item 14/E: " << testDictionary->getItem(14) << std::endl;

	std::cout << "Contains key/item 17/H: " << testDictionary->contains(17) << std::endl;

	std::cout << "Contains key/item 00/??: " << testDictionary->contains(00) << std::endl;

	testDictionary->clear();

	std::cout << "\nTrying to traverse after clear\n";
	testDictionary->traverse(display);
	std::cout << "If nothing displayed, that is good!\n";

	if (testDictionary->remove(11))
		std::cout << "Removed 20 from an empty dictionary :-(\n\n";
	else
		std::cout << "Could not remove 11 from an empty dictionary :-)\n\n";
}  // end dictionaryTest1
