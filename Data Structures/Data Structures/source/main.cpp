#include "List.h"
#include <iostream>

int main() {
	eik::List<int> intList;
	intList.Add(3);
	intList.Add(2);
	intList.Add(5);
	intList.Insert(7, 2);
	intList.RemoveAt(1);
	std::cout << intList[0] + intList[1] << "\n";
	return 0;
}