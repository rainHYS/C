#include <iostream>
using namespace std;

//自己写的，运用了组合代码，但是会遍历大量无效化的组合（如1 1 1，1 1 2等等，导致时间巨长）
//
//int n, k, cnt = 0;
//int* result;
//
//void recDiv(int pos) {
//	if (pos > k) {
//		int sum = 0;
//		for (int i = 1; i <= k; i++) {
//			sum += result[i];
//		}
//		if (sum == n) {
//			cnt++;
//		}
//		return;
//	}
//	for (int i = 1; i <= n - k + 1; i++) {
//		if (i >= result[pos - 1]) {
//			result[pos] = i;
//			recDiv(pos + 1);
//		}
//	}
//}
//
//int main() {
//	cin >> n >> k;
//	result = new int[k + 1]();
//	recDiv(1);
//	cout << cnt;
//}

// ---------------------------------------------------------
// 正解：剪枝，将大量不可能的组合剪掉，有效降低时间复杂度

int n, k, cnt = 0;
int* result;

void recDiv(int pos, int currentSum) {
	if (pos > k) {
		if (currentSum == n) cnt++;
		return;
	}

	// 剪枝优化：当前数至少为上一个数，最多为剩余数的平分值
	int minValue = result[pos - 1]; // 保证非递减
	for (int i = minValue; i <= n - currentSum - (k - pos); i++) {
		result[pos] = i;
		recDiv(pos + 1, currentSum + i);
	}
}

int main() {
	cin >> n >> k;
	result = new int[k + 1]();  // 多一位，方便 result[0] = 1 的初始化
	result[0] = 1;              // 初始为1，确保第一项能为1开始（非负递增）
	recDiv(1, 0);
	cout << cnt;
	delete[] result;
	return 0;
}
