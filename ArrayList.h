#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "List.h"
using namespace std;

// sortowanie przez scalanie

template <typename T>
class ArrayList
    :public List<T>
{
private:
    unsigned size;
    unsigned capacity;
    T *array;
    void Resaiz(unsigned newCapacity);
public:
    ArrayList();
    ~ArrayList();
    unsigned Size();
    unsigned Capacity();
    T GetValue(unsigned index);
    void AddBack(T number);
    void AddFront(T number);
    void AddPlace(T number, unsigned index);
    void RemoveBack();
    void RemoveFront();
    void RemovePlace(unsigned index);
    void Display();
    int Search(T number);
};
//Podstawowy Konstruktor z ustalonym rozmiarem
template <typename T>
ArrayList<T>::ArrayList(): size{0}, capacity{1}{
    array = new T[capacity];
}
//Destruktor
template <typename T>
ArrayList<T>::~ArrayList(){
    delete[] array;
}
//Metoda powiększająca ArrayList w momęcie przekroczenia rozmiaru
template <typename T>
void ArrayList<T>::Resaiz(unsigned newCapacity){
    capacity = newCapacity;                         //zmiana rozmiaru tablicy
    T *array_pom = new T[capacity];                 //tablica do przepisania elementów
    for(int i = 0; i < size; i++){                  //przepisanie
        array_pom[i] = array[i];
    }
    delete[] array;                                 //usuwanie starej tablicy 
    array = array_pom;                              //array to teraz nowa tablica
    
}
template <typename T>
void ArrayList<T>::Display(){
    for(int i = 0; i<size; i++){
        cout<<array[i]<<endl;
    }
}
template <typename T>
unsigned ArrayList<T>::Size(){
    return size;
}
template <typename T>
unsigned ArrayList<T>::Capacity(){
    return capacity;
}

//metoda zwracjaąca wartość na danym indexie
template <typename T>
T ArrayList<T>::GetValue(unsigned index){
    if(index < size- 1){
        return array[index];
    }
    else{
        cout<<"out of range"<<endl;
    }
}

//metoda dodająca do tyłu;
template <typename T>
void ArrayList<T>::AddBack(T number){
    if(size != capacity){               //jeżeli starczy miejsca
        array[size] = number;           //jako ostatni jest number
        size++;                         // ilość elementów ikrementacja
    }   
    else{
        Resaiz(capacity*2);             //Powiększenie miejsca o 2
        array[size] = number;           //jako ostatni jest number
        size++;                         // ilość elementów ikrementacja
    }
}

//metoda dodająca na początek
template <typename T>
void ArrayList<T>::AddFront(T number){
    if(size == capacity){               //jeżeli ilość elementów zajmie całe miejsce
        capacity *= 2;                  //miejsce razy 2
        T *array_pom = new T[capacity]; //Noswy tablica do przepisania
        for(int i = 0; i < size; i++){
        array_pom[i+1] = array[i];      //przepisanie na kolejne miejsce
        }
        delete[] array;                 //usunięcie starej tablicy
        array = array_pom;              // zmian tablicy w miescu array
    }
    else{                              //jeżeli ilość elementów nie zajmie całe miejsce
        for(int i = size; i>0; i--){    //przepisanie na kolejne miejsce
            array[i] = array[i-1];
        }
    }
    array[0] = number;              //przypisanie pierwszego elementu tablicy
    size++;
}

//metoda usuwająca z tyłu
template <typename T> 
void ArrayList<T>::RemoveBack(){
    if(size > 0){
        size--;                     //dekrementacja ilości elementów
    }
}

//metoda usuwająca pierwszy element
template <typename T>
void ArrayList<T>::RemoveFront(){
    if(size > 0){
        size--;                         //dekrementacja ilości elementów  
        for(int i = 0; i < size; i++){
            array[i] = array[i + 1];    //przepisanie elementów
        }
    }
}
//Dodaje element na dowolne miejsce;
template <typename T>
void ArrayList<T>::AddPlace(T number, unsigned index){
    if(size == capacity){                               //gdy ilość elementów osiągnie rozmiar zwiększ tablicę i przepisz elementy
        Resaiz(capacity*2);
    }
    if(index < size && index > 0){                      //warunki że index jest w tabeli                   
        for(int i = size; i > index; i++){              //przepisanie elementów
            array[i] = array[i-1];
        }
        array[index] = number;                          // dodanie w miejscu index wartości number
        size++;                                         //ikrementacja rozmiaru
    }

}
//Usuwa dowolny element
template <typename T>
void ArrayList<T>::RemovePlace(unsigned index){
    if(size > 0 && index > 0 && index < size){         //jeśli index jiest w tablicy
        for(int i = index; i<size; i++){              //przepisz na prawo od indexu na jego miejsce
            array[i]= array[i + 1];
        }
        size--;                                       //dekrementacja ilośći elementów
    }
}
template <typename T>
int ArrayList<T>::Search(T number){
    for(int i = 0; i<size; i++){                     //dopuki nie osiąnie size
        if(number == array[i]){                      // czy to miejsce nie jest równe wartości
            return(i);                       //gdy tak zwróć wartość     
        }
    }
}
#endif