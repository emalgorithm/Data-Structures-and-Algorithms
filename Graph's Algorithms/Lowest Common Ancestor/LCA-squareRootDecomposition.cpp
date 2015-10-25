//This algorithm allows you to find the Lowest Common Ancestor of two nodes in
//O(N) preprocessing and O(sqrt(N) per query using a technique called
//'Square root decomposition'
//After having construct the tree in an adjacency list, it is needed to call
//the 'findAncestor'function for the preprocessing in this way:
//findAncestor(root, root, sqrt(height));
//After that it is possible to call the function LCA
#include <vector>

const int MAX_N = 100000;

std :: vector < int > tree[MAX_N];
bool visited[MAX_N] = {false};
int ancestor[MAX_N];
int level[MAX_N];
int parent[MAX_N];
int height; //Set this value as desired. If it's not given, can be computed with a DFS

void findAncestor(int node, int root, int heightSqrt) {
    visited[node] = true;
    if(node == root) {
        level[node] = 0;
        parent[node] = node;
    }
    if(level[node] < heightSqrt) {
        ancestor[node] = root;
    }
    else {
        if(level[node] % heightSqrt == 0) { //The node is in the first layer
            ancestor[node] = parent[node];
        }
        else {
            ancestor[node] = ancestor[parent[node]];
        }
    }
    for(int i = 0; i < tree[node].size(); i++) {
        int son = tree[node][i];
        if(visited[son] == false) {
            level[son] = level[node] + 1;
            parent[son] = node;
            height = max(height, level[son] + 1);
            findAncestor(son, root, heightSqrt);
        }
    }
}

int LCA(int firstNode, int secondNode) {
    if(level[firstNode] > level[secondNode]) {
        swap(firstNode, secondNode);
    }
    while(ancestor[firstNode] != ancestor[secondNode]) {
        secondNode = ancestor[secondNode];
    }
    while(firstNode != secondNode) {
        if(level[firstNode] > level[secondNode]) {
            firstNode = parent[firstNode];
        }
        else {
            secondNode = parent[secondNode];
        }
    }
    return firstNode;
}
