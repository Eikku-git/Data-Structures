#include <vector>
#include <iostream>
#include "Test.h"

class Object {
public:

	std::string hello = "Hello";

};

template <typename Type> 
class List {

public:

	List() {
		starter = new entry();
		latestentry = starter;
	}

	void Add(const Type& T) {
		latestentry->value = T;
		entry* next = new entry();
		latestentry->nextptr = next;
		next->previousptr = latestentry;
		latestentry = latestentry->nextptr;
		numOfElements++;
	}


	void RemoveAt(int index) {
		entry* item = findindex(index);
		entry* previous = item->previousptr;
		previous->nextptr = item->nextptr;
		item->nextptr = NULL;
		delete item;
	}

	int Count() {
		return this->numOfElements;
	}

	void Clear() {
		delete starter;
	}

	const Type& operator[] (int index) {
		return findindex(index)->value;
	}

	const Type& GetFirstEntry() {
		return latestentry->value;
	}

	~List() {
		delete starter;
	}

private:

	int numOfElements = 0;

	struct entry {

		Type value;
		entry* nextptr;
		entry* previousptr;

		~entry() {
			delete nextptr;
			std::cout << "Deleted entry \n";
		}
	};

	entry* starter;
	entry* latestentry;

	inline entry* findindex(int index) {
		entry* entry = starter;
		for (int i = 0; i != index; i++) {
			entry = entry->nextptr;
		}
		return entry;
	}
};

void lol() {
	List<Object> list;
	Object obj;
	obj.hello = "not Hello";
	Object obj2;
	obj2.hello = "Hi";
	list.Add(obj);
	list.Add(obj2);
	std::cout << list[list.Count() - 1].hello << "\n";
	list.RemoveAt(1);
}