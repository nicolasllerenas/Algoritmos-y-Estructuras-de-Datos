#include <iostream>
#include <queue>
#include <vector>
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
    void traversal(TreeNode* root, int nodes[], int& currIdx) {
        if (!root) return;
        traversal(root->left, nodes, currIdx);
        nodes[currIdx++] = root->val;
        traversal(root->right, nodes, currIdx);
    }

    TreeNode* sortedArrayToBST(int nodes[], int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = sortedArrayToBST(nodes, start, mid - 1);
        root->right = sortedArrayToBST(nodes, mid + 1, end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        int nodes[10000];
        int currIdx = 0;
        traversal(root, nodes, currIdx);
        return sortedArrayToBST(nodes, 0, currIdx - 1);
    }
};

// Función para imprimir el árbol en el formato que usa LeetCode
void printLeetCodeFormat(TreeNode* root) {
    if (!root) {
        cout << "[]\n";
        return;
    }

    vector<string> result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }

    // Eliminar 'null's al final innecesarios
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i + 1 < result.size()) cout << ",";
    }
    cout << "]\n";
}

int main() {
    // Crear el árbol desbalanceado: 1 -> 2 -> 3 -> 4
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* balanced = sol.balanceBST(root);

    cout << "Arbol balanceado en formato LeetCode: ";
    printLeetCodeFormat(balanced);

    return 0;
}
