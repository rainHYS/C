#include <iostream>
#include <algorithm>
using namespace std;

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