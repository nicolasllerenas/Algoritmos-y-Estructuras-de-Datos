#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        void dfs(int node, vector<vector<int>>& isConnected, bool* visited, int n) {
            visited[node] = true;
            for (int i = 0; i < n; ++i) {
                if (isConnected[node][i] == 1 && !visited[i]) {
                    dfs(i, isConnected, visited, n);
                }
            }
        }
    
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            bool* visited = new bool[n];
            for (int i = 0; i < n; ++i) visited[i] = false;
    
            int provinces = 0;
    
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    dfs(i, isConnected, visited, n);
                    provinces++;
                }
            }
    
            delete[] visited;
            return provinces;
        }
    };


    int main() {
        Solution sol;
        
        // Ejemplo 1: 2 provincias
        cout << "=== EJEMPLO 1 ===" << endl;
        vector<vector<int>> isConnected1 = {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}
        };
        
        cout << "Matriz de conexiones:" << endl;
        for (int i = 0; i < isConnected1.size(); i++) {
            cout << "[";
            for (int j = 0; j < isConnected1[i].size(); j++) {
                cout << isConnected1[i][j];
                if (j < isConnected1[i].size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
        
        int result1 = sol.findCircleNum(isConnected1);
        cout << "Numero de provincias: " << result1 << endl;
        cout << "Explicacion: Ciudad 0 y 1 están conectadas (provincia 1), ciudad 2 sola (provincia 2)" << endl << endl;
        
        // Ejemplo 2: 3 provincias
        cout << "=== EJEMPLO 2 ===" << endl;
        vector<vector<int>> isConnected2 = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };
        
        cout << "Matriz de conexiones:" << endl;
        for (int i = 0; i < isConnected2.size(); i++) {
            cout << "[";
            for (int j = 0; j < isConnected2[i].size(); j++) {
                cout << isConnected2[i][j];
                if (j < isConnected2[i].size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
        
        int result2 = sol.findCircleNum(isConnected2);
        cout << "Numero de provincias: " << result2 << endl;
        cout << "Explicacion: Cada ciudad forma su propia provincia (0, 1, 2)" << endl << endl;
        
        // Ejemplo 3: 1 provincia (todas conectadas)
        cout << "=== EJEMPLO 3 ===" << endl;
        vector<vector<int>> isConnected3 = {
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {0, 1, 1, 0},
            {1, 1, 0, 1}
        };
        
        cout << "Matriz de conexiones:" << endl;
        for (int i = 0; i < isConnected3.size(); i++) {
            cout << "[";
            for (int j = 0; j < isConnected3[i].size(); j++) {
                cout << isConnected3[i][j];
                if (j < isConnected3[i].size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
        
        int result3 = sol.findCircleNum(isConnected3);
        cout << "Numero de provincias: " << result3 << endl;
        cout << "Explicacion: Todas las ciudades estan conectadas directa o indirectamente" << endl << endl;
    
        return 0;
    }