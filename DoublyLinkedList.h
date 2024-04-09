#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
using namespace std;

//struktura karzdego z węzłów


template <typename T>   //Struktura Node przechowująca rozmiar i wskaźniki na następny i poprzedni element
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
    int size;
    
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void AddBack(T value);
    void AddFront(T value);
    void Display();
    void AddRand(T value, int index);
    int Search(T value);
    void DeliteBack();
    void DeliteFront();
    void DeliteRandom(int index);
};

 
template <typename T>                                                               //destruktor i konstruktor listy
DoublyLinkedList<T>::DoublyLinkedList(): head(nullptr), tail(nullptr), size(0){};   
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    while (head != nullptr) {
            Node3<T>* temp = head;
            head = head->next;
            delete temp;
        }
};
template <typename T>                   //metoda wyświetlająca elementy struktury
void DoublyLinkedList<T>::Display(){
    Node3<T>* temp = head;
    while(temp != nullptr){
        cout<<temp->value<<endl;
        temp = temp->next;
    }
}

template <typename T>                          //Dodawanie do tyłu
void DoublyLinkedList<T>::AddBack(T newvalue){
    Node3<T>* newNode = new Node3<T>(newvalue); //Nowy węzeł
    if(head == nullptr){                        //Warunek pierwszego elementu
        head = newNode;
        tail = newNode;
    }
    else{                                       //Standardowe przypisanie elementów
        tail -> next = newNode;
        newNode -> previuse = tail;
        tail = newNode;
    }
    size++;
}
template <typename T>                                   //Dodawanie na początek
void DoublyLinkedList<T>::AddFront(T newvalue){     
    Node3<T>* newNode = new Node3<T>(newvalue); //Nowy węzeł
    if(head == nullptr){                        //Warunek pierwszego elementu
        head = newNode;
        tail = newNode;
    }
    else{                                        //Standardowe przypisanie elementów
        head -> previuse = newNode;
        newNode -> next = head;
        head = newNode;
    }
    size++;
}
template <typename T>                     //Wyszukiwanie od head przechodzi przez strukturę nextem aż nż do znalezienia
int  DoublyLinkedList<T>::Search(T value){
    Node3<T>* temp = head;
    int i = 0;
    while(temp != nullptr){               //Pętla która szuka aż do końca tablicy następnie zwraca index elementu
        if(temp -> value == value){
            return(i);
        }
        temp = temp->next;
        i++;
    }
}
template <typename T>                                   //Dodawnaie elementu w dowolnym miejscu
void DoublyLinkedList<T>::AddRand(T value, int index){
    if(index == 0){                                     //Kiedy początek koniec                 
        AddFront(value);
    }
    else if(index == size){
        AddBack(value);
    }
    else{
        Node3<T>* current = head;                       //Pętla przeszukująca strukturę do i
        int  i = 0;
        while(i < index - 1){
            current = current->next;
            i++;
        }
        Node3<T> *newNode = new Node3<T>(value);       //Nowy node i przypisanie wartości wskaźniką poprzedzającym i następnym
        newNode->next = current->next;
        newNode->previuse = current;
        current->next->previuse = newNode;
        current->next = newNode;
        size++;
    }

}
template <typename T>
void DoublyLinkedList<T>::DeliteBack(){
    Node3<T>* temp = tail;                      //Usuwanie elementu na końcu przez przepisanie wskaźnikuw na przedostatni element
    if(tail->previuse != nullptr){
        tail->previuse->next = nullptr;
        tail = tail->previuse;
        delete temp;
    }
    else{
        tail = nullptr;
        head = nullptr;
        delete temp;
    }
    size--;
}
template <typename T>
void DoublyLinkedList<T>::DeliteFront(){     //Usuwanie elementu na początku przez przepisanie wskaźnikuw na drugi element
    Node3<T>* temp = head;
    if(head->next != nullptr){               // Gdy element nie jest jedyny
        head->next->previuse = nullptr;      //ustawienie przed drugim jako null
        head = head->next;                  //ustawienie drugiego jako pierwsze
        delete temp;                        //usunięcie pierszego
        
    }
    else{                                   //Gdy jest jeden element ustawienie listy na pustą
        tail = nullptr;
        head = nullptr;
        delete temp;                        //usuwanie elementu
    }
    size--;                                 //dekrementacja rozmiaru              
    
}
template <typename T>
void DoublyLinkedList<T>::DeliteRandom(int index){  //Usuwanie elementu na dowolnym miejscu.
    if(index == 0){                                 //Kiedy pierszy bądz ostatni uruchamia delate Front i Back
        DeliteFront();
    }
    else if(index == size){
        DeliteBack();
    }
    else{                                           
       Node3<T>* curennt = head;                    //Wskażni przeszukujący
       int i = 0;
       while(i < index && curennt != nullptr){      //pętla gdzie dochodzimy do elementu z numerem indexu
        curennt = curennt->next;
        i++;
       }
        curennt->previuse->next = curennt->next;        // przepisanie wskażnika na następny w poprzednim
        curennt->next->previuse = curennt->previuse;    // przepisanie wskaźnika na poprzedni w nastempnym
        delete curennt;                                 // usunięcie elementu
        size--;                                         // dekrementacja rozmiaru
    }

}

#endif