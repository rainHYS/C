#include <iostream>
using namespace std;

// ��1~n�⼸�����������ѡȡ��������������п��ܵ�ѡ�񷽰���

// �����ʽ:
// ����һ������n��

// �����ʽ:
// ÿ�����һ�ַ�����
// ͬһ���ڵ��������������У�������������ǡ��1���ո����������û��ѡ�κ����ķ�����������С�

// ����������
// 3

// ���������
// 3 
// 2 
// 2 3 
// 1 
// 1 2 
// 1 2 3 

// ͷ�Է籩д�����ĳ���ʹ����α�ݹ�ʵ�֣���������ʵ�ǵ��ƣ�Ϊ���
void recurrenceEnum(int n, int max) {
	if (n == 0) {
		return;
	}
	for (int i = n; i <= max; i++) {
		for (int j = n; j <= i; j++) {
			cout << j << " ";
		}
		cout << endl;
	}
	recurrenceEnum(n - 1, max);
}

// ��ȷ�𰸣�ʹ�õݹ�ʵ��
void recursionEnum(int n){

}

int main() {
	int n;
	cout << "������n��";
	cin >> n;
	int max = n;
	recurrenceEnum(n, max);
	recursionEnum(n);
}