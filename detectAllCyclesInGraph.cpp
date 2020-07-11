// C++ program to print all cycles of that
// undirected graph which contains all such  
// type of cycles that are neither touch nor  
// intersect to each other
#include <iostream>
using namespace std;
void printAllCycles(int** graph, int vrtx, bool visited[], int i, int parent[], int stop[])
{
	for (int j = 0; j < vrtx; j++) {
		if (graph[i][j] == 1 && !visited[j]) {
			visited[j] = true;
			parent[j] = i;
			printAllCycles(graph, vrtx, visited, j, parent, stop);
		}
		else if(graph[i][j] == 1 && j != parent[i] && !stop[j]) {
			stop[i] = 1;
			int index = i;
			while (j != index) {
				cout << index + 1 << " ";
				index = parent[index];
			}
			cout << index + 1 << endl;
		}
	}
}
void detectAllCycles(int** graph, int vrtx, int edge)
{
	bool visited[vrtx];
	int parent[vrtx];
	int root = 0;
	int i = root;
	int stop[vrtx];
	for (int j = 0; j < vrtx; j++) {
		visited[j] = false;
	}
	for (int j = 0; j < vrtx; j++) {
		stop[j] = 0;
	}
	visited[i] = true;
	parent[i] = -1;
	printAllCycles(graph, vrtx, visited, i, parent, stop);
	cout << "parent array : " << endl;
	for (int j = 0; j < vrtx; j++) {
		cout << "parent of " << j + 1 << " is " << parent[j] + 1 << endl;
	}
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
		int vrtx1, vrtx2;
		cin >> vrtx1 >> vrtx2;
		graph[vrtx1 - 1][vrtx2 - 1] = 1;
		graph[vrtx2 - 1][vrtx1 - 1] = 1;
	}
	detectAllCycles(graph, vrtx, edge);
}