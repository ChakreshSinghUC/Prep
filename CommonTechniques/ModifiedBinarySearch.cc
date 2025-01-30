/*
Modified Binary Search is a technique used to solve problems that require more than just finding an element in a sorted array. It involves modifying the standard binary search algorithm to handle various conditions and constraints.

Example Problem: Find the Rotation Count in a Rotated Sorted Array
Given a sorted array that has been rotated, find the index of the minimum element. The number of rotations is equal to the index of the minimum element.

*/

#include <iostream>
#include <vector>

using namespace std;

int findRotationCount(const vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        // If the array is already sorted, return the first element
        if (nums[low] <= nums[high])
        {
            return low;
        }

        int mid = low + (high - low) / 2;
        int next = (mid + 1) % nums.size();
        int prev = (mid - 1 + nums.size()) % nums.size();

        // Check if the mid element is the minimum element
        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev])
        {
            return mid;
        }

        // Decide whether to go to the left half or the right half
        if (nums[mid] <= nums[high])
        {
            high = mid - 1;
        }
        else if (nums[mid] >= nums[low])
        {
            low = mid + 1;
        }
    }

    return -1; // This should never be reached if the input array is valid
}

int main()
{
    vector<int> nums = {15, 18, 2, 3, 6, 12};
    int rotationCount = findRotationCount(nums);
    cout << "The array is rotated " << rotationCount << " times." << endl;
    return 0;
}