// Binary search
// Algo - Sorted array [pre req], keep dividing, and choose one half and again keep on dividing to find the element
// Time complexity - theta(log n) , O(1)
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int key)
{
    // Non-recursive
    int l = 1;
    int n = arr.size();
    int h = n;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == arr[mid])
            return mid; // Base condition
        else if (key < arr[mid])
            h = mid - 1; // lower half
        else 
            l = mid + 1; // upper half
    }
    return 0; // No element found
}

int recBinarySearch(vector<int>& arr, int key, int l, int h)
{
    //Recursive
    if (l > h)
        return -1; // Not found case
    
    int mid = (l + h) / 2;
    if (arr[mid] == key)// Base condition
        return mid;
    if (key < arr[mid])
        return recBinarySearch(arr, key, l, mid - 1); // lower half    
    return recBinarySearch(arr, key, mid + 1, h);// upper half
}

// Used for Binary insertion sort
int binarySearchPos(vector<int>& arr, int key, int l, int h) {
    if (l > h) return l; // insertion position
    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid + 1; // insert after equal elements (stable)
    if (key < arr[mid])
        return binarySearchPos(arr, key, l, mid - 1);
    return binarySearchPos(arr, key, mid + 1, h);
}
