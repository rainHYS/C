#include <iostream>
using namespace std;

// 题目描述
// 给定两个已经从小到大排好序的数组A, B(设A，B的元素个数为n，m)，将他们合并成一个从小到大排列的数组并输出

// 输入描述
// 第一行为n, m两个整数表示A，B数组的元素个数
// 第二行n个整数表示A中的元素
// 第三行m个整数表示B中的元素

// 输出描述
// 一行m + n个整数用空格隔开

void bubbleOrder(int arrayA[], int arrayB[], int arrayC[], int m, int n) {
	//直接将arrayA和arrayB暴力塞进arrayC里面，拼接完再排序
	for (int i = 0; i < m; i++) {
		arrayC[i] = arrayA[i];
	}
	for (int i = 0; i < n; i++) {
		arrayC[m + i] = arrayB[i];
	}
	//请在下面填写代码：对arrayC进行冒泡排序并输出
	for (int i = 0; i < m + n; i++) {
		for (int j = i; j < m + n; j++) {
			if (arrayC[i] > arrayC[j]) {
				int temp = arrayC[i];
				arrayC[i] = arrayC[j];
				arrayC[j] = temp;
			}
		}
	}
	for (int i = 0; i < m + n; i++) {
		cout << arrayC[i] << " ";
	}
	cout << endl;
}

void binaryMerge(int arrayA[], int arrayB[], int arrayC[], int m, int n) {
	//二路归并排序思想，边放进去边对比着排序
	int i = 0, j = 0, k = 0;  // i遍历A，j遍历B，k填充C
	while (i < m && j < n) {
		if (arrayA[i] < arrayB[j]) {
			arrayC[k++] = arrayA[i++];
		}
		else {
			arrayC[k++] = arrayB[j++];
		}
	}
	while (i < m) {
		arrayC[k++] = arrayA[i++];
	} // 处理A剩余部分
	while (j < n) {
		arrayC[k++] = arrayB[j++];
	} // 处理B剩余部分
	for (i = 0; i < m + n; i++) {
		cout<<arrayC[i]<<" ";
	}
	cout << endl;
}

int main() {
	int m, n;
	cin >> m >> n;
	int* arrayA = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> arrayA[i];
	}
	int* arrayB = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arrayB[i];
	}
	int* arrayC = new int[m + n];
	bubbleOrder(arrayA, arrayB, arrayC, m, n);
	binaryMerge(arrayA, arrayB, arrayC, m, n);
}