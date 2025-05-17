#include <iostream>
using namespace std;

// 题目描述
// 一个小于 100 万的正整数 n，尝试把, n变成带分数形式，也就是 n = a + b / c，
// 其中a，b，c是三个正整数，并且数字 1~9(不含 0)在 a、b、c中，必须出现，且只能出现一次。
// 例如 : 100 = 3 + 69258 / 714，其中1到9这9个数字全都出现了，
// 并且只出现一次。当然，100 还等于 82 + 3546 / 197，
// 也就是说将 100 变成带分数形式，会有两种组合方式。
// 事实上 100，可以写成 11 种 1到9 组成整数加上分数的形式。
// 请编写一个程序，根据一个输入 N，程序输出该数字用数1~9不重复不遗漏地组成带分数表示的全部可能性。
// 不要求输出每个表示，只输出有多少种表示法!

// 输入格式
// 输入一行，表示要分解的正整数。

// 输出格式
// 输出一行，表示有多少分法。

// 输入样例
// 100

// 输出样例
// 11

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