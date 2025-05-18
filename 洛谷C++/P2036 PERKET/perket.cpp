#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int n;
int** seasoning;
int minDif = INT_MAX;
bool* status;

void recComb(int pos, int usedCount) {
	if (pos == n) {
		if (usedCount == 0) {  // ❗️忽略没有选任何调料的情况
			return;
		}
		int product = 1;	//酸味的积
		int sum = 0;	//苦味的和
		for (int i = 0; i < n; i++) {
			if (status[i]) {
				product *= seasoning[i][0];
				sum += seasoning[i][1];
			}
		}
		if (abs(sum - product) < minDif) {
			minDif = abs(sum - product);
		}
		return;
	}
	status[pos] = true;
	recComb(pos + 1, usedCount + 1);  // 选择当前调料
	status[pos] = false;
	recComb(pos + 1, usedCount);      // 不选当前调料
}

int main() {
	cin >> n;
	status = new bool[n]();
	seasoning = new int* [n];     // 创建 n 个“行指针”
	for (int i = 0; i < n; i++) {
		seasoning[i] = new int[2];     // 为每一行分配2个整型空间
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> seasoning[i][j];
		}
	}
	recComb(0, 0);
	cout << minDif;
	return 0;
}