#include <iostream>
using namespace std;

// Radix Sort
void radixSort(int arr[], int size) {
    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    // Apply counting sort for every digit
    for (int pos = 1; maxElement / pos > 0; pos *= 10) {
        int output[size];
        int count[10] = {0};  // Count array for digits 0-9

        // Counting sort for the current digit
        for (int i = 0; i < size; i++) {
            int digit = (arr[i] / pos) % 10;
            count[digit]++;
        }
        // Update count array
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        // Build output array using count array
        for (int i = size - 1; i >= 0; i--) {
            int digit = (arr[i] / pos) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        // Copy output array to the original array
        for (int i = 0; i < size; i++) {
            arr[i] = output[i];
        }
    }
}
// Count Sort
void countSort(int arr[], int size) {
    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    int count[maxElement + 1] = {0};
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

void heapify(int arr[], int n, int i) {
    int left = 2 * i + 1;  // Left child (0-based index)
    int right = 2 * i + 2; // Right child (0-based index)
    int largest = i;
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    // If right child is larger than root
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);  // Recursively heapify the affected subtree
    }
}
// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a max heap (0-based indexing)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
// Bucket Sort
 void insertionSort(float bucket[], int size) {
    for (int i = 1; i < size; ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}
void bucketSort(float arr[], int n) {
    const int numBuckets = n;
    const int maxBucketSize = n;
    float b[numBuckets][maxBucketSize];
    int bucketSizes[numBuckets] = {0};

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = numBuckets * arr[i];
        b[bi][bucketSizes[bi]++] = arr[i];
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < numBuckets; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(b[i], bucketSizes[i]);
        }
    }
    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = b[i][j];
        }
    }
}
// Function to print the array of integers
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Function to print the array of floats
void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Main function with menu-driven logic
int main() {
    int size, choice;
    cout << "Choose Sorting Algorithm:\n";
    cout << "1. Count Sort\n";
    cout << "2. Radix Sort\n";
    cout << "3. Heap Sort\n";
    cout << "4. Bucket Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cout << "Enter the number of elements: ";
    cin >> size;
    if (choice == 4) {
        float arr[size];
        cout << "Enter the elements (float values): ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        bucketSort(arr, size);
        cout << "Array sorted using Bucket Sort: ";
        printArray(arr, size);
    } else {
        int arr[size];
        cout << "Enter the elements (integer values): ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        switch (choice) {
            case 1:
                countSort(arr, size);
                cout << "Array sorted using Count Sort: ";
                break;
            case 2:
                radixSort(arr, size);
                cout << "Array sorted using Radix Sort: ";
                break;
            case 3:
                heapSort(arr, size);
                cout << "Array sorted using Heap Sort: ";
                break;
            default:
                cout << "Invalid choice!" << endl;
                return 1;
        }
        printArray(arr, size);
    }
    return 0;
}
