#include <algorithm> //'swap'

//At the end of each iteration of the outer loop, the last i elements
//of the array are the biggest and are in sorted order

void bubble_sort(int array[], int length) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - i - 1; j++) {
            if(array[j + 1] < array[j]) {
                std :: swap(array[j + 1], array[j]);
            }
        }
    }
}
