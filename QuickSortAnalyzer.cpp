#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisonCount = 0; // Global variable to count comparisons
int swapCount = 0; // Global variable to count swaps

int partition(int arr[], int start, int end) {
    // Partition the array
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        comparisonCount++;
        if (arr[i] <= pivot)
            count++;
    }
    
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    swapCount++;
    
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
            comparisonCount++;
        }
        while (arr[j] > pivot) {
            j--;
            comparisonCount++;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
            swapCount++;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
    // Base case
    if (start >= end)
        return;
    // Partitioning the array
    int p = partition(arr, start, end);
    // Sorting the left part
    quickSort(arr, start, p - 1);
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    cout<<"Part 1: Random array (average case)"<<endl;
    int size;
    cout << "Enter the array size number: ";
    cin >> size;
    //generate the random number array.
    int Rand[size];
    srand(time(nullptr)); // Seed for random number generation
    for (int r = 0; r < size; r++)
        Rand[r] = rand() % 1000; // Random numbers between 0 and 999

    cout << "\nOriginal Random Array:\n";
    printArray(Rand, size);

    //sort the average array
    quickSort(Rand, 0, size - 1);

    cout << "Sorted Array (average case):\n";
    printArray(Rand, size);
    cout << "Comparisons: " << comparisonCount << endl;
    cout << "Swaps: " << swapCount << endl;

    cout<<"\nPart 2: selected numbers array(worst case)";
    // Hard-coded array (worst case)
    int worstcaseArr[] = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int worstcaseSize = sizeof(worstcaseArr) / sizeof(worstcaseArr[0]);

    cout << "\nSelected Array Elements:\n";
    printArray(worstcaseArr, worstcaseSize);

    // Sorting worst case array using split sort
    comparisonCount = 0;
    swapCount = 0;
    quickSort(worstcaseArr, 0, worstcaseSize - 1);
    cout << "Sorted selected Array(worst case):\n";
    printArray(worstcaseArr, worstcaseSize);
    cout << "Comparisons: " << comparisonCount << endl;
    cout << "Swaps: " << swapCount << endl;

    return 0;
}
