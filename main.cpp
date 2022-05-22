#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;


//Распечатка массива с консоль
void print(vector<int>& arr) {
	for (int i = 0; i < arr.size(); cout << arr[i++] << ' ');
	cout << endl;
}

//Сортировка пузырьком с флажком
void bubbleSortFlag(vector<int>& arr) {
	bool flag;
	for (int i = 0; i < arr.size(); ++i) {
		flag = true;
		for (int j = 0; j < arr.size() - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				flag = false;
			}
		}
		if (flag)
			return;
	}
}

int main(void) {
	vector<int> arr = {5,4,3,2,10,40};
	bubbleSortFlag(arr);
	print(arr);
}