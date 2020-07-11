#include <iostream>
using namespace std;
int min(int x, int y)
{
	return x < y ? x : y;
}

void printBridges(int** graph, int vrtx, int edge, bool visited[], int i, int wTime[], int lTime[], int parent)
{
	static int time = 0;
	for (int j = 0; j < vrtx; j++) {
		if (graph[i][j] == 1 && !visited[j]) {
			visited[j] = true;
			time++;
			wTime[j] = time;
			lTime[j] = time; 
			printBridges(graph, vrtx, edge, visited, j, wTime, lTime, i);
			//lTime[i] = min(lTime[i], lTime[j]);
				if(wTime[i] < lTime[j] ) {
					// cout << (char)(i + 65) << " ";
					// cout << (char)(i + 65) << " to " << (char)(j + 65) << endl;
				}
				else {
					lTime[i] = min(lTime[i], lTime[j]);
				}
		}
		else if (graph[i][j] == 1 && j != parent) {

				lTime[i] = min(lTime[i], lTime[j]);
		}
	}
}

void findBridges(int** graph, int vrtx, int edge)
{
	int wTime[vrtx];
	int lTime[vrtx];
	int parent;
	bool visited[vrtx];
	for (int i = 0; i < vrtx; i++) {
		visited[i] = false;
	}
	int root = 0;
	visited[root] = true;
	wTime[root] = 0;
	lTime[root] = 0;
	parent = -1;

	printBridges(graph, vrtx, edge, visited, root, wTime, lTime, parent);
	

	// cout << endl;
	for(int i=0 ; i < vrtx; i++) {
		cout << lTime[i] + 1 << " ";
	}
	// 	cout << endl;
	// for(int i=0 ; i < vrtx; i++) {
	// 	cout << wTime[i] << " ";
	// }
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
		// graph[vrtx2 - 1][vrtx1 - 1] = 1;
	}
	findBridges(graph, vrtx, edge);
}