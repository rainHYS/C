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

// 自己头脑风暴写出来的程序，使用了伪递归实现，本质上其实是递推，为错解
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

// 正确答案，使用DFS（深度优先算法）和递归搜索树实现
// 思路：
// 要输出所有可能子序列，可以这么处理：
// 假定一个数组status表示各个数的状态，0代表×，1代表√，2代表还不确定：
//                1     2      3
//                ?     ?      ?
//	        出现/                 \不出现
//		     1 2 3               1 2 3
//           √ ? ?               × ? ? 
//  	    /      \            /      \ 
//        123      123        123      123
//        √√?      √×?        ×√?      ××?
//       /  \     /   \      /  \     /   \
//     123  123  123  123  123  123  123  123
//     √√√  √√×  √×√  √××  ×√√  ×√×  ××√  ××× 

void recursionEnum(int n) {
	if (n == 0) {
		return;
	}
	recursionEnum(n);
	cout << n << " ";
	recursionEnum(n - 1);
	cout << endl;
}

int main() {
	int n;
	cout << "请输入n：";
	cin >> n;
	int max = n;
	recurrenceEnum(n, max);
	recursionEnum(n);
}