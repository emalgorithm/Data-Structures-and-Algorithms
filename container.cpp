#include "container.h"

Container::Container(size_t maxSize) {
    this->maxSize = maxSize;
}

size_t Container::size() {
    return sizeValue;
}

bool Container::empty() {
    return size() == 0;
}

bool Container::full() {
    return size() == maxSize;
}
