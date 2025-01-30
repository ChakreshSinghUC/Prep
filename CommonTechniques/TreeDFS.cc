#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Preorder Traversal: Root -> Left -> Right
void preorderTraversal(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    result.push_back(root->val);
    preorderTraversal(root->left, result);
    preorderTraversal(root->right, result);
}

// Inorder Traversal: Left -> Root -> Right
void inorderTraversal(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

// Postorder Traversal: Left -> Right -> Root
void postorderTraversal(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->val);
}

void printTraversal(const vector<int> &traversal)
{
    for (int val : traversal)
    {
        cout << val << " ";
    }
    cout << endl;
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

    vector<int> preorderResult;
    preorderTraversal(root, preorderResult);
    cout << "Preorder traversal of the binary tree: ";
    printTraversal(preorderResult);

    vector<int> inorderResult;
    inorderTraversal(root, inorderResult);
    cout << "Inorder traversal of the binary tree: ";
    printTraversal(inorderResult);

    vector<int> postorderResult;
    postorderTraversal(root, postorderResult);
    cout << "Postorder traversal of the binary tree: ";
    printTraversal(postorderResult);

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