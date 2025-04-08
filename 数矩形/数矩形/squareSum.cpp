#include <iostream>
using namespace std;

// 描述：设有一个N* M方格的棋盘（1 <= N <= 100，1 <= M <= 100）
// 求出该棋盘中包含有多少个正方形，多少个长方形（不包括正方形）。

// 例如：当N = 2，M = 3时：
// 正方形的个数有8个，即边长为1的正方形有6个；边长为2的正方形有2个。长方形的个数有10个

int main() {
	int n, m, square = 0, rectangle = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int x = i; x < n; x++) {
				for (int y = j; y < m; y++) {
					if (y - j == x - i) {
						square++;
					}
					else {
						rectangle++;
					}
				}
			}
		}
	}
	cout << "正方形：" << square << endl;
	cout << "长方形：" << rectangle << endl;
}