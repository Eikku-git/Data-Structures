#pragma once
#include <iostream>

namespace eik {

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

		void Insert(const Type& T, int index) {
			entry* insert = new entry();
			entry* atindex = findindex(index);
			entry* prev = atindex->previousptr;
			insert->previousptr = prev;
			atindex->previousptr = insert;
			insert->nextptr = atindex;
			insert->value = T;
			prev->nextptr = insert;
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
				std::cout << "Deleted entry" << "\n";
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
}