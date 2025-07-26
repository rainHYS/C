#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;  // 直接读取整个分数字符串，如"1/2"或"12/34"

    // 解析第一个分数
    size_t slash_pos = a.find('/');
    int num1 = stoi(a.substr(0, slash_pos));
    int den1 = stoi(a.substr(slash_pos + 1));

    // 解析第二个分数
    slash_pos = b.find('/');
    int num2 = stoi(b.substr(0, slash_pos));
    int den2 = stoi(b.substr(slash_pos + 1));

    // 计算乘积
    int num = num1 * num2;
    int den = den1 * den2;

    // 计算最大公约数
    int gcd = 1;
    for (int i = min(abs(num), abs(den)); i >= 1; --i) {
        if (num % i == 0 && den % i == 0) {
            gcd = i;
            break;
        }
    }

    // 约分
    num /= gcd;
    den /= gcd;

    cout << den << " " << num;
    return 0;
}