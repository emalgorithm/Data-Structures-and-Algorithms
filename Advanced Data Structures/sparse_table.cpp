#include <string.h> //'memset'
#include <math.h> //'log2'

//In sparse-table-matrix[i][j] we store the index of the minimum element in the
//subarray starting from i and of length 2 to the j (which can be calculated as
//(1 << j) using bitwise operations).
//This data structure provides an efficient solution for the static version of
//the range minimum query (RMQ) problem. it has a O(N * log N) complexity for
//the preprocessing and a O(1) complexity for each query.

const int MAX_N = 100000;
const int LOG_TWO_MAX_N = 20; //This number contains an upper bound for MAX_N

class sparse_table {
private:
    int array[MAX_N];
    int sparse_table_matrix[MAX_N][LOG_TWO_MAX_N];
public:
    sparse_table(int input_array[], int size) {
        for(int i = 0; i < size; i++) {
            array[i] = input_array[i];
        }
        memset(sparse_table_matrix, -1, sizeof sparse_table_matrix);
        for(int i = 0; i < size; i++) {
            for(int j = 0; i + (1 << j) <= size; j++) {
                compute_sparse_table(i, j);
            }
        }
    }

    int compute_sparse_table(int start, int logLength) {
        if(logLength == 0) {  //Base case, just one element so it is the minimun
            return sparse_table_matrix[start][logLength] = start;
        }
        if(sparse_table_matrix[start][logLength] != -1) {
            return sparse_table_matrix[start][logLength];
        }

        int halfIndex = start + (1 << (logLength - 1));
        int firstHalf = compute_sparse_table(start, logLength - 1);
        int secondHalf = compute_sparse_table(halfIndex, logLength - 1);
     
        if(array[firstHalf] <= array[secondHalf]) {
            sparse_table_matrix[start][logLength] = firstHalf;
        }
        else {
            sparse_table_matrix[start][logLength] = secondHalf;
        }

        return sparse_table_matrix[start][logLength];
    }

    int range_minimum_query(int start, int end) {
        int length = end - start + 1;
        int logLength = floor(log2(length));
        int firstPart = sparse_table_matrix[start][logLength];
        int secondPart = sparse_table_matrix[end - (1 << logLength) + 1][logLength];
        
        if(array[firstPart] <= array[secondPart]) {
            return firstPart;
        }
        else {
            return secondPart;
        }
    }
};
