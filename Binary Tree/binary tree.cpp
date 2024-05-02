#include <iostream>

using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node() {
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insertRecursive(int newKey, Node* currentRoot) {
        if (currentRoot == NULL) {
            Node* newNode = new Node();
            newNode->key = newKey;
            return newNode;
        }

        if (newKey < currentRoot->key) {
            currentRoot->left = insertRecursive(newKey, currentRoot->left);
        }
        else if (newKey > currentRoot->key) {
            currentRoot->right = insertRecursive(newKey, currentRoot->right);
        }
        return currentRoot;
    }

    void topRoot(int newKey) {
        root = insertRecursive(newKey, root);
    }

    Node* preOrderRecursive(Node* currentRoot) {
        if (currentRoot != NULL) {
            cout << currentRoot->key << " ";
            preOrderRecursive(currentRoot->left);
            preOrderRecursive(currentRoot->right);
        }
    }

    void preOrderTraversal() {
        cout << "Pre Order Traversal: ";
        preOrderRecursive(root);
        cout << endl;
    }

    Node* inOrderRecursive(Node* currentRoot) {
        if (currentRoot != NULL) {
            inOrderRecursive(currentRoot->left);
            cout << currentRoot->key << " ";
            inOrderRecursive(currentRoot->right);
        }
    }

    void inOrderTraversal() {
        cout << "In Order Traversal: ";
        inOrderRecursive(root);
        cout << endl;
    }

    Node* postOrderRecursive(Node* currentRoot) {
        if (currentRoot != NULL) {
            postOrderRecursive(currentRoot->left);
            postOrderRecursive(currentRoot->right);
            cout << currentRoot->key << " ";
        }
    }

    void postOrderTraversal() {
        cout << "Post Order Traversal: ";
        postOrderRecursive(root);
        cout << endl;
    }

    int findMinValue(Node* currentRoot) {
        while (currentRoot->left != NULL) {
            currentRoot = currentRoot->left;
        }
        return currentRoot->key;
    }

    int findMaxValue(Node* currentRoot) {
        while (currentRoot->right != NULL) {
            currentRoot = currentRoot->right;
        }
        return currentRoot->key;
    }

    int getMinValue() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        return findMinValue(root);
    }

    int getMaxValue() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        return findMaxValue(root);
    }
};

int main(int argc, char** argv) {
    BST* bin1 = new BST();

    bin1->topRoot(6);
    bin1->topRoot(7);
    bin1->topRoot(4);
    bin1->topRoot(5);
    bin1->topRoot(8);
    bin1->topRoot(3);

    bin1->preOrderTraversal();
    bin1->inOrderTraversal();
    bin1->postOrderTraversal();

    cout << "Minimum value in the tree: " << bin1->getMinValue() << endl;
    cout << "Maximum value in the tree: " << bin1->getMaxValue() << endl;

    return 0;
}