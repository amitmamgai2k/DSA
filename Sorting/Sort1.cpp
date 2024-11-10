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

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function with menu-driven logic
int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Count Sort\n";
    cout << "2. Radix Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            countSort(arr, size);
            cout << "Array sorted using Count Sort: ";
            printArray(arr, size);
            break;

        case 2:
            radixSort(arr, size);
            cout << "Array sorted using Radix Sort: ";
            printArray(arr, size);
            break;

        default:
            cout << "Invalid choice! Please select 1 or 2." << endl;
            break;
    }

    return 0;
}
