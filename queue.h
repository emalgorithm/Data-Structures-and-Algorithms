/* 
 * File:   queue.h
 * Author: ema
 *
 * Created on September 18, 2015, 3:51 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#include "node.h"
#include "container.h"

template <class T> class Queue : public Container {
public:
    Queue(size_t maxSize = 50000000);
    bool push(T value);
    T pop();
    T front() const;
private:
    Node<T>* queue;           
};

//Implementations
template <class T> Queue<T>::Queue(size_t maxSize) : Container(maxSize){
    queue = new Node<T>(true);
    queue->head = queue;
}

template <class T> bool Queue<T>::push(T value) {
    if(full()) {
        cout<<"The queue is full\n";
        return false;
    }
    else {
        queue->next = new Node<T>(value, queue->head, queue, nullptr);
        queue = queue->next;
        sizeValue++;
        return true;
    }
}

template <class T> T Queue<T>::pop() {
    if(empty()) {
        cout<<"The queue is empty, impossible to remove an element\n";
    }
    else {
        Node<T>* headT = queue->head;
        Node<T>* first = headT->next;
        Node<T>* second = first->next;
        if(second == nullptr) {
            queue = headT;
            queue->next = nullptr;
        }
        else {
            headT->next = second;
            second->prev = headT;
        }
        //TODO: fix memory leaks
        sizeValue--;
        return first->value;
    }
}

template <class T> T Queue<T>::front() const{
    if(empty()) {
        cout<<"The queue is empty\n";
    }
    else {
        Node<T>* headT = queue->head;
        Node<T>* first = headT->next;
        return first->value;
    }
}

#endif	/* QUEUE_H */

