// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
        {
            return {left + 1, right + 1}; // Return 1-based indices
        }
        else if (sum < target)
        {
            // Move the left pointer to the right as we need a bigger number to reach the target
            left++;
        }
        else
        {
            // Move the right pointer to the left as we need a smaller number to reach the target
            right--;
        }
    }

    return {}; // Return an empty vector if no solution is found
}

int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}