#include <iostream>
using namespace std;
int tColor = 0;
int maxClr = -1;
bool canColoured(int mtrx[][10], int i, int vrtx, int clr[], int k)
{
	for (int j = 0; j < vrtx; j++) {
		if (mtrx[i][j] == 1 && clr[j] == k) {
			return false;
		}
	}
	return true;
}
bool colouredUtil(int mtrx[][10], int i, int vrtx, bool visited[], int clr[], int m)
{
	for (int k = 1; k <= m; k++) {
		if (canColoured(mtrx, i, vrtx, clr, k)) {
			clr[i] = k;
			tColor++;
			// cout << "clr  " << i + 1 << ", " << k << endl;
			// cout << tColor << endl;
			maxClr = k > maxClr ? k : maxClr;
			
			if (tColor == vrtx && maxClr <= m) {

				return true;
			}
			if (maxClr > m) return false;

			for (int j = 0; j < vrtx; j++) {
				if (mtrx[i][j] == 1 && !visited[j]) {
					visited[j] = true;
					bool ans = colouredUtil(mtrx, j, vrtx, visited, clr, m);
					if (ans == true) {
						return true;
					}
					visited[j] = false;
				}
			}
			clr[i] = -1;
			tColor--; 
			// cout << "unClr  " << i + 1 << endl;		
			// cout << tColor << endl;
			return false;	//Note : if i remove return statement
						//from here, then it will generate all possible configuratio of colour
						// if don't remove then it works as a backtracking	
		}
	}
	return false;

}
bool coloured(int mtrx[][10], int i, int vrtx, int m)
{
	bool visited[vrtx] = {false};
	int clr[vrtx] = {-1};
	visited[i] = true;
	bool ans = colouredUtil(mtrx, i, vrtx, visited, clr, m);
	for (int i = 0; i < vrtx; i++){
		cout << clr[i] << " ";
	}
	cout << endl << maxClr << endl;
	return ans;
}
int main()
{

	int vrtx = 10;
	// int edge = 5;
	int m = 3;
	// int mtrx[4][4] = {  
	// 					{ 0, 1, 1, 1 },
	// 					{ 1, 0, 1, 0 },
	// 					{ 1, 1, 0, 1 },
	// 					{ 1, 0, 1, 0 }
	// 			     };	

	int mtrx[10][10] = {  
						{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
						{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
						{ 0, 1, 0, 0, 1, 0, 1, 0, 0, 0 },
						{ 0, 0, 1, 1, 0, 1, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
						{ 0, 0, 0, 1, 0, 0, 0, 0, 1, 1 },
						{ 0, 1, 0, 0, 0, 1, 0, 0, 1, 0 },
						{ 0, 0, 1, 0, 0, 0, 1, 1, 0, 0 },
						{ 1, 0, 0, 0, 0, 1, 1, 0, 0, 0 }
						
				     };		

	// for (int i = 0; i < vrtx ; i++) {
	// 	for (int j = 0 ; j < vrtx; j++) {
	// 		if (mtrx[i][j] == 1) {
	// 			cout << i + 1 << " <-> " << j + 1 << endl;
	// 			mtrx[j][i] = 0;
	// 		}
	// 	}
	// }     

	if (coloured(mtrx, 0, vrtx, m) == true) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}