#include <iostream>
#include <algorithm>
using namespace std;

// 题目描述
// 有一个大晴天，Oliver 与同学们一共 N 人出游，他们走到一条河的东岸边，想要过河到西岸。而东岸边有一条小船。
// 船太小了，一次只能乘坐两人。每个人都有一个渡河时间 T，船划到对岸的时间等于船上渡河时间较长的人所用时间。
// 现在已知 N 个人的渡河时间 T，Oliver 想要你告诉他，他们最少要花费多少时间，才能使所有人都过河。
// 注意，只有船在东岸（西岸）的人才能坐上船划到对岸。

// 输入格式
// 输入文件第一行为人数 N，以下有 N 行，每行一个数。
// 第 i + 1 行的数为第 i 个人的渡河时间。

// 输出格式
// 输出文件仅包含一个数，表示所有人都渡过河的最少渡河时间。

// 输入样例
// 4
// 6
// 7
// 10
// 15

// 输出样例
// 42

int minTime(int* costTime, int n) {
    if (n == 1) return costTime[0];
    if (n == 2) return max(costTime[0], costTime[1]);
    if (n == 3) return costTime[0] + costTime[1] + costTime[2];

    int sum = 0;
    while (n > 3) {
        sum += min(
            costTime[1] + costTime[0] + costTime[n - 1] + costTime[1],
            costTime[n - 1] + costTime[0] + costTime[n - 2] + costTime[0]
        );
        n -= 2;
    }
    if (n == 3) sum += costTime[0] + costTime[1] + costTime[2];
    else if (n == 2) sum += costTime[1];
    return sum;
}

int main() {
    int n;
    cin >> n;
    int* costTime = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> costTime[i];
    }
    sort(costTime, costTime + n);

    cout << minTime(costTime, n) << endl;
    delete[] costTime;
    return 0;
}