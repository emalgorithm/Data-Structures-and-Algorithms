#include <queue>


const int MAX_N = 1000000;
const int INF = 2 << 31;
//Storing the graph in an adjacency list lead to a O(V) complexity
//The vector of ints 'distance' contains the distance of each node from the source, and it's initially set to infinite
std :: vector< int > graph[MAX_N]; 
std :: vector< int > distance(MAX_N, INF);

//Inside main
//Use a queue to store the nodes in a First-In First-Out order
//'source' is the node from which you want to start the visit, here it is set to 0
queue<int> q;
int source = 0;
distance[source] = 0;
q.push(source);

while(q.empty() == false) {
    int node = q.front();
    q.pop();
    for(int i = 0; i < graph[node].size(); i++) {
        int adjNode = graph[node][i];
        if(distance[adjNode] == INF) {
            distance[adjNode] = distance[node] + 1;
            q.push(adjNode);
        }
    }
}



