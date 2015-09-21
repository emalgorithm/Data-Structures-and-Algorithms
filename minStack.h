/* 
 * File:   minStack.h
 * Author: ema
 *
 * Created on September 15, 2015, 5:15 PM
 */

#ifndef MINSTACK_H
#define	MINSTACK_H

#include "stack.h"

using namespace std;

template<class T> class MinStack : public Stack<T> {
public:
    MinStack();
    T min() const;
    bool push(T value);
    T pop();
private:
    Stack<T>* stackOfMinima;
    T mi;
};

template<class T> MinStack<T>::MinStack() {
    cout<<"MinStack created";
    Stack<T>();
    stackOfMinima = new Stack<T>;
}

template<class T> T MinStack<T>::min() const{
    if(this->empty()) {       
        cout<<"Minimum is not defined\n";
    }
    else {
        return mi;
    }
}

template<class T> bool MinStack<T>::push(T value) {
    //Call super function which returns true if it inserts the element in the stack successfully
    bool isStackEmpty = this->empty();
    if(Stack<T>::push(value)) {    //Super function
        if(isStackEmpty || value <= mi) {
            stackOfMinima->push(value);
            mi = value;
        } 
        return true;
    }
    else {
        return false;
    }
}

template<class T> T MinStack<T>::pop() {
    if(this->empty() == false) {     
        T removedValue = Stack<T>::pop();   //Super function
        if(removedValue == stackOfMinima->top()) {
            stackOfMinima->pop();
            mi = stackOfMinima->top();
        }
        return removedValue;
    }
    else {
        cout<<"The stack is empty, impossible to remove an element\n";
    }
}



#endif	/* MINSTACK_H */

