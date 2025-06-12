#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int M, N;
vector<vector<int>> altitudes;
vector<vector<int>> roadMap;

int dR[4] = { 0, 1, 0, -1 };
int dC[4] = { -1, 0, 1, 0 };

// 检查当最大海拔差为D时，所有路标是否联通
bool check(int D) {
	vector<vector<bool>> visited(M, vector<bool>(N, false));
	queue<pair<int, int>> q;

	// 找第一个路标作为起点
	bool foundStart = false;
	int sR, sC;
	for (int i = 0; i < M && !foundStart; i++) {
		for (int j = 0; j < N && !foundStart; j++) {
			if (roadMap[i][j] == 1) {
				sR = i;
				sC = j;
				foundStart = true;
			}
		}
	}

	q.push(make_pair(sR, sC));
	visited[sR][sC] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();	//pair<int, int> 是 C++ 标准库中的一个模板类型，表示 一对（两个）值，可以把它看成一个装了两个数据的小容器
		q.pop();
		int r = cur.first;	//第一个值
		int c = cur.second;	//第二个值

		for (int d = 0; d < 4; d++) {
			int nR = r + dR[d];
			int nC = c + dC[d];

			if (nR < 0 || nR >= M || nC < 0 || nC >= N) {
				continue;
			}

			if (visited[nR][nC]) {
				continue;
			}

			if (abs(altitudes[nR][nC] - altitudes[r][c]) > D) {
				continue;
			}
			visited[nR][nC] = true;
			q.push(make_pair(nR, nC));
		}
	}

	// 检查所有路标是否都访问过
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (roadMap[i][j] == 1 && !visited[i][j]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	cin >> M >> N;
	altitudes.resize(M, vector<int>(N));
	roadMap.resize(M, vector<int>(N));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> altitudes[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> roadMap[i][j];
		}
	}

	int left = 0, right = 1000000000;
	int ans = -1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << endl;
	return 0;
}
