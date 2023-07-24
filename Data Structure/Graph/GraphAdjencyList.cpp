#include <iostream>
using namespace std;
#define SIZE 100

class Node {
    char data;
    Node* next;

    public:
        Node(char data) {
            this -> data = data;
            this -> next = NULL;
        }

        char getdata() {
            return data;
        }

        Node* getnext() {
            return next;
        }

        void insert(Node* &head, char data) { // insert at nth position
            Node* temp1 = new Node(data);
            Node* temp2 = head;
            while (temp2 -> next != NULL) temp2 = temp2 -> next;
            temp2 -> next = temp1;
        }
};

class Graph {
    char vertex[SIZE];
    Node* edge_list[SIZE];
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

        void insertVertex(char name) {
            vertex_end++;
            vertex[vertex_end] = name;
            edge_list[vertex_end] = new Node(name);
        }

        void insertEdge(char start, char end) {
            int start_index;
            int end_index;
            if (!check_inlist(start, end, start_index, end_index)) {cout << "Invalid vertices!" << endl; return;}
            edge_list[start_index] -> insert(edge_list[start_index], end);
            edge_list[end_index] -> insert(edge_list[end_index], start);
        }

        char* get_adjacent_vertices(char data) {
            int index;
            if (!check_inlist(data, index)) {cout << "Invalid vertices!" << endl; return NULL;}
            char* array = new char[SIZE];
            for (int i = 0; i < SIZE; i++) array[i] = NULL;
            int n = 0;
            Node* temp = edge_list[index];
            while (temp -> getnext() != NULL) {
                temp = temp -> getnext();
                array[n] = temp -> getdata();
                n++;
            }
            return array;
        }

        bool edge_exist(char start, char end) {
            int start_index;
            int end_index;
            if (!check_inlist(start, end, start_index, end_index)) {cout << "Invalid vertices!" << endl; return false;}
            Node* temp = edge_list[start_index];
            while (temp -> getnext() != NULL) {
                temp = temp -> getnext();
                if (temp -> getdata() == end) return true;
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