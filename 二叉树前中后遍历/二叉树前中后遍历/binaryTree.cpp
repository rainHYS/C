#include <iostream>
using namespace std;

// ��Ŀ������
// ����һ��n�����Ķ��������������������ǰ���������������ͺ��������

// ���룺
// ��һ����һ������n��0 < n < 26������ʾ��������n����㣻
// ����n�У�ÿ�е�һ��Ϊһ����д��ĸ��ʾ����ֵ����i+1�еĽ����Ϊi
// ����Ϊ����������һ����ʾ�ý�����ӽ���ţ��ڶ�����ʾ�ý���Һ��ӵĽ���ţ�
// ����ñ��Ϊ0 0��ʾû�У������Ϊ1�Ľ�������ĸ���

// �����
// �����У���һ��Ϊ��������ǰ��������ڶ���Ϊ���������������Ϊ���������

struct tree {
	char caps;
	int lChild, rChild;
}treeInfo[26];

void preOrder(int currentNode) {
	if (treeInfo[currentNode].lChild == 0 && treeInfo[currentNode].rChild == 0) {
		cout << treeInfo[currentNode].caps;
		return;
	}
	cout << treeInfo[currentNode].caps;
	preOrder(treeInfo[currentNode].lChild);
	preOrder(treeInfo[currentNode].rChild);
	return;
}

void inOrder(int currentNode) {
	if (treeInfo[currentNode].lChild == 0 && treeInfo[currentNode].rChild == 0) {
		cout << treeInfo[currentNode].caps;
		return;
	}
	inOrder(treeInfo[currentNode].lChild);
	cout << treeInfo[currentNode].caps;
	inOrder(treeInfo[currentNode].rChild);
	return;
}

void postOrder(int currentNode) {
	if (treeInfo[currentNode].lChild == 0 && treeInfo[currentNode].rChild == 0) {
		cout << treeInfo[currentNode].caps;
		return;
	}
	postOrder(treeInfo[currentNode].lChild);
	postOrder(treeInfo[currentNode].rChild);
	cout << treeInfo[currentNode].caps;
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> treeInfo[i].caps>> treeInfo[i].lChild>> treeInfo[i].rChild;
	}
	for (int i = 1; i <= n; i++) {
		cout << treeInfo[i].caps  << treeInfo[i].lChild << treeInfo[i].rChild <<endl;
	}
	cout << endl;
	preOrder(1);
	cout << endl;
	inOrder(1);
	cout << endl;
	postOrder(1);
}