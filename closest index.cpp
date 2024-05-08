#include<bits/stdc+++.h>
#include <iostream>
#include <vector>
#include <cmath>
//first approach
int closestElementIndex(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Found exact match
        } else if (nums[mid] < target) {
            left = mid + 1; // Adjust left boundary
        } else {
            right = mid - 1; // Adjust right boundary
        }
    }

    // At this point, left > right, so the closest element is either nums[right] or nums[left]
    if (right < 0) {
        return left; // target is smaller than all elements in nums
    } else if (left >= nums.size()) {
        return right; // target is larger than all elements in nums
    } else {
        // Check which element is closer to target
        return (abs(nums[right] - target) <= abs(nums[left] - target)) ? right : left;
    }
}
//second approach
int binarySearchClosest(int arr[], int left, int right, int target){
    //Write your code here
    int size = right+1;
    sort(arr,arr+size);
    while (left < right){
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    if (arr[right] - target > target - arr[left]){
        return right;
    }
    return left;
}
int main() {
    std::vector<int> nums = {1, 3, 7, 9, 11, 12, 45};
    int target = 4;

    int closestIndex = closestElementIndex(nums, target);
    std::cout << "Index of closest element to " << target << ": " << closestIndex << std::endl;

    return 0;
}
