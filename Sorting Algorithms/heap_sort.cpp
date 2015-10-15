#include <queue> //'priority_queue'
#include <vector> //'vector'
#include <functional> //'greater'

//'priority_queue' is the C++ implementation for an heap
//The key feature of an heap is that its top element is always the smallest 
std :: priority_queue < int, std :: vector < int>, std :: greater <int > > heap;

void heap_sort(int array[], int length) {
    for(int i = 0; i < length; i++) {
        heap.push(array[i]);
    }
    for(int i = 0; i < length; i++) {
        int nextElement = heap.top();
        heap.pop(); //remove the element from the heap
        array[i] = nextElement;
    }
}
