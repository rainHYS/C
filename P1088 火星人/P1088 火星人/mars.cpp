#include <iostream>
using namespace std;

// 题目描述
// 人类终于登上了火星的土地并且见到了神秘的火星人。人类和火星人都无法理解对方的语言，
// 但是我们的科学家发明了一种用数字交流的方法。这种交流方法是这样的，
// 首先，火星人把一个非常大的数字告诉人类科学家，科学家破解这个数字的含义后，
// 再把一个很小的数字加到这个大数上面，把结果告诉火星人，作为人类的回答。

// 火星人用一种非常简单的方式来表示数字――掰手指。
// 火星人只有一只手，但这只手上有成千上万的手指，
// 这些手指排成一列，分别编号为 1, 2, 3, ⋯。
// 火星人的任意两根手指都能随意交换位置，他们就是通过这方法计数的。

// 一个火星人用一个人类的手演示了如何用手指计数。
// 如果把五根手指――拇指、食指、中指、无名指和小指分别编号为 1, 2, 3, 4 和 5，
// 当它们按正常顺序排列时，形成了 5 位数 12345，
// 当你交换无名指和小指的位置时，会形成 5 位数 12354，
// 当你把五个手指的顺序完全颠倒时，会形成 54321，
// 在所有能够形成的 120 个 5 位数中，12345 最小，它表示 1；
// 12354 第二小，它表示 2；54321 最大，它表示 120。
// 下表展示了只有 3 根手指时能够形成的 6 个 3 位数和它们代表的数字：

// 三位数	代表的数字
//  123			1
//  132			2
//  213			3
//  231			4
//  312			5
//  321			6
// 现在你有幸成为了第一个和火星人交流的地球人。
// 一个火星人会让你看他的手指，科学家会告诉你要加上去的很小的数。
// 你的任务是，把火星人用手指表示的数与科学家告诉你的数相加，
// 并根据相加的结果改变火星人手指的排列顺序。输入数据保证这个结果不会超出火星人手指能表示的范围。

// 输入格式
// 共三行。
// 第一行一个正整数 N，表示火星人手指的数目（1≤N≤10000）。
// 第二行是一个正整数 M，表示要加上去的小整数（1≤M≤100）。
// 下一行是 1 到 N 这 N 个整数的一个排列，用空格隔开，表示火星人手指的排列顺序。

// 输出格式
// N 个整数，表示改变后的火星人手指的排列顺序。每两个相邻的数中间用一个空格分开，不能有多余的空格。

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