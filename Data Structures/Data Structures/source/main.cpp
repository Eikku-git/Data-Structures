#include "List.h"
#include <iostream>
#include <string>
#include <algorithm>

void quickSort(int arr[], int start, int end);

int main() {
	//eik::List<int> intList;
	//intList.Add(3);
	//intList.Add(2);
	//intList.Add(5);
	//intList.Insert(7, 2);
	//intList.RemoveAt(1);
	//std::cout << intList[0] + intList[1] << "\n";
	int arr[5] = { 85, 745, 2345, 234, 540 };
	quickSort(arr, 0, 5);
	std::string str;
	for (int i = 0; i < 4; i++) {
		str += std::to_string(arr[i]) + ", ";
	}
	str += std::to_string(arr[4]);
	std::cout << str << "\n";
	return 0;
}

int partition(int arr[], int start, int end) {
	int i = start;
	for (int j = start; j < end; j++) {
		if (arr[j] < arr[end - 1]) {
			std::swap(arr[i], arr[j]);
			i++;
		}
	}
	std::swap(arr[i], arr[end - 1]);
	return i;
}

void quickSort(int arr[], int start, int end) {
	if (start >= end || start < 0) {
		return;
	}
	int p = partition(arr, start, end);
	quickSort(arr, start, p);
	quickSort(arr, p + 1, end);
}

