#include <iostream>
#include <string>
using namespace std;

// ��Ŀ������
// �кܶ��Ӳ�Ұ���һ�У������泯�ϵģ�Ҳ�б��泯�ϵġ����泯�ϵ���1��ʾ�����泯�ϵ���0��ʾ��
// ����Ҫ������еĵ�һ��Ӳ�ҿ�ʼ�����ӵ�һ��Ӳ�ҿ�ʼ��ǰ���ɸ�Ӳ��ͬʱ���棬
// �����Ҫ������Ӳ�ҷ������泯�ϣ�����Ҫ���������Ĳ������ٴΣ�

// ���룺
// һ���ַ�������0��1��ɣ���ʾӲ�ҵĳ�ʼ״̬��

// �����
// һ����������ʾҪ��ת�����ٴ�����

int main() {
	string coinList;
	int count=0;
	cin >> coinList;
	for (int i = coinList.length() - 1; i >= 0; i--) {
		cout << "��" << i + 1 << "λ" << coinList[i] << endl;
		if (coinList[i] == '0') {
			for (int j = 0; j <= i; j++) {
				coinList[j] = coinList[j] ^ 1;
			}
			count++;
		}
		for (int j = 0; j < coinList.length(); j++) {
			cout << coinList[j];
		}
		cout << endl;
	}
	cout << count;
}