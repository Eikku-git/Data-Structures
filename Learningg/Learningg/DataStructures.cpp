#include <vector>
#include <iostream>
#include "Test.h"

class Object {
public:

	std::string hello = "Hello";

};

class OutOfRangeException : public std::exception {
public:
};

template <typename Type> 
class List {

public:

	List() {
		starter = new entry();
		nextptr = starter;
	}

	void Add(const Type& T) {
		nextptr->value = T;
		nextptr->pointer = new entry();
		nextptr = nextptr->pointer;
		numOfElements++;
	}

	void Clear() {
		delete starter;
	}

	int Count() {
		return this->numOfElements;
	}

	const Type& operator[] (int index) {	
		if (index >= numOfElements) {
			throw OutOfRangeException();
		}
		else if (index < 0) {
			throw OutOfRangeException();
		}
		entry* entry = starter;
		for (int i = 0; i != index; i++) {
			entry = entry->pointer;
		}
		return entry->value;
	}

	const Type& GetFirstEntry() {
		return nextptr->value;
	}

	~List() {
		delete starter;
	}

private:

	int numOfElements = 0;

	struct entry {

		Type value;
		entry* pointer = nullptr;

		~entry() {
			delete pointer;
			std::cout << "Deleted entry \n";
		}
	};

	entry* starter;
	entry* nextptr;
};

void lol() {
	List<Object> list;
	Object obj;
	obj.hello = "not Hello";
	Object obj2;
	obj2.hello = "Hi";
	list.Add(obj);
	list.Add(obj2);
	std::cout << list[0].hello;
	std::cout << list.Count();
}