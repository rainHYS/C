#include<iostream>
using namespace std;

//// 自己写的，只能判断abc是一位数的情况，解不完全
//int match[10] = { 6,2,5,5,4,5,6,3,7,6 };	//0-9的火柴数
//int result[3];	//排列结果数组
//bool matchStatus[10] = { 0 };	//状态数组
//int n;	//用户输入
//int cnt = 0;	//计数
//
//void recEqution(int pos) {	//递归求火柴棒等式
//	if (pos == 3) {
//		//cout << result[0] << " " << result[1] << " " << result[2] << endl;
//		int matchSum = match[result[0]] + match[result[1]] + match[result[2]];
//		if (matchSum == n && result[0] + result[1] == result[2]) {
//			cnt++;
//		}
//		return;
//	}
//	for (int i = 0; i < 10; i++) {
//		matchStatus[i] = true;
//		result[pos] = i;
//		recEqution(pos + 1);
//		matchStatus[i] = false;
//		result[pos] = 0;
//	}
//}
//
//int main() {
//	cin >> n;
//	n -= 4;	//减掉+=的火柴棒数
//	recEqution(0);
//	cout << cnt;
//}

// ---------------------------------------------
// 正解，递推枚举所有的1000内a、b、c（用a+b表示）的可能，并且放到getMatchCount函数里转成火柴棍数，再计算是否符合n

// 每个数字需要的火柴数
int getMatchCount(int num) {
    int matchDigit[10] = { 6,2,5,5,4,5,6,3,7,6 };
    if (num == 0) return matchDigit[0];
    int sum = 0;
    while (num > 0) {
        sum += matchDigit[num % 10];
        num /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;

    // -4 是为了减去 '+' 和 '=' 所用的火柴
    for (int a = 0; a < 1000; a++) {
        for (int b = 0; b < 1000; b++) {
            int c = a + b;
            int total = getMatchCount(a) + getMatchCount(b) + getMatchCount(c);
            if (total == n - 4) {
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}
