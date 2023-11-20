#include <iostream>
#include <vector>

// Function to heapify a subtree rooted at node i.
// n is the size of the heap.
template <typename T>
void heapify(std::vector<T>& arr, int n, int i) {
    int largest = i; // Initialize largest as the root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

template <typename T>
void heapSort(std::vector<T>& arr) {
    int n = arr.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]); // Move current root to the end
        heapify(arr, i, 0); // Call max heapify on the reduced heap
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }

    heapSort(arr);

    std::cout << "\nSorted array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}