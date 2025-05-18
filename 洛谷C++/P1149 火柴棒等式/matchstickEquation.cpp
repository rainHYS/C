#include<iostream>
using namespace std;

// 题目描述
// 给你 n 根火柴棍，你可以拼出多少个形如 A + B = C 的等式？
// 等式中的 A、B、C 是用火柴棍拼出的整数（若该数非零，则最高位不能是 0）。用火柴棍拼数字 0∼9 的拼法如图所示：
// 注意：
// 1、加号与等号各自需要两根火柴棍；
// 2、如果 A != B，则 A + B = C 与 B + A = C 视为不同的等式（A, B, C≥0）；
// 3、n 根火柴棍必须全部用上。

// 输入格式
// 一个整数 n(1≤n≤24)。

// 输出格式
// 一个整数，能拼成的不同等式的数目。

// 输入输出样例
// 输入
// 14
// 输出
// 2
// 输入
// 18
// 输出
// 9

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
