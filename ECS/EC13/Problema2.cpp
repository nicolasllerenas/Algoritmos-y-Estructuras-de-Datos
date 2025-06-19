#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        // Listas de adyacencia
        int redAdj[101][101];     
        int blueAdj[101][101];    
        int redCount[101];        
        int blueCount[101];       
        
        // Cola para BFS
        struct Node {
            int vertex;
            int color; 
            int dist;
        };
        Node queue[10000];
        int front, rear;
        
    public:
        vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
            front = rear = 0;
            for (int i = 0; i < n; i++) {
                redCount[i] = 0;
                blueCount[i] = 0;
            }
            
            for (int i = 0; i < redEdges.size(); i++) {
                int from = redEdges[i][0];
                int to = redEdges[i][1];
                redAdj[from][redCount[from]++] = to;
            }
            
            for (int i = 0; i < blueEdges.size(); i++) {
                int from = blueEdges[i][0];
                int to = blueEdges[i][1];
                blueAdj[from][blueCount[from]++] = to;
            }
            
            
            vector<int> result(n, -1);
            result[0] = 0;
            
            bool visited[101][2] = {false}; 
            
            queue[rear++] = {0, 0, 0}; 
            queue[rear++] = {0, 1, 0}; 
            
            // BFS
            while (front < rear) {
                Node current = queue[front++];
                
                if (visited[current.vertex][current.color]) continue;
                visited[current.vertex][current.color] = true;
                
                // Exploramos vecinos con color opuesto
                if (current.color == 0) { 
                    for (int i = 0; i < blueCount[current.vertex]; i++) {
                        int neighbor = blueAdj[current.vertex][i];
                        if (!visited[neighbor][1]) {
                            if (result[neighbor] == -1) {
                                result[neighbor] = current.dist + 1;
                            }
                            queue[rear++] = {neighbor, 1, current.dist + 1};
                        }
                    }
                } else { 
                    for (int i = 0; i < redCount[current.vertex]; i++) {
                        int neighbor = redAdj[current.vertex][i];
                        if (!visited[neighbor][0]) {
                            if (result[neighbor] == -1) {
                                result[neighbor] = current.dist + 1;
                            }
                            queue[rear++] = {neighbor, 0, current.dist + 1};
                        }
                    }
                }
            }
            
            return result;
        }
    };

int main() {
    Solution solution;
    
    // Ejemplo 1: redEdges = [[0,1],[1,2]], blueEdges = []
    cout << "Ejemplo 1:" << endl;
    vector<vector<int>> red1 = {{0,1}, {1,2}};
    vector<vector<int>> blue1 = {};
    vector<int> result1 = solution.shortestAlternatingPaths(3, red1, blue1);
    
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    
    return 0;
}