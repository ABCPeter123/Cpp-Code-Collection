#include <iostream>
using namespace std;
#define SIZE 100

class Edge {
    char startVertex;
    char endVertex;

    public:
        void setstart(char vertex1) {
            startVertex = vertex1;
        }
        
        void setend(char vertex1) {
            endVertex = vertex1;
        }

        char getstart() {
            return startVertex;
        }

        char getend() {
            return endVertex;
        }
};

class Graph {
    char vertex[SIZE];
    Edge edge_list[SIZE];
    int vertex_end = -1;
    int edge_end = -1;

    public:
        bool check_inlist(char character1, char character2) {
            int cnt = 0;
            for (int i = 0; i <= vertex_end; i++) {
                if (character1 == vertex[i] || character2 == vertex[i]) cnt++;
                if (cnt == 2) return true;
            } 
            return false;
        }

        bool check_inlist(char character) {
            for (int i = 0; i <= vertex_end; i++) {
                if (character == vertex[i]) return true;
            } 
            return false;
        }

        void insertVertex(char name) {
            vertex_end++;
            vertex[vertex_end] = name;
        }

        void insertEdge(char start, char end) {
            if (!check_inlist(start, end)) {cout << "Invalid vertices!" << endl; return;}
            Edge edge;
            edge.setstart(start);
            edge.setend(end);
            edge_end++;
            edge_list[edge_end] = edge;
        }

        char* get_adjacent_vertices(char vertices) {
            for (int i = 0; i <= vertex_end; i++) {
                if (vertex[i] == vertices) {
                    char* adjacent = new char[SIZE];
                    for (int k = 0; k < SIZE; k++) adjacent[k] = NULL;
                    int n = 0;
                    for (int j = 0; j <= edge_end; j++) {
                        if (edge_list[j].getstart() == vertex[i]) {
                            adjacent[n] = edge_list[j].getend();
                            n++;
                        } else if (edge_list[j].getend() == vertex[i]) {
                            adjacent[n] = edge_list[j].getstart();
                            n++;
                        }
                    }
                    return adjacent;
                }
            }
            return NULL;
        }

        bool edge_exist(char start, char end) {
            for (int i = 0; i <= edge_end; i++) {
                if ((edge_list[i].getstart() == start && edge_list[i].getend() == end) || (edge_list[i].getstart() == end && edge_list[i].getend() == start)) {
                    return true;
                }
            } 
            return false;
        }

        void print() {
            for (int i = 0; i <= vertex_end; i++) {
                cout << "Vertex " << vertex[i];
                char* array = get_adjacent_vertices(vertex[i]);
                if (array != NULL) {
                    int j = 0;
                    while (array[j] != NULL) {
                        cout << " -> " << array[j];
                        j++;
                    }
                } else cout << " -> None";
                cout << endl;
            }
        }
};

int main() {
    Graph graph;
    graph.insertVertex('a');
    graph.insertVertex('b');
    graph.insertVertex('c');
    graph.insertVertex('d');
    graph.insertVertex('e');
    graph.insertVertex('f');

    graph.insertEdge('a', 'e');
    graph.insertEdge('a', 'b');
    graph.insertEdge('a', 'c');
    graph.insertEdge('a', 'd');
    graph.insertEdge('d', 'e');
    graph.insertEdge('d', 'f');
    graph.insertEdge('b', 'c');

    graph.print();

    cout << "Enter 2 characters: ";
    char a, b;
    cin >> a >> b;
    if (graph.edge_exist(a, b)) cout << "Edge exists!" << endl;
    else cout << "No edge!" << endl;
}