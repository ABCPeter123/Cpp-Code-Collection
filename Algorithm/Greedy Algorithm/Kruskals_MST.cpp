#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> edgelist;

    Graph(int v) {
        V = v;
    }

    void add_edge(int src, int dest, int weight) {
        edgelist.push_back({weight, src, dest});
    }

    void remove_edge() {
        edgelist.erase(edgelist.end());
    }
};

class Union_Find {
public:
    vector<int> parent;

    Union_Find(int V) {
        for (int i = 0; i < V; i++) {
            parent.push_back(i);
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return find(parent[i]);
    }

    void Union(int x, int y) {
        parent[x] = y;
    }

    bool isCycle(Graph graph, int index) {
        int x = find(graph.edgelist[index][1]);
        int y = find(graph.edgelist[index][2]);

        if (x == y) return true;

        Union(x, y);
        return false;
    }

};

void krustals_mst(Graph graph) {
    sort(graph.edgelist.begin(), graph.edgelist.end());
    int answer = 0;
    Graph temp(graph.V);
    Union_Find ufa(graph.V);
    for (auto edge : graph.edgelist) {
        int weight = edge[0];
        int x = edge[1];
        int y = edge[2];

        if (temp.edgelist.size() == temp.V - 1) break;

        temp.add_edge(x, y, weight);

        if (ufa.isCycle(temp, temp.edgelist.size() - 1)) {
            temp.remove_edge();
        }
        else {
            answer += weight;
            cout << "Edge " << x << " to " << y << " is included!" << endl;
        }
    }
    
    cout << "The minimum cost of the spanning tree is " << answer << endl;

}