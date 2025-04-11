#include <iostream>
using namespace std;

// 从1~n这几个整数中随机选取任意多个，输出所有可能的选择方案。

// 输入格式:
// 输入一个整数n。

// 输出格式:
// 每行输出一种方案。
// 同一行内的数必须升序排列，相邻两个数用恰好1个空格隔开。对于没有选任何数的方案，输出空行。

// 输入样例：
// 3

// 输出样例：
// 3 
// 2 
// 2 3 
// 1 
// 1 2 
// 1 2 3 

// 头脑风暴写出来的程序，使用了伪递归实现，本质上其实是递推，为错解
void recurrenceEnum(int n, int max) {
	if (n == 0) {
		return;
	}
	for (int i = n; i <= max; i++) {
		for (int j = n; j <= i; j++) {
			cout << j << " ";
		}
		cout << endl;
	}
	recurrenceEnum(n - 1, max);
}

// 正确答案，使用递归实现
void recursionEnum(int n){

}

int main() {
	int n;
	cout << "请输入n：";
	cin >> n;
	int max = n;
	recurrenceEnum(n, max);
	recursionEnum(n);
}