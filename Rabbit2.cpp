#include <iostream>

using namespace std;

// Tamaño de la matriz
const int N = 6;

// Estructura para un nodo del árbol
struct TreeNode {
    int val;
    int i, j;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v, int row, int col) {
        val = v;
        i = row;
        j = col;
        left = right = nullptr;
    }
};

// Estructura para representar una coordenada en el camino
struct Coord {
    int i, j;
};

// Clase principal
class Solution {
public:
    TreeNode* buildTree(int grid[N][N], int i, int j) {
        if (i >= N || j >= N) return nullptr;
        TreeNode* node = new TreeNode(grid[i][j], i, j);
        node->left = buildTree(grid, i, j + 1);   // Mover a la derecha
        node->right = buildTree(grid, i + 1, j);  // Mover hacia abajo
        return node;
    }

    // Encontrar el mejor camino (más zanahorias)
    void maxCarrots(TreeNode* node, int sum, int& maxSum, Coord path[N * 2], Coord bestPath[N * 2], int depth) {
        if (!node) return;

        path[depth].i = node->i;
        path[depth].j = node->j;
        sum += node->val;

        if (!node->left && !node->right) { // Es hoja
            if (sum > maxSum) {
                maxSum = sum;
                for (int k = 0; k <= depth; k++) {
                    bestPath[k] = path[k];
                }
                bestPathLen = depth + 1;
            }
        } else {
            maxCarrots(node->left, sum, maxSum, path, bestPath, depth + 1);
            maxCarrots(node->right, sum, maxSum, path, bestPath, depth + 1);
        }
    }

    void findBestPath(int grid[N][N], Coord bestPathOut[N * 2], int& outLen, int& maxZanahorias) {
        TreeNode* root = buildTree(grid, 0, 0);
        int maxSum = 0;
        Coord path[N * 2], bestPath[N * 2];
        bestPathLen = 0;

        maxCarrots(root, 0, maxSum, path, bestPath, 0);

        for (int i = 0; i < bestPathLen; i++) {
            bestPathOut[i] = bestPath[i];
        }
        outLen = bestPathLen;
        maxZanahorias = maxSum;
    }

private:
    int bestPathLen = 0;
};

void imprimirCamino(Coord path[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "(" << path[i].i << "," << path[i].j << ")";
        if (i != len - 1) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int grid[N][N] = {
        {5, 3, 2, 1, 4, 6},
        {7, 8, 1, 2, 3, 1},
        {3, 1, 9, 4, 2, 7},
        {1, 2, 1, 10, 1, 3},
        {4, 1, 3, 2, 8, 4},
        {2, 6, 1, 5, 2, 9}
    };

    Solution sol;
    Coord bestPath[N * 2];
    int len = 0;
    int maxZanahorias = 0;

    sol.findBestPath(grid, bestPath, len, maxZanahorias);

    cout << "Recorrido con más zanahorias:\n";
    imprimirCamino(bestPath, len);
    cout << "Total de zanahorias: " << maxZanahorias << endl;

    return 0;
}
