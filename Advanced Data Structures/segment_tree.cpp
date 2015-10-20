#include <vector>

class segment_tree {
private:
    vector<int> array;
    vector<int> segment_tree_array;
    int size;

    void build(int pos, int start, int end) {
        if(start == end) {
            segment_tree_array[pos] = start;
        }
        else {
            int middle = (start + end) / 2;
            int leftSon =(pos << 1);
            int rightSon = (pos << 1) + 1; 
            build(leftSon, start, middle);
            build(rightSon, middle + 1, end);
            int leftIndex = segment_tree_array[leftSon];
            int rightIndex = segment_tree_array[rightSon];
            if(array[leftIndex] <= array[rightIndex]) {
                segment_tree_array[pos] = leftIndex;
            }
            else {
                segment_tree_array[pos] = rightIndex;
            }
        }
    }

    int rmq(int pos, int start, int end, int queryStart, int queryEnd) {
        if(start > queryEnd || end < queryStart) {
        return -1;
        }    
        if(start >= queryStart && end <= queryEnd) {
            return segment_tree_array[pos];
        }
        int middle = (start + end) / 2;
        int leftSon =(pos << 1);
        int rightSon = (pos << 1) + 1; 
        int leftIndex = rmq(leftSon, start, middle, queryStart, queryEnd);
        int rightIndex = rmq(rightSon, middle + 1, end, queryStart, queryEnd);
        if(leftIndex == -1) {
            return rightIndex;
        }
        if(rightIndex == -1) {
            return leftIndex;
        }

        if(array[leftIndex] <= array[rightIndex]) {
            return leftIndex;
        }
        else {
            return rightIndex;
        }
    }
    void update_private(int pos, int start, int end, int index) {
        if(start == end && start == index) {
            return;
        }
        if(start > index || end < index) {
            return;
        }
        int middle = (start + end) / 2;
        int leftSon =(pos << 1);
        int rightSon = (pos << 1) + 1; 
        update_private(leftSon, start, middle, index);
        update_private(rightSon, middle + 1, end, index);
        int leftIndex = segment_tree_array[leftSon];
        int rightIndex = segment_tree_array[rightSon];
        if(array[leftIndex] <= array[rightIndex]) {
            segment_tree_array[pos] = leftIndex;
        }
        else {
            segment_tree_array[pos] = rightIndex;
        }
    }
public:
    segment_tree(const vector<int> &input_array) {
        size = input_array.size();
        array = input_array;
        segment_tree_array.assign(4 * size, 0);
        build(1, 0, size - 1);
    }
    int range_minimum_query(int queryStart, int queryEnd) {
        return rmq(1, 0, size - 1, queryStart, queryEnd);
    }
    void update(int index, int value) {
        array[index] = value;
        update_private(1, 0, size - 1, index);
    }
};
