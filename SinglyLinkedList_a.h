#ifndef SINGLYLINKEDLIST_A_H
#define SINGLYLINKEDLIST_A_H
#include <iostream>

using namespace std;              

template<typename T>                
class Node {                         
public:
    T data;                   //definicja elementu
    Node* next;                 //wskaźnik na następny węzeł    

    Node(T val) : data(val), next(nullptr) {}  
};

template<typename T>                 
class LinkedList {                   
private:
    Node<T>* head;                   
public:
    LinkedList() : head(nullptr) {}  
    ~LinkedList() {                   
        while (head != nullptr) {    
            Node<T>* temp = head;    
            head = head->next;      
            delete temp;             
        }
    }

    Node<T>* find(T val) {    // Funkcja do wyszukiwania elementu
        Node<T>* current = head;     // Ustawiamy wskaźnik current na początek listy
        while (current != nullptr) {   // Dopóki current nie jest równy nullptr, przeszukujemy wgłąb listę, aż natrafi na szukany element val
            if (current->data == val) {    
                cout << "Znaleziony element: " << current->data << endl;  
                return current;        
            }
            current = current->next;   
        }
        if (current == nullptr){     
            cout << "Brak elementu w liście" << endl;  
            return nullptr;           
        }
        }
    }

    void addToFront(T val) {         // Funkcja dodająca na początek
        Node<T>* newNode = new Node<T>(val);  // Tworzymy nowy węzeł z wartością val
        newNode->next = head;         // Ustawiamy wskaźnik next nowego elementu na obecny head
        head = newNode;               // Ustawiamy head na nowy element
    }

    void removeFromFront() {         // Funkcja usuwająca z początku
        if (head != nullptr) {        // Jeśli lista nie jest pusta, ustawiamy temp na pierwszy element i go usuwamy, a head ustawiamy na następny
            Node<T>* temp = head;     
            head = head->next;        
            delete temp;              
        }
    }

    void addToEnd(T val) {           // Funkcja dodająca na koniec
        Node<T>* newNode = new Node<T>(val);  // Tworzymy nowy węzeł z wartością val
        if (head == nullptr) {        // Jeśli lista jest pusta, ustawiamy head na nowy element
            head = newNode;           
        }
        else {                        // W przeciwnym razie ustawiamy wskaźnik temp na początek listy
            Node<T>* temp = head;    
            while (temp->next != nullptr) {  // Dopóki next węzła z temp nie jest równy nullptr, przechodzimy do następnego węzła
                temp = temp->next;    
            }
            temp->next = newNode;     // Ustawiamy wskaźnik next ostatniego elementu na nowy element
        }
    }

    void removeFromEnd() {           // Funkcja usuwająca na końcu
        if (head != nullptr) {        // Jeśli lista nie jest pusta
            if (head->next == nullptr) {  // Jeśli lista zawiera tylko jeden element, usuwamy go
                delete head;          
                head = nullptr;      
            }
            else {                    // W przeciwnym razie ustawiamy wskaźnik temp na początek listy
                Node<T>* temp = head; 
                while (temp->next->next != nullptr) {  // Dopóki next na dwa węzły dalej od temp nie jest równy nullptr
                    temp = temp->next; // Przechodzimy do następnego elementu
                }
                delete temp->next;   // Usuwamy ostatni element
                temp->next = nullptr;  // Ustawiamy next ostatniego elementu na nullptr
            }
        }
    }

    void addAtPosition(T val, int position) {  // Funkcja dodająca na określonej pozycji
        if (position < 0) {                    // Jeżeli pozycja jest ujemna, kończymy funkcję
            return; 
        }
        Node<T>* newNode = new Node<T>(val);   // Tworzymy nowy węzeł z wartością val
        if (position == 0) {                    // Jeżeli pozycja to 0, Ustawiamy next nowego węzła na obecny head, a head na nowy węzeł
            newNode->next = head;              
            head = newNode;                     
        } else {                                // W przeciwnym wypadku ustawiamy wskaźnik temp na początek listy
            Node<T>* temp = head;             
            for (int i = 0; temp != nullptr && i < position - 1; i++) {  // Przesuwamy temp do elementu przed określoną pozycją
                temp = temp->next;
            }
            if (temp == nullptr) {              // Jeżeli temp jest nullptr, kończymy funkcję
                return; 
            }
            newNode->next = temp->next;         // Ustawiamy next nowego węzła na next węzła z temp
            temp->next = newNode;               // Ustawiamy next węzła temp na nowy węzeł
        }
    }

    void removeAtPosition(int position) {       // Funckja usuwającą element na określonej pozycji
        if (position < 0) {  // Jeżeli pozycja jest ujemna, kończymy funkcję
            return; 
        }
        if (head == nullptr) {        // Jeśli lista jest pusta, kończymy funkcję
            return;                   
        }
        Node<T>* temp = head;                   // Ustawiamy wskaźnik temp na początek listy
        if (position == 0) {                    // Jeżeli pozycja to 0, przesuwamy head na następny element i usuwamy pierwszy
            head = head->next;                  
            delete temp;
        } else {                                // W przeciwnym wypadku przesuwamy temp do elementu przed określoną pozycją
            for (int i = 0; temp != nullptr && i < position - 1; i++) {  
                temp = temp->next;
            }
            if (temp == nullptr || temp->next == nullptr) {  // Jeżeli temp jest nullptr lub next węzła z temp jest nullptr, kończymy funkcję
                return; 
            }
            Node<T>* toDelete = temp->next;     // Ustawiamy wskaźnik toDelete na węzeł do usunięcia
            temp->next = toDelete->next;        // Przesuwamy next węzła z temp na next węzła z toDelete
            delete toDelete;                    // Usuwamy zawartość węzła ze wskażnikiem toDelete
        }
    }


    void display() {                  // Funkcja wyświetlająca zawartość listy
        Node<T>* temp = head;          
        while (temp != nullptr) {     
            cout << temp->data << " "; 
            temp = temp->next;         
        }
        cout << endl;              
    }
};

#endif
