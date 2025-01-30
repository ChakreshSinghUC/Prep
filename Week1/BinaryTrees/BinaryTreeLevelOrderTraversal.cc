// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <iostream>

using namespace std;

/* Definition for a binary tree node. */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution{
    public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> currentLevel;
            for(int i = 0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();
                currentLevel.push_back(current->val);
                if(current->left != nullptr){
                    q.push(current->left);
                }
                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};

int main()
{}
