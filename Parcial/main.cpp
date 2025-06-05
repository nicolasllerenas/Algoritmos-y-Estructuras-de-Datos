#include <cassert>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
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
int goodNodes(TreeNode* root) {
    if (!root) return 0;

    int goodCount = 0;

    vector<pair<TreeNode*, int>> stack;
    stack.push_back({root, root->val});

    while (!stack.empty()) {
        auto [node, maxVal] = stack.back();
        stack.pop_back();

        if (node->val >= maxVal) {
            goodCount++;
            maxVal = node->val;
        }

        if (node->left) stack.push_back({node->left, maxVal});
        if (node->right) stack.push_back({node->right, maxVal});
    }

    return goodCount;
}

};
int main() {
Solution sol;
// Test 1: Single node
TreeNode* test1 = new TreeNode(5);
assert(sol.goodNodes(test1) == 1);
// Test 2: Tree with some good nodes
TreeNode* test2 = new TreeNode(3);
test2->left = new TreeNode(1);
test2->left->left = new TreeNode(3);
test2->right = new TreeNode(4);
test2->right->right = new TreeNode(5);
assert(sol.goodNodes(test2) == 4);
// Test 3: Árbol con todos los nodos iguales
TreeNode* test3 = new TreeNode(2);
test3->left = new TreeNode(2);
test3->right = new TreeNode(2);
test3->left->left = new TreeNode(2);
test3->left->right = new TreeNode(2);
assert(sol.goodNodes(test3) == 5); // todos son "good nodes"
// Test 4: Árbol creciente en línea recta (derecha)
TreeNode* test4 = new TreeNode(1);
test4->right = new TreeNode(2);
test4->right->right = new TreeNode(3);
test4->right->right->right = new TreeNode(4);
assert(sol.goodNodes(test4) == 4); // cada nodo es mayor que el anterior
// Test 5: Árbol decreciente
TreeNode* test5 = new TreeNode(5);
test5->left = new TreeNode(3);
test5->left->left = new TreeNode(1);
test5->right = new TreeNode(4);
assert(sol.goodNodes(test5) == 1); // solo la raíz
// Test 6: Árbol donde cada hijo izquierdo es mayor que el padre
TreeNode* test6 = new TreeNode(1);
test6->left = new TreeNode(2);
test6->left->left = new TreeNode(3);
assert(sol.goodNodes(test6) == 3); // todos son good nodes
// Test 7: Árbol zig-zag con algunos valores menores
TreeNode* test7 = new TreeNode(3);
test7->right = new TreeNode(1);
test7->right->left = new TreeNode(4);
assert(sol.goodNodes(test7) == 2); // 3 y 4 son good nodes
// Test 8: Árbol con valores negativos
TreeNode* test8 = new TreeNode(-1);
test8->left = new TreeNode(-2);
test8->right = new TreeNode(-3);
assert(sol.goodNodes(test8) == 1); // solo -1 es good node
// Test 9: Árbol más complejo con mezcla de buenos y no buenos nodos
TreeNode* test9 = new TreeNode(5);
test9->left = new TreeNode(1);
test9->right = new TreeNode(7);
test9->right->left = new TreeNode(6);
test9->right->right = new TreeNode(9);
assert(sol.goodNodes(test9) == 3); // 5, 7, 9
// Test 10: Árbol vacío
TreeNode* test10 = nullptr;
assert(sol.goodNodes(test10) == 0);
std::cout << "All tests passed!\n";
return 0;
}