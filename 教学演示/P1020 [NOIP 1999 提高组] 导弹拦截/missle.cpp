#include <iostream>
using namespace std;

int main() {
    int a[100] = { 0 };
    int cnt = 1;
    for (int i = 0; i < 100; i++) {
        if (cin.peek() == '\n') {
            break;
        }
        cin >> a[i];
    }
    for (int i = 1; a[i] != 0; i++) {
        if (a[i] > a[i - 1]) {
            cnt++;
        }
    }
    cout << cnt;
}