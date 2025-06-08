#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, sR, sC, eR, eC;

typedef struct {
	int x, y;
}point;

vector<vector<int>> map;
vector<vector<int>> dist;
vector<vector<bool>> status;
queue<point> q;

// 四个方向：左、上、右、下
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void shortestDistance(int cR, int cC) {
	q.push({ cR,cC });
	status[cR][cC] = true;
	dist[cR][cC] = 0;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			// 越界或走过或是店铺（1）就跳过
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue;
			}
			if (status[nx][ny] || map[nx][ny] == 1) {
				continue;
			}

			status[nx][ny] = true;
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
			q.push({ nx, ny });

			// 一旦到终点，立即输出结果并 return
			if (nx == eR && ny == eC) {
				cout << dist[nx][ny] << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int main() {
	cin >> n;
	map.resize(n, vector<int>(n));
	dist.resize(n, vector<int>(n, -1));
	status.resize(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input; // 一整行读入字符串，比如 "001"
		for (int j = 0; j < n; j++) {
			map[i][j] = input[j] - '0'; // 把字符转为数字
		}
	}
	cin >> sR >> sC;
	cin >> eR >> eC;
	sR--;
	sC--;
	eR--;
	eC--;
	shortestDistance(sR, sC);
}