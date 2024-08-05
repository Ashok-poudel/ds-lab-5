#include <iostream>
#include <vector>
#include <algorithm>

void swap(std::vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse(std::vector<int>& arr, int start) {
    int end = arr.size() - 1;
    while (start < end) {
        swap(arr, start, end);
        start++;
        end--;
    }
}

bool nextPermutation(std::vector<int>& arr) {
    int i = arr.size() - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    int j = arr.size() - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }
    swap(arr, i, j);
    reverse(arr, i + 1);
    return true;
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    std::sort(arr.begin(), arr.end());
    do {
        printArray(arr);
    } while (nextPermutation(arr));
    return 0;
}
