#include <iostream>
using namespace std;

// ����������һ��N* M��������̣�1 <= N <= 100��1 <= M <= 100��
// ����������а����ж��ٸ������Σ����ٸ������Σ������������Σ���

// ���磺��N = 2��M = 3ʱ��
// �����εĸ�����8�������߳�Ϊ1����������6�����߳�Ϊ2����������2���������εĸ�����10��

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
	cout << "�����Σ�" << square << endl;
	cout << "�����Σ�" << rectangle << endl;
}