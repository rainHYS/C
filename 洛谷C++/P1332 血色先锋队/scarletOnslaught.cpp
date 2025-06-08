#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, m, a, b;

typedef struct {
	int r, c;
}point;

vector<vector<int>> scarletOnslaught;	//血色先锋军
vector<vector<bool>> undeathPlague;		//亡灵瘟疫

queue<point> q;

int dR[4] = { 0,1,0,-1 };
int dC[4] = { -1,0,1,0 };

//天灾军团，会将你吞噬！

void infect() {
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nR = cur.r + dR[i];
			int nC = cur.c + dC[i];
			if (nR < 0 || nR >= n || nC < 0 || nC >= m || undeathPlague[nR][nC]) {
				continue;
			}
			scarletOnslaught[nR][nC] = scarletOnslaught[cur.r][cur.c] + 1;
			undeathPlague[nR][nC] = true;
			q.push({ nR,nC });
		}
	}
}

int main() {
	cin >> n >> m >> a >> b;
	scarletOnslaught.resize(n, vector<int>(m, INT_MAX));
	undeathPlague.resize(n, vector<bool>(m, false));

	// 所有感染源先入队
	for (int i = 0; i < a; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		q.push({ x, y });
		scarletOnslaught[x][y] = 0;
		undeathPlague[x][y] = true;
	}
	infect();
	for (int i = 0; i < b; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		cout << scarletOnslaught[x][y] << endl;
	}
}