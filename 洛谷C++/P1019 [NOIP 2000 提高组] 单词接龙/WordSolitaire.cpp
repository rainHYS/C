#include <iostream>
using namespace std;

int n;
string* word;

int main() {
	cin >> n;
	word = new string[n+1]();
	for (int i = 1; i <= n; i++) {
		cin >> word[i];
	}
	cin >> word[0];
}