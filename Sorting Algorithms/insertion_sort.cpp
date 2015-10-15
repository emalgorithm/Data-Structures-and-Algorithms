#include <algorithm> //'swap'

//At the start of each iteration of the for loop, the elements in the range 
//0...(i - 1) are sorted. Inside the loop we then insert the ith element
//in the right position to maintain the range 0...i sorted

void insertion_sort(int array[], int length) {
    for(int i = 1; i < length; i++) { 
        int j = i;               
        while(j > 0 && array[j] < array[j - 1]) {  
            std :: swap(array[j], array[j - 1]); 
            j--;
        }
    }
}
