#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<pair<int, int>>> adj;
    
    Graph(int V) {
        this -> V = V;
        for (int i = 0; i < V; i++) {
            adj.push_back({});
            for (int j = 0; j < V; j++) {
                adj[i].push_back(make_pair(0, 0));
            }
        }
    }

    void add_edge(int start, int dest, int length, int cost) {
        adj[start][dest] = make_pair(length, cost);
        adj[dest][start] = make_pair(length, cost);
    }

    void remove_edge(int start, int dest) {
        adj[start][dest] = make_pair(0, 0);
        adj[dest][start] = make_pair(0, 0);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    int u,v,l,c;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> l >> c;
        graph.add_edge(u, v, l, c);
    }
    while (M != 0) {
        
        M--;
    }
}