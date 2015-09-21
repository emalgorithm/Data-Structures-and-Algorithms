/* 
 * File:   stack.h
 * Author: ema
 *
 * Created on September 16, 2015, 5:00 PM
 */

#ifndef STACK_H
#define	STACK_H

#include "node.h"
#include "container.h"
#include <iostream>

using namespace std;

//Interface
template<class T> class Stack : public Container {
public:
    Stack(size_t maxSize = 50000000);
    bool push(T value);
    T pop();
    T top() const;
private:
    Node<T>* stack;
};

//Declaration
template<class T> Stack<T>::Stack(size_t maxSize) : Container(maxSize){
    stack = new Node<T>(true);
    stack->head = stack;
}

template<class T> bool Stack<T>::push(T v) {
    if(full()) {
        cout<<"The stack is full\n";
        return false;
    }
    else {
        stack->next = new Node<T>(v, stack->head, stack, 0);
        stack = stack->next;
        sizeValue++;
        return true;
    }
}

template<class T> T Stack<T>::pop() {
    if(empty()) {
        cout<<"The stack is empty, impossible to remove an element\n";
    }
    else {
        Node<T>* temp = stack;
        stack = stack->prev;
        stack->next = nullptr;
        sizeValue--;
        return temp->value;
                //TODO: fix memory leaks
    }
}

template<class T> T Stack<T>::top() const{
    if(empty()) {
        cout<<"The stack is empty\n";
    }
    else {
        return stack->value;
    }
}

#endif	/* STACK_H */

