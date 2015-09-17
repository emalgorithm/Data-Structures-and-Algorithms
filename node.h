/* 
 * File:   list.h
 * Author: ema
 *
 * Created on September 16, 2015, 5:07 PM
 */

#ifndef LIST_H
#define	LIST_H

using namespace std;

//Interface
template<class T> class Node {
private:
    bool isNodeHead;

public:
    Node<T>* head;
    Node<T>* next;
    Node<T>* prev;
    T value;
    Node(T value, Node<T>* head, Node<T>* prev, Node<T>* next);
    Node();
    Node(bool isNodeHead);
    bool isHead();
};

//Implementation
template<class T> Node<T>::Node(T value, Node<T>* head, Node<T>* prev, Node<T>* next) {
    this->head = head;
    this->prev = prev;
    this->next = next;
    this->value = value;
    isNodeHead = false;
}

template<class T> Node<T>::Node() {
    head = nullptr;
    prev = nullptr;
    next = nullptr;
    isNodeHead = false;
}

template <class T> Node<T>::Node(bool isNodeHead) {
    head = nullptr;
    prev = nullptr;
    next = nullptr;
    this->isNodeHead = isNodeHead;
}

template <class T> bool Node<T>::isHead() {
    return isNodeHead;
}


#endif	/* LIST_H */

