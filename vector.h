/* 
 * File:   vector.h
 * Author: ema
 *
 * Created on September 19, 2015, 3:48 PM
 */

#ifndef VECTOR_H
#define	VECTOR_H

#include "container.h"
#include <iostream>


template <class T> class Vector : Container {
public:
    typedef T* Iterator;
    Vector(size_t reservedSize = 2);
    void resize(size_t newReservedSize);
    void resize(size_t newReservedSize, T value);
    T back() const;
    bool push_back(T value);
    T pop_back();
    Iterator begin() { return array; }
    Iterator end() { return array + sizeValue; }
private:
    T* array;
    size_t reservedSize;
};

//Implementation
template <class T> Vector<T>::Vector(size_t reservedSize) {
    array = new T[reservedSize];
    this->reservedSize = reservedSize;
    sizeValue = 0;
}

template <class T> void Vector<T>::resize(size_t newReservedSize) {
    cout<<"vector resized to size "<<newReservedSize<<endl;
    T* newArray = new T[newReservedSize];
    for(int i = 0; i < size(); i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    reservedSize = newReservedSize;
}

template <class T> void Vector<T>::resize(size_t newReservedSize, T value) {
    resize(newReservedSize);
    for(int i = size(); i < newReservedSize; i++) {
        array[i] = value;
    }
}

template <class T> T Vector<T>::back() const{
    if(size() == 0) {
        cout<<"The vector is empty, impossible to show last element\n";
    }
    else {
        return array[size() - 1];
    }
}

template <class T> bool Vector<T>::push_back(T value) {
    if(size() == reservedSize) {
        resize(2 * reservedSize);
    }
    array[sizeValue++] = value;
}

template <class T> T Vector<T>::pop_back() {
    if(size() == 0) {
        cout<<"The vector is empty, impossible to remove last element\n";
    }
    else {
        return array[--sizeValue];
    }
}



#endif	/* VECTOR_H */

