#include <iostream>
#include <iomanip>
using namespace std;

// ��Ŀ����
// ��֪m = max��a��b��c�� / ��max��a + b��b��c�� * max��a��b��b + c������
// ����max��a��b��c������������a��b��c�����ֵ��

// ����
// ������������a��b��c���м��ÿո�ֿ�

// ���
// ��m��ֵ��������λС����

double max(int a, int b, int c) {
	if (a >= b && a >= c) {
		return a;
	}
	else if (b >= c && b >= a) {
		return b;
	}
	else {
		return c;
	}
}

int main() {
	int a, b, c;
	float m;
	cin >> a >> b >> c;
	m = max(a, b, c) / (max(a + b, b, c) * max(a, b, b + c));
	cout << fixed << setprecision(3) << m << endl;
}