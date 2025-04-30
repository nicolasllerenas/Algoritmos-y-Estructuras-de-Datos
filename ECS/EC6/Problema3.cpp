#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

class Solution {
private:
    int sum = 0;

    void reverseInOrder(TreeNode* node) {
        if (!node) return;
        reverseInOrder(node->right);
        sum += node->val;
        node->val = sum;
        reverseInOrder(node->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        reverseInOrder(root);
        return root;
    }
};

int main() {
    TreeNode* root = nullptr;
    int values[] = {5, 2, 13};
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Original BST: ";
    printInOrder(root);
    cout << endl;

    Solution sol;
    root = sol.convertBST(root);

    cout << "Greater Tree: ";
    printInOrder(root);
    cout << endl;

    return 0;
}