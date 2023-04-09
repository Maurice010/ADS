using namespace std;

// Implementacja wskaznikowa
// #########################
class Node {
public:
    int value;
    Node* next;
    Node(int x): value(x), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;
    int size;

    SinglyLinkedList(): head(nullptr), size(0) {}
    
    // Zwraca wskaznik do elementu poprzedzajacego ten o zadanej wartosci
    Node* findIndex(int value) {
        Node* current = head;
        for(int i = 0; i < size - 1; i++) {
            if(current->next->value == value || current->value == value) return current;
            current = current->next;
        }
        return nullptr;
    }

    int findValue(int index) {
        if(index >= size || index < 0) {
            throw out_of_range("Wrong index");
        }
        Node* current = head;
        for(int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    void add(int index, int value) {
        if(index > size || index < 0) return;

        Node* current = head;
        Node* node_to_add = new Node(value);

        if(index == 0) {
            node_to_add->next = current;
            head = node_to_add;
        }
        else {
            for(int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            node_to_add->next = current->next;
            current->next = node_to_add;
        }
        size++;
    }

    void remove(int value) {
        Node* current = findIndex(value);

        if(current == head && current->next->value != value) {
            Node* next_node = head->next;
            delete head;
            head = next_node;
        }
        else {
            Node* next_node = current->next->next;
            delete current->next;
            current->next = next_node;
        }
        size--;
    }

    ~SinglyLinkedList() {
        Node* node = head;
        while(head != nullptr) {
            head = head->next;
            delete node;
            node = head;
        }
    }
};

class Node2 {
public:
    int value;
    Node2* next;
    Node2* prev;
    Node2(int x): value(x), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node2* head;
    int size;

    DoublyLinkedList(): head(nullptr), size(0) {}
    
    // Zwraca wskaznik do pierwszego elemenut o zadanej wartosci
    Node2* findIndex(int value) {
        Node2* current = head;
        for(int i = 0; i < size; i++) {
            if(current->value == value) return current;
            current = current->next;
        }
        return nullptr;
    }

    int findValue(int index) {
        if(index >= size || index < 0) {
            throw out_of_range("Wrong index");
        }
        Node2* current = head;
        for(int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    void add(int index, int value) {
        if(index > size || index < 0) return;

        Node2* current = head;
        Node2* node_to_add = new Node2(value);

        if(index == 0) {
            node_to_add->next = current;
            head = node_to_add;
        }
        else {
            for(int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            node_to_add->next = current->next;
            current->next = node_to_add;
            node_to_add->prev = current;
            if(node_to_add->next != nullptr) {
                node_to_add->next->prev = node_to_add;
            }
        }
        size++;
    }

    void remove(int value) {
        Node2* current = findIndex(value);

        if(current == head) {
            Node2* next_node = head->next;
            delete head;
            head = next_node;
        }
        else {
            if(current->next != nullptr)
                current->next->prev = current->prev;
            if(current->prev != nullptr)
                current->prev->next = current->next;
            delete current;
        }
        size--;
    }

    ~DoublyLinkedList() {
        Node2* node = head;
        while(head != nullptr) {
            head = head->next;
            delete node;
            node = head;
        }
    }
};
// #########################