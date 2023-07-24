#include <iostream>
#include <vector>
using namespace std;

struct Dijkstra {
	vector<int> direction;
	vector<bool> seen;
	vector<int> distance;
	int src;

	Dijkstra(int V, int SRC) {
		for (int i = 0; i < V; i++) direction.push_back(i);

		for (int i = 0; i < V; i++) seen.push_back(false);

		for (int i = 0; i < V; i++) distance.push_back(INT_MAX);
		src = SRC;
	}

	void minimum_paths(vector<vector<int>> graph) {
		seen[src] = true;
		distance[src] = 0;
		int current_idx = src;
		for (int count = 0; count < direction.size(); count++) {
			for (int connected = 0; connected < graph[current_idx].size(); connected++) {
				if (!seen[connected] && graph[current_idx][connected] && distance[current_idx] != INT_MAX && distance[current_idx] + graph[current_idx][connected] < distance[connected]) {
					distance[connected] = distance[current_idx] + graph[current_idx][connected];
					direction[connected] = current_idx;
				}
			}
			int min = INT_MAX;
			int min_idx = -1;
			for (int i = 0; i < distance.size(); i++) {
				if (!seen[i] && distance[i] < min) {
					min = distance[i];
					min_idx = i;
				}
			}

			current_idx = min_idx;
			seen[current_idx] = true;
		}
	}

	void reset(int V, int SRC) {
		direction = {};
		seen = {};
		distance = {};
		src = SRC;
		for (int i = 0; i < V; i++) direction.push_back(i);

		for (int i = 0; i < V; i++) seen.push_back(false);

		for (int i = 0; i < V; i++) distance.push_back(INT_MAX);
	}

	void print_path(int dest) {
		vector<int> path = {dest};
		int current_idx = dest;
		while (current_idx != src) {
			path.insert(path.begin(), direction[current_idx]);
			current_idx = direction[current_idx];
		}

		cout << path[0];
		path.erase(path.begin());
		for (auto i : path) {
			cout << " --> " << i;
		}
		cout << "\n";
	}

	void print_distance(int dest) {
		cout << "The minimum distance from vertex " << src << " to vertex " << dest << " is " << distance[dest] << endl;  
	}
};

// int main() {
// 	int v = 9;
// 	vector<vector<int>> adjacency_matrix = 
// 	{
// 	{0, 4, 0, 0, 0, 0, 0, 8, 0},
// 	{4, 0, 8, 0, 0, 0, 0,11, 0},
// 	{0, 8, 0, 7, 0, 4, 0, 0, 2},
// 	{0, 0, 7, 0, 9,14, 0, 0, 0},
// 	{0, 0, 0, 9, 0,10, 0, 0, 0},
// 	{0, 0, 4,14,10, 0, 2, 0, 0},
// 	{0, 0, 0, 0, 0, 2, 0, 1, 6},
// 	{8,11, 0, 0, 0, 0, 1, 0, 7},
// 	{0, 0, 2, 0, 0, 0, 6, 7, 0}
// 	};

// 	Dijkstra dijkstra(v, 0);
// 	for (int i = 0; i < v; i++) {
// 		dijkstra.minimum_paths(adjacency_matrix);
// 		for (int j = 0; j < v; j++) {
// 			dijkstra.print_distance(j);
// 			dijkstra.print_path(j);
// 		}
// 		dijkstra.reset(v, i + 1);
// 	}
	
// 	// Dijkstra dijkstra(v, 2);
// 	// dijkstra.minimum_paths(adjacency_matrix);
// 	// for (int i = 0; i < v; i++) {
// 	// 	dijkstra.print_distance(i);
// 	// 	dijkstra.print_path(i);
// 	// }
// }