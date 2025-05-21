#include <iostream>
using namespace std;

int n;
int cal = 0;
int seasoning[11];

void calFuction(int current, int sum) {
	if (current > 10) {
		if (sum == n) {
			cal++;
		}
		return;
	}
	for (int i = 1; i <= 3; i++) {
		seasoning[current] = i;
		calFuction(current + 1, sum + i);
		seasoning[current] = 0;
	}
}

void roastChicken(int current, int sum) {
	if (current > 10) {
		if (sum == n) {
			for (int i = 1; i <= 10; i++) {
				cout << seasoning[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= 3; i++) {
		seasoning[current] = i;
		roastChicken(current + 1, sum + i);
		seasoning[current] = 0;
	}
}

int main() {
	cin >> n;
	if (n > 30 || n < 10) {
		cout << 0;
		return 0;
	}
	calFuction(1, 0);
	cout << cal << endl;
	roastChicken(1, 0);
	return 0;
}