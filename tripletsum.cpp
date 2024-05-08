#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> findTriplets(int *arr, int n, int X) {
    std::vector<std::vector<int>> triplets;
    // Sort the array
    std::sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == X) {
                triplets.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;
            } else if (sum < X) {
                left++;
            } else {
                right--;
            }
        }
    }

    return triplets;
}

int main() {
    int arr[] = {1, 2, 3, 4, 7, 5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 12;

    std::vector<std::vector<int>> triplets = findTriplets(arr, n, X);

    if (triplets.empty()) {
        std::cout << "No triplet found with sum " << X << std::endl;
    } else {
        std::cout << "Triplets with sum " << X << " are:" << std::endl;
        for (const auto &triplet : triplets) {
            std::cout << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << std::endl;
        }
    }

    return 0;
}
