//'quick_sort' at first partition the array around an element called pivot,
//such that all elements on its left are smaller than or equal to it and
//all elements on its right are greater than or equal to it.
//Then it sorts the two partitions of the array independently recursively.
//Its worst case is O(N ^ 2) even if its running time is much more frequently
//O(N * log N). Moreover it doesn't use additional memory.
//A little drawback is that it's not stable 

void quick_sort(int array[], int start, int end) {
    if(start >= end) {
        return;
    }
    int pivotIndex = end;
    int pivot = array[pivotIndex];
    int index = start - 1;

    for(int i = start; i < end; i++) {
        if(array[i] <= pivot) {
            index++;
            swap(array[index], array[i]);
        }
    }
    swap(array[pivotIndex], array[index + 1]);
    pivotIndex = index + 1;

    quick_sort(array, start, pivotIndex - 1);
    quick_sort(array, pivotIndex + 1, end);
}
