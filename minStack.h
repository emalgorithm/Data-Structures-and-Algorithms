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
private:
    Stack<T>* stackOfMinima;
    T mi;
public:
    MinStack();
    T getMin();
    bool push(T value);
    T pop();
};



template<class T> MinStack<T>::MinStack() {
    cout<<"MinStack created";
    Stack<T>();
    stackOfMinima = new Stack<T>;
}

template<class T> T MinStack<T>::getMin() {
    if(Stack<T>::isEmpty()) {       //Should work without 'Stack<T>::', but it doesn't
        cout<<"Minimum is not defined\n";
    }
    else {
        return mi;
    }
}

template<class T> bool MinStack<T>::push(T value) {
    //Call super function which returns true if it inserts the element in the stack successfully
    bool isStackEmpty = Stack<T>::isEmpty();
    if(Stack<T>::push(value)) {    
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
    if(Stack<T>::isEmpty() == false) {     //Should work without 'Stack<T>::', but it doesn't
        T removedValue = Stack<T>::pop();
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

