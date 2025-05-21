#include <iostream>
using namespace std;

void recursionSum(int current, int maxN, int maxK, int num[], int result[], bool status[]) {
	int sum = 0;
	if (current > maxK) {
		for (int i = 1; i <= maxK; i++) {
			sum = sum + result[i];
		}
		bool check = true;
		for (int i = 2; i < sqrt(sum); i++) {
			if (!(sum % i)) {
				check = false;
				break;
			}
		}
		if (check) {
			for (int j = 1; j <= maxK; j++) {
				cout << result[j];
				if (j < maxK) {
					cout << "+";
				}
			}
			cout << "=" << sum;
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= maxN; i++) {
		if (!status[i] && num[i] > result[current - 1]) {
			status[i] = true;
			result[current] = num[i];
			recursionSum(current + 1, maxN, maxK, num, result, status);
			status[i] = false;
			result[current] = 0;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	int* num = new int[n + 1]();
	int* result = new int[k + 1]();
	bool* status = new bool[n + 1]();
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	recursionSum(1, n, k, num, result, status);
}