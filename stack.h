/* 
 * File:   stack.h
 * Author: ema
 *
 * Created on September 16, 2015, 5:00 PM
 */

#ifndef STACK_H
#define	STACK_H

#include "node.h"
#include <iostream>

using namespace std;

//Interface
template<class T> class Stack {
private:
    size_t size;
    Node<T>* stack;
    static const size_t maxSize = 10000000;
public:
    Stack();
    bool isEmpty();
    bool isFull();
    bool push(T value);
    T pop();
    T top();
    size_t getSize();
};

//Declaration
template<class T> Stack<T>::Stack() {
    cout<<"Stack created\n";
    size = 0;
    stack = new Node<T>(true);
}

template<class T> bool Stack<T>::push(T v) {
    if(isFull()) {
        cout<<"The stack is full\n";
        return false;
    }
    else {
        stack->next = new Node<T>(v, stack->head, stack, 0);
        stack = stack->next;
        size++;
        return true;
    }
}

template<class T> bool Stack<T>::isEmpty() {
    return size == 0;
}

template<class T> bool Stack<T>::isFull() {
    return size == maxSize;
}

template<class T> T Stack<T>::pop() {
    if(isEmpty()) {
        cout<<"The stack is empty, impossible to remove an element\n";
    }
    else {
        Node<T>* temp = stack;
        stack = stack->prev;
        stack->next = nullptr;
        size--;
        return temp->value;
    }
}

template<class T> T Stack<T>::top() {
    if(isEmpty()) {
        cout<<"The stack is empty\n";
    }
    else {
        return stack->value;
    }
}

template <class T> size_t Stack<T>::getSize() {
    return size;
}

#endif	/* STACK_H */

