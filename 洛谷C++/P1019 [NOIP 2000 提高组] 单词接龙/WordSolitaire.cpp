#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
char start;
string* words;
int* used;
int** overlap;
int res = 0;

void recWord(string dragon, int index) {
	res = max(res, (int)dragon.size());
	used[index]++;
	for (int i = 0; i < n; i++) {
		if (overlap[index][i] && used[i] < 2) {
			recWord(dragon + words[i].substr(overlap[index][i]), i);
		}
	}
	used[index]--;
}

int main() {
	cin >> n;
	words = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}
	used = new int[n]();
	overlap = new int* [n]();
	for (int i = 0; i < n; i++) {
		overlap[i] = new int[n]();
	}

	cin >> start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			string suffix = words[i];
			string prefix = words[j];
			for (int k = 1; k < min(suffix.size(), prefix.size()); k++) {
				if (suffix.substr(suffix.size() - k, k) == prefix.substr(0, k)) {
					overlap[i][j] = k;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (words[i][0] == start) {
			recWord(words[i], i);
		}
	}
	cout << res;
}
