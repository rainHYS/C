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
// 
// 3 
// 2 
// 2 3 
// 1 
// 1 3 
// 1 2 
// 1 2 3 

// 自己头脑风暴写出来的程序，使用了伪递归实现，本质上其实是递推，而且结果少一个“1 3 ”
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
// 假定一个布尔类型的数组status表示各个数的状态：
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
// 观察这颗树，我们可以直观地看到所有的可能都在叶节点上，我们只需要从右往左输出叶节点即可

void recursionEnum(int n, int max, bool status[]) {
	if (n > max) {  // 修改终止条件
		for (int i = 1; i <= max; i++) {  // 从1开始检查
			if (status[i]) {
				cout << i << " ";
			}
		}
		cout << endl;
		return;
	}

	// 不选当前数字
	status[n] = false;
	recursionEnum(n + 1, max, status);

	// 选当前数字
	status[n] = true;
	recursionEnum(n + 1, max, status);
}

int main() {
	int n;
	cout << "请输入n：";
	cin >> n;

	int max = n;
	cout << "递推实现输出（只能生成连续子序列，少“1 3 ”）：" << endl;
	recurrenceEnum(n, max);
	cout << "--------------------------------------------" << endl;

	cout << "DFS深度优先+递归搜索树方法输出：" << endl;
	bool* status = new bool[n + 1]();  // 索引1到n对应数字1到n
	recursionEnum(1, max, status);  // 从1开始递归

	delete[] status;
	return 0;
}