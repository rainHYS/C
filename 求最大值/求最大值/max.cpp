#include <iostream>
#include <iomanip>
using namespace std;

// 题目描述
// 已知m = max（a，b，c） / （max（a + b，b，c） * max（a，b，b + c）），
// 其中max（a，b，c）是求三个数a，b，c的最大值；

// 输入
// 输入三个整数a，b，c，中间用空格分开

// 输出
// 求m的值（保留三位小数）

double max(int a, int b, int c) {
	if (a >= b && a >= c) {
		return a;
	}
	else if (b >= c && b >= a) {
		return b;
	}
	else {
		return c;
	}
}

int main() {
	int a, b, c;
	float m;
	cin >> a >> b >> c;
	m = max(a, b, c) / (max(a + b, b, c) * max(a, b, b + c));
	cout << fixed << setprecision(3) << m << endl;
}