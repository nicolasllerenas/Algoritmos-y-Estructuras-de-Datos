#include <iostream>
using namespace std;


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
    int checkHeight(TreeNode* root, bool& check) {
        if (!root) return 0;

        int heightLeft = checkHeight(root->left, check);
        int heightRight = checkHeight(root->right, check);

        int difference = abs(heightLeft - heightRight);
        if (difference > 1) check = false;

        return max(heightLeft, heightRight) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool check = true;
        checkHeight(root, check);
        return check;
    }
};


TreeNode* createExample1() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

TreeNode* createExample2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    return root;
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* example1 = createExample1();
    cout << "Example 1: " << (solution.isBalanced(example1) ? "true" : "false") << endl;

    // Example 2
    TreeNode* example2 = createExample2();
    cout << "Example 2: " << (solution.isBalanced(example2) ? "true" : "false") << endl;

    return 0;


}