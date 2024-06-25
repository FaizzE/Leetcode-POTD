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

class Solution {
public:
    void solve(TreeNode* root, int &sum) {
        if (!root) {
            return;
        }

        solve(root->right, sum); // Process right subtree
        
        sum += root->val; // Update the sum with the current node's value
        root->val = sum; // Update the current node's value to the sum
        
        solve(root->left, sum); // Process left subtree
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};

// Utility function to print the inorder traversal of the tree
void inorder(TreeNode* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Construct the tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2, nullptr, new TreeNode(3));
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7, nullptr, new TreeNode(8));

    // Print the original tree (inorder)
    cout << "Original tree (inorder): ";
    inorder(root);
    cout << endl;

    // Transform the BST to GST
    Solution solution;
    TreeNode* newRoot = solution.bstToGst(root);

    // Print the transformed tree (inorder)
    cout << "Transformed tree (inorder): ";
    inorder(newRoot);
    cout << endl;

    return 0;
}
