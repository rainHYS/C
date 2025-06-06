#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x, y;
vector<vector<int>> matrix;
vector<vector<bool>> status;
typedef struct {
	int r, c;
}point;
queue<point> q;

int dR[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dC[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void knightTraverse(int cR, int cC) {
	q.push({ cR,cC });
	matrix[cR][cC] = 0;
	status[cR][cC] = true;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nR = cur.r + dR[i];
			int nC = cur.c + dC[i];
			if (nR < 0 || nR >= n || nC < 0 || nC >= m || status[nR][nC]) {
				continue;
			}
			status[nR][nC] = true;
			matrix[nR][nC] = matrix[cur.r][cur.c] + 1;
			q.push({ nR, nC });
		}
	}
}


int main() {
	cin >> n >> m >> x >> y;
	x--;
	y--;
	matrix.resize(n, vector<int>(m, -1));
	status.resize(n, vector<bool>(m, false));
	knightTraverse(x, y);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}