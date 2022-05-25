#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include "merge.h"
#include <ctime>
using namespace std;




//Сортировка пузырьком с флажком
static void bubbleSortFlag(vector<int>& arr) {
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



static void BucketSort(vector<int>& data) {
    if (data.size() <= 1)
        return;

    int count = data.size();
    int maxValue = data[0]; 
    for (int i = 1; i < count; i++)
        if (data[i] > maxValue) //Поиск максимального элемента в массиве
            maxValue = data[i];
 
    

    int bucketLength = maxValue/10 + 1;
    //int bucketLength = maxValue - minValue + 1; При таком количестве блоков сортировка преобразуется в count sort
    

    vector<int>* buckets = new vector<int>[bucketLength];

    for (int i = 0; i < bucketLength; i++) //Инициализация блоков
        buckets[i] = vector<int>();
    

    for (int i = 0; i < count; i++) // Заполнение блоков
        buckets[data[i] / 10].push_back(data[i]);
        //bucket[data[i] - minValue].push_back(data[i]); если подсчётом
    

    int k = 0;
    for (int i = 0; i < bucketLength; i++) 
    {
        int bucketSize = buckets[i].size();
        MergeSort(buckets[i], 0, buckets[i].size() - 1); //Сортировка блоков

        for (int j = 0; j < bucketSize; j++)
        {
            data[k] = buckets[i][j];
            k++;
        }

    }


}


//Распечатка массива с консоль
void print(vector<int>& arr) {
    for (int i = 0; i < arr.size(); cout << arr[i++] << ' ');
    cout << endl;
}

void random_generator(vector<int>& arr, int count) {
    for (int i = 0; i < count; ++i)
        arr.push_back(rand() % 5000);
}



// N - количество элементов в массиве
void test(void sorting(vector<int>&), int NumberOfTests, int N) {
    unsigned int startTime, endTime, searchTime;
    vector<int> v;


    for (int i = 0; i < NumberOfTests; ++i) {
        random_generator(v, N);
        cout << "I started!" << endl;

        startTime = clock();
        sorting(v);
        endTime = clock();

        searchTime = endTime - startTime;
        cout << N << ": " << searchTime <<  "|" << endl;
        v.clear();


    }
}

int main(void) {
    

    test(bubbleSortFlag, 10, 10000);
    
    
}

