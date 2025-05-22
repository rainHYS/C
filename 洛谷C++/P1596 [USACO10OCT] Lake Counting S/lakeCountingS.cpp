#include <iostream>
using namespace std;

int n, m, cnt = 0;
char** field;
bool** status;

void recField(int ch, int cw) {
	if (ch < 0 || ch >= n || cw < 0 || cw >= m || status[ch][cw] || field[ch][cw] == '.') {
		return;
	}
	status[ch][cw] = true;
	recField(ch - 1, cw);
	recField(ch + 1, cw);
	recField(ch, cw - 1);
	recField(ch, cw + 1);
	recField(ch - 1, cw - 1);
	recField(ch - 1, cw + 1);
	recField(ch + 1, cw - 1);
	recField(ch + 1, cw + 1);
}

int main() {
	cin >> n >> m;
	field = new char* [n];
	for (int i = 0; i < n; i++) {
		field[i] = new char[m];
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
		}
	}
	status = new bool* [n]();
	for (int i = 0; i < n; i++) {
		status[i] = new bool[m]();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == 'W' && !status[i][j]) {	//操你妈是大写W不是小写w
				cnt++;
				recField(i, j);
			}
		}
	}
	cout << cnt;
}