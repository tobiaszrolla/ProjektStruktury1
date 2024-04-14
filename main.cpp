#include <iostream>
#include <random>
#include <time.h>
#include "DoublyLinkedList.h"
#include "SinglyLinkedList_a.h"
#include "SinglyLinkedList_b.h"
#include "ArrayList.h"
#include "List.h"
#include <fstream>
using namespace std;

static int elements = 40000;
int powturzenia = 100;

void testAddBack(ArrayList<int> arraylist[], DoublyLinkedList<int> doublelist[], LinkedList<int> lista_a[], SinglyLinkedList<int> lista_b[], ofstream& zapis,int numb,int dane[]){
    long long result[4];
    int start = clock();
    for(int i = 0; i<powturzenia; i++){
        arraylist[i].AddBack(dane[numb]);
    }
    result[0] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        doublelist[i].AddBack(dane[numb]);
    }
    result[1] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_a[i].AddBack(dane[numb]);
    }
    result[2] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_b[i].AddBack(dane[numb]);
    }
    result[3] = (clock() - start);

    zapis<<"adbc"<<endl<<result[0]<<endl;
    zapis<<result[1]<<endl;
    zapis<<result[2]<<endl;
    zapis<<result[3]<<endl;
}
void testAddPlace(ArrayList<int> arraylist[], DoublyLinkedList<int> doublelist[], LinkedList<int> lista_a[], SinglyLinkedList<int> lista_b[], ofstream& zapis,int numb,int dane[]){
    long long result[4];
    int rand_place[50];
    for(int i = 0; i<powturzenia; i++){
        rand_place[i] = rand()%numb;
    }
    int start = clock();
    for(int i = 0; i<powturzenia; i++){
        arraylist[i].AddPlace(dane[numb],rand_place[i]);
    }
    result[0] =(clock() - start);
    cout<<"arr"<<endl;

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        doublelist[i].AddPlace(dane[numb],rand_place[i]);
    }
    result[1] =(clock() - start);
        cout<<"doub"<<endl;

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_a[i].AddPlace(dane[numb],rand_place[i]);
    }
    result[2] =(clock() - start);
           cout<<"a"<<endl;

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_b[i].AddPlace(dane[numb],rand_place[i]);
    }
    result[3] = (clock() - start);
               cout<<"b"<<endl;

    zapis<<"adbc"<<endl<<result[0]<<endl;
    zapis<<result[1]<<endl;
    zapis<<result[2]<<endl;
    zapis<<result[3]<<endl;
}
void testAddFront(ArrayList<int> arraylist[], DoublyLinkedList<int> doublelist[], LinkedList<int> lista_a[], SinglyLinkedList<int> lista_b[], ofstream& zapis,int numb,int dane[]){
    long long result[4];
    int start = clock();
    for(int i = 0; i<powturzenia; i++){
        arraylist[i].AddFront(dane[numb]);
    }
    result[0] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        doublelist[i].AddFront(dane[numb]);
    }
    result[1] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_a[i].AddFront(dane[numb]);
    }
    result[2] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_b[i].AddFront(dane[numb]);
    }
    result[3] = (clock() - start);

    zapis<<"adbc"<<endl<<result[0]<<endl;
    zapis<<result[1]<<endl;
    zapis<<result[2]<<endl;
    zapis<<result[3]<<endl;
}
void testSearch(ArrayList<int> arraylist[], DoublyLinkedList<int> doublelist[], LinkedList<int> lista_a[], SinglyLinkedList<int> lista_b[], ofstream& zapis,int numb,int dane[]){
    long long result[4];
    int rand_number[50];
    numb--;
    for(int i = 0; i<powturzenia; i++){
        int nr = rand()%numb;
        rand_number[i] = dane[nr];
    }
   
    int start = clock();
    for(int i = 0; i<powturzenia; i++){
        arraylist[i].Search(rand_number[i]);
    }
    result[0] =(clock() - start);
    cout<<"1"<<endl;

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        doublelist[i].Search(rand_number[i]);
    }
    result[1] =(clock() - start);
    cout<<"2"<<endl;
/*
    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_a[i].Search(rand_number[i]);
    }
    result[2] =(clock() - start);
    cout<<"3"<<endl;

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_b[i].Search(rand_number[i]);
    }
    result[3] = (clock() - start);
    cout<<"4"<<endl;*/

    zapis<<"adbc"<<endl<<result[0]<<endl;
    zapis<<result[1]<<endl;
   //zapis<<result[2]<<endl;
    //zapis<<result[3]<<endl;
}
void testRemoveBack(ArrayList<int> arraylist[], DoublyLinkedList<int> doublelist[], LinkedList<int> lista_a[], SinglyLinkedList<int> lista_b[], ofstream& zapis){
    long long result[4];
    int start = clock();
    for(int i = 0; i<powturzenia; i++){
        arraylist[i].RemoveBack();
    }
    result[0] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        doublelist[i].RemoveBack();
    }
    result[1] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_a[i].RemoveBack();
    }
    result[2] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_b[i].RemoveBack();
    }
    result[3] = (clock() - start);

    zapis<<"adbc"<<endl<<result[0]<<endl;
    zapis<<result[1]<<endl;
    zapis<<result[2]<<endl;
    zapis<<result[3]<<endl;
}
void testRemoveFront(ArrayList<int> arraylist[], DoublyLinkedList<int> doublelist[], LinkedList<int> lista_a[], SinglyLinkedList<int> lista_b[], ofstream& zapis){
    long long result[4];
    int start = clock();
    for(int i = 0; i<powturzenia; i++){
        arraylist[i].RemoveFront();
    }
    result[0] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        doublelist[i].RemoveFront();
    }
    result[1] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_a[i].RemoveFront();
    }
    result[2] =(clock() - start);

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_b[i].RemoveFront();
    }
    result[3] = (clock() - start);

    zapis<<"adbc"<<endl<<result[0]<<endl;
    zapis<<result[1]<<endl;
    zapis<<result[2]<<endl;
    zapis<<result[3]<<endl;
}
void testRemovePlace(ArrayList<int> arraylist[], DoublyLinkedList<int> doublelist[], LinkedList<int> lista_a[], SinglyLinkedList<int> lista_b[], ofstream& zapis, int numb){
    long long result[4];
    int rand_place[50];
    for(int i = 0; i<powturzenia; i++){
        rand_place[i] = rand()%numb;
    }
    int start = clock();
    for(int i = 0; i<powturzenia; i++){
        arraylist[i].RemovePlace(rand_place[i]);
    }
    result[0] =(clock() - start);
    cout<<"0"<<endl;

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        doublelist[i].RemovePlace(rand_place[i]);
    }
    result[1] =(clock() - start);
    cout<<"1"<<endl;

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_a[i].RemovePlace(rand_place[i]);
    }
    result[2] =(clock() - start);
        cout<<"2"<<endl;

    start = clock();
    for(int i = 0; i<powturzenia; i++){
        lista_b[i].RemovePlace(rand_place[i]);
    }
    result[3] = (clock() - start);
            cout<<"3"<<endl;
    
    zapis<<"adbc"<<endl<<result[0]<<endl;
    zapis<<result[1]<<endl;
    zapis<<result[2]<<endl;
    zapis<<result[3]<<endl;
}

