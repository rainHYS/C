#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//int n;
//int cnt = 0;
//int result[8]; // x只能是2-9，最多8种可能
//
//bool isAllSame(int num) {
//    int last = num % 10;
//    while (num > 0) {
//        if (num % 10 != last) {
//            return false;
//        }
//        num /= 10;
//    }
//    return true;
//}
//
//bool hasInvalidZeros(int num) {
//    return (num % 10 == 0) || (num / (int)pow(10, n - 1) == 0);
//}
//
//int revNum(int num) {
//    int reversed = 0;
//    while (num > 0) {
//        reversed = reversed * 10 + num % 10;
//        num /= 10;
//    }
//    return reversed;
//}
//
//void checkEquel() {
//    int start = pow(10, n - 1);
//    int end = pow(10, n) - 1;
//
//    // 预计算可能的x范围
//    for (int x = 2; x <= 9; x++) {
//        // 计算满足num * x = reverse(num)的最小可能num
//        int min_num = ceil(start / (double)x);
//        // 计算最大可能num
//        int max_num = min(end, (int)(pow(10, n) - 1) / x);
//
//        for (int num = min_num; num <= max_num; num++) {
//            if (hasInvalidZeros(num) || isAllSame(num)) continue;
//
//            int reversed = revNum(num);
//            if (num * x == reversed) {
//                result[cnt++] = x;
//                break; // 找到该x的一个解即可
//            }
//        }
//    }
//}
//
//int main() {
//    cin >> n;
//    checkEquel();
//
//    if (cnt == 0) {
//        cout << 0;
//    }
//    else {
//        sort(result, result + cnt);
//        for (int i = 0; i < cnt; i++) {
//            cout << result[i];
//            if (i < cnt - 1) cout << " ";
//        }
//    }
//    return 0;
//}

// ----------------------------------------------------------------------

// 正确解法（很TM扯，数学归纳法O(1)秒了）：
// 硬要解释的话，因为2和8是特殊数对，乘4会变成对方（4×8=32——2结尾；4×2=8——8结尾；刚好互为对方）
// 1和9是特殊数对，乘9会变成对方（1×9=9——9结尾；9×9=81——1结尾；刚好互为对方）
// 所以答案只有4和9
int main() {
    int n;
    cin >> n;
    if (n >= 4) {
        cout << "4 9";
    }
    else {
        cout << "0";
    }
    return 0;
}