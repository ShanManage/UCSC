#include <bits/stdc++.h>
using namespace std;

class Graph{

    vector<int>* graph;
    bool* visited;

    public:

        Graph(int v);
        void addEdge(int from, int to);
        void DFS(int from);
        void resetVisited(int v);
};

Graph :: Graph(int v){
    graph = new vector<int>[v];
    visited = new bool[v];
}

void Graph :: addEdge(int from, int to){
    graph[from].push_back(to);
}

void Graph :: resetVisited(int v){
    int i;
    for(i = 0; i < v; i++){
        visited[i] = false;
    }
}

void Graph :: DFS(int from){

    if (visited[from] == true) return;

    cout << from << " ";
    visited[from] = true;

    vector<int> line = graph[from];
    int i;
    for(i = 0; i < line.size(); i++){
        DFS(line[i]);
    }
}

int main(){

    int v = 5;
    Graph g(v);
    g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
    g.resetVisited(v);
    g.DFS(1);

    return 0;
}