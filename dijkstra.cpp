#include <bits/stdc++.h>
using namespace std;
void initializeParameter(int dist[], int parent[], bool ext[], int src, int vrtx)
{
	for (int i = 0; i < vrtx; i++) {
		dist[i] = INT_MAX - 1;
	}
	dist[src] = 0;

	for (int i = 0; i < vrtx; i++) {
		ext[i] = false;
	}
}

int extractMinVrtx(int dist[], bool extracted[], int vrtx)
{
	// for(int i=0 ; i<vrtx; i++)
	// {
	// 	cout << dist[i] << " ";
	// }
	// cout << endl;

	int min = INT_MAX;
	int index = -1;
	for (int i = 0; i < vrtx; i++) {
		if (dist[i] < min && !extracted[i]) {
			min = dist[i];
			index = i;
		}
	}
	if(min == INT_MAX)
		return -1;
	else
	{
		extracted[index] = true;
		//cout << index << endl;
		return index;
	}
}

void relaxTheNeighbourVrtx(int** graph, bool extracted[], int parent[], int i, int vrtx, int dist[])
{
	for (int j = 0; j < vrtx; j++) {
		if (graph[i][j] > 0 && !extracted[j]) {
			if (dist[i] + graph[i][j] < dist[j]) {
				dist[j] = dist[i] + graph[i][j];
				parent[j] = i;
			}
		}
	}
}

void printPath(int parent[], int src, int dest)
{
	if(dest == src) {
		// cout << src << " -> ";
		return ;
	}
	printPath(parent, src, parent[dest]);
	cout << parent[dest] << " -> ";
}

void dijkstraImplementation(int** graph, int vrtx, int edge, int src, int dest)
{
	// for(int i=0 ; i<vrtx; i++)
	// {
	// 	for(int j=0 ; j< vrtx; j++)
	// 	{
	// 		if(graph[i][j] > 0)
	// 		{
	// 			cout << i << " " << j << " "<< graph[i][j] << endl;
	// 		}
	// 	}
	// }
	//int vArr[vrtx];
	int dist[vrtx];
	int parent[vrtx];
	bool extracted[vrtx];
	int minVrtx = src;
	int count = 0;
	parent[src] = src;
	initializeParameter(dist, parent, extracted, src, vrtx);

	while (count < vrtx) {
		minVrtx = extractMinVrtx(dist, extracted, vrtx);
		// cout << "min : " << minVrtx << " dist : " << dist[minVrtx] << endl; 
		if(minVrtx == -1) break;
		relaxTheNeighbourVrtx(graph, extracted, parent, minVrtx, vrtx, dist);
		count++;
	}
	// for (int i = 0; i < vrtx; i++) {
	// 	cout << dist[i] << " ";
	// }

	// for (int i = 0; i< vrtx ; i++) {
	// 	cout << parent[i] << " ";
	// }

	printPath(parent, src, dest);
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
	// int arr1[edge];
	// int arr2[edge];
	graph = new int*[vrtx];

	for(int i=0; i<vrtx; i++)
	{
		graph[i] = new int[vrtx];
	}
	for (int i = 0; i < vrtx; i++) {
		for (int j = 0; j < vrtx; j++) {
			graph[i][j] = 0;
		}
	}

	for (int i=0 ; i < edge; i++) {
		int vrtx1, vrtx2, weight;
		cin >> vrtx1 >> vrtx2 >> weight;
		graph[vrtx1][vrtx2] = weight;
		graph[vrtx2][vrtx1] = weight;
	}
	int src, dest;
	cin >> src >> dest;
	dijkstraImplementation(graph, vrtx, edge, src, dest);
}