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

void recursionSum(int current, int maxN, int maxK, int num[], int result[], bool status[]) {
	int sum = 0;
	if (current > maxK) {
		for (int i = 1; i <= maxK; i++) {
			sum = sum + result[i];
		}
		bool check = true;
		for (int i = 2; i < sqrt(sum); i++) {
			if (!(sum % i)) {
				check = false;
				break;
			}
		}
		if (check) {
			for (int j = 1; j <= maxK; j++) {
				cout << result[j];
				if (j < maxK) {
					cout << "+";
				}
			}
			cout << "=" << sum;
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= maxN; i++) {
		if (!status[i] && num[i] > result[current - 1]) {
			status[i] = true;
			result[current] = num[i];
			recursionSum(current + 1, maxN, maxK, num, result, status);
			status[i] = false;
			result[current] = 0;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	int* num = new int[n + 1]();
	int* result = new int[k + 1]();
	bool* status = new bool[n + 1]();
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	recursionSum(1, n, k, num, result, status);
}