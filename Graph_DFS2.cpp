#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs)
{
	storeDfs.push_back(i);
	vis[i] = 1;
	for (auto j : adj[i])
	{
		if (!vis[j])
		dfs(j, vis, adj, storeDfs);
	}
}

vector<int> dfsOfGraph(int n, vector<int> adj[])
{
	vector<int> storeDfs;
	vector<int> vis(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		dfs(i, vis, adj, storeDfs);
	}
	return storeDfs;
}

int main()
{
	// n = no of nodes
	// e = no of edges
	int n, e;
	cout << "No of node: ";
	cin >> n;
	cout << "No of edges: ";
	cin >> e;

	// declare the adjacent matrix
	vector<int> adj[n];

	// take edges as input
	cout << "Provide 'e' lines of nodes connection(u-v) : " << endl;
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=0;i<n;i++){
		cout<<i<<" -> ";
		for(auto j:adj[i]){
			cout<<j<<" ";
		}
		cout<<endl;
	}

	cout << "DFS: ";
	vector<int> ans = dfsOfGraph(n, adj);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}