#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void create() {
        int ch = 1;
        while (ch) {
            int value;
            cout << "\nEnter the data to insert: ";
            cin >> value;

            Node* newNode = new Node(value);

            if (head == nullptr) {
                head = tail = newNode;  // Initialize head and tail
            } else {
                tail->next = newNode;   // Link the new node at the end
                newNode->prev = tail;   // Set the previous pointer
                tail = newNode;         // Move the tail pointer
            }

            cout << "\nEnter the choice:\n1. Continue\n0. Exit: ";
            cin >> ch;
        }
    }

    void display() {
        cout << "\nThe elements in the doubly linked list:" << endl;
        Node* current = head;
        cout<<"\nThe elements in reverse order:"<<endl;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
        cout<<"\nThe elements in reverse order:"<<endl;
        current=tail;
        while(current)
        {
            cout<<current->data<<" ";
            current=current->prev;
        }
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList dL;
    dL.create();
    dL.display();
    return 0;
}
