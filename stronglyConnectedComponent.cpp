#include<iostream>
using namespace std;
void getStackByFinishTimeVrtx(int** graph, int vrtx, int edge, int i, int visited[], int stack[], int &top)
{
	for (int j = 0; j < vrtx; j++) {
		if(graph[i][j] == 1 && !visited[j]) {
			visited[j] = 1;
			getStackByFinishTimeVrtx(graph, vrtx, edge, j, visited, stack, top);
			stack[++top] = j;
		}
	}
}
void reverseGraph(int** graph, int vrtx, int edge, int visited[], int arr1[], int arr2[])
{
	for (int i = 0; i < vrtx; i++) {
		for (int j = 0; j < vrtx; j++) {
			graph[i][j] = 0;
		}
	}
	for (int i = 0; i < edge; i++) {
		graph[arr2[i] - 1][arr1[i] - 1] = 1;
	}
}

void printConnectedComponent(int** graph, int vrtx, int visited[], int i)
{
	for (int j = 0; j < vrtx; j++) {
		if(graph[i][j] == 1 && !visited[j]) {
			visited[j] = 1;
			cout << (char)(j + 65) << " ";
			printConnectedComponent(graph, vrtx, visited, j);
		}
	}
}

void printComponents(int** graph, int vrtx, int edge, int visited[], int stack[], int &top)
{
	while (top >= 0) {
		int popVrtx = stack[top--];
		if (!visited[popVrtx]) {
			visited[popVrtx] = 1;
			cout << (char)(popVrtx + 65) << " ";
			printConnectedComponent(graph, vrtx, visited, popVrtx);
			cout << endl;
		}
	}
}

void printStronglyConnectedComponent(int** graph, int vrtx, int edge, int arr1[], int arr2[])
{
	int visited[vrtx];
	for (int i = 0; i < vrtx; i++) {
		visited[i] = 0;
	}
	int stack[vrtx];
	int top = -1;
	for (int i = 0; i < vrtx; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			getStackByFinishTimeVrtx(graph, vrtx, edge, i, visited, stack, top);
			stack[++top] = i;
		}
	}
	for (int i = 0; i < vrtx; i++) {
		visited[i] = 0;
	}

	reverseGraph(graph, vrtx, edge, visited, arr1, arr2);


	printComponents(graph, vrtx, edge, visited, stack, top);
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
	int arr1[edge];
	int arr2[edge];
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
		cin >> arr1[i] >> arr2[i];
		graph[arr1[i] - 1][arr2[i] - 1] = 1;
	}
	printStronglyConnectedComponent(graph, vrtx, edge, arr1, arr2);
}