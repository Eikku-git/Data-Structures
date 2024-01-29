#pragma once

#include <iostream>
#include <vector>

namespace eik {

	template <typename T>
	class DynArray {

	public:

		DynArray() {
			Alloc(2);
 		}

		const T& operator[] (int index) {

		}

	private:

		T[] m_Array;
		size_t m_Capacity;

		void Alloc(size_t capacity) {
			T* block = new T[capacity];
			m_Capacity = capacity;
		}
	};
}