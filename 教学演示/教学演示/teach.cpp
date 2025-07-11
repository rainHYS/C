#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[1000];
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	return 0;
}