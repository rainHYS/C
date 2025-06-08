#include <iostream>
#include <vector>
#include <queue>
#define max 21
using namespace std;

typedef struct {
	int r, c;
} point;

int dR[12] = { -2, -1, 1, 2, 2, 1, -1, -2 , -2, 2, 2, -2 };
int dC[12] = { 1, 2, 2, 1, -1, -2, -2, -1 , 2, 2, -2, -2 };

int minStep(int startR, int startC) {
	vector<vector<int>> chess(max, vector<int>(max, 0));
	vector<vector<bool>> status(max, vector<bool>(max, false));
	queue<point> q;

	chess[startR][startC] = 0;
	status[startR][startC] = true;
	q.push({ startR, startC });

	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		if (cur.r == 0 && cur.c == 0) {
			return chess[0][0];
		}
		for (int i = 0; i < 12; i++) {
			int nR = cur.r + dR[i];
			int nC = cur.c + dC[i];
			if (nR < 0 || nR >= max || nC < 0 || nC >= max || status[nR][nC]) {
				continue;
			}
			chess[nR][nC] = chess[cur.r][cur.c] + 1;
			status[nR][nC] = true;
			q.push({ nR, nC });
		}
	}
}

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;

	cout << minStep(x1 - 1, y1 - 1) << endl;
	cout << minStep(x2 - 1, y2 - 1) << endl;

	return 0;
}
