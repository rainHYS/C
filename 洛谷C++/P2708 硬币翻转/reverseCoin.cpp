#include <iostream>
#include <string>
using namespace std;

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

// ---------------------------------

// 正解：
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