#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define maxSize 305
using namespace std;

int M;
typedef struct {
	int r, c, t;
}point;
vector<vector<int>> map;
vector<vector<bool>> status;
vector<point> rock;
queue<point> q;

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,1,0,-1 };

void aerolite(int cR, int cC, int cT) {
	map[cR][cC] = min(map[cR][cC], cT);
	for (int i = 0; i < 4; i++) {
		int nR = cR + dR[i];
		int nC = cC + dC[i];
		if (nR < 0 || nR >= maxSize || nC < 0 || nC >= maxSize) {
			continue;
		}
		map[nR][nC] = min(map[nR][nC], cT);
	}
}

void escapeMeteor(int cR, int cC) {
	status[cR][cC] = true;
	q.push({ cR,cC,0 });
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nR = cur.r + dR[i];
			int nC = cur.c + dC[i];
			int nT = cur.t + 1;
			if (nR < 0 || nR >= maxSize || nC < 0 || nC >= maxSize || nT >= map[nR][nC] || status[nR][nC]) {
				continue;
			}
			if (map[nR][nC] == INT_MAX) {
				cout << nT;
				return;
			}
			status[nR][nC] = true;
			q.push({ nR,nC,nT });
		}
	}
	cout << -1;
	return;
}

int main() {
	cin >> M;
	rock.resize(M);
	map.resize(maxSize, vector<int>(maxSize, INT_MAX));
	status.resize(maxSize, vector<bool>(maxSize, false));
	for (int i = 0; i < M; i++) {
		cin >> rock[i].r >> rock[i].c >> rock[i].t;
		aerolite(rock[i].r, rock[i].c, rock[i].t);
	}
	escapeMeteor(0, 0);
}