#include <iostream>
using namespace std;
#define SIZE 100

class Graph {
    char vertex[SIZE];
    int matrix[SIZE][SIZE];
    int vertex_end = -1;

    public:
        bool check_inlist(char a, char b, int& index1, int& index2) {
            int cnt = 0;
            for (int i = 0; i <= vertex_end; i++) {
                if (a == vertex[i]) {index1 = i; cnt++;}
                if (b == vertex[i]) {index2 = i; cnt++;}
                if (cnt == 2) return true;
            } 
            return false;
        }

        bool check_inlist(char a, int& index) {
            for (int i = 0; i <= vertex_end; i++) {
                if (a == vertex[i]) {index = i; return true;}
            } 
            return false;
        }

        void insertVertex(char data) {
            vertex_end++;
            vertex[vertex_end] = data;
        }

        void insertEdge(char start, char end) {
            int start_index;
            int end_index;
            if (!check_inlist(start, end, start_index, end_index)) {cout << "Invalid vertices!" << endl; return;}
            matrix[start_index][end_index] = 1;
            matrix[end_index][start_index] = 1;
        }

        char* get_adjacent_vertices(char data) {
            int index;
            if (!check_inlist(data, index)) {cout << "Invalid vertices!" << endl; return NULL;}
            char* array = new char[SIZE];
            for (int i = 0; i < SIZE; i++) array[i] = NULL;
            int n = 0;
            for (int i = 0; i <= vertex_end; i++) {
                if (matrix[index][i] == 1) {array[n] = vertex[i]; n++;}
            }
            return array;
        }

        bool edge_exist(char start, char end) {
            int start_index;
            int end_index;
            if (!check_inlist(start, end, start_index, end_index)) {cout << "Invalid vertices!" << endl; return false;}
            if (matrix[start_index][end_index] == 1 || matrix[end_index][start_index] == 1) return true;
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