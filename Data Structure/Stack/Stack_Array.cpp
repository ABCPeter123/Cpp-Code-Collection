#include <iostream>
using namespace std;
#define SIZE 100

class Stack {
    int top;
    int stack[SIZE];

    public:
        Stack() {
            top = -1;
        }

        void push(int x) {
            if (top == SIZE - 1) {
                cout << "Error: stack overflow" << endl;
                return;
            }
            this -> stack[++top] = x;
        }

        void pop() {
            if (top == -1) {
                cout << "Error: stack is empty!" << endl;
                return;
            }
            top--;
        }

        void print() {
            cout << "Stack: ";
            for (int i = top; i >= 0; i--) {
                cout << this -> stack[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack stack;
    stack.pop();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print();
    stack.pop();
    stack.print();
}