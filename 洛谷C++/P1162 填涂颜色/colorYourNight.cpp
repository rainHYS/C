#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
bool isClose;
vector<vector<int>> matrix;

typedef struct {
	int r, c;
} point;

queue<point> q;

// 四个方向
int dR[4] = { -1, 0, 1, 0 };
int dC[4] = { 0, 1, 0, -1 };

// 把闭合圈内的区域染成 2
void color(int cR, int cC) {
	vector<vector<bool>> status(n, vector<bool>(n, false));
	status[cR][cC] = true;
	q.push({ cR, cC });

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		matrix[cur.r][cur.c] = 2; // 染色

		for (int i = 0; i < 4; i++) {
			int nR = cur.r + dR[i];
			int nC = cur.c + dC[i];

			if (nR < 0 || nR >= n || nC < 0 || nC >= n) {
				continue;
			}
			if (matrix[nR][nC] != 0 || status[nR][nC]) {
				continue;
			}

			status[nR][nC] = true;
			q.push({ nR, nC });
		}
	}
}

// 检查从某个 0 开始能否走到边界，不能的话就染色
void checkClose(int cR, int cC) {
	vector<vector<bool>> status(n, vector<bool>(n, false));
	status[cR][cC] = true;
	q.push({ cR, cC });

	isClose = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		// 如果能到达边界
		if (cur.r == 0 || cur.r == n - 1 || cur.c == 0 || cur.c == n - 1) {
			isClose = false;
		}

		for (int i = 0; i < 4; i++) {
			int nR = cur.r + dR[i];
			int nC = cur.c + dC[i];

			if (nR < 0 || nR >= n || nC < 0 || nC >= n) {
				continue;
			}
			if (matrix[nR][nC] != 0 || status[nR][nC]) {
				continue;
			}

			status[nR][nC] = true;
			q.push({ nR, nC });
		}
	}

	if (isClose) {
		color(cR, cC);
	}
}

int main() {
	cin >> n;
	matrix.resize(n, vector<int>(n));

	// 输入矩阵
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	// 遍历所有点，找闭合圈内的 0 并填色
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 0) {
				checkClose(i, j);
			}
		}
	}

	// 输出结果
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
