/*
The Two Heaps technique is a powerful method for solving problems that require finding the median of a stream of numbers or maintaining the balance between two parts of a dataset. This technique involves using two heaps: a max-heap to store the smaller half of the numbers and a min-heap to store the larger half.
Given a stream of numbers, design a data structure that supports adding a number and finding the median of all numbers added so far
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder
{
private:
    priority_queue<int> maxHeap;                            // Max-heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for the larger half

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else
        {
            return maxHeap.top();
        }
    }
};

int main()
{
    MedianFinder mf;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    for (int num : nums)
    {
        mf.addNum(num);
        cout << "Added " << num << ", current median: " << mf.findMedian() << endl;
    }

    return 0;
}