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
    void Resaiz();
    void HelpAddFront();
public:
    ArrayList();
    ~ArrayList();
    unsigned Size();
    T& GetPlace(unsigned index);
    T GetValue(unsigned index);
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
//Metoda powiększająca ArrayList w momęcie przekroczenia rozmiaru
template <typename T>
void ArrayList<T>::Resaiz(){
    T *array_pom = new T[capacity*2];
    for(int i = 0; i < capacity; ++i){
        array_pom[i] = array[i];
    }
    delete[] array;
    array = array_pom;
    capacity = capacity*2;
    
}
template <typename T>
void ArrayList<T>::HelpAddFront(){
        T *array_pom = new T[capacity];
        for(int i = 0; i < capacity; ++i){
        array_pom[i+1] = array[i];
        }
        delete[] array;
        array = array_pom;
}
template <typename T>
unsigned ArrayList<T>::Size(){
    return size;
}
template <typename T>
T& ArrayList<T>::GetPlace(unsigned index){
    if(index >= 0 && index < size){
        return &array[index];
    }
}

//metoda zwracjaąca wartość na danym indexie
template <typename T>
T ArrayList<T>::GetValue(unsigned index){
    if(index >= 0 && index < size){
        return array[index];
    }
}

//metoda dodająca do tyłu;
template <typename T>
void ArrayList<T>::AddBack(T number){
    if(size != capacity){
        array[size] = number;
        size++;
    }
    else{
        Resaiz();
        array[size] = number;
        size++;
    }
}
template <typename T>
void ArrayList<T>::AddFront(T number){
    if(size < capacity){
    }
    else{
    }
}





#endif