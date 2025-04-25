#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return 0;
        
        int total = 0;
        
        for (int i = 0; i < n; ++i) {
            // Creamos un array dinámico para distancias cuadradas
            int* distancias = new int[n - 1];
            int idx = 0;
            
            // Calculamos las distancias desde el punto i
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                distancias[idx++] = dx * dx + dy * dy;
            }
            
            // Ordenamos para agrupar distancias iguales
            sort(distancias, distancias + n - 1);
            
            // Contamos grupos de distancias iguales
            int contador = 1;
            for (int k = 1; k < n - 1; ++k) {
                if (distancias[k] == distancias[k - 1]) {
                    contador++;
                } else {
                    total += contador * (contador - 1);
                    contador = 1;
                }
            }
            total += contador * (contador - 1); // Último grupo
            
            delete[] distancias; // Liberar memoria
        }
        
        return total;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: [[0,0],[1,0],[2,0]] → Output: 2
    vector<vector<int>> points1 = {{0,0}, {1,0}, {2,0}};
    cout << "Test 1: " << sol.numberOfBoomerangs(points1) << endl;
    
    // Test Case 2: [[1,1],[2,2],[3,3]] → Output: 2
    vector<vector<int>> points2 = {{1,1}, {2,2}, {3,3}};
    cout << "Test 2: " << sol.numberOfBoomerangs(points2) << endl;
    
    // Test Case 3: [[1,1]] → Output: 0
    vector<vector<int>> points3 = {{1,1}};
    cout << "Test 3: " << sol.numberOfBoomerangs(points3) << endl;
    
    return 0;
}