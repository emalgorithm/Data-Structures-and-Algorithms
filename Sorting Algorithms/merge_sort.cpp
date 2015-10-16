//The initial call will be merge_sort(array, 0, length)
//The algorithm then procedes diving the array in half and sorting
//each part independently. Once this step has been done, the algorithm
//merge the two sorted halves in a longer sorted array
//The complexity of merge_sort is therefore O(N * log N)

const int MAX_VALUE = 1 << 30; 
//This value need to be greater than every number in the array

void merge_sort(int array[], int start, int end) {
    if(start + 1 == end) { //Just one element, it is already sorted
        return;
    }

    int middle = (end + start) / 2;
    
    merge_sort(array, start, middle);  
    merge_sort(array, middle, end);   
    
    int leftLength = middle - start;
    int leftArray[leftLength + 1];
    for(int i = 0; i < leftLength; i++) {
        leftArray[i] = array[start + i];
    }
    leftArray[leftLength] = MAX_VALUE;

    int rightLength = end - middle;
    int rightArray[rightLength + 1];
    for(int i = 0; i < rightLength; i++) {
        rightArray[i] = array[middle + i];
    }
    rightArray[rightLength] = MAX_VALUE;

    int leftIndex = 0;
    int rightIndex = 0;
    for(int i = start; i < end; i++) {
        int leftElement = leftArray[leftIndex];
        int rightElement = rightArray[rightIndex];   
        if(leftElement <= rightElement) {
            array[i] = leftElement;
            leftIndex++;
        }
        else {
            array[i] = rightElement;
            rightIndex++;
        }
    }
}
