#include <iostream>
using namespace std;

void recursionPermutations(int n, int max, bool status[], int result[]) {
	if (n > max) {
		for (int i = 1; i <= max; i++) {
			cout << result[i];
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= max; i++) {
		if (!status[i]) {
			status[i] = true;
			result[n] = i;
			recursionPermutations(n + 1, max, status, result);
			status[i] = false;
			result[n] = 0;
		}
	}
	return;
}

int main() {
	int n;
	cout << "ÇëÊäÈën£º";
	cin >> n;
	int* result = new int[n]();
	bool* status = new bool[n + 1]();
	recursionPermutations(1, n, status, result);
	return 0;
}