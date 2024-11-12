#include <iostream>
using namespace std;
// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left; // left subarray starting index
    int j = mid + 1; // right subarray starting index
    int k = 0;
    // Merge the two subarrays into temp[]
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    // Copy any remaining elements of the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    // Copy any remaining elements of the right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    // Copy the sorted subarray back into the original array
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}
// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
// Partition function for Quick Sort
int partition(int arr[], int startIndex, int endIndex) {
    int pivot = arr[endIndex];
    int pivotIndex = startIndex;
    for (int i = startIndex; i < endIndex; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(arr[pivotIndex], arr[endIndex]);
    return pivotIndex;
}
// Quick Sort function
void quicksort(int arr[], int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int pivotIndex = partition(arr, startIndex, endIndex);
        quicksort(arr, startIndex, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, endIndex);
    }
}
// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int size, choice;
    cout << "Enter the size of your array: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " Elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    // Menu for sorting choice
    cout << "\nChoose sorting method:\n";
    cout << "1. Merge Sort\n";
    cout << "2. Quick Sort\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "\nPerforming Merge Sort...\n";
            mergeSort(arr, 0, size - 1);
            cout << "Sorted Array (Merge Sort): ";
            displayArray(arr, size);
            break;
        case 2:
            cout << "\nPerforming Quick Sort...\n";
            quicksort(arr, 0, size - 1);
            cout << "Sorted Array (Quick Sort): ";
            displayArray(arr, size);
            break;
        default:
            cout << "Invalid choice! Please enter 1 or 2.\n";
            break;
    }
    return 0;
}
