#include <iostream> 
#include <vector> 
using namespace std; 

// ==================== Searching ==================== 
int binarySearch(vector<int>& arr, int key); 
int recBinarySearch(vector<int>& arr, int key, int l, int h); 
int binarySearchPos(vector<int>& arr, int key, int l, int h); 

// ==================== Sorting ==================== 
void mergeSort(vector<int>& arr, int l, int h); 
void quickSort(vector<int>& arr, int l, int h); 
void bubbleSort(vector<int>& arr); 
void insertionSort(vector<int>& arr); 
void binaryInsertionSort(vector<int>& arr); 
void selectionSort(vector<int>& arr); 

// ==================== Utility ==================== 
void printArray(const vector<int>& arr) 
{ 
    for (int x : arr) 
        cout << x << " "; 
    cout << endl; 
} 

int main() 
{ 
    cout << "========== SEARCHING ==========\n"; 
    vector<int> searchArr = {10, 20, 30, 40, 50, 60, 70}; 
    cout << "Array: "; 
    printArray(searchArr); 
    int key = 40; 

    // Iterative Binary Search 
    int result = binarySearch(searchArr, key); 
    cout << "Iterative Binary Search (" << key << "): " << result << endl; 

    // Recursive Binary Search 
    result = recBinarySearch( searchArr, key, 0, searchArr.size() - 1 ); 
    cout << "Recursive Binary Search (" << key << "): " << result << endl; 

    // Binary Search Position 
    int insertionPos = binarySearchPos( searchArr, 35, 0, searchArr.size() - 1 ); 
    cout << "Insertion position for 35: " << insertionPos << endl; 


    cout << "\n========== SORTING ==========\n"; 

    // ---------------- Merge Sort ---------------- 
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90}; 
    cout << "\nMerge Sort\n"; cout << "Before: "; 
    printArray(arr1); 
    mergeSort(arr1, 0, arr1.size() - 1); 
    cout << "After: "; 
    printArray(arr1); 

    // ---------------- Quick Sort ---------------- 
    vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90}; 
    cout << "\nQuick Sort\n"; 
    cout << "Before: "; 
    printArray(arr2); 
    quickSort(arr2, 0, arr2.size() - 1); 
    cout << "After: "; 
    printArray(arr2); 

    // ---------------- Bubble Sort ---------------- 
    vector<int> arr3 = {64, 34, 25, 12, 22, 11, 90}; 
    cout << "\nBubble Sort\n"; 
    cout << "Before: "; 
    printArray(arr3); 
    bubbleSort(arr3); 
    cout << "After: "; 
    printArray(arr3); 

    // ---------------- Insertion Sort ---------------- 
    vector<int> arr4 = {64, 34, 25, 12, 22, 11, 90}; 
    cout << "\nInsertion Sort\n"; 
    cout << "Before: "; 
    printArray(arr4); 
    insertionSort(arr4); 
    cout << "After: "; 
    printArray(arr4); 

    // ---------------- Binary Insertion Sort ---------------- 
    vector<int> arr5 = {64, 34, 25, 12, 22, 11, 90}; 
    cout << "\nBinary Insertion Sort\n"; 
    cout << "Before: "; 
    printArray(arr5); 
    binaryInsertionSort(arr5); 
    cout << "After: "; 
    printArray(arr5); 

    // ---------------- Selection Sort ---------------- 
    vector<int> arr6 = {64, 34, 25, 12, 22, 11, 90}; 
    cout << "\nSelection Sort\n"; 
    cout << "Before: "; 
    printArray(arr6); 
    selectionSort(arr6); 
    cout << "After: "; 
    printArray(arr6); 
    return 0; 
}