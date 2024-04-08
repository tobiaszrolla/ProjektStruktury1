#include <iostream>
#include <random>
#include <time.h>
#include "DoublyLinkedList.h"
#include "SinglyLinkedList_a.h"
#include "SinglyLinkedList_b.h"
#include "ArrayList.h"
using namespace std;


int main(){
    srand(time(NULL));
    //Program na testy
    DoublyLinkedList<int> DoubleList;
    DoubleList.AddBack(444);
    for(int i = 0; i< 10; i++){
        DoubleList.AddBack(rand()%10);
    }
    DoubleList.Display();
    cout<<endl;
    DoubleList.DeliteRandom(3);
    DoubleList.Display();  

    return 0;
}