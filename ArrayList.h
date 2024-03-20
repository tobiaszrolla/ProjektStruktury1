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
    void DelateBack();
    void DelateFront();
    void DelatePlace(unsigned index);
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
    capacity = newCapacity;
    T *array_pom = new T[capacity];
    for(int i = 0; i < size; i++){
        array_pom[i] = array[i];
    }
    delete[] array;
    array = array_pom;
    
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
    if(size != capacity){
        array[size] = number;
        size++;
    }
    else{
        Resaiz(capacity*2);
        array[size] = number;
        size++;
    }
}

//metoda dodająca na początek
template <typename T>
void ArrayList<T>::AddFront(T number){
    if(size == capacity){
        capacity *= 2;
        T *array_pom = new T[capacity];
        for(int i = 0; i < size; i++){
        array_pom[i+1] = array[i];
        }
        delete[] array;
        array = array_pom;
    }
    else{
        for(int i = size; i>0; i--){
            array[i] = array[i-1];
        }
    }
    array[0] = number;
    size++;
}

//metoda usuwająca z tyłu
template <typename T>
void ArrayList<T>::DelateBack(){
    if(capacity > 0){
        size--;
        Resaiz(size);
    }
}

//metoda usuwająca pierwszy element
template <typename T>
void ArrayList<T>::DelateFront(){
    if(capacity > 0){
        size--;
        T *array_pom = new T[size];
        for(int i = 0; i < size; i++){
            array_pom[i] = array[i+ 1];
        }
        delete[] array;
        array = array_pom;
        capacity = size;
    }
}
//Dodaje element na dowolne miejsce;
template <typename T>
void ArrayList<T>::AddPlace(T number, unsigned index){
    if(index < capacity){
        array[index] = number;
    }
    else{
        Resaiz(index+1);
        for(int i = size; i<index + 1; i++){
            array[i] = 0;
        }
        array[index] = number;
        size = index + 1;
    }
}
//Usuwa dowolny element
template <typename T>
void ArrayList<T>::DelatePlace(unsigned index){
    if(index <= capacity){
        T *array_pom =new T[size - 1];
        for(int i = 0; i < index; i++){
            array_pom[i] = array[i];
        }
        for(int i = index; i < size; i++){
            array_pom[i] = array[i + 1];
        }
        delete[] array;
        array = array_pom;
        size = size--;
        capacity = size;
    }
}
#endif