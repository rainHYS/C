#include <iostream>
#include <vector>
using namespace std;

int m, n, sR, sC, eR, eC;
bool isFind = false;
vector<vector<int>> maze;
vector<vector<bool>> status;

typedef struct {
	int x, y;
} point;
vector<point> path;

void findPath(int cR, int cC) {
	// 越界、访问过、遇到障碍就跳过
	if (cR < 0 || cR >= m || cC < 0 || cC >= n || status[cR][cC] || !maze[cR][cC]) {
		return;
	}

	// 加入路径、标记为已访问
	path.push_back({ cR, cC });
	status[cR][cC] = true;

	// 到达终点：输出路径
	if (cR == eR && cC == eC) {
		isFind = true;
		for (int i = 0; i < path.size(); ++i) {
			cout << "(" << path[i].x + 1 << "," << path[i].y + 1 << ")";
			if (i != path.size() - 1) cout << "->";
		}
		cout << endl;
	}
	else {
		// 递归探索四个方向（左上右下）
		findPath(cR, cC - 1);
		findPath(cR - 1, cC);
		findPath(cR, cC + 1);
		findPath(cR + 1, cC);
	}

	// 回溯：取消标记、移除路径
	status[cR][cC] = false;
	path.pop_back();
}

int main() {
	cin >> m >> n;
	maze.resize(m, vector<int>(n));
	status.resize(m, vector<bool>(n, false));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}

	cin >> sR >> sC >> eR >> eC;
	sR--; sC--; eR--; eC--;

	findPath(sR, sC);
	if (!isFind) {
		cout << -1 << endl; // ⭐没找到路径，输出 -1
	}
}
