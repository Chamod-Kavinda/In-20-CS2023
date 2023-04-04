#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // maximum size of the stack

struct Stack {
    int top; // index of the top element in the stack
    int arr[MAX_SIZE]; // array to store the elements in the stack
};

// function to push an element onto the stack
void push(Stack& S, int x) {
    S.top++;
    if (S.top >= MAX_SIZE) {
        cout << "Stack Overflow\n";
        S.top--;
    }
    else {
        S.arr[S.top] = x;
    }
}

// function to pop an element from the stack
int pop(Stack& S) {
    if (S.top < 0) {
        cout << "Stack Underflow\n";
        return -1;
    }
    else {
        int val = S.arr[S.top];
        S.top--;
        return val;
    }
}

// function to check if the stack is empty
bool is_empty(Stack& S) {
    return (S.top < 0);
}

bool is_full(Stack& S) {
    return (S.top >= MAX_SIZE - 1);
}

int stackTop(Stack& S) {
    if (S.top >= MAX_SIZE - 1) {
        cout << "Stack is empty\n";
        return -1;
    }
    else {
        return S.arr[S.top];
    }
}

void display(Stack& S) {
    if (S.top >= MAX_SIZE - 1) {
        cout << "[]\n";
        return;
    }
    else {
        cout << "[";
        for (int j = 0; j <= S.top; j++) {
            cout << S.arr[j] << ", ";
        }
        cout << "]\n";
    }
}

int main() {
    Stack S;
    S.top = -1; // initialize the stack
    push(S, 10); // push 10 onto the stack
    display(S);
    push(S, 20); // push 20 onto the stack
    display(S);
    push(S, 30); // push 30 onto the stack
    display(S);
    cout << pop(S) << endl; // pop 30 from the stack and print it
    display(S);
    cout << pop(S) << endl; // pop 20 from the stack and print it
    display(S);
    cout << pop(S) << endl; // pop 10 from the stack and print it
    display(S);
    cout << pop(S) << endl; // try to pop from an empty stack
    display(S);

    return 0;
}