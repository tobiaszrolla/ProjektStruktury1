#ifndef SINGLYLINKEDLIST_A_H
#define SINGLYLINKEDLIST_A_H
#include <iostream>

using namespace std;              

template<typename T>                
class Node {                         // Definiujemy węzeł jako klasę
public:
    T data;                          // Zmienna data typu T
    Node* next;                      // Wskaźnik na kolejny element typu Node

    Node(T val) : data(val), next(nullptr) {}  // Konstruktor wieloargumentowy z ustawionymi wartościami dla data i next
};

template<typename T>                 
class LinkedList 
    :public List<T>
{                   // Definiujemy listę jako klasę
private:
    Node<T>* head;                   // Wskaźnik head na początek listy 
public:
    LinkedList() : head(nullptr) {}  // Konstruktor wieloargumentowy z ustawioną wartością head
    ~LinkedList() {                   // Destruktor klasy LinkedList
        while (head != nullptr) {    // Dopóki head nie jest równy nullptr
            Node<T>* temp = head;    // Ustawiamy temp na początek listy
            head = head->next;      // Ustawiamy head na następny element
            delete temp;             // Zwalniamy pamięć bieżącego elementu
        }
    }

    bool Search(T searchData) {    // Funkcja do wyszukiwania elementu
        Node<T>* current = head;     // Ustawiamy current na początek listy
        while (current != nullptr) {   // Dopóki current nie jest równy nullptr
            if (current->data == searchData) {    // Jeśli dane w bieżącym elemencie są równe searchData
                cout << "Znaleziony element: " << current->data << endl;  // Wyświetlamy znaleziony element
                return(true);       // Zwracamy wskaźnik na bieżący element
            }
            current = current->next;   // Przechodzimy do następnego elementu
        }
        if (current == nullptr){      // Jeśli current jest równy nullptr
            cout << "Brak elementu w liście" << endl;  // Wyświetlamy komunikat o braku elementu
            return(false);           // Zwracamy nullptr
        }
        return(false);
        }

    void AddFront(T val) {         // Funkcja dodająca na początek
        Node<T>* newNode = new Node<T>(val);  // Tworzymy nowy element
        newNode->next = head;         // Ustawiamy wskaźnik next nowego elementu na obecny head
        head = newNode;               // Ustawiamy head na nowy element
    }

    void RemoveFront() {         // Funkcja usuwająca z początku
        if (head != nullptr) {        // Jeśli lista nie jest pusta
            Node<T>* temp = head;     // Ustawiamy temp na pierwszy element listy
            head = head->next;        // Ustawiamy head na następny element
            delete temp;              // Zwalniamy pamięć bieżącego elementu
        }
    }

    void AddBack(T val) {           // Funkcja dodająca na koniec
        Node<T>* newNode = new Node<T>(val);  // TWorzymy nowy element
        if (head == nullptr) {        // Jeśli lista jest pusta
            head = newNode;           // Ustawiamy head na nowy element
        }
        else {                        // W przeciwnym razie
            Node<T>* temp = head;     // Ustawiamy temp na początek listy
            while (temp->next != nullptr) {  // Dopóki next temp nie jest równy nullptr
                temp = temp->next;     // Przechodzimy do następnego elementu
            }
            temp->next = newNode;     // Ustawiamy wskaźnik next ostatniego elementu na nowy element
        }
    }

    void RemoveBack() {           // Funkcja usuwająca na końcu
        if (head != nullptr) {        // Jeśli lista nie jest pusta
            if (head->next == nullptr) {  // Jeśli lista zawiera tylko jeden element
                delete head;          // Zwolniamy pamięć jedynego elementu
                head = nullptr;       // Ustawiamy head na nullptr
            }
            else {                    // W przeciwnym razie
                Node<T>* temp = head; // Ustawiamy temp na początek listy
                while (temp->next->next != nullptr) {  // Dopóki next next temp nie jest równy nullptr
                    temp = temp->next; // Przechodzimy do następnego elementu
                }
                delete temp->next;   // Zwolniamy pamięć ostatniego elementu
                temp->next = nullptr;  // Ustawiamy next ostatniego elementu na nullptr
            }
        }
    }

    void AddPlace(T val, int position) {  // Funkcja dodająca na określonej pozycji
        if (position < 0) {                    // Jeżeli pozycja jest ujemna, kończymy funkcję
            return; 
        }
        Node<T>* newNode = new Node<T>(val);   // Tworzymy nowy węzeł z wartością 'val'
        if (position == 0) {                    // Jeżeli pozycja to 0
            newNode->next = head;               // Ustawiamy 'next' nowego węzła na obecny 'head'
            head = newNode;                     // Ustawiamy 'head' na nowy węzeł
        } else {                                // Jeżeli pozycja nie jest 0
            Node<T>* temp = head;               // Ustawiamy wskaźnik 'temp' na początek listy
            for (int i = 0; temp != nullptr && i < position - 1; i++) {  // Przesuwamy 'temp' do elementu przed określoną pozycją
                temp = temp->next;
            }
            if (temp == nullptr) {              // Jeżeli 'temp' jest nullptr, kończymy funkcję
                return; 
            }
            newNode->next = temp->next;         // Ustawiamy 'next' nowego węzła na 'next' węzła 'temp'
            temp->next = newNode;               // Ustawiamy 'next' węzła 'temp' na nowy węzeł
        }
    }

    bool RemovePlace(int position) {       // Funckja usuwającą element na określonej pozycji
        if (position < 0) {  // Jeżeli pozycja jest ujemna lub lista jest pusta, kończymy funkcję
            return(false); 
        }
        if (head == nullptr) {        // Jeśli lista jest pusta
            return(false);                   // kończymy funkcję
        }
        Node<T>* temp = head;                   // Ustawiamy wskaźnik 'temp' na początek listy
        if (position == 0) {                    // Jeżeli pozycja to 0
            head = head->next;                   // Przesuwamy 'head' na następny element
            delete temp;                         // Zwalniamy pamięć bieżącego elementu
        } else {                                // Jeżeli pozycja nie jest 0
            for (int i = 0; temp != nullptr && i < position - 1; i++) {  // Przesuwamy 'temp' do elementu przed określoną pozycją
                temp = temp->next;
            }
            if (temp == nullptr || temp->next == nullptr) {  // Jeżeli 'temp' jest nullptr lub 'next' węzła 'temp' jest nullptr, kończymy funkcję
                return(false); 
            }
            Node<T>* toDelete = temp->next;     // Ustawiamy wskaźnik 'toDelete' na węzeł do usunięcia
            temp->next = toDelete->next;        // Przesuwamy 'next' węzła 'temp' na 'next' węzła 'toDelete'
            delete toDelete;   
            return(true);                 // Zwalniamy pamięć węzła 'toDelete'
        }
    }


    void Display() {                  // Funkcja wyświetlająca zawartość listy
        Node<T>* temp = head;          // Ustawiamy temp na początek listy
        while (temp != nullptr) {      // Dopóki temp nie jest równy nullptr
            cout << temp->data << " "; // Wyświetlamy dane bieżącego elementu
            temp = temp->next;         // Przechodzimy do następnego elementu
        }
        cout << endl;              
    }
};

#endif                               

