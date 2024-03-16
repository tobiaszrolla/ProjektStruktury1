#ifndef ARRAYLIST_H
#define ARRAYLIST_H
using namespace std;

// sortowanie przez scalanie

template <typename T>
class ArrayList
{
private:
    unsigned size;
    unsigned capacity;
    T *array;
public:
    ArrayList();
    ~ArrayList();
    unsigned Size();
    T& GetIndex(unsigned index);
    void AddBack(T number);
    void AddFront(T number);
};
//Podstawowy Konstruktor z ustalonym rozmiarem
template <typename T>
ArrayList<T>::ArrayList(): size{0}, capacity{5}{
    array = new T[capacity];
}
//Destruktor
template <typename T>
ArrayList<T>::~ArrayList(){
    delete[] array;
}
template <typename T>
unsigned ArrayList<T>::Size(){
    return size;
}
template <typename T>
T& ArrayList<T>::GetIndex(unsigned index){
    if(index >= 0 && index < size){
        return &array[index];
    }
}
template <typename T>
void ArrayList<T>::AddBack(T number){
    if(size <= capacity){
        array[size] = number;
        size++;
    }
}
template <typename T>
void ArrayList<T>::AddFront(T number){
    if(size <= capacity){
        array[size] = number;
        size++;
    }
}




#endif