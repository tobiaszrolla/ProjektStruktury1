#ifndef SINGLYLINKEDLIST_B_H
#define SINGLYLINKEDLIST_B_H
#include <iostream>

using namespace std;

template<typename T>                 
class Node2 {                        // Definiujemy węzeł jako klasę
public:
    T data;                          // Zmienna data typu T
    Node2* next;                     // Wskaźnik na kolejny element typu Node2

    Node2(T newData) : data(newData), next(nullptr) {}  // Konstruktor wieloargumentowy inicjalizujący wartości dla data i next
};

template<typename T>                 
class SinglyLinkedList
    :public List<T>
{             // Definiujemy listę jako klasę 
private:
    Node2<T>* head;                  // Wskaźnik na początek listy typu Node2<T>
    Node2<T>* tail;                  // Wskaźnik na koniec listy typu Node2<T>

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}  // Konstruktor inicjalizujący wartoci dla head i tail
    ~SinglyLinkedList() {            // Destruktor 
        Node2<T>* current = head;    // Ustawiamy wskaźnik current na początek listy
        while (current != nullptr) { // Dopóki current nie jest równy nullptr
            Node2<T>* next = current->next;  // Ustawiamy next na wskaźnik na następny element
            delete current;           // Zwalniamy pamięć bieżącego elementu
            current = next;           // Przechodzimy do następnego elementu
        }
    }

    bool Search(T searchData) {   // Funkcja do wyszukiwania elementu
        if (tail->data == searchData) {  // Jeśli dane w ostatnim elemencie są równe searchData
            cout << "Znaleziony element: " << tail->data << endl;  // Wyświetlamy znaleziony element
            return(true);              // Zwracamy wskaźnik na ostatni element
        }
        Node2<T>* current = head;     // Ustawiamy current na początek listy
        while (current != nullptr) {  // Dopóki current nie jest równy nullptr
            if (current->data == searchData) {  // Jeśli dane w bieżącym elemencie są równe searchData
                cout << "Znaleziony element: " << current->data << endl;  // Wyświetlamy znaleziony element
                return(true);        // Zwracamy wskaźnik na bieżący element
            }
            current = current->next;  // Przechodzimy do następnego elementu
        }
        if (current == nullptr){      // Jeśli current jest równy nullptr
            cout << "Brak elementu w liście" << endl;  // Wyświetlamy komunikat o braku elementu
            return(false);           // Zwracamy nullptr
        }
        return(false);
    }

    void AddFront(T newData) {     // Funkcja dodająca na początek
        Node2<T>* newNode = new Node2<T>(newData);  // Tworzymy nowy element
        if (head == nullptr) {        // Jeśli lista jest pusta
            head = newNode;           // Ustaiamy head na nowy element
            tail = newNode;           // Ustawiamy tail na nowy element
        } else {                      // W przeciwnym razie
            newNode->next = head;     // Ustawiamy wskaźnik next nowego elementu na obecny head
            head = newNode;           // Ustawiamy head na nowy element
        }
    }

    void AddBack(T newData) {       // Funkcja dodająca na koniec
        Node2<T>* newNode = new Node2<T>(newData);  // Tworzymy nowy element
        if (tail == nullptr) {        // Jeśli lista jest pusta
            head = newNode;           // Ustawiamy head na nowy element
            tail = newNode;           // Ustawiamy tail na nowy element
        } else {                      // W przeciwnym razie
            tail->next = newNode;     // Ustawiamy wskaźnik next ostatniego elementu na nowy element
            tail = newNode;           // Ustawiamy tail na nowy element
        }
    }

    void AddPlace(T newData, int position) {  // Funkcja dodająca na zadaną pozycję
        if (position < 0) {           // Jeśli pozycja jest mniejsza od zera
            return;                   // Kończymy funkcję
        }
        if (position == 0) {          // Jeśli pozycja jest równa zero
            AddFront(newData);      // Dodajemy nowy element na początek listy
        } else {                      // W przeciwnym razie
            Node2<T>* newNode = new Node2<T>(newData);  // Tworzymy nowy element
            Node2<T>* current = head; // Ustawiamy current na początek listy
            int currentPosition = 0;  // Zmienna przechowująca bieżącą pozycję

            while (current != nullptr && currentPosition < position - 1) {  // Dopóki current nie jest równy nullptr i bieżąca pozycja jest mniejsza od pozycji - 1
                current = current->next;  // Przechodzimy do następnego elementu
                currentPosition++;       // Inkrementujemy bieżącą pozycję
            }

            if (current == nullptr) {  // Jeśli current jest równy nullptr
                return;                 // Kończymy funkcję
            }

            newNode->next = current->next;  // Ustawiamy wskaźnik next nowego elementu na next bieżącego elementu
            current->next = newNode;         // Ustawiamy next bieżącego elementu na nowy element
            if (current == tail) {           // Jeśli bieżący element jest równy tail
                tail = newNode;              // Ustawiamy tail na nowy element
            }
        }
    }

    void RemoveFront() {          // Funkcja usuwająca na początku
        if (head == nullptr) {        // Jeśli lista jest pusta
            return;                   // Kończymy funkcję
        }

        Node2<T>* temp = head;        // Ustawiamy temp na pierwszy element listy
        head = head->next;            // Ustawiamy head na następny element
        delete temp;                  // Zwalniamy pamięć bieżącego elementu
        if (head == nullptr) {        // Jeśli head jest równy nullptr
            tail = nullptr;           // Ustawiamy tail na nullptr
        }
    }

    void RemoveBack() {           // Funkcja usuwająca na końcu
        if (tail == nullptr) {        // Jeśli lista jest pusta
            return;                   // KOńczymy funkcję
        }

        if (head == tail) {           // Jeśli lista zawiera tylko jeden element
            delete head;              // Zwolniamy pamięć jedynego elementu
            head = nullptr;           // Ustawiamy head na nullptr
            tail = nullptr;           // Ustawiamy tail na nullptr
            return;                   // Kończymy funkcję
        }

        Node2<T>* current = head;     // Ustawiamy current na początek listy
        while (current->next != tail) {  // Dopóki next bieżącego elementu nie jest równy tail
            current = current->next;  // Przechodzimy do następnego elementu
        }

        delete tail;                  // Zwalniamy pamięć ostatniego elementu
        tail = current;               // Ustawiamy tail na poprzedni element
        tail->next = nullptr;         // Ustawiamy next ostatniego elementu na nullptr
    }

    bool RemovePlace(int position) {        // Funkcja usuwająca element na podanej pozycji
        if (position < 0) {           // Jeśli pozycja jest mniejsza od zera
            return(false);                   // Kończymy funkcję
        }

        if (head == nullptr) {        // Jeśli lista jest pusta
            return(false);                   // Kończymy funkcję
        }
        

        if (position == 0) {          // Jeśli pozycja jest równa zero
            RemoveFront();       // Usuwamy pierwszy element z listy
        } else {                      // W przeciwnym razie
            Node2<T>* current = head; // Ustawiamy current na początek listy
            Node2<T>* previous = nullptr;  // Ustawiamy previous na nullptr
            int currentPosition = 0;  // Zmienna przechowująca bieżącą pozycję

            while (current != nullptr && currentPosition < position) {  // Dopóki current nie jest równy nullptr i bieżąca pozycja jest mniejsza od pozycji
                previous = current;     // Ustawiamy previous na bieżący element
                current = current->next;  // Przechodzimy do następnego elementu
                currentPosition++;       // Inkrementujemy bieżącą pozycję
            }

            if (current == nullptr) {  // Jeśli current jest równy nullptr
                cerr << "Position exceeds the size of the list." << endl;  // Wyświetlamy komunikat o błędzie
                return(false);                 // Kończymy funkcję
            }

            if (current == tail) {     // Jeśli bieżący element jest równy tail
                tail = previous;        // Ustawiamy tail na poprzedni element
            }

            previous->next = current->next;  // Ustawiamy next poprzedniego elementu na next bieżącego elementu
            delete current;
            return(true);               // Zwalniamy pamięć bieżącego elementu
        }
    }

    void Display() {                 // Funkcja wyświetlająca zawartość listy
        Node2<T>* current = head;     // Ustawiamy current na początek listy
        while (current != nullptr) {  // Dopóki current nie jest równy nullptr
            cout << current->data << " ";  // Wyświetlamy dane bieżącego elementu
            current = current->next;  // Przechodzimy do następnego elementu
        }
        cout << endl;               
    }
};

#endif
