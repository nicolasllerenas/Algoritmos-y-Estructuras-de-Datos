#include <iostream>
#include <vector>     
#include <cassert>    
using namespace std;

class Solution {
public:
    int comunidadMasExtensa(vector<vector<int>>& mapa) {
        if (mapa.empty() || mapa[0].empty()) return 0;

        const int m = static_cast<int>(mapa.size());
        const int n = static_cast<int>(mapa[0].size());
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mapa[i][j] == 1) {
                    int area = dfs(mapa, i, j, m, n);   
                    if (area > maxArea) maxArea = area; 
                }
            }
        }
        return maxArea;
    }

private:
    int dfs(vector<vector<int>>& mapa,
            int x, int y, int m, int n) {

        if (x < 0 || x >= m || y < 0 || y >= n || mapa[x][y] == 0) return 0;

        mapa[x][y] = 0;          
        int area = 1;            

        area += dfs(mapa, x + 1, y, m, n);
        area += dfs(mapa, x - 1, y, m, n);
        area += dfs(mapa, x, y + 1, m, n);
        area += dfs(mapa, x, y - 1, m, n);

        return area;
    }
};
////////////////////////////////
// Do not edit the code below //
////////////////////////////////
int main() {
Solution sol;
// Test 1:
vector<vector<int>> grid1 = {
{1, 0, 0},
{1, 0, 0},
{1, 1, 1}
};
assert(sol.comunidadMasExtensa(grid1) == 5);
// Test 2:
vector<vector<int>> grid2 = {
{1, 0, 0},
{0, 1, 0},
{0, 0, 1}
};
assert(sol.comunidadMasExtensa(grid2) == 1);
// Test 3:
vector<vector<int>> grid3 = {
{1,1,0,0,0},
{1,1,0,1,1},
{0,0,0,1,1}
};
assert(sol.comunidadMasExtensa(grid3) == 4);
// Test 4:
vector<vector<int>> grid4 = {
{1,1,1},
{1,0,1},
{1,1,1}
};
assert(sol.comunidadMasExtensa(grid4) == 8);
// Test 5:
vector<vector<int>> grid5 = {
{1,1,0,0,0,1,1},
{1,1,0,1,0,1,1},
{0,0,0,1,0,0,0},
{1,1,1,1,1,1,1}
};
assert(sol.comunidadMasExtensa(grid5) == 9);
// Test 6:
vector<vector<int>> grid6 = {
{1,0,1,0,1,1,0,1,1,1}
};
assert(sol.comunidadMasExtensa(grid6) == 3);
// Test 7:
vector<vector<int>> grid7(10, vector<int>(10, 0));
for (int i = 0; i < 10; ++i) {
grid7[0][i] = grid7[9][i] = 1;
grid7[i][0] = grid7[i][9] = 1;
}
assert(sol.comunidadMasExtensa(grid7) == 36);
// Test 8:
vector<vector<int>> grid8(5, vector<int>(5, 0));
assert(sol.comunidadMasExtensa(grid8) == 0);
// Test 9:
vector<vector<int>> grid9 = {
{1,1,1,1,1},
{1,0,0,0,1},
{1,0,1,0,1},
{1,0,0,0,1},
{1,1,1,1,1}
};
assert(sol.comunidadMasExtensa(grid9) == 16);
// Test 10:
vector<vector<int>> grid10 = {
{0,0,0},
{0,1,0},
{0,0,0}
};
assert(sol.comunidadMasExtensa(grid10) == 1);
cout << "Todos los tests pasaron correctamente" << endl;
return 0;
}