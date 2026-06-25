#include <iostream>
#include <vector>
using namespace std;

int binarySearchPos(std::vector<int>& arr, int key, int l, int h);

// Comparison sorts
// Merge Sort
// Divide from middle - Conquer - Combine
// T.C. = O(nlogn) , extra space required - Not the stack space but an extra array hence O(n)
// Hence not in-place algo but stable
void mergeAlgo(vector<int>& arr, int l, int h, int mid)
{
    // Merge Algo - 2 parts of an array, keep 2 pointers, comparison goes on, 
    // and whichever is smaller put it in a temp arr, in the end when everything is done, 
    // put rest of the elements in the tmp array
    // It sorts the given array
    int low = l; // starting pointer of 1st half
    int high = mid + 1; // starting pointer of 2nd half

    vector<int> tmp;

    while (low <= mid && high <= h)
    {
        if (arr[low] < arr[high]){
            tmp.push_back(arr[low]);
            low ++;
        }
        else if (arr[low] > arr[high]){
            tmp.push_back(arr[high]);
            high ++;
        }
    }

    while (low <= mid)
    {
        tmp.push_back(arr[low]);
        low ++;
    }

    while (high <= h)
    {
        tmp.push_back(arr[high]);
        high ++;
    }

    // reverse the order - tmp[0] = arr[l] , tmp[h-l] = arr[h]
    for (int i = l; i <= h; i++)
        arr[i] = tmp [i-l];
}

void mergeSort(vector<int>& arr, int l, int h)
{
    if (l >= h)
        return;

    int mid = (l + h) / 2;
    mergeSort(arr, l, mid); // lower half // T(n/2)
    mergeSort(arr, mid+1, h); // upper half // T(n/2)
    mergeAlgo(arr, l, h, mid); // n , so total theta(nlogn)
}

// Quick Sort
// Divide acc to partition ele's pos
// T.C. - Best case O(nlogn) , Worst - O(n^2)
int partitionAlgo(vector<int>& arr, int l, int h)
{
    // Pick first / last / mid / median element as pivot
    // Take 2 counters, initialize it, while i < pivot, keep eles as it is, but i++, let's say you found one ele in the shorter side > than pivot;  
    // go to the next block now while j > pivot, keep ele as it is, but j-- , now if you found j's ele
    // swap i & j -> do all these 3 until i <= j, 
    // after that swap j with pivot, now you have a list when left of pivot is small, right of pivot is bigger
    int pivot = arr[l];
    int i = l+1;
    int j = h;
    
    while(i <= j)
    {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;
        
        if (i <= j)
        {
            i++;
            j--;
            std::swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int l, int h)
{
    if (l >= h)
        return;

    int partitionPos = partitionAlgo(arr, l, h);
    quickSort(arr, l, partitionPos);
    quickSort(arr, partitionPos + 1, h);
}

// Bubble Sort
// Side by side comparison
// T.C. = Best case : O(n) , Worst / Avg case : O(n^2)
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swapped = true;
                std::swap(arr[j], arr[j+1]);
            }
        }
        if (swapped == false)
            break;
    }
}

// Insertion Sort
// one side is already sorted, take ele from another half, search where to put by doing comparison, 
// then make space for it by doing passes, hence for n elements n search + n swap = O(n^2)
void insertionSort(vector<int>& arr)
{
    // Initialize, declare a temp value
    // if temp < array's element, continue swapping, decrement counter, cause in that pass I am going to compare till I find the smallest
    // once I find next element is smaller, I can't swap anymore, in the vaccum I put the tmp I was carrying
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int tmp = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>tmp)
        {
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = tmp;
    }
}

// Binary insertion
// T.C. = n * (log n + n) ~ n^2
void binaryInsertionSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i=1; i<n; i++)
    {
        int tmp = arr[i];
        int j = i-1;
        int pos = binarySearchPos(arr, tmp, 0, j); // O(log n)
        while (j>=pos) // O(n)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
    }
}

// Selection

// Radix

// Heap