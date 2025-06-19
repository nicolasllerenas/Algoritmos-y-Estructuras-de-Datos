#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        int dx[8] = {-1,-1,-1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0,-1,-1};

        int qx[10000], qy[10000], dist[10000];
        int front = 0, rear = 0;
        int visited[100][100] = {0};

        qx[rear] = 0;
        qy[rear] = 0;
        dist[rear] = 1;
        rear++;
        visited[0][0] = 1;

        while (front < rear) {
            int x = qx[front];
            int y = qy[front];
            int d = dist[front];
            front++;

            if (x == n - 1 && y == n - 1) return d;

            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    !visited[nx][ny] && grid[nx][ny] == 0) {
                    qx[rear] = nx;
                    qy[rear] = ny;
                    dist[rear] = d + 1;
                    visited[nx][ny] = 1;
                    rear++;
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> grid = {
            {0, 0, 0},
            {1, 1, 0},
            {1, 1, 0}
    };

    Solution sol;
    cout << "Shortest path: " << sol.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}
