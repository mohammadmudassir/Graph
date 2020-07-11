// All pair shortest path in directed path
#include <bits/stdc++.h>
using namespace std;
# define INF INT_MAX

void printPath(int src, int dest, int** parent)
{
	if(src == dest)
	{
		return;
	}
	printPath(src, parent[src][dest], parent);
	cout << parent[src][dest]<< " ";
}

void AllPairShortestPath(int** graph, int vrtx, int edge, int src, int dest)
{
	int **dp;
	int **parent;
	dp = new int*[vrtx];
	parent = new int*[vrtx];

	for(int i=0; i<vrtx; i++)
	{
		dp[i] = new int[vrtx];
		parent[i] = new int[vrtx];
	}
	
	for(int i = 0; i < vrtx; i ++) {
		for (int j = 0; j < vrtx; j++) {
			dp[i][j] = graph[i][j];
			if (graph[i][j] == 0 || graph[i][j] == INF)
				parent[i][j] = -1;
			else {
				parent[i][j] = i;
			}
		}
	}

	for (int k = 0; k < vrtx; k++) {
		for(int i = 0; i < vrtx; i ++) {
			for (int j = 0; j < vrtx; j++) { 
				int prev = dp[i][j];
				int current = INF;
				if (dp[i][k] != INF && dp[k][j] != INF)
					current = dp[i][k] + dp[k][j];

				if (current < prev) {
					dp[i][j] = current;
					parent[i][j] = parent[k][j];
				}
			}
		}
	}


	for(int i = 0; i < vrtx; i ++) {
		for (int j = 0; j < vrtx; j++) {
			cout << dp[i][j] << "   ";
		}
		cout << endl;
	}
	// cout << endl << endl;


	// for(int i = 0; i < vrtx; i ++) {
	// 	for (int j = 0; j < vrtx; j++) {
	// 		cout << parent[i][j] << "   ";
	// 	}
	// 	cout << endl;
	// }

	printPath(src, dest, parent);
	cout << dest;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int vrtx;
	int edge;
	cin >> vrtx >> edge;
	int **graph;
	graph = new int*[vrtx];

	for(int i=0; i<vrtx; i++)
	{
		graph[i] = new int[vrtx];
	}
	for (int i = 0; i < vrtx; i++) {
		for (int j = 0; j < vrtx; j++) {
			if (i == j) {
				graph[i][j] = 0;
			} 
			else {
				graph[i][j] = INF;

			}
		}
	}

	for (int i=0 ; i < edge; i++) {
		int vrtx1, vrtx2, weight;
		cin >> vrtx1 >> vrtx2 >> weight;
		graph[vrtx1][vrtx2] = weight;
	}
	int src = 1, dest = 0;
	AllPairShortestPath(graph, vrtx, edge, src, dest);
}