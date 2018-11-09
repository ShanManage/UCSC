#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
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

	//Get text caces
	int T;
	cin >> T;
	cout << endl;

	for (int i=0; i<T; i++){
        int V, E;
        cin >> V >> E;
        cout << endl;

        vector<int> adj[V];

        int a, b;
        for (int i=0; i<E; i++){
            cin >> a >> b;
            cout << endl;
            addEdge(adj, a, b);
        }

        printGraph(adj, V);

	}
	return 0;
}