int main(){
    ofstream zapis("./data.txt");
    srand(time(NULL));

    int dane[elements];
    for(int i = 0; i<elements; i++){
        dane[i]=rand()%1001;
    }
    ArrayList<int> listaAray[powturzenia];
    DoublyLinkedList<int> doublelist[powturzenia];
    LinkedList<int> lista_a[powturzenia];
    SinglyLinkedList<int> lista_b[powturzenia];
    for(int j = 0; j<powturzenia; j++){
        for(int i = 0; i<5000; i++){
            listaAray[j].AddBack(dane[i]);
            doublelist[j].AddBack(dane[i]);
            lista_a[j].AddBack(dane[i]);
            lista_b[j].AddBack(dane[i]);
    }
    }
    testSearch(listaAray,doublelist,lista_a,lista_b,zapis,5000,dane);
    cout<<listaAray[0].Size()<<endl;
    for(int j = 0; j<powturzenia; j++){
        for(int i = 5000; i<10000; i++){
            listaAray[j].AddBack(dane[i]);
            doublelist[j].AddBack(dane[i]);
            lista_a[j].AddBack(dane[i]);
            lista_b[j].AddBack(dane[i]);
    }
    }
    testSearch(listaAray,doublelist,lista_a,lista_b,zapis,10000,dane);
    cout<<listaAray[0].Size()<<endl;
        for(int j = 0; j<powturzenia; j++){
        for(int i = 10000; i<15000; i++){
            listaAray[j].AddBack(dane[i]);
            doublelist[j].AddBack(dane[i]);
            lista_a[j].AddBack(dane[i]);
            lista_b[j].AddBack(dane[i]);
    }
    }
    testSearch(listaAray,doublelist,lista_a,lista_b,zapis,15000,dane);
    cout<<listaAray[0].Size()<<endl;
        for(int j = 0; j<powturzenia; j++){
        for(int i = 15000; i<20000; i++){
            listaAray[j].AddBack(dane[i]);
            doublelist[j].AddBack(dane[i]);
            lista_a[j].AddBack(dane[i]);
            lista_b[j].AddBack(dane[i]);
    }
    }
    testSearch(listaAray,doublelist,lista_a,lista_b,zapis,20000,dane);
    cout<<listaAray[0].Size()<<endl;
        for(int j = 0; j<powturzenia; j++){
        for(int i = 20000; i<25000; i++){
            listaAray[j].AddBack(dane[i]);
            doublelist[j].AddBack(dane[i]);
            lista_a[j].AddBack(dane[i]);
            lista_b[j].AddBack(dane[i]);
    }
    }
    testSearch(listaAray,doublelist,lista_a,lista_b,zapis,25000,dane);
    cout<<listaAray[0].Size()<<endl;
            for(int j = 0; j<powturzenia; j++){
        for(int i = 25000; i<30000; i++){
            listaAray[j].AddBack(dane[i]);
            doublelist[j].AddBack(dane[i]);
            lista_a[j].AddBack(dane[i]);
            lista_b[j].AddBack(dane[i]);
    }
    }
    testSearch(listaAray,doublelist,lista_a,lista_b,zapis,30000,dane);
    cout<<listaAray[0].Size()<<endl;
        for(int j = 0; j<powturzenia; j++){
        for(int i = 30000; i<35000; i++){
            listaAray[j].AddBack(dane[i]);
            doublelist[j].AddBack(dane[i]);
            lista_a[j].AddBack(dane[i]);
            lista_b[j].AddBack(dane[i]);
    }
    }
    testSearch(listaAray,doublelist,lista_a,lista_b,zapis,35000,dane);
    cout<<listaAray[0].Size()<<endl;
        for(int j = 0; j<powturzenia; j++){
        for(int i = 35000; i<40000; i++){
            listaAray[j].AddBack(dane[i]);
            doublelist[j].AddBack(dane[i]);
            lista_a[j].AddBack(dane[i]);
            lista_b[j].AddBack(dane[i]);
    }
    }
    testSearch(listaAray,doublelist,lista_a,lista_b,zapis,40000,dane);



    cout<<listaAray[0].Size()<<endl;
    //zapis<<result/powturzenia<<endl;


    zapis.close();
    return(0);
}

