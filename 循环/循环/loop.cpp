#include <iostream>
using namespace std;


int main() {
	//zombie����1ʱ����ʬ����
	int zombie = 0;
	//game����0��ʱ���ʾ��Ϸ��û����������1��ʱ����Ϸ����
	int game = 0;

	while (game == 0) {
		if (zombie == 1) {
			//������㶹���ַ����㶹��
			cout << "�㶹���ַ����㶹" << endl;
		}
		else {
			cout << "�������㶹" << endl;
		}

		for (int i = 0; i < 3; i++) {
			cout << "���տ�ҡ�ڵ�" << i << "��" << endl;
		}
		cout << "���⣡" << endl;
		game++;
	}
	do {
		if (zombie == 1) {
			//������㶹���ַ����㶹��
			cout << "�㶹���ַ����㶹" << endl;
		}
		else {
			cout << "�������㶹" << endl;
		}

		for (int i = 0; i < 3; i++) {
			cout << "���տ�ҡ�ڵ�" << i << "��" << endl;
		}
		cout << "���⣡" << endl;
		game--;
	} while (game != 0);

}