#ifndef COLLECTION_HPP_
#define COLLECTION_HPP_
#include <iostream>
#include "List.hpp"
template <typename T>
class Collection;
template <typename T>
bool equal(const Collection<T>&, const Collection<T>&);
template <typename T>
class Collection{
public:
    Collection() : tol(nullptr){};
    void add(const T&);
    void remove(const T&);
    void print();
    T last();
    void printAll();
    friend bool equal<T>(const Collection&, const Collection&);


private:
    node<T>* tol;
};

template <typename T>
void Collection<T>::add(const T& prize){
    node<T>* tmp = new node<T>;
    tmp->setData(prize);
    tmp->setNext(tol);
    tol = tmp;
}

template <typename T>
void Collection<T>::remove(const T& prize){ //prize = 2
    node<T>* last = nullptr;
    node<T>* current = tol; //example ---   0 1 2 3 4 5 6
    while (current) {
        if (current->getData() == prize) {
            node<T>* tmp = current->getNext();
            if (!last){      //if (last != nullptr)
                // std::cout << "sum sum sum sum" << std::endl;
                tol = tmp;
            }
            else last->setNext(tmp);
            delete current;
            current = tmp;
        }
        else {
            last = current;
            current = current->getNext(); 
        }
        // else current = current->getNext();
    }
}

//returns the data of the last element in the list
template<typename T>
T Collection<T>::last(){
    return tol->getData();
}

template<typename T>
void Collection<T>::print(){
    node<T>* current = tol;          //addition to prevent seg fault
    while(current != nullptr){       //addition to prevent seg fault
        //prints out the information in the node
        std::cout << current->getData() << " " << std::endl;
        //points to the next node
        current = current->getNext();  
    }
    //ENDLESS LOOP
}

template<typename T>
bool equal(const Collection<T>& lhs, const Collection<T>& rhs) {
    //testing if two collections of nodes are the same
    node<T> *left = lhs.tol; //lines 65-66 tol == nullptr
    node<T> *right = rhs.tol;
    //testing all possible cases to determine whether to return true or false depending on equivalency
    //testing if == to nullptr is knowing if hit list's end
    if (left == nullptr && right == nullptr) 
        return true;
    else if (left == nullptr && right != nullptr) 
        return false;
    else if (left != nullptr && right == nullptr) 
        return false;
    //if neither list is equal to nullptr (the end of the list) then continue looping through the lists until end
    else {
        while (left != nullptr && right != nullptr) {
            if (left->getData() != right->getData())  return false;
            left = left->getNext();
            right = right->getNext();
    }
    //one value should be null if not... return false else... true
    if (left == nullptr && right != nullptr) return false;
    else if (left != nullptr && right == nullptr) return false;
    }
    // if all elements are equivalent, linked lists are the same size, return true
    return true;
}
#endif
