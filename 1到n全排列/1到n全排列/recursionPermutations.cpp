#include <iostream>
using namespace std;

// 题目描述：
// 按照字典序输出自然数1到n所有不重复的排列，
// 即n的全排列，要求所产生的任一数字序列中不允许出现重复的数字，

// 输入格式：
// 一个整数n

// 输出格式：
// 由1~n组成的所有不重复的数字序列，每行一个序列，每个数字保留5个场宽。

// 输入样例：
// 3
// 输出样例：
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

void recursionPermutations(int n, int max, bool status[], int result[]) {
	if (n > max) {
		for (int i = 1; i <= max; i++) {
			cout << result[i];
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= max; i++) {
		if (!status[i]) {
			status[i] = true;
			result[n] = i;
			recursionPermutations(n + 1, max, status, result);
			status[i] = false;
			result[n] = 0;
		}
	}
}

int main() {
	int n;
	cout << "请输入n：";
	cin >> n;
	int* result = new int[n]();
	bool* status = new bool[n + 1]();
	recursionPermutations(1, n, status, result);
	return 0;
}