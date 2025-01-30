// https://leetcode.com/problems/validate-binary-search-tree/description/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBST(TreeNode *root, long minVal, long maxVal)
    {
        if (!root)
        {
            return true;
        }
        if (root->val <= minVal || root->val >= maxVal)
        {
            return false;
        }
        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << "Is valid BST: " << s.isValidBST(root) << endl;
    return 0;
}