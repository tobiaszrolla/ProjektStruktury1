#include <iostream>
#include "DoublyLinkedList.h"
#include "SinglyLinkedList_a.h"
#include "SinglyLinkedList_b.h"
#include "ArrayList.h"
using namespace std;

int main(){
    //Program na testy
    ArrayList<int> Array;
    for(int i = 1; i <= 20; i++){
        Array.AddFront(i*3);
    }
    for(int i = 0; i < 20; i++){
        cout<<Array.GetValue(i)<<endl;
    }
    cout<<Array.Size()<<endl;
    cout<<Array.Capacity()<<endl<<endl;
    /*for(int i = 0; i <5; i++){
        Array.DelateFront();
    }*/
    //Array.AddPlace(666,19);
    Array.DelatePlace(19);
    cout<<Array.Size()<<endl;
    cout<<Array.Capacity()<<endl<<endl;
    for(int i = 0; i < 20; i++){
        cout<<Array.GetValue(i)<<endl;
    }
    cout<<Array.GetValue(20)<<endl;
    
    return 0;
}