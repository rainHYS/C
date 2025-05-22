#include<iostream>
using namespace std;

int n, k, answer = 0;
char** matrix;
bool* status;

void recChess(int row, int cnt) {
	if (cnt == k) {
		answer++;
		return;
	}
	if (row >= n) {
		return;
	}
	for (int i = 0; i < n; i++) {
		if (matrix[row][i] == '#' && !status[i]) {
			status[i] = true;
			recChess(row + 1, cnt + 1);
			status[i] = false;
		}
	}
	recChess(row + 1, cnt);
}

int main() {
	while (1) {
		cin >> n >> k;
		answer = 0;
		if (n == -1 && k == -1) {
			break;
		}
		matrix = new char* [n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new char[n];
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
		status = new bool[n]();
		recChess(0, 0);
		cout << answer << endl;
	}
	return 0;
}