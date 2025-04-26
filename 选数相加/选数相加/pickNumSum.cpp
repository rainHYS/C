#include <iostream>
using namespace std;

// 题目描述:
// 已知n个整数对X1，X2，... ，Xn，以及1个整数k（k < n）。从n个整数中任选k个整数相加，
// 可分别得到一系列的和。例如当n = 4，k = 3，
// 4个整数分别为3，7，12，19时，可得全部的组合与它们的和为：
// 3 + 7 + 12 = 22
// 3 + 7 + 19 = 29
// 7 + 12 + 19 = 38
// 3 + 12 + 19 = 34
// 现在，要求你计算出和为素数共有多少种，
// 例如上例，只有一种的和为素数：3 + 7 + 19 = 29，

// 输入格式
// 第一行两个空格隔开的整数n，k（1 < n < 20，k < n）。
// 第二行n个整数，分别为X1，X2，...，Xn（1 <= Xi <= 5 × 10^6）

// 输出格式
// 输出一个整数，表示种类数。

void recursionSum(int current, int maxN, int maxK, int num[], bool status[]) {
	if (current == maxN) {
		return;
	}
	for (int i = 0; i < maxN; i++) {
		if (!status[i]) {
			status[i] = true;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	int* num = new int[n];
	bool* status = new bool[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	recursionSum(0, n, k, num, status);
}