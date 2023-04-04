#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int MAX_SIZE = 100; // maximum size of the stack

struct StackArray {
    int top; // index of the top element in the stack
    int arr[MAX_SIZE]; // array to store the elements in the stack
};

// function to push an element onto the stack
void push(StackArray& S, int x) {
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
int pop(StackArray& S) {
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
bool is_empty(StackArray& S) {
    return (S.top < 0);
}

bool is_full(StackArray& S) {
    return (S.top >= MAX_SIZE - 1);
}

int stackTop(StackArray& S) {
    if (S.top >= MAX_SIZE - 1) {
        cout << "Stack is empty\n";
        return -1;
    }
    else {
        return S.arr[S.top];
    }
}

void display(StackArray& S) {
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

struct Node {
    int data;
    Node* next;
};

struct StackList {
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
void push(StackList& S, int x) {
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
int pop(StackList& S) {
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
bool is_empty(StackList& S) {
    return (S.top == NULL);
}

int stack_top(StackList& S) {
    if (S.top == NULL) {
        cout << "Stack Underflow\n";
        return -1;
    }
    else {
        return S.top->data;
    }
}

void display(StackList S) {
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

#define TIMES 1000

int main() {

    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < TIMES; i++) {
        StackArray S;
        S.top = -1;
        push(S, 8);
        push(S, 10);
        push(S, 5);
        push(S, 11);
        push(S, 15);
        push(S, 23);
        push(S, 6);
        push(S, 18);
        push(S, 20);
        push(S, 17);
        display(S);

        pop(S);
        pop(S);
        pop(S);
        pop(S);
        pop(S);
        display(S);

        push(S, 4);
        push(S, 30);
        push(S, 3);
        push(S, 1);
        display(S);
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    auto time1 = duration1.count() / TIMES;

    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < TIMES; i++) {
        StackList S;
        S.top = NULL;
        push(S, 8);
        push(S, 10);
        push(S, 5);
        push(S, 11);
        push(S, 15);
        push(S, 23);
        push(S, 6);
        push(S, 18);
        push(S, 20);
        push(S, 17);
        display(S);

        pop(S);
        pop(S);
        pop(S);
        pop(S);
        pop(S);
        display(S);

        push(S, 4);
        push(S, 30);
        push(S, 3);
        push(S, 1);
        display(S);
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    auto time2 = duration2.count() / TIMES;

    cout << "Time taken by StackUsingArray: " << time1 << " microseconds" << endl;
    cout << "Time taken by StackUsingList: " << time2 << " microseconds" << endl;

    return 0;
}