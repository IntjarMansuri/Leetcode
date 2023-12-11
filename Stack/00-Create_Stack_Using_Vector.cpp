#include<iostream>
#include<vector>
using namespace std;

class Stack {
private:
    vector<int> vec;

public:
    // Function to push an element onto the stack
    void push(int val) {
        vec.push_back(val);
    }

    // Function to pop an element from the stack
    void pop() {
        if (!empty()) {
            vec.pop_back();
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    // Function to get the top element of the stack
    int top() {
        if (!empty()) {
            return vec.back();
        } else {
            // Return a special value (e.g., -1) to indicate an empty stack
            cout << "Stack is empty. Cannot get top element." << endl;
        }
        return -1;
    }

    // Function to check if the stack is empty
    bool empty() {
        return vec.empty();
    }

    // Function to print the elements of the stack
    void printStack() {
        cout << "Stack: ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {

    Stack myStack;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        myStack.push(val);
    }

    myStack.printStack();
    myStack.pop();
    myStack.printStack();

    return 0;
}
