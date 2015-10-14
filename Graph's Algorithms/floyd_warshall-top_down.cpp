#include <algorithm> //min

const int MAX_N = 300;
const int INF = 1 << 30;

long long graph[MAX_N][MAX_N]; 
long long result[MAX_N][MAX_N][MAX_N]; 

long long floyd_warshall(int startNode, int endNode, int setNode) {
    if(setNode == 0) {
        return graph[startNode][endNode];
    }
    if(result[startNode][endNode][setNode] != -1) {
        return result[startNode][endNode][setNode];
    }
    long long firstCase  = floyd_warshall(startNode, endNode, setNode - 1);
    long long secondCase = floyd_warshall(startNode, setNode - 1, setNode - 1) + floyd_warshall(setNode - 1, endNode, setNode - 1);
    secondCase           = min(secondCase, (long long)INF);
    long long answer     = std :: min(firstCase, secondCase);
    return result[startNode][endNode][setNode] = answer; 
}

int main() {
    //Set every element in graph to be INF unless the indixes are the same, in that case graph[i][i] = 0
    //Set every element in result to be -1. Can be easily done with memset
    //Read graph
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            floyd_warshall(i, j, n); //Where n is the number of nodes in the graph
        }
    }

    //Shortest path between i and j can be found in result[i][j][n]
}
