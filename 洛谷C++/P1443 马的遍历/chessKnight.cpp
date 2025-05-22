#include <iostream>
using namespace std;

int n, m, x, y, cnt=0;
int** matrix;
bool** status;

void recChess(int cy, int cx, int cnt) {
	if (cy < 0 || cy >= n || cx < 0 || cx >= m || status[cy][cx]) {
		return;
	}

	if (matrix[cy][cx] != -1 && matrix[cy][cx] <= cnt) {
		return;
	}

	matrix[cy][cx] = cnt;
	status[cy][cx] = true;

	recChess(cy + 2, cx + 1, cnt + 1);
	recChess(cy + 2, cx - 1, cnt + 1);
	recChess(cy - 2, cx + 1, cnt + 1);
	recChess(cy - 2, cx - 1, cnt + 1);
	recChess(cy + 1, cx + 2, cnt + 1);
	recChess(cy + 1, cx - 2, cnt + 1);
	recChess(cy - 1, cx + 2, cnt + 1);
	recChess(cy - 1, cx - 2, cnt + 1);

	status[cy][cx] = false; // ¼ÇµÃ»ØËÝ
}


int main() {
	cin >> n >> m >> x >> y;
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
		for (int j = 0; j < m; j++) {
			matrix[i][j] = -1;
		}
	}
	status = new bool* [n]();
	for (int i = 0; i < n; i++) {
		status[i] = new bool[m]();
	}
	recChess(y - 1, x - 1, cnt);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}