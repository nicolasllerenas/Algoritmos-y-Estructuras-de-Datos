//Tinco Aliaga César Abelardo

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode_partial {
    int val;
    int i, j; 
    TreeNode_partial *left;
    TreeNode_partial *right;
    TreeNode_partial(int x, int row, int col) : val(x), i(row), j(col), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode_partial* BT(vector<vector<int>>& grid, int i, int j) {
        int space = grid.size();
        if (i >= space || j >= space){ 
            return nullptr;
        }

        TreeNode_partial* node = new TreeNode_partial(grid[i][j], i, j);
        node->left = BT(grid, i, j + 1); 
        node->right = BT(grid, i + 1, j); 
        return node;
    }
    
    void MC(TreeNode_partial* node, int sum, int& maxSum, vector<pair<int, int>>& path, vector<pair<int, int>>& bPath) {
        if (!node) {
            return;
        }
        path.push_back({node->i, node->j});
        sum += node->val;
        if (!node->right && !node->left) { 
            if (sum > maxSum) {
                maxSum = sum;
                bPath = path;
            }
        } else {
            MC(node->left, sum, maxSum, path, bPath);
            MC(node->right, sum, maxSum, path, bPath);
        }
        path.pop_back();
    }

    vector<pair<int, int>> BCPath(vector<vector<int>>& grid) {
        TreeNode_partial* root = BT(grid, 0, 0);
        int maxSum = 0;
        vector<pair<int, int>> path, bPath;
        MC(root, 0, maxSum, path, bPath);
        return bPath;
    }
};

string printP(vector<pair<int, int>> path) {
    stringstream carrot;
    for (auto& pat : path) {
        carrot << "(" << pat.first << "," << pat.second << ") ";
    }
    return carrot.str();
}

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1, 2, 3},
        {0,-1, 4},
        {7, 0, 5}
    };

    vector<pair<int, int>> result = sol.BCPath(grid);
    cout << "Recorrido mas optimo para las zanahorias:\n";
    cout << printP(result) << endl;


    vector<vector<int>> grid2 = {
        {1, -1},
        {2, 3}
    };

    vector<pair<int, int>> result2 = sol.BCPath(grid2);
    cout << "Recorrido mas optimo para las zanahorias:\n";
    cout << printP(result2) << endl;
    return 0;
}

