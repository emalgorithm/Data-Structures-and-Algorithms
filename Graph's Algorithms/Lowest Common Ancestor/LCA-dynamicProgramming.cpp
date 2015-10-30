#include <vector>
#include <utility>

const int MAX_N = 100005;
const int MAX_LOG = 20;
std :: vector <int> tree[MAX_N];
int parent[MAX_N]; //Initially should all be -1
int level[MAX_N];
int ancestor[MAX_N][MAX_LOG];

void preprocessing(int node, int root) {
    if(node == root) {
        level[node] = 0;
        parent[node] = node;
    }
    for(int j = 0; j < MAX_LOG; j++) {
        if(j == 0) {
            ancestor[node][j] = parent[node];
        }
        else {
            int halfwayAncestor = ancestor[node][j - 1];
            ancestor[node][j] = ancestor[halfwayAncestor][j - 1];
        }
    }
    for(int i = 0; i < tree[node].size(); i++) {
        int son = tree[node][i];
        if(parent[son] == -1) { //Still to visit
            parent[son] = node;
            level[son] = level[node] + 1;
            preprocessing(son, root);
        }
    }
}

int LCA(int firstNode, int secondNode) {
    if(level[firstNode] < level[secondNode]) {
        std :: swap(firstNode, secondNode);
    }
    for(int j = MAX_LOG - 1; j >= 0; j--) { //We try to cover the distance between
        int ances = ancestor[firstNode][j];
        if(level[ances] >= level[secondNode]) {
            firstNode = ances;
        }
    }
    //Now firstNode and Second now are at the same level
    if(firstNode == secondNode) {
        return firstNode;
    }
    for(int j = MAX_LOG - 1; j >= 0; j--) {
        int firstAncestor = ancestor[firstNode][j];
        int secondAncestor = ancestor[secondNode][j];
        if(firstAncestor != secondAncestor) { 
            firstNode = firstAncestor;
            secondNode = secondAncestor;
        }
    }
    return ancestor[firstNode][0];
}
