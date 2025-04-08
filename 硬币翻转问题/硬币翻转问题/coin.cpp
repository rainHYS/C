#include <iostream>
#include <string>
using namespace std;

// 题目描述：
// 有很多个硬币摆在一行，有正面朝上的，也有背面朝上的。正面朝上的用1表示，背面朝上的用0表示。
// 现在要求从这行的第一个硬币开始，将从第一个硬币开始的前若干个硬币同时翻面，
// 求如果要将所有硬币翻到正面朝上，最少要进行这样的操作多少次？

// 输入：
// 一个字符串，由0和1组成，表示硬币的初始状态。

// 输出：
// 一个整数，表示要翻转的最少次数。

int main() {
	string coinList;
	int count=0;
	cin >> coinList;
	for (int i = coinList.length() - 1; i >= 0; i--) {
		cout << "第" << i + 1 << "位" << coinList[i] << endl;
		if (coinList[i] == '0') {
			for (int j = 0; j <= i; j++) {
				coinList[j] = coinList[j] ^ 1;
			}
			count++;
		}
		for (int j = 0; j < coinList.length(); j++) {
			cout << coinList[j];
		}
		cout << endl;
	}
	cout << count;
}