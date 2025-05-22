#include <iostream>
using namespace std;

int n, m, t, sx, sy, fx, fy, bx, by, cnt = 0;
int** maze;	//0表示可走，1表示有障碍
bool** status;

void recMaze(int cy, int cx) {
	if (cy < 0 || cy >= n || cx < 0 || cx >= m || maze[cy][cx] || status[cy][cx]) {
		return;
	}
	if (cx == fx - 1 && cy == fy - 1) {
		cnt++;
		return;
	}
	status[cy][cx] = true;
	recMaze(cy - 1, cx);	//向上
	recMaze(cy + 1, cx);	//向下
	recMaze(cy, cx - 1);	//向左
	recMaze(cy, cx + 1);	//向右
	status[cy][cx] = false;
}

int main() {
	cin >> n >> m >> t;

	maze = new int* [n]();
	for (int i = 0; i < n; i++) {
		maze[i] = new int[m]();
	}

	status = new bool* [n]();
	for (int i = 0; i < n; i++) {
		status[i] = new bool[m]();
	}

	cin >> sx >> sy >> fx >> fy;
	for (int i = 0; i < t; i++) {
		cin >> bx >> by;
		maze[by - 1][bx - 1] = 1;
	}
	recMaze(sy - 1, sx - 1);
	cout << cnt;
}