#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> node_prob;
        for (int i = 0; i < n; i++) {
            node_prob.push_back(0.0);
        }
        node_prob[start_node] = 1.0;
        bool seen[n];
        for (int i = 0; i < n; i++) seen[i] = false;
        int current = start_node;
        while (seen[end_node] == false) {
            seen[current] = true;
            vector<int> index = edge(edges, seen, current);
            double max_prob = 0;
            int max_node = current;
            double new_prob = 0;
            for (auto i : index) {
                if (edges[i][0] == current) {
                    if (seen[edges[i][1]] == false) {
                        new_prob = node_prob[current] * succProb[i];
                        if (new_prob > node_prob[edges[i][1]]) node_prob[edges[i][1]] = new_prob;
                    }
                } else {
                    if (seen[edges[i][0]] == false) {
                        new_prob = node_prob[current] * succProb[i];
                        if (new_prob > node_prob[edges[i][0]]) node_prob[edges[i][0]] = new_prob;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (node_prob[i] > max_prob && seen[i] == false) {
                    max_prob = node_prob[i];
                    max_node = i;
                }
            }
            current = max_node;
        }
        return node_prob[end_node];
    }

    vector<int> edge(vector<vector<int>> edges, bool seen[], int node) {
        vector<int> array;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] == node && seen[edges[i][1]] == false) array.push_back(i);
            else if (edges[i][1] == node && seen[edges[i][0]] == false) array.push_back(i);
        }
        return array;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges = {{0, 1}, {0, 5}, {1, 5}, {5, 7}, {5, 4}, {4, 7}, {4, 2}, {2, 7}, {1, 2}, {1, 7}, {1, 3}, {3, 2}};
    vector<double> succProb = {0.8, 0.7, 0.1, 0.3, 0.4, 0.8, 0.3, 0.5, 0.7, 0.2, 0.3, 0.2};
    cout << solution.maxProbability(8, edges, succProb, 0, 7) << endl;
}