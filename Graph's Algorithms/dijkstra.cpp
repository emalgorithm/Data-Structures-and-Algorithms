#include <vector>    //Contains 'vector' class
#include <queue>     //Contains 'priority_queue' class
#include <utility>   //Contains the 'pair' structure
#include <functional>//Contains the 'greater' function

using namespace std;  //We set 'std' as the global namespace since we are using a lot of classes from it

const int MAX_N = 1000000;
const int INF   = 1 << 30;

typedef pair < int, int > ii; //We define 'ii' to be a 'pair <int, int>' in order to reduce the code

vector < ii > graph[MAX_N]; //A pair is a convenient way to represent a relation in a graph. The first element represents the adjacent node and the second one the cost
vector < int > dist(MAX_N, INF);
//The priority queue contains pairs of ints whose second element is a node and first element is the current distance of that node from the source
priority_queue < ii, vector < ii >, greater < ii > > pq; //The priority queue declared in this way contains at its top the pair with the least first element

void dijkstra(int source) {
    dist[source] = 0; 
    pq.push(make_pair(dist[source], source)); //Remeber, in the priority queue the first member is the distance and the second the node

    while(pq.empty() == false) {
        int node         = pq.top().second;
        int nodeDistance = pq.top().first;
        pq.pop();

        if(dist[node] < nodeDistance) { //Optimization. Since we are pushing the same node more than once in the queue
            continue;                       //we want to be sure to run this code for it only once
        }

        for(int i = 0; i < graph[node].size(); i++) {
            int adjNode  = graph[node][i].first;
            int edgeCost = graph[node][i].second;
            if(dist[adjNode] > dist[node] + edgeCost) { //If we can improve the distance of a node, we do so and we push the node inside the priority queue
                dist[adjNode] = dist[node] + edgeCost;
                pq.push(make_pair(dist[adjNode], adjNode));
            }
        }
    }
}
