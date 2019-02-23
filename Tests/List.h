//
// Created by Мария on 23.02.2019.
//

#ifndef LABORATORYWORK_1_LIST_H
#define LABORATORYWORK_1_LIST_H


#include <iostream>
using namespace std;


template <typename T>
class Node {
public:
    Node *nextNode;
    T field;
    Node(T field) {
        this->field = field;
        this->nextNode = nullptr;
    }
};


template <typename T>
class List {
public:

    List() {
        sizeOfList = 0;
        head = nullptr;
    }

    ~List() {
        //clear();
        head = nullptr;
    }

    void push_back(T field);
    void push_front(T field);
    void pop_back();
    void pop_front();
    void insert(T field, int index);
    T At(int index);
    void remove(int index);
    int getSize() { return sizeOfList; }
    void clear();
    void set(T field, int index);
    bool isEmpty() { return (sizeOfList == 0); }

    friend ostream& operator<< (ostream &out, const List<T> list);

private:
    Node<T> *head;
    int sizeOfList = 0;
};


template<typename T>
void List<T>::push_back(T field)
{
    if (head == nullptr) {
        head = new Node<T>(field);
    }
    else {
        Node<T> *lastItemSearch = this->head;
        while (lastItemSearch->nextNode != nullptr) {
            lastItemSearch = lastItemSearch->nextNode;
        }
        lastItemSearch->nextNode = new Node<T>(field);
    }

    sizeOfList++;
}

template<typename T>
void List<T>::push_front(T field)
{
    if (head == nullptr) {
        head = new Node<T>(field);
    }
    else {
        Node<T> *firstItem = this->head;
        head = new Node<T>(field);
        head->nextNode = firstItem;
    }

    sizeOfList++;
}

template<typename T>
void List<T>::pop_back()
{
    if (head != nullptr) {
        Node<T> *penultimateItemSearch = this->head;

        if (head->nextNode == nullptr) {
            delete penultimateItemSearch;
            head = nullptr;
        }
        else {
            while (penultimateItemSearch->nextNode->nextNode != nullptr) {
                penultimateItemSearch = penultimateItemSearch->nextNode;
            }

            delete penultimateItemSearch->nextNode;
            penultimateItemSearch->nextNode = nullptr;
        }

        sizeOfList--;
    }
}


template<typename T>
void List<T>::pop_front()
{
    if (head != nullptr) {
        Node<T> *firstElem = this->head;

        if (head->nextNode == nullptr) {
            delete firstElem;
            head = nullptr;
        }
        else {
            head = head->nextNode;
            delete firstElem;
        }

        sizeOfList--;
    }
}


template<typename T>
void List<T>::insert(T field, int index)
{
    if (index < 0) throw invalid_argument("Index must be >= 0");
    if (index > sizeOfList) throw invalid_argument("Index is larger than size of list");


    if (index == 0) push_front(field);
    else {
        Node<T> *newItem = new Node<T>(field);
        Node<T> *beforeNewItem = this->head;

        int currentIndex = 0;

        while (currentIndex + 1 != index) {
            beforeNewItem = beforeNewItem->nextNode;
            currentIndex++;
        }

        newItem->nextNode = beforeNewItem->nextNode;
        beforeNewItem->nextNode = newItem;

        sizeOfList++;
    }
}

////////im stopped here

template<typename T>
T List<T>::At(int index)
{
    if (index < 0) throw out_of_range("Index must be >= 0");
    if (index > sizeOfList) throw out_of_range("Index is larger than size of list");

    Node<T> *itemSearch = this->head;
    int currentIndex = 0;

    while (currentIndex != index) {
        //if (currentIndex == index) return itemSearch->field;
        itemSearch= itemSearch->nextNode;
        currentIndex++;
    }

    return itemSearch->field;
}

template<typename T>
void List<T>::remove(int index)
{
    if (index < 0) throw invalid_argument("Index must be >= 0");
    if (index > sizeOfList) throw invalid_argument("Index is larger than size of list");

    if (index == 0) pop_front();
    else {
        Node<T> *beforeDeleted = this->head;
        int currentIndex = 0;

        while (currentIndex + 1 != index) {
            beforeDeleted = beforeDeleted->nextNode;
            currentIndex++;
        }

        delete beforeDeleted->nextNode;
        beforeDeleted->nextNode = nullptr;

        sizeOfList--;
    }
}

template<typename T>
inline void List<T>::clear()
{
    while (head != nullptr) {
        Node<T> *itemSearch = head;
        head = head->nextNode;
        delete itemSearch;
    }

    sizeOfList = 0;
}

template<typename T>
void List<T>::set(T field, int index)
{
    if (index < 0) throw invalid_argument("Index must be >= 0");
    if (index > sizeOfList) throw invalid_argument("Index is larger than size of list");

    Node<T> *itemSearch = this->head;
    int currentIndex = 0;

    while (currentIndex != index) {
        itemSearch = itemSearch->nextNode;
        currentIndex++;
    }

    itemSearch->field = field;
}


template<typename T>
ostream &operator<<(ostream &out, List<T> list)
{

    int currentIndex = 0;
    while (currentIndex < list.getSize()) {
        cout << currentIndex << " element is {" << list.At(currentIndex) << "} " << endl;
        currentIndex++;
    }

    return out;
}



#endif //LABORATORYWORK_1_LIST_H