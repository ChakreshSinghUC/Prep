// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        unordered_map<int, vector<int> > tree;
        for (int i = 0; i < n; ++i)
        {
            if (manager[i] != -1)
            {
                tree[manager[i]].push_back(i);
            }
        }
        return dfs(headID, tree, informTime);
    }

private:
    int dfs(int curr, unordered_map<int, vector<int> > &tree, vector<int> &informTime)
    {
        int maxTime = 0;
        for (int subordinate : tree[curr])
        {
            maxTime = max(maxTime, dfs(subordinate, tree, informTime));
        }
        return informTime[curr] + maxTime;
    }
};

int main()
{
    Solution s;
    vector<int> manager = {2, 2, -1, 2, 2, 2};
    vector<int> informTime = {0, 0, 1, 0, 0, 0};
    cout << "Time to inform all employees: " << s.numOfMinutes(6, 2, manager, informTime) << endl;
    return 0;
}
