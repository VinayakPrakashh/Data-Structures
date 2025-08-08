#include <iostream>
using namespace std;

#define N 5

class Stack {
private:
    int stack[N];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push() {
        int x;
        cout << "\nEnter the data to push: ";
        cin >> x;

        if (top == N - 1) {
            cout << "\nStack is full. Insertion failed!" << endl;
        } else {
            top++;
            stack[top] = x;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "\nStack is empty!" << endl;
        } else {
            int item = stack[top];
            cout << "\n" << top << "-th value deleted, value = " << item << endl;
            top--;
        }
    }

    void peek() {
        if (top == -1) {
            cout << "\nStack is empty!" << endl;
        } else {
            cout << "\nTop element = " << stack[top] << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "\nStack is empty!" << endl;
            return;
        }

        cout << "\nStack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int ch;

    do {
        cout << "\nEnter choice\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit: ";
        cin >> ch;

        switch (ch) {
            case 1: s.push(); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.display(); break;
            case 5: ch = 0; break;
            default: cout << "\nInvalid choice!" << endl;
        }
    } while (ch != 0);

    return 0;
}
