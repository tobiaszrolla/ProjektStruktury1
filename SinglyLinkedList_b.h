#ifndef SINGLYLINKEDLIST_B_H
#define SINGLYLINKEDLIST_B_H
#include <iostream>

using namespace std;

template<typename T>                 
class Node2 {                       
public:
    T data;                          // Definiujemy element
    Node2* next;                     // Wskaźnik na kolejny element typu Node2

    Node2(T val) : data(val), next(nullptr) {}  
};

template<typename T>                 
class SinglyLinkedList
    :public List<T>
{             
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

    bool Search(T val) {   // Funkcja do wyszukiwania elementu
        if (tail->data == val) {  // Jeśli dane w ostatnim elemencie są równe val, wyświetlamy znaleziony element
            cout << "Znaleziony element: " << tail->data << endl;  
            return(true);              
        }
        Node2<T>* current = head;     // Tworzymy current na początek listy
        while (current != nullptr) {  // Dopóki current nie jest równy nullptr, przeszukujemy listę aż natrafimy na element z wartością val
            if (current->data == val) {  
                cout << "Znaleziony element: " << current->data << endl;  
                return(true);       
            }
            current = current->next;  
        }
        if (current == nullptr){      
            cout << "Brak elementu w liście" << endl;  
            return(false);           
        }
        return(false);
    }

    void AddFront(T val) {     // Funkcja dodająca na początek
        Node2<T>* newNode = new Node2<T>(val);  // Tworzymy nowy element
        if (head == nullptr) {        // Jeśli lista jest pusta, ustawiamy head i tail na nowy element
            head = newNode;           
            tail = newNode;           
        } else {                      // W przeciwnym razie, ustawiamy next nowego elementu na obecny head, a head ustawiamy na nowy element
            newNode->next = head;     
            head = newNode;           
        }
    }

    void AddBack(T val) {       // Funkcja dodająca na koniec
        Node2<T>* newNode = new Node2<T>(val);  // Tworzymy nowy element
        if (tail == nullptr) {        // Jeśli lista jest pusta, ustawiamy head i tail na nowy element
            head = newNode;           
            tail = newNode;           
        } else {                      // W przeciwnym razie, ustawiamy tail i next przedostatniego elementu na nowy
            tail->next = newNode;     
            tail = newNode;           
        }
    }

    void AddPlace(T val, int position) {  // Funkcja dodająca na zadaną pozycję
        if (position < 0) {           // Jeśli pozycja jest mniejsza od zera, kończymy funkcję
            return;                   
        }
        if (position == 0) {          // Jeśli pozycja jest równa zero, dodajemy nowy element na początek listy
            AddFront(val);      
        } else {                      // W przeciwnym razie
            Node2<T>* newNode = new Node2<T>(val);  // Tworzymy nowy element
            Node2<T>* current = head; // Tworzymy current na początek listy
            int currentPosition = 0;  // Tworzymy zmienną przechowującą bieżącą pozycję

            while (current != nullptr && currentPosition < position - 1) {  // Przesuwamy current do elementu przed określoną pozycją
                current = current->next;  
                currentPosition++;       
            }

            if (current == nullptr) {  // Jeśli current jest równy nullptr, kończymy
                return;                 
            }

            newNode->next = current->next;  // Ustawiamy wskaźnik next nowego elementu na next bieżącego elementu
            current->next = newNode;         // Ustawiamy next bieżącego elementu na nowy element
            if (current == tail) {           // Jeśli bieżący element jest równy tail. ustawiamy go na nowy element
                tail = newNode;              
            }
        }
    }

    void RemoveFront() {          // Funkcja usuwająca na początku
        if (head == nullptr) {        // Jeśli lista jest pusta, kończymy funkcję
            return;                  
        }

        Node2<T>* temp = head;        // Tworzymy temp na pierwszy element listy
        head = head->next;            // Ustawiamy head na następny element
        delete temp;                  // Usuwamy pierwszy element
        if (head == nullptr) {        // Jeśli head jest równy nullptr, ustawiamy tail na nullptr
            tail = nullptr;           
        }
    }

    void RemoveBack() {           // Funkcja usuwająca na końcu
        if (tail == nullptr) {        // Jeśli lista jest pusta, kończymy funkcję
            return;                  
        }

        if (head == tail) {           // Jeśli lista zawiera tylko jeden element, usuwamy go
            delete head;              
            head = nullptr;           
            tail = nullptr;           
            return;                  
        }

        Node2<T>* current = head;     // Ustawiamy current na początek listy
        while (current->next != tail) {  // Dopóki next bieżącego elementu nie jest równy tail, przechodzimy do następnego elementu
            current = current->next;  
        }

        delete tail;                  // Usuwamy ostatni element
        tail = current;               // Ustawiamy tail na poprzedni element
        tail->next = nullptr;         // Ustawiamy next ostatniego elementu na nullptr
    }

    bool RemovePlace(int position) {        // Funkcja usuwająca element na podanej pozycji
        if (position < 0) {           // Jeśli pozycja jest mniejsza od zera, kończymy funkcję
            return(false);                  
        }

        if (head == nullptr) {        // Jeśli lista jest pusta, kończymy funkcję
            return(false);                   
        }
        

        if (position == 0) {          // Jeśli pozycja jest równa zero, usuwamy pierwszy element z listy
            RemoveFront();       
        } else {                      // W przeciwnym razie
            Node2<T>* current = head; // Tworzymy current na początek listy
            Node2<T>* previous = nullptr;  // Tworzymy previous i ustawiamy na nullptr
            int currentPosition = 0;  // Tworzymy zmienną przechowująca bieżącą pozycję

            while (current != nullptr && currentPosition < position) {  // Przesuwamy current do elementu przed określoną pozycją
                previous = current;     // Ustawiamy previous na bieżący element
                current = current->next;  // Przechodzimy do następnego elementu
                currentPosition++;       // Inkrementujemy bieżącą pozycję
            }

            if (current == nullptr) {  // Jeśli current jest równy nullptr, kończymy funkcję
                return(false);               

            if (current == tail) {     // Jeśli bieżący element jest równy tail, ustawiamy tail na poprzedni element
                tail = previous;        
            }

            previous->next = current->next;  // Ustawiamy next poprzedniego elementu na next bieżącego elementu
            delete current;                  //Usuwamy element z bieżącej pozycji
            return(true);               
        }
    }

    void Display() {                 // Funkcja wyświetlająca zawartość listy
        Node2<T>* current = head;     
            cout << current->data << " ";  
            current = current->next;  
        cout << endl;               
    }
};

#endif
