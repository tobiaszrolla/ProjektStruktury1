#ifndef LIST_H
#define LIST_H

template<typename T>
class List{
    public:
        List()= default;
        ~List() = default;

        virtual void AddFront(T element)=0;
        virtual void AddBack(T element) =0;
        virtual void AddPlace(T element, int index)=0;
        virtual void RemoveFront()=0;
        virtual void RemoveBack()=0;
        virtual bool RemovePlace(int index)=0;
        virtual bool Search(T element)=0;
        virtual void Display()=0;




};
#endif