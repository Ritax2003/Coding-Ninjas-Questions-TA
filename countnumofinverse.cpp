#include <iostream>
#include <vector>
using namespace std;

int selectionSortAndSum(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            sum += minIndex - i;
            swap(arr[i], arr[minIndex]);
        }
    }
    return sum;
}

int main() {
    vector<int> nums = {17,5,14,16,11,18,10};
    cout << "Sum of differences in indices: " << selectionSortAndSum(nums) << endl;
    return 0;
}