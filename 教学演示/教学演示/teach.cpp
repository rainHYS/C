#include<iostream>
using namespace std;

int step = 0;

void hanoi(int n, char pos1, char pos2, char pos3) {
	if (n == 1) {
		step++;
		cout << pos1 << " To " << pos3 << endl;
		return;
	}
	hanoi(n - 1, pos1, pos3, pos2);
	step++;
	cout << pos1 << " To " << pos3 << endl;
	hanoi(n - 1, pos2, pos1, pos3);
}


int main() {
	int n;
	cin >> n;
	hanoi(n, '1', '2', '3');
	cout << step << endl;
	return 0;
}
