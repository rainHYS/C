#include <iostream>
using namespace std;

// ������Nλ��������ҹ�������Ҫ�����ֵ�Ͳ��
// ��N������ֻ��һ���ֵ�Ͳ��������ͬʱֻ���������˹���
// ÿ���˵�����������ʱ����֪�������������ͬʱ����������ʱ�����ߵ������Ǹ��˵������������ʱ�䡣
// ���һ������������N���˾�����ţ�������N���˵���̹���ʱ�䡣

// ���磺�м��ұ����ĸ��ˣ����ǹ��������ʱ��ֱ���1��2��5��10��
// ������2�����ȹ��ţ�Ȼ�����ܵ������˻�ȥ��ʣ�µ��ˡ�
// ���ü��ҹ�ȥ��2���ӣ����׻�����1���ӣ����ױ���ȥ��5���ӣ�
// �׻�����1���ӣ����׶��ٹ�ȥ��10���ӣ����ܹ���Ҫ19���ӡ�

int fastFirst(int* costTime, int n) {
	int sum = 0;
	while (1) {
		sum += costTime[n - 1];
		n--;
		if (n==1) {
			return sum;
		}
		else {
			sum += costTime[0];
		}
	}
}

int fastSlow(int* costTime, int n) {
	int sum = 0;
	while (n > 1) {
		if (n > 3) {
			sum += costTime[0] + 2 * costTime[1] + costTime[n - 1];
			n -= 2;
		}
		else if (n == 3) {
			sum += costTime[0] + costTime[n-1];
			n--;
		}
		else{
			sum += costTime[1];
			n -= 2;
		}
	}
	return sum;
}

int main() {
	int n, result1, result2;
	cin >> n;
	int* costTime = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> costTime[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (costTime[i] > costTime[j]) {
				int temp = costTime[i];
				costTime[i] = costTime[j];
				costTime[j] = temp;
			}
		}
	}

	// ��ȡ���ֲ��ԣ�

	// ��һ�ֲ��ԣ�������ȫ���������ؽ���
	result1 = fastFirst(costTime, n);
	cout << result1 << endl;
	// �ڶ��ֲ��ԣ�һ��һ��������ӣ����ʹο���ӣ����أ���������ʹ������ӣ��ο�أ������ظ�ֱ��ȫԱ����
	result2 = fastSlow(costTime, n);
	cout << result2 << endl;
	return 0;
}