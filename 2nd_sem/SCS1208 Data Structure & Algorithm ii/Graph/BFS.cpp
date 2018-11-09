#include <bits/stdc++.h>
using namespace std;

class Graph {

    int V;
    vector<int>* graph;
    
    public:

        Graph (int v);
        void addEdge(int from, int to);
        void BFS(int from);

};

Graph :: Graph (int v){
    this->V = v;
    graph = new vector<int>[V];
}

void Graph :: addEdge (int from, int to){
    graph[from].push_back(to);
}

void Graph :: BFS (int from){

    bool visited[V];
    int i;
    for (i = 0; i < V; i++)
        visited[i] = false;

    queue <int> q;

    visited[from] = true;
    q.push(from);

    while(!q.empty()){

        int front = q.front();
        cout << front << " ";
        q.pop();

        vector<int> line = graph[front];
        int j;
        for(j = 0; j < line.size(); j++){
            if(!visited[line[j]]){
                visited[line[j]] = true;
                q.push(line[j]);
            }
        }
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

    g.BFS(0);

    return 0;
}
