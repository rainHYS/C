#include <iostream>
using namespace std;

// -----------------------------------------------------------------

// 自己写的思路：先分位数再排列
int n;
int cnt;
int digitCount[4];     // a, b, c的位数
int digitValue[10];    // 存储1~9的某个排列
bool oneToNine[10] = { 0 }; // 标记数字是否使用过

void permOneToNine(int pos, int max) {
	if (pos > max) {
		int a = 0, b = 0, c = 0;
		int index = 1;
		// 构造a
		for (int i = 0; i < digitCount[1]; i++) {
			a = a * 10 + digitValue[index++];
		}
		// 构造b
		for (int i = 0; i < digitCount[2]; i++) {
			b = b * 10 + digitValue[index++];
		}
		// 构造c
		for (int i = 0; i < digitCount[3]; i++) {
			c = c * 10 + digitValue[index++];
		}
		// 判断是否符合 n = a + b / c ，转成乘法避免浮点数问题
		if (c != 0 && c * (n - a) == b) {
			cout << a << " " << b << " " << c << endl;
			cnt++;
		}
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (!oneToNine[i]) {
			oneToNine[i] = true;
			digitValue[pos] = i;
			permOneToNine(pos + 1, max);
			oneToNine[i] = false;
			digitValue[pos] = 0;
		}
	}
}

void permDigit(int current, int sum) {
	if (current > 3) {
		if (sum == 9) {
			permOneToNine(1, 9);
		}
		return;
	}
	for (int i = 1; i <= 7; i++) { // 限制最长不超过9位
		digitCount[current] = i;
		permDigit(current + 1, sum + i);
		digitCount[current] = 0;
	}
}

int main() {
	cin >> n;
	cnt = 0;
	permDigit(1, 0);
	cout << cnt << endl;
	return 0;
}