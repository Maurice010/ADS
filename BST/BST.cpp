#include <iostream>

class BST {
    struct node {
        int value;
        node* left;
        node* right;

        node(int value): value(value), left(nullptr), right(nullptr) {}
    };

public:
    node* root;

    // funkcja do destruktora
    void removeTree(node* current) {
        if(current == nullptr)
            return;
        removeTree(current->left);
        removeTree(current->right);
        delete current;
    }

    void insert(int x) {
        if(root == nullptr) {
            root = new node(x);
            return;
        }

        node* current = root;
        while(1) {
            if(x < current->value) {
                if(current->left == nullptr) {
                    current->left = new node(x);
                    return;
                }
                current = current->left;
            } else {
                if(current->right == nullptr) {
                    current->right = new node(x);
                    return;
                }
                current = current->right;
            }
        }
    }

    bool search(int x) {
        node* current = root;
        while(current != nullptr) {
            if(x == current->value) {
                std::cout<<"Value "<<x<<" was found.\n";
                return true;
            }
            if(x < current->value)
                current = current->left;
            else
                current = current->right;
        }
        std::cout<<"Value "<<x<<" wasn't found.\n";
        return false;
    }

    void remove(int x) {
        if(root == nullptr) {
            std::cout<<"BST has no elements.\n";
            return;
        }

        node* current = root;
        node* parent = nullptr;
        // zamiast tej zmiennej mozna sprawdzac bezposrednio
        bool currentIsLeftChild = false;

        // szukanie elementu
        while(current != nullptr && current->value != x) {
            parent = current;
            if(x < current->value) {
                current = current->left;
                currentIsLeftChild = true;
            }
            else {
                current = current->right;
                currentIsLeftChild = false;
            }
        }

        if(current == nullptr) {
            std::cout<<"Value "<<x<<" wasn't found.\n";
            return;
        }

        // #1 brak dzieci
        if(current->left == nullptr && current->right == nullptr) {
            if(parent == nullptr) {
                root = nullptr;
            }
            else if(currentIsLeftChild) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
            delete current;
        }
        // #2 jedno prawe dziecko
        else if(current->left == nullptr) {
            if(parent == nullptr) {
                root = current->right;
            }
            else if(currentIsLeftChild) {
                parent->left = current->right;
            }
            else {
                parent->right = current->right;
            }
            delete current;
        }
        // #3 jedno lewe dziecko
        else if(current->right == nullptr) {
            if(parent == nullptr) {
                root = current->left;
            }
            else if(currentIsLeftChild) {
                parent->left = current->left;
            }
            else {
                parent->right = current->left;
            }
            delete current;
        }
        // #4 prawe i lewe dziecko
        else {
            // szukanie najmniejszego nastepnika w prawym poddrzewie
            node* successor = current->right;
            node* successorParent = current;
            while(successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            if(successorParent->left == successor) {
                successorParent->left = successor->right;
            }

            // usuniecie danego elementu i zastapienie go nastepnikiem
            if(parent == nullptr) {
                root = successor;
            }
            else if(currentIsLeftChild) {
                parent->left = successor;
            }
            else {
                parent->right = successor;
            }
            successor->left = current->left;
            if(current->right != successor)
                successor->right = current->right;

            delete current;
        }
    }

    BST(): root(nullptr) {}

    ~BST() {
        removeTree(root);
    }
};