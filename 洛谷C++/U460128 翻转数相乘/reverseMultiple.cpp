#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

// 题目描述
// 假设一个n位数，如 a1a2a3..an，其中ai是这个数的第i位上的数字，且这个n位数不是每个位都相等的数字，例如不是 2222 或类似。
// 如果有一个整数 x，并且1 < x < 10，使得 a1a2a3..an * x = ana(n - 1)a(n - 2)...a1，求x,
// 其中 a1 和 an不能为 0，如果x无解，则输出 0，如果有多个 x，则从小到大输出所有x的解，中间用空格隔开。
// 例如 : 一个5位数，ABCDE * ? = EDCBA，其中A、B、C、D、E是个位整数，ABCDE和EDCBA是一个万位数，求符合这个等式的乘数。

// 输入格式
// 输入1个数，表示要求解的n位数。

// 输出格式
// 输出表示所有可能的乘数，并按照从小到大排列，用回车隔开，

// 输入输出样例
// 输入
// 6

// 输出
// 4
// 9
int n;
int cnt = 0;
int result[9];

// 检查数字是否全相同（如2222）
bool isAllSame(int num) {
    int last = num % 10;
    while (num > 0) {
        if (num % 10 != last) return false;
        num /= 10;
    }
    return true;
}

// 检查首位或末位是否为0
bool hasInvalidZeros(int num) {
    return (num % 10 == 0) || (num / (int)pow(10, n - 1) == 0);
}

int revNum(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

void checkEquel() {
    for (int i = (int)pow(10, n - 1); i < (int)pow(10, n); i++) {
        if (hasInvalidZeros(i) || isAllSame(i)) continue;

        int reversed = revNum(i);
        int x = reversed / i;
        if (reversed % i == 0 && x > 1 && x < 10) {
            result[cnt++] = x;
        }
    }
}

int main() {
	cin >> n;
	checkEquel();
	if (!cnt) {
		cout << 0;
	}
	else {
		sort(result, result + cnt);
		for (int i = 0; i < cnt; i++) {
			cout << result[i];
			if (i != cnt - 1) {
				cout << endl;
			}
		}
	}
}