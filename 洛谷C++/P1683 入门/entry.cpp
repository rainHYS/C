#include <iostream>
using namespace std;

int h, w, cnt = 0;
int atX = 0, atY = 0;
char** charMatrix;
bool** status;

void recEntry(int x, int y) {
	// 判断越界或撞墙或走过
	if (x < 0 || y < 0 || x >= h || y >= w || charMatrix[x][y] == '#' || status[x][y]) {
		return;
	}
	status[x][y] = true;
	cnt++;

	// 向上
	recEntry(x - 1, y);
	// 向下
	recEntry(x + 1, y);
	// 向左
	recEntry(x, y - 1);
	// 向右
	recEntry(x, y + 1);
}

int main() {
	cin >> w >> h;  // 注意：题目是宽在前，表示列数

	charMatrix = new char* [h];
	for (int i = 0; i < h; i++) {
		charMatrix[i] = new char[w];
	}

	status = new bool* [h];
	for (int i = 0; i < h; i++) {
		status[i] = new bool[w]();
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> charMatrix[i][j];
			if (charMatrix[i][j] == '@') {
				atX = i;
				atY = j;
			}
		}
	}

	recEntry(atX, atY);
	cout << cnt;
}
