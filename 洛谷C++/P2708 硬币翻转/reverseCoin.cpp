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

//我自己思考打出来的双重for，能出正解，但处理e^10的情况时间复杂度极高，在洛谷只能拿50分
//int main() {
//	string coinList;
//	int count = 0;
//	cin >> coinList;
//	for (int i = coinList.length() - 1; i >= 0; i--) {
//		//cout << "第" << i + 1 << "位" << coinList[i] << endl;
//		if (coinList[i] == '0') {
//			for (int j = 0; j <= i; j++) {
//				coinList[j] = coinList[j] ^ 1;
//			}
//			count++;
//		}
//		/*for (int j = 0; j < coinList.length(); j++) {
//			cout << coinList[j];
//		}
//		cout << endl;*/
//	}
//	cout << count;
//}

// 时间复杂度O(n)，只判断不实际翻，天才写法
// 并且从右向左处理：确保每次翻转都能解决最右边的'0'，最后必定是全正面
int main() {
    string coins;
    cin >> coins;
    int count = 0;
    bool flip = false;  // 标记当前是否需要翻转

    // 从右向左遍历
    for (int i = coins.size() - 1; i >= 0; i--) {
        // 当前硬币的实际状态
        bool current = (coins[i] == '1') ^ flip;

        if (!current) {  // 如果是反面朝上
            count++;
            flip = !flip;  // 翻转状态
        }
    }

    cout << count;
    return 0;
}