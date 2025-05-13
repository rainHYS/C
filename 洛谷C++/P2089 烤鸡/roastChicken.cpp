#include <iostream>
using namespace std;
// 题目背景
// 猪猪 Hanke 得到了一只鸡。

// 题目描述
// 猪猪 Hanke 特别喜欢吃烤鸡（本是同畜牲，相煎何太急！）Hanke 吃鸡很特别，为什么特别呢？
// 因为他有 10 种配料（芥末、孜然等），每种配料可以放 1 到 3 克，任意烤鸡的美味程度为所有配料质量之和。
// 现在， Hanke 想要知道，如果给你一个美味程度 n ，请输出这 10 种配料的所有搭配方案。

// 输入格式
// 一个正整数 n，表示美味程度。

// 输出格式
// 第一行，方案总数。
// 第二行至结束，10 个数，表示每种配料所放的质量，按字典序排列。
// 如果没有符合要求的方法，就只要在第一行输出一个 0。

int n;
int cal = 0;
int seasoning[11];

void calFuction(int current, int sum) {
	if (current > 10) {
		if (sum == n) {
			cal++;
		}
		return;
	}
	for (int i = 1; i <= 3; i++) {
		seasoning[current] = i;
		calFuction(current + 1, sum + i);
		seasoning[current] = 0;
	}
}

void roastChicken(int current, int sum) {
	if (current > 10) {
		if (sum == n) {
			for (int i = 1; i <= 10; i++) {
				cout << seasoning[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= 3; i++) {
		seasoning[current] = i;
		roastChicken(current + 1, sum + i);
		seasoning[current] = 0;
	}
}

int main() {
	cin >> n;
	if (n > 30 || n < 10) {
		cout << 0;
		return 0;
	}
	calFuction(1, 0);
	cout << cal << endl;
	roastChicken(1, 0);
	return 0;
}