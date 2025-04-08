#include <iostream>
using namespace std;

// 描述：N位旅行者在夜里过桥需要借助手电筒。
// 但N个人中只有一个手电筒，而且桥同时只能让两个人过。
// 每个人单独过桥所需时间已知，但如果两个人同时过桥则所需时间是走得慢的那个人单独过桥所需的时间。
// 设计一个方案，让这N个人尽快过桥，计算这N个人的最短过桥时间。

// 比如：有甲乙丙丁四个人，他们过河所需的时间分别是1，2，5，10。
// 让最快的2个人先过桥，然后让跑的最快的人回去接剩下的人。
// 先让甲乙过去（2分钟），甲回来（1分钟），甲丙过去（5分钟）
// 甲回来（1分钟），甲丁再过去（10分钟），总共需要19分钟。

int fastFirst(int* costTime, int n) {
	int sum = 0;
	while (1) {
		sum += costTime[n - 1];
		n--;
		if (n==1) {
			return sum;
		}
		else {
			sum += costTime[0];
		}
	}
}

int fastSlow(int* costTime, int n) {
	int sum = 0;
	while (n > 1) {
		if (n > 3) {
			sum += costTime[0] + 2 * costTime[1] + costTime[n - 1];
			n -= 2;
		}
		else if (n == 3) {
			sum += costTime[0] + costTime[n-1];
			n--;
		}
		else{
			sum += costTime[1];
			n -= 2;
		}
	}
	return sum;
}

int main() {
	int n, result1, result2;
	cin >> n;
	int* costTime = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> costTime[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (costTime[i] > costTime[j]) {
				int temp = costTime[i];
				costTime[i] = costTime[j];
				costTime[j] = temp;
			}
		}
	}

	// 采取两种策略：

	// 第一种策略：让最快的全程跑腿来回接送
	result1 = fastFirst(costTime, n);
	cout << result1 << endl;
	// 第二种策略：一快一慢交替过河，最快和次快过河，最快回，随后最慢和次慢过河，次快回；依次重复直到全员过河
	result2 = fastSlow(costTime, n);
	cout << result2 << endl;
	return 0;
}