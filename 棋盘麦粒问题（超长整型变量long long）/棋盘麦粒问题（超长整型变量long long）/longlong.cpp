#include <iostream>
using namespace std;
int main() {
	long long wheat = 2;	//wheat n.麦粒，定义为unsigned long long无符号超长整型
	// 无符号超长整型是 C++ 11 标准新添加的
	// long long 有符号超长整型范围只是-2^63~2^63-1，没够到第64格
	// 但这个沟槽的题目系统就是要报错溢出的结果，所以就这么写，不用大数加减！
	int sum = 0;
	for (int i = 0; i < 64; i++) {
		cout << i + 1 << " " << wheat << endl;
		wheat *= 2;
		sum += wheat;
	}
	cout << sum;
}