#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
using namespace std;

//struktura karzdego z węzłów


template <typename T>
class Node3
{
public:
    T value;
    Node3<T>* next;
    Node3<T>* previuse;
    Node3(T value): value(value), next(nullptr), previuse(nullptr){};
};

template <typename T>
class DoublyLinkedList
{
private:
    Node3<T>* head;
    Node3<T>* tail;
    
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void AddBack(T value);
    void AddFront(T value);
    void Display();
    void AddRand(T value, int index);
    int Search(T value);

};


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(): head(nullptr), tail(nullptr) {};
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    while (head != nullptr) {
            Node3<T>* temp = head;
            head = head->next;
            delete temp;
        }
};
template <typename T>
void DoublyLinkedList<T>::Display(){
    Node3<T>* temp = head;
    while(temp != nullptr){
        cout<<temp->value<<endl;
        temp = temp->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::AddBack(T newvalue){
    Node3<T>* newNode = new Node3<T>(newvalue);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next = newNode;
        newNode -> previuse = tail;
        tail = newNode;
    }
}
template <typename T>
void DoublyLinkedList<T>::AddFront(T newvalue){
    Node3<T>* newNode = new Node3<T>(newvalue);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        head -> previuse = newNode;
        newNode -> next = head;
        head = newNode;
    }
}
template <typename T>
int DoublyLinkedList<T>::Search(T value){
    Node3<T>* temp = head;
    int i = 0;
    while(temp != nullptr){
        if(temp -> value == value){
            return(i);
        }
        temp = temp->next;
        i++;
    }
}
template <typename T>
void DoublyLinkedList<T>::AddRand(T value, int index){
    if(index == 0){
        AddFront(value);
    }
    else{
        Node3<T>* current = head;
        int  i = 0;
        while(i < index && current != nullptr){
            current = current->next;
            i++;
        }
        if(current == nullptr){
            if(i == index){
                AddBack(value);
            }
            else{
                cout<<"out of range"<<endl;
            }
        }
        else{
            Node3<T>* from_back = tail;
            AddBack(from_back->value);
            while(current != from_back){
                from_back ->value = from_back->previuse->value;
                from_back = from_back->previuse;
            }
            from_back->value = value;
        }
    }

}

#endif