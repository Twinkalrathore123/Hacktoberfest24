#include <iostream>
#include <vector>
#include <algorithm>

// Function to get the maximum element in the array
int getMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

// Counting sort based on the significant digit (exp)
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};

    // Count the occurrences of digits
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so it contains the actual position of this digit in output
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(std::vector<int>& arr) {
    int maxNum = getMax(arr);

    // Apply counting sort for each digit, increasing the place value (exp)
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    // Input: Array of integers
    std::vector<int> arr;
    int n, element;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> element;
        arr.push_back(element);
    }

    // Perform Radix Sort
    radixSort(arr);

    // Output: Sorted array
    std::cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
