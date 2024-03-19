#include <iostream>
#include "DoublyLinkedList.h"
#include "SinglyLinkedList_a.h"
#include "SinglyLinkedList_b.h"
#include "ArrayList.h"
using namespace std;

int main(){
    //Program na testy
    ArrayList<int> Array;
    int z = 0;
    while(z<5){
        Array.AddFront(z*2);
        cout<<Array.GetValue(z)<<endl;
        z++;
    }
    return 0;
}