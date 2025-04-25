#include <iostream>
using namespace std;

// 题目要求：
// 排列与组合是常用的数学方法，其中组合就是从n个元素中抽出r个元素（不分顺序且r < n），
// 我们可以简单地将几个元素理解为自然数1，2，...，n，从中任取r个数。
// 现要求你输出所有组合。
// 例如n = 5，r = 3，所有组合为：
// 123，124，125，134，135，145，234，235，245，345.

// 输入格式
// 一行两个自然数n，r（1 < n < 21，0 < r < n）。

// 输出格式
// 所有的组合，每一个组合占一行且其中的元素按由小到大的顺序排列，
// 每个元素占三个字符的位置，所有的组合也按字典顺序。

void recursionCombination(int current, int maxN, int maxR, int result[], bool status[]) {
	if (current > maxN) {
		for (int i = 1; i <= maxR; i++) {
			cout << result[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= maxN; i++) {
		if (!status[i]) {
			status[i] = true;
			result[i] = i;
			recursionCombination(current + 1, maxN, maxR, result, status);
			status[i] = false;
			result[i] = 0;
		}
	}
	return;
}

int main() {
	int n, r;
	cin >> n >> r;
	int* result = new int[r + 1]();
	bool* status = new bool[n + 1]();
	recursionCombination(1, n, r, result, status);
	
	return 0;
}