#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int key);
int recBinarySearch(vector<int>& arr, int key, int l, int h);

void mergeSort(vector<int>& arr, int l, int h);
void quickSort(vector<int>& arr, int l, int h);
void bubbleSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void binaryInsertionSort(vector<int>& arr);


int main()
{
    vector<int> arr = {2, 5, 9, 11, 19, 23, 45, 78, 90};
    int pos1 = binarySearch(arr, 90);
    std::cout<< "Position: " << pos1 << " " << "Element: " << arr[pos1] << "\n";

    int pos2 = recBinarySearch(arr, 5, 0, arr.size()-1);
    std::cout<< "Position: " << pos2 << " " << "Element: " << arr[pos2] << "\n";

    vector<int> arr1 = {5, 7, 2, 9, 189, 45, 67, 23, 51};
    mergeSort(arr1, 0, arr1.size()-1);
    std::cout<< "Array after merge sort: " << "\n";
    for (int i: arr1)
        std::cout << i <<", ";
    std::cout<<'\n';

    vector<int> arr2 = {5, 7, 2, 9, 189, 45, 67, 23, 51};
    quickSort(arr2, 0, arr2.size()-1);
    std::cout<< "Array after quick sort: " << "\n";
    for (int i: arr2)
        std::cout << i <<", ";
    std::cout<<'\n';

    vector<int> arr3 = {5, 7, 2, 9, 189, 45, 67, 23, 51};
    bubbleSort(arr3);
    std::cout<< "Array after bubble sort: " << "\n";
    for (int i: arr3)
        std::cout << i <<", ";
    std::cout<<'\n';

    vector<int> arr4 = {5, 7, 2, 9, 189, 45, 67, 23, 51};
    insertionSort(arr4);
    std::cout<< "Array after insertion sort: " << "\n";
    for (int i: arr4)
        std::cout << i <<", ";
    std::cout<<'\n';

    vector<int> arr5 = {5, 7, 2, 9, 189, 45, 67, 23, 51};
    binaryInsertionSort(arr5);
    std::cout<< "Array after binary insertion sort: " << "\n";
    for (int i: arr5)
        std::cout << i <<", ";
}