#include <iostream>
#include <math.h>
using namespace std;

// ��ʹ�����������ʵ��

class calculator {
private:
	string array;
	int arrayLength;
public:
	// ���캯����ֱ�ӽ�����ת��������
	calculator() {
		string tempArray;
		cout << "�����������";
		cin >> tempArray;
		arrayLength = tempArray.length();
		array.resize(arrayLength);  // �ȸ�array����ռ�
		for (int i = 0; i < arrayLength; i++) {
			array[i] = tempArray[arrayLength - 1 - i];
		}
		for (int i = 0; i < arrayLength; i++) {
			cout << array[i];
		}
		cout << endl;
	}
	// addend n.����
	// augend n.������
	calculator operator +(calculator& augend) {
		string arraySum;
		int carry=0;
		for (int i = 0; i < max(this->arrayLength, augend.arrayLength); i++) {
			arraySum[i] = this->array[i] + augend.array[i]+carry;
			if (arraySum[i] > 9) {
				carry = 1;
				arraySum[i] -= 10;
			}
			else {
				carry = 0;
			}
		}
		if (carry) {
			carry += '0';
		}
		
		return 
	}
};

int main() {
	calculator a, b;

}