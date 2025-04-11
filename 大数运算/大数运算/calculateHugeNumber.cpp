#include <iostream>
#include <math.h>
using namespace std;

// 请使用运算符重载实现

class calculator {
private:
	string array;
	int arrayLength;
public:
	// 构造函数，直接将数据转换成数组
	calculator() {
		string tempArray;
		cout << "请输入大数：";
		cin >> tempArray;
		arrayLength = tempArray.length();
		array.resize(arrayLength);  // 先给array分配空间
		for (int i = 0; i < arrayLength; i++) {
			array[i] = tempArray[arrayLength - 1 - i];
		}
		for (int i = 0; i < arrayLength; i++) {
			cout << array[i];
		}
		cout << endl;
	}
	// addend n.加数
	// augend n.被加数
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