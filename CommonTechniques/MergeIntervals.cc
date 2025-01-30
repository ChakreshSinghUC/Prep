/*
Merging intervals is a common problem where you are given a collection of intervals, and you need to merge all overlapping intervals.

Example Problem: Merge Intervals
Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Merge Intervals Solution
Here is a C++ implementation to merge overlapping intervals:
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    if (intervals.empty())
    {
        return {};
    }

    // Sort the intervals based on the start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        // If the current interval overlaps with the last merged interval, merge them
        if (intervals[i][0] <= merged.back()[1])
        {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
        else
        {
            // Otherwise, add the current interval to the merged list
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

void printIntervals(const vector<vector<int>> &intervals)
{
    for (const auto &interval : intervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "Original intervals: ";
    printIntervals(intervals);

    vector<vector<int>> mergedIntervals = mergeIntervals(intervals);

    cout << "Merged intervals: ";
    printIntervals(mergedIntervals);

    return 0;
}