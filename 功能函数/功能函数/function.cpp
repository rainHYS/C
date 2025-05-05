#include <iostream>
using namespace std;

// 题目描述
// 对于一个递归函数w(a, b, c)
// 这是个简单的递归函数，但实现起来可能会有些问题。比如当a, b, c均为15时，调用的次数将非常的多。你要想个办法才行.
// 如果a <= 0或b <= 0或c <= 0就返回 1;
// 如果a > 20或b > 20或c > 20 就返回w(20, 20, 20); 
// 如果a < b幷且b < c就返回w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); 
// 其他时候返回 w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)。
// 比如 w(30, -1, 0)既满足条件1又满足条件2 > 这种时候我们就按最上面的条件来算 > 所以答案为1

// 输入描述
// 会有若干行。
// 并以 - 1. - 1. - 1结束
// 保证输入的数在[-9223372036854775808, 9223372036854775807]之间，并且是整数

// 输出描述
// 一行一个结果!

long long int w(long long int a, long long int b, long long int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}
	else if (a < b && b < c) {
		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main() {
	long long int a, b, c, result;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		//c++输出写法
		cout << "w(" << a << "," << b << "," << c << ")" << "=" << w(a, b, c) << endl;
		//c输出写法
		printf("w(%ld,%ld,%ld)=%ld\n", a, b, c, w(a, b, c));
	}
}