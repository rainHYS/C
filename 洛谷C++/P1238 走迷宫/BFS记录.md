# ✅ 使用 BFS 寻找迷宫路径

该版本程序使用 **广度优先搜索（BFS）** 算法，从起点出发，在地图中寻找通往终点的路径。实现了以下功能：

- ✅ 找到从起点到终点的**一条可行路径**（一定是最短路径）
- ✅ 输出路径坐标（格式形如 `(x,y)->(x,y)->...`）
- ✅ 使用 `vector` 实现了自定义队列结构，便于理解
- ✅ 使用 `pre[x][y]` 记录每个点是从哪里来的，用于反向回溯路径

---

## ⚠️ 局限性：

**当前程序仅能输出一条最短路径，不支持输出所有可能的路径。**

这是因为：

- BFS 一旦找到终点就立刻返回
- `pre[x][y]` 只记录了单一前驱，无法回溯多种来源路径

如需输出所有路径，请使用 DFS + 回溯。

---

## 🧾 完整代码如下：

```cpp
#include <iostream>
#include <vector>
using namespace std;

int m, n, startX, startY, endX, endY;

vector<vector<int>> maze;
vector<vector<bool>> status;

// 定义方向数组：左上右下
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

typedef struct {
	int x;
	int y;
} point;

struct VectorQueue {
	vector<point> v;
	int front = 0;

	void push(point p) {
		v.push_back(p);
	}

	bool pop(point& p) {
		if (front >= v.size()) return false;
		p = v[front++];
		return true;
	}

	bool isEmpty() {
		return front >= v.size();
	}
};

vector<vector<point>> pre; // 记录路径

void findPath() {
	VectorQueue Q;
	Q.push({ startX, startY });
	status[startX][startY] = true;

	while (!Q.isEmpty()) {
		point cur;
		Q.pop(cur);

		if (cur.x == endX && cur.y == endY) {
			vector<point> path;
			point p = { endX, endY };
			while (!(p.x == -1 && p.y == -1)) {
				path.push_back(p);
				p = pre[p.x][p.y];
			}
			for (int i = path.size() - 1; i >= 0; --i) {
				cout << "(" << path[i].x + 1 << "," << path[i].y + 1 << ")";
				if (i != 0) cout << "->";
			}
			cout << endl;
			return;
		}

		for (int i = 0; i < 4; ++i) {
			int nextX = cur.x + dx[i];
			int nextY = cur.y + dy[i];
			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
				if (maze[nextX][nextY] == 1 && !status[nextX][nextY]) {
					status[nextX][nextY] = true;
					Q.push({ nextX, nextY });
					pre[nextX][nextY] = cur;  // ⭐记录路径来源
				}
			}
		}
	}
	cout << -1 << endl;
}

int main() {
	cin >> m >> n;

	maze.resize(m, vector<int>(n));
	status.resize(m, vector<bool>(n, false));
	pre.resize(m, vector<point>(n, { -1, -1 }));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}

	cin >> startX >> startY;
	cin >> endX >> endY;
	startX--; startY--; endX--; endY--;
	findPath();
}
```

#### ✍️ 给未来的自己：

> 如果你发现这段代码只能输出一条路径，不要惊讶 —— 它做的就是“找到一条最短路径”。
>  想输出所有可行路径，直接换 DFS 或 BFS+回溯，别试图魔改当前逻辑，会变得很绕。
>  记得：**BFS 的特点是“快而简单”，DFS 的特点是“全而灵活”。**