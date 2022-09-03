#ifndef FORWARD_LIST
#define FORWARD_LIST

#include "node.h"

template<typename T>
class FList
{
    public:
        FList();
        FList(const T&);
        FList(const FList&);
        FList(const FList&&);
        ~FList();
    public:
        FList& operator=( FList&);
        FList& operator=(const FList&&);
        FList& operator+(const FList&);
        FList& operator+=(const FList&);
        friend std::ostream& operator<<(std::ostream & os, FList<T>& obj)  
        { 
            while(obj.head != nullptr) {    
                os << obj.head->getItem() << " ";
                obj.head = obj.head->getNext();
            }        
            return os;
        }

    public:
        bool insert(int, const T&);
        FList& push_front(const T&);
        bool remove_at(int);
        bool isEmpty() const;     
        void clear();
        T getEntry(int);
        void setEntry(int, const T&);
        Node<T>* getHead() const;
        void setHead(Node<T>*);
        int getItemCount() const;
        void setItemCount(int);
    private:
        Node<T>* head;
        int itemCount;
};
#include "forward_list.tpp"
#endif//FORWARD_LIST