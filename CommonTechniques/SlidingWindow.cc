/*
The Sliding Window technique is a powerful method for solving problems that involve finding a subarray or substring that meets certain criteria. It is particularly useful for problems involving contiguous subarrays or substrings.

Example Problem: Maximum Sum Subarray of Size K
Given an array of integers and a number K, find the maximum sum of a subarray of size K.

Sliding Window Solution
Here is a C++ implementation to find the maximum sum of a subarray of size K using the Sliding Window technique:

}
Explanation:
Initialization: The function maxSumSubarrayOfSizeK takes a vector of integers nums and an integer K as input and returns the maximum sum of a subarray of size K.
Sliding Window: Initialize maxSum to the smallest possible integer, windowSum to 0, and windowStart to 0.
Expand Window: Use a for loop to iterate through the array, expanding the window by adding the current element to windowSum.
Check Window Size: If the window size is equal to K (windowEnd >= K - 1), update maxSum with the maximum of maxSum and windowSum.
Slide Window: Subtract the element going out of the window (nums[windowStart]) from windowSum and increment windowStart to slide the window ahead.
Return Result: Return maxSum, which contains the maximum sum of a subarray of size K.
Example Output:
9
Explanation of Sliding Window:
Expand Window: Add elements to the window until the window size reaches K.
Check and Slide: Once the window size is K, update the maximum sum and slide the window by removing the element going out of the window and adding the next element.
Time Complexity:
Time Complexity: O(n), where n is the number of elements in the array. Each element is added and removed from the window exactly once.
Space Complexity:
Space Complexity: O(1), as the algorithm uses a fixed amount of extra space.
Other Applications of Sliding Window:
Longest Substring Without Repeating Characters:

Find the length of the longest substring without repeating characters in a given string.
Smallest Subarray with a Given Sum:

Find the length of the smallest contiguous subarray whose sum is greater than or equal to a given number.
Maximum Sum of Subarray of Size K:

Find the maximum sum of any contiguous subarray of size K.
Example Code for Longest Substring Without Repeating Characters:
}
Explanation:
Initialization: The function lengthOfLongestSubstring takes a string s as input and returns the length of the longest substring without repeating characters.
Sliding Window: Use an unordered map charIndexMap to store the last index of each character. Initialize maxLength to 0 and windowStart to 0.
Expand Window: Use a for loop to iterate through
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSumSubarrayOfSizeK(const vector<int> &nums, int K)
{
    int maxSum = INT_MIN;
    int windowSum = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++)
    {
        windowSum += nums[windowEnd]; // Add the next element to the window

        // Slide the window if we've hit the required window size of K
        if (windowEnd >= K - 1)
        {
            maxSum = max(maxSum, windowSum); // Update the maximum sum
            windowSum -= nums[windowStart];  // Subtract the element going out of the window
            windowStart++;                   // Slide the window ahead
        }
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int K = 3;
    int result = maxSumSubarrayOfSizeK(nums, K);
    cout << "Maximum sum of a subarray of size " << K << " is: " << result << endl;
    return 0;
}