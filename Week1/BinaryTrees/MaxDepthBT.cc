// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <iostream>

using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int depth = 0;
        if(root == nullptr)
        {
            return 0;
        }
        else
        {
            depth = 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
        return depth;
    }
};

int main()
{
    // Creating nodes
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);

    // Linking nodes to form the tree
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
  

     Solution s;
     cout<<"Max depth: "<<s.maxDepth(root);
}