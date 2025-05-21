#include <iostream>
using namespace std;

void recursionCombination(int current, int maxN, int maxR, int result[], bool status[]) {
	if (current > maxR) {
		for (int i = 1; i <= maxR; i++) {
			cout << result[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= maxN; i++) {
		if (!status[i] && i > result[current - 1]) {
			status[i] = true;
			result[current] = i;
			recursionCombination(current + 1, maxN, maxR, result, status);
			status[i] = false;
			result[current] = 0;	
		}
	}
	return;
}

int main() {
	int n, r;
	cin >> n >> r;
	int* result = new int[r + 1]();
	bool* status = new bool[n + 1]();
	recursionCombination(1, n, r, result, status);

	return 0;
}