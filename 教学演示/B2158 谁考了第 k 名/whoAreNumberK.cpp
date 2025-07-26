#include<iostream>
using namespace std;
struct student {
	int number;
	float score;
};
int main() {
	int n, k;
	cin >> n >> k;
	k--;
	student stu[105];
	for (int i = 0; i < n; i++) {
		cin >> stu[i].number;
		cin >> stu[i].score;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (stu[i].score < stu[j].score) {
				student temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
	/*cout << "________________________" << endl;
	for (int i = 0; i < n; i++) {
		cout << stu[i].number << " " << stu[i].score << endl;
	}*/
	printf("%d %g\n", stu[k].number, stu[k].score);
	return 0;
}
