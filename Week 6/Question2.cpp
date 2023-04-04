#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

// function to create a new node
Node* create_node(int x) {
    Node* node = new Node;
    node->data = x;
    node->next = NULL;
    return node;
}

// function to push an element onto the stack
void push(Stack& S, int x) {
    Node* node = create_node(x);
    if (S.top == NULL) {
        S.top = node;
    }
    else {
        node->next = S.top;
        S.top = node;
    }
}

// function to pop an element from the stack
int pop(Stack& S) {
    if (S.top == NULL) {
        cout << "Stack Underflow\n";
        return -1;
    }
    else {
        int x = S.top->data;
        Node* temp = S.top;
        S.top = S.top->next;
        delete temp;

        return x;
    }
}

// function to check if the stack is empty
bool is_empty(Stack& S) {
    return (S.top == NULL);
}

int stack_top(Stack& S) {
    if (S.top == NULL) {
        cout << "Stack Underflow\n";
        return -1;
    }
    else {
        return S.top->data;
    }
}

void display(Stack S) {
    if (S.top == NULL) {
        cout << "[]\n";
    }
    else {
        Node* temp = S.top;
        cout << "[";
        while (temp != NULL) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << "]\n";
    }
}

int main() {
    Stack S;
    S.top = NULL;
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