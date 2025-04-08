#include <iostream>
using namespace std;

int main() {
	float a;
	cin >> a;
	if (a > 0) {
		cout << "正数";
	}
	else if (a == 0) {
		cout << "零";
	}
	else {
		cout << "负数";
	}
}