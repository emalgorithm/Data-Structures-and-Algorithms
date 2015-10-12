#include "container.h"

Container::Container(size_t maxSize) {
    this->maxSize = maxSize;
}

size_t Container::size() const{
    return sizeValue;
}

bool Container::empty() const{
    return size() == 0;
}

bool Container::full() const{
    return size() == maxSize;
}
