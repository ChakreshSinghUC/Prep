#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return result;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *currentNode = q.front();
            q.pop();
            currentLevel.push_back(currentNode->val);

            if (currentNode->left != NULL)
            {
                q.push(currentNode->left);
            }
            if (currentNode->right != NULL)
            {
                q.push(currentNode->right);
            }
        }

        result.push_back(currentLevel);
    }

    return result;
}

void printLevelOrder(const vector<vector<int>> &levels)
{
    for (const auto &level : levels)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrder(root);
    cout << "Level order traversal of the binary tree:" << endl;
    printLevelOrder(result);

    // Free the allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}