#include <iostream>
#include <vector>
#include <queue>
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

void infect(int cR, int cC) {
	scarletOnslaught[cR][cC] = 0;
	undeathPlague[cR][cC] = true;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nR = cur.r + dR[i];
			int nC = cur.c + dC[i];
			if (nR < 0 || nR >= n || nC < 0 || nC >= m || undeathPlague[nR][nC]) {
				continue;
			}

		}
	}
}

int main() {
	cin >> n >> m >> a >> b;
	scarletOnslaught.resize(n, vector<int>(m, INT_MAX));
	undeathPlague.resize(n, vector<bool>(m, false));
	for (int i = 0; i < a; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		infect(x, y);
	}
}