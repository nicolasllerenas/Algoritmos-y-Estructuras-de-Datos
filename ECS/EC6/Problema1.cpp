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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        // Intercambiamos los hijos
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        // Invertimos recursivamente los subárboles
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main() {
    // Creamos un árbol de ejemplo
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    TreeNode* invertedRoot = solution.invertTree(root);

    // Esto devuelve el valor de la raíz del árbol invertido
    cout << "Raiz del arbol invertido: " << invertedRoot->val << endl;

    return 0;
}