#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Estructura del nodo del árbol
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* arrayToAVL(vector<int>& array) {
        quickSort(array, 0, array.size() - 1);
        return constructTree(array, 0, array.size() - 1);
    }

    void quickSort(vector<int>& array, int left, int right) {
        if (left < right) {
            int pivotIdx = partition(array, left, right);
            quickSort(array, left, pivotIdx - 1);
            quickSort(array, pivotIdx + 1, right);
        }
    }

    int partition(vector<int>& array, int left, int right) {
        int pivot = array[right];
        int idx = left - 1;

        for (int j = left; j < right; ++j) {
            if (array[j] < pivot) {
                idx++;
                swap(array[idx], array[j]);
            }
        }
        swap(array[idx + 1], array[right]);
        return idx + 1;
    }

    TreeNode* constructTree(vector<int>& array, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(array[mid]);
        node->left = constructTree(array, left, mid - 1);
        node->right = constructTree(array, mid + 1, right);

        return node;
    }

    void printTree(TreeNode* root) {
        if (!root) {
            cout << "[]" << endl;
            return;
        }

        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            } else {
                result.push_back(-1);
            }
        }

        while (!result.empty() && result.back() == -1) {
            result.pop_back();
        }

        cout << "[";
        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) cout << ", ";
            if (result[i] == -1)
                cout << "null";
            else
                cout << result[i];
        }
        cout << "]" << endl;
    }
};

int main() {
    Solution solution;

    vector<int> array = {2, 4, 1, 3, 5, 6, 7};

    TreeNode* root = solution.arrayToAVL(array);

    solution.printTree(root);

    return 0;
}