#include<bits/stdc++.h>
using namespace std;

vector<int>* adj;

void addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; v++)
	{
		cout << v;
		for (auto x : adj[v])
		cout << "-> " << x;
		printf("\n");
	}
}

int main()
{
	int V = 5;
	adj = new vector<int>[V];
	addEdge(0, 1);
	addEdge(0, 4);
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(2, 3);
	addEdge(3, 4);
	printGraph(adj, V);

	return 0;
}

