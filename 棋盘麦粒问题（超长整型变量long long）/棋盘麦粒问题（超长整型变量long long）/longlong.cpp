#include <iostream>
using namespace std;
int main() {
	long long wheat = 2;	//wheat n.����������Ϊunsigned long long�޷��ų�������
	// �޷��ų��������� C++ 11 ��׼����ӵ�
	// long long �з��ų������ͷ�Χֻ��-2^63~2^63-1��û������64��
	// ��������۵���Ŀϵͳ����Ҫ��������Ľ�������Ծ���ôд�����ô����Ӽ���
	int sum = 0;
	for (int i = 0; i < 64; i++) {
		cout << i + 1 << " " << wheat << endl;
		wheat *= 2;
		sum += wheat;
	}
	cout << sum;
}