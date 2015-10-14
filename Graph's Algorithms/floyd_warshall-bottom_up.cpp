#include <algorithm> //min

const int MAX_N = 300;

long long graph[MAX_N][MAX_N]; 

//inside main. At first you need to initialise each element graph to INF unless the indexes are the same
//for example, we have to set graph[i][i] = 0, because the cost from a node to itself is 0
//At the end of the 3 loops, the matrix graph[i][j] will contain the cost of the shortest path from i to j

for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
}
