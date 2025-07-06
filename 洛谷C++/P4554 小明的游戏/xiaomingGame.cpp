#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int n, m, x1, y1, x2, y2;
vector<vector<char>> chess;
vector<vector<int>> distant;

struct node {
	int r, c;
};

int dR[4] = { -1, 0, 1, 0 };
int dC[4] = { 0, -1, 0, 1 };

void bfs(int sR, int sC) {
	deque<node> q;
	q.push_front({ sR, sC });
	distant[sR][sC] = 0;

	while (!q.empty()) {
		node cur = q.front();
		q.pop_front();

		for (int i = 0; i < 4; i++) {
			int nR = cur.r + dR[i];
			int nC = cur.c + dC[i];

			if (nR < 0 || nR >= n || nC < 0 || nC >= m) {
				continue;
			}

			// 计算代价
			int cost = (chess[cur.r][cur.c] == chess[nR][nC]) ? 0 : 1;

			// 如果更优，更新并入队
			if (distant[cur.r][cur.c] + cost < distant[nR][nC]) {
				distant[nR][nC] = distant[cur.r][cur.c] + cost;
				if (cost == 0) {
					q.push_front({ nR, nC });
				}
				else {
					q.push_back({ nR, nC });
				}

			}
		}
	}
}

int main() {
	while (cin >> n >> m && (n || m)) {
		chess.assign(n, vector<char>(m));
		distant.assign(n, vector<int>(m, INT_MAX));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> chess[i][j];

		cin >> x1 >> y1 >> x2 >> y2;

		bfs(x1, y1);
		cout << distant[x2][y2] << endl;
	}
	return 0;
}
