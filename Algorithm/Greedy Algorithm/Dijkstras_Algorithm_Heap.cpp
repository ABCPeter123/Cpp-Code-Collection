#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Graph {
    int V;
    vector<vector<pair<int, int>>> adj;
    
    Graph(int V) {
        this -> V = V;
        for (int i = 0; i < V; i++) {
            adj.push_back({});
        }
    }

    void add_edge(int start, int dest, int weight) {
        adj[start].push_back(make_pair(dest, weight));
        adj[dest].push_back(make_pair(start, weight));
    }

    void shortest_path(int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty()) {
            int current = pq.top().second;
            pq.pop();

            vector<pair<int, int>>::iterator i;
            for (i = adj[current].begin(); i != adj[current].end(); ++i) {
                int vertex = (*i).first;
                int weight = (*i).second;

                if (dist[vertex] > dist[current] + weight) {
                    dist[vertex] = dist[current] + weight;
                    pq.push(make_pair(dist[vertex], vertex));
                }
            }
        }

        for (int i = 0; i < dist.size(); i++) {
            cout << "Minimum distance to " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    int V = 9;
    Graph g(V);
 
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
 
    g.shortest_path(0);
}