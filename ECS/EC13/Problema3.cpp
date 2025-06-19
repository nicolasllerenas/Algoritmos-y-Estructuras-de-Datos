#include <iostream>
using namespace std;

class Solution {
    static const int MAXN = 50005;
    static const int MAXM = 100005;
    static const int INF = 1e9 + 7;

    struct Edge {
        int to, weight, next;
    };

    Edge adj[2 * MAXM];
    int head[MAXN], edgeCount;

    void addEdge(int u, int v, int w) {
        adj[edgeCount] = {v, w, head[u]};
        head[u] = edgeCount++;
    }

    struct MinHeap {
        int heap[MAXN];
        int pos[MAXN];
        int dist[MAXN];
        int size;

        void init(int n, int d[]) {
            size = n;
            for (int i = 0; i < n; ++i) {
                heap[i] = i;
                pos[i] = i;
                dist[i] = d[i];
            }
            for (int i = n / 2 - 1; i >= 0; --i)
                heapify(i);
        }

        void heapify(int i) {
            int smallest = i;
            int l = 2 * i + 1, r = 2 * i + 2;

            if (l < size && dist[heap[l]] < dist[heap[smallest]])
                smallest = l;
            if (r < size && dist[heap[r]] < dist[heap[smallest]])
                smallest = r;

            if (smallest != i) {
                swap(i, smallest);
                heapify(smallest);
            }
        }

        void decreaseKey(int node, int newDist) {
            dist[node] = newDist;
            int i = pos[node];
            while (i > 0) {
                int parent = (i - 1) / 2;
                if (dist[heap[i]] < dist[heap[parent]]) {
                    swap(i, parent);
                    i = parent;
                } else break;
            }
        }

        void swap(int i, int j) {
            int tmp = heap[i];
            heap[i] = heap[j];
            heap[j] = tmp;
            pos[heap[i]] = i;
            pos[heap[j]] = j;
        }

        int extractMin() {
            int minNode = heap[0];
            heap[0] = heap[--size];
            pos[heap[0]] = 0;
            heapify(0);
            return minNode;
        }

        bool empty() {
            return size == 0;
        }
    };

    void dijkstra(int start, int n, int dist[]) {
        for (int i = 0; i < n; ++i) dist[i] = INF;
        dist[start] = 0;

        MinHeap heap;
        heap.init(n, dist);

        while (!heap.empty()) {
            int u = heap.extractMin();

            for (int i = head[u]; i != -1; i = adj[i].next) {
                int v = adj[i].to;
                int w = adj[i].weight;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    heap.decreaseKey(v, dist[v]);
                }
            }
        }
    }

public:
    bool* findAnswer(int n, int edges[][3], int m) {
        for (int i = 0; i < n; ++i) head[i] = -1;
        edgeCount = 0;

        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            addEdge(u, v, w);
            addEdge(v, u, w);
        }

        int distFrom0[MAXN], distToN[MAXN];
        dijkstra(0, n, distFrom0);
        dijkstra(n - 1, n, distToN);

        int shortest = distFrom0[n - 1];

        bool* answer = new bool[m];

        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if ((distFrom0[u] + w + distToN[v] == shortest) ||
                (distFrom0[v] + w + distToN[u] == shortest)) {
                answer[i] = true;
            } else {
                answer[i] = false;
            }
        }

        return answer;
    }
};

int main() {
    Solution sol;

    int n = 6;
    int edges[][3] = {
        {0, 1, 4},
        {0, 2, 1},
        {1, 3, 2},
        {1, 4, 3},
        {1, 5, 1},
        {2, 3, 1},
        {3, 5, 3},
        {4, 5, 2}
    };
    int m = sizeof(edges) / sizeof(edges[0]);

    bool* result = sol.findAnswer(n, edges, m);

    cout << "Resultado: [";
    for (int i = 0; i < m; ++i) {
        cout << (result[i] ? "true" : "false");
        if (i < m - 1) cout << ", ";
    }
    cout << "]" << endl;

    delete[] result;
    return 0;
}
