#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            if (source == destination) return true;
            vector<vector<int>> adj(n);
            for (auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            vector<bool> visited(n, false);
            return dfs(adj, visited, source, destination);
        }
        
    private:
        bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int current, int destination) {
            visited[current] = true;
            if (current == destination) {
                return true;
            }
            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    if (dfs(adj, visited, neighbor, destination)) {
                        return true;
                    }
                }
            }
            return false;
        }
    };

    int main() {
        Solution sol;
        
        // Ejemplo 1: Grafo conectado
        cout << "=== EJEMPLO 1 ===" << endl;
        int n1 = 3;
        vector<vector<int>> edges1 = {{0,1}, {1,2}, {2,0}};
        int source1 = 0, destination1 = 2;
        
        cout << "Grafo: n = " << n1 << ", edges = [[0,1], [1,2], [2,0]]" << endl;
        cout << "Buscar camino de " << source1 << " a " << destination1 << endl;
        bool result1 = sol.validPath(n1, edges1, source1, destination1);
        cout << "Resultado: " << (result1 ? "true" : "false") << endl;
        cout << "Caminos posibles: 0->1->2, 0->2" << endl << endl;
        
        // Ejemplo 2: Grafo desconectado
        cout << "=== EJEMPLO 2 ===" << endl;
        int n2 = 6;
        vector<vector<int>> edges2 = {{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};
        int source2 = 0, destination2 = 5;
        
        cout << "Grafo: n = " << n2 << ", edges = [[0,1], [0,2], [3,5], [5,4], [4,3]]" << endl;
        cout << "Buscar camino de " << source2 << " a " << destination2 << endl;
        bool result2 = sol.validPath(n2, edges2, source2, destination2);
        cout << "Resultado: " << (result2 ? "true" : "false") << endl;
        cout << "Explicacion: Nodo 0 esta en componente {0,1,2}, nodo 5 en {3,4,5}" << endl << endl;
        
        // Ejemplo 3: Mismo nodo source y destination
        cout << "=== EJEMPLO 3 ===" << endl;
        int n3 = 1;
        vector<vector<int>> edges3 = {};
        int source3 = 0, destination3 = 0;
        
        cout << "Grafo: n = " << n3 << ", edges = []" << endl;
        cout << "Buscar camino de " << source3 << " a " << destination3 << endl;
        bool result3 = sol.validPath(n3, edges3, source3, destination3);
        cout << "Resultado: " << (result3 ? "true" : "false") << endl;
        cout << "Explicacion: Mismo nodo, siempre hay camino" << endl;
        
        return 0;
    }