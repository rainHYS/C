#include <iostream>
#include <string>
using namespace std;

class calculator {
private:
	string array;
	int arrayLength;
public:
	// ���캯��
	calculator() {
		string tempArray;
		cout << "�����������";
		cin >> tempArray;
		arrayLength = (int)tempArray.length();
		array.resize(arrayLength);
		for (int i = 0; i < arrayLength; i++) {
			array[i] = tempArray[arrayLength - 1 - i]; // ���Ŵ洢����λ��ǰ
		}
	}

	// �ڲ����캯��
	calculator(string s) : array(s), arrayLength((int)s.length()) {}

	// �ӷ����������
	calculator operator+(calculator& augend) {
		string result;
		int carry = 0;
		int maxLength = max(this->arrayLength, augend.arrayLength);

		for (int i = 0; i < maxLength || carry; i++) {
			int digit1 = (i < this->arrayLength) ? (this->array[i] - '0') : 0;
			int digit2 = (i < augend.arrayLength) ? (augend.array[i] - '0') : 0;

			int sum = digit1 + digit2 + carry;
			carry = sum / 10;
			result.push_back((sum % 10) + '0');
		}

		// ��ת����ȷ��˳��
		reverse(result.begin(), result.end());
		return calculator(result);
	}

	void display() {
		// �Ѿ�������洢��ֱ�����
		cout << array << endl;
	}
};

int main() {
	calculator a, b;
	calculator c = a + b;
	cout << "��ӽ����";
	c.display();
	return 0;
}