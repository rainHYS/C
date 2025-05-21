#include <iostream>
using namespace std;

// 以下是自己打的代码，会出现溢出和内存占用极大
//int N, M, cal = 0, location = 0, * currentFinger, * marsFinger, ** result;
//bool same, * status;
//
//int permutation(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	return n * permutation(n - 1);
//}
//
//void calcular(int current) {
//	if (current > N) {
//		same = true;
//		cal++;
//		// 存储当前排列到二维数组result中
//		for (int i = 1; i <= N; i++) {
//			result[cal][i] = currentFinger[i];
//		}
//		// 判断当前序列与火星人手指是否一致
//		for (int i = 1; i <= N; i++) {
//			if (marsFinger[i] != currentFinger[i]) {
//				same = false;
//				break;
//			}
//		}
//		if (same) {
//			location = cal;
//		}
//		return;
//	}
//	for (int i = 1; i <= N; i++) {
//		if (!status[i]) {
//			status[i] = true;
//			currentFinger[current] = i;
//			calcular(current + 1);
//			status[i] = false;
//		}
//	}
//}
//
//int main() {
//	cin >> N;
//	cin >> M;
//	currentFinger = new int[N + 1]();
//	marsFinger = new int[N + 1]();
//	status = new bool[N + 1]();
//	// 动态建立二维数组
//	result = new int* [permutation(N) + 1]();
//	for (int i = 0; i <= permutation(N); i++) {
//		result[i] = new int[N + 1]();  // 每行存储一个排列
//	}
//	// 把火星人手指存进marsFinger中
//	for (int i = 1; i <= N; i++) {
//		cin >> marsFinger[i];
//	}
//	// 开始递归
//	calcular(1);
//	// 输出和火星人相同的手指序列
//	for (int i = 1; i <= N; i++) {
//		cout << result[location][i] << " ";
//	}
//	cout << "表示数字" << location << endl;
//	// 输出加完数字之后得到的的手指序列和对应的数字
//	for (int i = 1; i <= N; i++) {
//		cout << result[location+M][i] << " ";
//	}
//	cout << "表示数字" << location+M << endl;
//}

int N, M, * marsFinger;

void nextPermutation() {
	int i = N - 1;
	while (i >= 1 && marsFinger[i] >= marsFinger[i + 1]) {
		i--;
	}

	if (i >= 1) {
		int j = N;
		while (marsFinger[j] <= marsFinger[i]) {
			j--;
		}
		swap(marsFinger[i], marsFinger[j]);
	}

	int left = i + 1, right = N;
	while (left < right) {
		swap(marsFinger[left], marsFinger[right]);
		left++;
		right--;
	}
}

int main() {
	cin >> N >> M;
	marsFinger = new int[N + 1]();

	for (int i = 1; i <= N; i++) {
		cin >> marsFinger[i];
	}

	for (int m = 0; m < M; m++) {
		nextPermutation();
	}

	for (int i = 1; i <= N; i++) {
		cout << marsFinger[i];
		if (i < N) cout << " ";
	}

	delete[] marsFinger;
	return 0;
}