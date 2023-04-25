#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* left, * right;
};

// Create a new node
struct node* newNode(int key) {
    struct node* temp1 = new node;
    temp1->key = key;
    temp1->left = temp1->right = NULL;
    return temp1;
}

// Inorder traversal
void traverseInOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
}

// Insert a node
struct node* insertNode(struct node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }
    if (key < root->key) {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

struct node* minValueNode(struct node* node) {
    struct node* temp2 = node;
    while (temp2 && temp2->left != NULL) {
        temp2 = temp2->left;
    }
    return temp2;
}

// Deleting a node
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct node* temp3 = root->right;
            delete root;
            return temp3;
        }
        else if (root->right == NULL) {
            struct node* temp3 = root->left;
            delete root;
            return temp3;
        }
        struct node* temp3 = minValueNode(root->right);
        root->key = temp3->key;
        root->right = deleteNode(root->right, temp3->key);
    }
    return root;
}

// Driver code
int main() {
    struct node* root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch (operation) {
        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }

    traverseInOrder(root);
}
