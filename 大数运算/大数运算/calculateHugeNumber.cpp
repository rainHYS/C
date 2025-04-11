#include <iostream>
#include <string>
using namespace std;

class calculator {
private:
	string array;
	int arrayLength;
public:
	// 构造函数
	calculator() {
		string tempArray;
		cout << "请输入大数：";
		cin >> tempArray;
		arrayLength = (int)tempArray.length();
		array.resize(arrayLength);
		for (int i = 0; i < arrayLength; i++) {
			array[i] = tempArray[arrayLength - 1 - i]; // 反着存储，个位在前
		}
	}

	// 内部构造函数
	calculator(string s) : array(s), arrayLength((int)s.length()) {}

	// 加法运算符重载
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

		// 反转回正确的顺序
		reverse(result.begin(), result.end());
		return calculator(result);
	}

	void display() {
		// 已经是正序存储，直接输出
		cout << array << endl;
	}
};

int main() {
	calculator a, b;
	calculator c = a + b;
	cout << "相加结果：";
	c.display();
	return 0;
}