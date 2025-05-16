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
int count;
int oneToNine[10] = { 0 };	//	0代表未使用，1代表已使用，2代表已在a里面

void recADigit(int i) {	// 递归，将a所包含的数在oneToNine里面置为2
	if (i == 0) {
		return;
	}
	oneToNine[i % 10] = 2;
	return recADigit(i / 10);
}

void recBDigit(int product) {	// 递归，查验乘积结果是否有重复用过数位
	if (oneToNine[product % 10] != 0) {
		return;
	}
	else {
		return recBDigit(product / 10);
	}
}

void calA(int n) {
	for (int i = 1; i <= n; i++) {
		recADigit(i);

	}
}

int main() {
	int n;
	cin >> n;
	calA(n);
}