#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        vector<int> color(n + 1, 0); // 0: no visitado, 1 y -1 son colores

        for (int i = 0; i < dislikes.size(); ++i) {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= n; ++i) {
            if (color[i] != 0) continue;

            vector<int> stack;
            stack.push_back(i);
            color[i] = 1;

            while (!stack.empty()) {
                int node = stack.back();
                stack.pop_back();

                for (int neighbor : adj[node]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        stack.push_back(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> dislikes = {
        {1, 2},
        {1, 3},
        {2, 4}
    };

    bool result = sol.possibleBipartition(n, dislikes);

    cout << (result ? "true" : "false") << endl;

    return 0;
}