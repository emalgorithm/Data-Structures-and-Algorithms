const int MAX_N = 1000000;

class segment_tree {
private:
    int array[MAX_N];
    int segment_tree_array[3 * MAX_N];
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
public:
    segment_tree(int input_array[], int input_size) {
        size = input_size;
        for(int i = 0; i < size; i++) {
            array[i] = input_array[i];
        }
        build(1, 0, size - 1);
    }
    int range_minimum_query(int queryStart, int queryEnd) {
        return rmq(1, 0, size - 1, queryStart, queryEnd);
    }
};
