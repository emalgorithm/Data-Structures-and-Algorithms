#include <vector>

const int MAX_N = 1000000;
//Storing the graph in an adjacency list lead to a O(V + E) complexity
//The bool 'visited' is true at position U if node U has already been visited, 0 otherwise
std :: vector< int > graph[MAX_N]; 
bool visited[MAX_N];

int dfs(int node) {
    visited[node] = true;
    //Call the dfs recursively for each node in the adjacency list of 'node' which has not been visited yet
    for(int i = 0; i < graph[node].size(); i++) {
        int adjNode = graph[node][i];
        if(visited[adjNode] == false) {
            dfs(adjNode);
        }
    }
}




