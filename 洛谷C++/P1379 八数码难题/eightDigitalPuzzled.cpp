#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// 初始状态字符串
string start = "";

// 棋盘状态结构体，包含当前状态字符串 + 当前步数
struct chess {
	string str;
	int step;
};

// BFS 队列
queue<chess> q;

// 目标状态
string goal = "123804765";

// 四个方向：左、上、右、下（注意顺序可以任意，只要统一）
int dR[4] = { 0, -1, 0, 1 };
int dC[4] = { -1, 0, 1, 0 };

// 判重用的哈希表
unordered_set<string> visited;

void bfs() {
	while (!q.empty()) {
		// 取出当前状态
		chess cur = q.front();
		q.pop();

		// 判断是否已经是目标状态
		if (cur.str == goal) {
			cout << cur.step << endl;
			return;
		}

		// 找出 '0' 的位置（空格的位置）
		int curPos = cur.str.find('0');
		int cR = curPos / 3; // 行号
		int cC = curPos % 3; // 列号

		// 遍历四个方向（尝试将相邻格子移入空格）
		for (int i = 0; i < 4; i++) {
			int nR = cR + dR[i];
			int nC = cC + dC[i];

			// 越界跳过
			if (nR < 0 || nR >= 3 || nC < 0 || nC >= 3) {
				continue;
			}

			// 计算目标交换位置
			int nextPos = 3 * nR + nC;

			// 创建下一步状态（复制当前字符串）
			string nextStr = cur.str;
			swap(nextStr[curPos], nextStr[nextPos]); // 把空格和相邻格子交换

			// 判重：如果 nextStr 已经访问过，就跳过
			if (!visited.count(nextStr)) {
				visited.insert(nextStr);
				q.push({ nextStr, cur.step + 1 });
			}
		}
	}
}

int main() {
	// 读取初始状态（9 个字符）
	for (int i = 0; i < 9; i++) {
		char ch;
		cin >> ch;
		start += ch;
	}

	// 初始化 BFS 队列
	q.push({ start ,0 });
	visited.insert(start);  // 不能漏！

	bfs(); // 开始搜索

	return 0;
}
