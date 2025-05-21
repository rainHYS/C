#include <iostream>
using namespace std;

int main() {
	int n, m, square = 0, rectangle = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int x = i; x < n; x++) {
				for (int y = j; y < m; y++) {
					if (y - j == x - i) {
						square++;
					}
					else {
						rectangle++;
					}
				}
			}
		}
	}
	cout << square << " " << rectangle << endl;
}