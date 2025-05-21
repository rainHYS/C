#include <iostream>
using namespace std;

int n, m, t, sx, sy, fx, fy;
int** mase;

int main() {
	cin >> n >> m >> t;
	mase = new int* [n];
	for (int i = 0; i < n; i++) {
		mase[i] = new int[m];
	}
}