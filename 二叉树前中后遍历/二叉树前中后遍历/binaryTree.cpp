#include <iostream>
using namespace std;

// 题目描述：
// 给出一个n个结点的二叉树，请求出二叉树的前序遍历，中序遍历和后序遍历。

// 输入：
// 第一行有一个整数n（0 < n < 26），表示二叉树有n个结点；
// 以下n行，每行第一个为一个大写字母表示结点的值，第i+1行的结点编号为i
// 后面为两整数，第一个表示该结点左孩子结点编号，第二个表示该结点右孩子的结点编号，
// 如果该编号为0 0表示没有；（编号为1的结点是树的根）

// 输出：
// 共三行，第一行为二叉树的前序遍历，第二行为中序遍历，第三行为后序遍历；

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