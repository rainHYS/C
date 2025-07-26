#include <iostream>
#include <cmath>
using namespace std;
struct student {
	string name;
	int score;
};
int main() {
	int n;
	cin >> n;
	student stu[25];
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].score;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (stu[i].score < stu[j].score || (stu[i].score == stu[j].score && stu[i].name > stu[j].name)) {
				student temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << stu[i].name << " " << stu[i].score << endl;
	}
	return 0;
}
