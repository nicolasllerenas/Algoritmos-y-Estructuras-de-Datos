#include <iostream>
using namespace std;

// Definición del nodo del árbol
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solución que inserta un valor en un árbol máximo
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        else if (root->val < val) {
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        else {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};

// Función para imprimir el árbol en preorden (raíz, izquierda, derecha)
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Construcción del árbol inicial: [4,1,3,null,null,null,2]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(2);

    int val = 5;

    Solution sol;
    TreeNode* updatedRoot = sol.insertIntoMaxTree(root, val);

    cout << "Árbol después de insertar " << val << " (en preorden): ";
    printPreorder(updatedRoot);
    cout << endl;

    return 0;
}
