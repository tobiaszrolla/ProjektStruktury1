#include <iostream>
#include <unistd.h>
#include <termio.h>
#include "DoublyLinkedList.h"
#include "SinglyLinkedList_a.h"
#include "SinglyLinkedList_b.h"
#include "ArrayList.h"
#include "List.h"
using namespace std;

void menu(List<int>* lista){
    bool wyjscie = false;
    char key;
    int value;
    int index;
    while(wyjscie == false){
        cout<<"Add Back 1:"<<endl<<"Add Front 2:"<<endl<<"Add in Position 3:"<<endl<<"Remove Back 4:"
        <<endl<<"Remove Front 5:"<<endl<<"Remove in Position 6:"<<endl<<"Search 7:"<<endl<<"Display 8:"<<endl<<"Quit q:"<<endl;
        cin>>key;
        switch (key){
            case '1':
                cout<<"Podaj liczbę"<<endl;
                cin>>value;
                lista->AddBack(value);
                break;
            case '2':
                cout<<"Podaj liczbę"<<endl;
                cin>>value;
                lista->AddFront(value);
                break;
             case '3':
                cout<<"Podaj liczbę"<<endl;
                cin>>value;
                cout<<"Podaj index"<<endl;
                cin>>index;
                lista->AddPlace(value,index);
                break;
            case '4':
                cout<<"Usuwam"<<endl;
                lista->RemoveBack();
                break;
            case '5':
                cout<<"Usuwam"<<endl;
                lista->RemoveFront();
                break;
             case '6':
                cout<<"Podaj index"<<endl;
                cin>>index;
                lista->RemovePlace(index);
                break; 
            case '7':
                cout<<"Podaj Liczbę do wyszukania"<<endl;
                cin>>value;
                lista->Search(value);
                break;  
            case '8':
                cout<<"Wyświetlam"<<endl;
                lista->Display();
                break;
            case 'Q':
                wyjscie = true;
                break;
            case 'q':
                wyjscie = true;
                break;

            default:
                {}
        }
    }

}

int main(){
    ArrayList<int> array_list;
    DoublyLinkedList<int> double_list;
    LinkedList<int> list_a;
    SinglyLinkedList<int> list_b;
    List<int>* lista = &array_list;
    
    bool wyjscie = false;
    char key;
    while (wyjscie != true)
    {
        cout<<"ArrayList 1"<<endl<<"DoubleLinkedList 2"<<endl<<"Single Linked List 3"<<endl<<"Single Linked Listn (with tail)  4"<<endl<<"wyjscie Q"<<endl;
        cin>>key;
        switch (key){
            case '1':
                lista = &array_list;
                menu(lista);
                break;
            case '2':
                lista = &double_list;
                menu(lista);
                break;
            case '3':
                lista = &list_a;
                menu(lista);
                break;
            case '4':
                lista = &list_b;
                menu(lista);
                break;
            case 'Q':
                wyjscie = true;
                break;
            case 'q':
                wyjscie = true;
                break;

            default:
                {}
        }
    }
    return(0);
}


