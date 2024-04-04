#ifndef SINGLYLINKEDLIST_B_H
#define SINGLYLINKEDLIST_B_H
#include <iostream>

using namespace std;

template<typename T>
class Node2 {
public:
    T data;
    Node2* next;

    Node2(T newData) : data(newData), next(nullptr) {}
};

template<typename T>
class SinglyLinkedList {
private:
    Node2<T>* head;
    Node2<T>* tail;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    ~SinglyLinkedList() {
        Node2<T>* current = head;
        while (current != nullptr) {
            Node2<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void addToFront(T newData) {
        Node2<T>* newNode = new Node2<T>(newData);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addToBack(T newData) {
        Node2<T>* newNode = new Node2<T>(newData);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addAtPosition(T newData, int position) {
        if (position < 0) {
            cerr << "Position must be a non-negative integer." << endl;
            return;
        }

        if (position == 0) {
            addToFront(newData);
        } else {
            Node2<T>* newNode = new Node2<T>(newData);
            Node2<T>* current = head;
            int currentPosition = 0;

            while (current != nullptr && currentPosition < position - 1) {
                current = current->next;
                currentPosition++;
            }

            if (current == nullptr) {
                cerr << "Position exceeds the size of the list." << endl;
                return;
            }

            newNode->next = current->next;
            current->next = newNode;
            if (current == tail) {
                tail = newNode;
            }
        }
    }

    void removeFromFront() {
        if (head == nullptr) {
            cerr << "List is empty. Cannot remove from an empty list." << endl;
            return;
        }

        Node2<T>* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void removeFromBack() {
        if (tail == nullptr) {
            cerr << "List is empty. Cannot remove from an empty list." << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node2<T>* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    void removeAtPosition(int position) {
        if (position < 0) {
            cerr << "Position must be a non-negative integer." << endl;
            return;
        }

        if (head == nullptr) {
            cerr << "List is empty. Cannot remove from an empty list." << endl;
            return;
        }

        if (position == 0) {
            removeFromFront();
        } else {
            Node2<T>* current = head;
            Node2<T>* previous = nullptr;
            int currentPosition = 0;

            while (current != nullptr && currentPosition < position) {
                previous = current;
                current = current->next;
                currentPosition++;
            }

            if (current == nullptr) {
                cerr << "Position exceeds the size of the list." << endl;
                return;
            }

            if (current == tail) {
                tail = previous;
            }

            previous->next = current->next;
            delete current;
        }
    }

    void printList() {
        Node2<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


#endif
