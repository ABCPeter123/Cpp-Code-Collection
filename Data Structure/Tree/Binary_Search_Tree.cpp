#include <iostream>
using namespace std;
#include "Queue_For_Tree.cpp"

class Node {
    int data;
    Node* left;
    Node* right;

    public:
        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

        Node* insert(Node* &root, int value) {
            Node* temp = new Node(value);
            if(root == NULL) {
                root = temp;
                return temp;
            }
            if (value <= (root -> data)) {
                root -> left = (root -> left) -> insert(root -> left, value);
            }
            else root -> right = (root -> right) -> insert(root -> right, value);
            return root;
        }

        Node* search(Node* root, int data) {
            if(root == NULL) return NULL;
            else if (root -> data == data) return root;
            else if (data <= root -> data) return search(root -> left, data);
            else if (data > root -> data) return search(root -> right, data);
            return NULL;
        }

        int findHeight(Node* root) {
            if (root == NULL) {
                return -1;
            }
            int leftHeight = findHeight(root -> left);
            int rightHeight = findHeight(root -> right);
            return max(leftHeight, rightHeight) + 1;
        }

        void print_inorder(Node* root) {
            if(root == NULL) {
                return;
            }
            print_inorder(root -> left);
            cout << root -> data << " ";
            print_inorder(root -> right);
        }

        Node* findMin() {
            Node* root = this;
            if (root == NULL) {
                cout << "Empty tree!";
            }
            while (root -> left != NULL) {
                root = root -> left;
            }
            cout << "The minimum value is " << root -> data << endl;
            return root;
        }

        Node* findMax() {
            Node* root = this;
            if (root == NULL) {
                cout << "Empty tree!";
            }
            while (root -> right != NULL) {
                root = root -> right;
            }
            cout << "The maximum value is " << root -> data << endl;
            return root;
        }

        void print_layer() {
            cout << "Queue: ";
            Queue q;
            q.enqueue(this -> data);
            while(!q.isEmpty()) {
                Node* current = this -> search(this, q.getFront());
                cout << q.getFront() << " ";
                if (current -> left != NULL) q.enqueue((current -> left) -> data);
                if (current -> right != NULL) q.enqueue((current -> right) -> data);
                q.dequeue();
            }
            cout << endl;
        }

        Node* delete_node(Node* &root, int value) {
            if (root == NULL) return root;
            else if (value < root -> data) delete_node(root -> left, value);
            else if (value > root -> data) delete_node(root -> right, value);
            else {
                if (root -> left == NULL && root -> right == NULL) {
                    delete root;
                    root = NULL;
                }
                else if (root -> left == NULL) {
                    root = root -> right;
                }
                else if (root -> right == NULL) {
                    root = root -> left;
                }
                else {
                    Node* temp = (root -> right) -> findMin();
                    root -> data = temp -> data;
                    root -> right = delete_node(root -> right, temp -> data);
                }
            }
            return root;
        }
};

int main() {
    Node* root = NULL;
    root -> insert(root, 13);
    root -> insert(root, 11);
    root -> insert(root, 12);
    root -> insert(root, 10);
    root -> insert(root, 15);
    root -> insert(root, 14);
    root -> insert(root, 16);
    cout << "Queue: ";
    root -> print_inorder(root);
    cout << endl;
    root -> print_layer();
    cout << endl;
    root -> findMin();
    root -> findMax();
    cout << root -> findHeight(root) << endl;
    cout << "Enter a number you want to search: ";
    int number;
    cin >> number;
    if (root -> search(root, number) != NULL) cout << "Found it!" << endl;
    else cout << "Not found!" << endl;

    cout << "Enter a number you want to delete: ";
    cin >> number;
    if (root -> delete_node(root, number) != NULL) {
        cout << "Deleted!" << endl;
        root -> print_layer();
    }
    else cout << "Does not exist!" << endl;
}