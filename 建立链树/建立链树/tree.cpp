#include <iostream>
//#include <bits\stdc++.h> 万能头
using namespace std;

#define MaxNode 1000

struct tree {
	int data;
	struct tree* lChild, * rChild;
};

void outputTree(tree *currentNode) {
	if (currentNode == NULL) {
		return;
	}
	// 递归遍历左子树
	outputTree(currentNode->lChild);
	// 递归遍历右子树
	outputTree(currentNode->rChild);
	// 输出当前节点的数据
	cout << currentNode->data << " ";
}

//用户持续输入树的层序遍历序列，0代表结点空，-1代表输入终止

int main() {
	int userInput[MaxNode];	//为方便教学，userInput[0]用来记录数据最后一位在哪，数据从位置1开始
	for (int i = 1;;i++) {
		cin >> userInput[i];
		if (userInput[i] == -1) {
			userInput[0] = i;
			break;
		}
	}
	////检验用户输入代码是否成功存储，后期记得注释掉
	//for (int i = 1; i < userInput[0]; i++) {
	//	cout << userInput[i] << " ";
	//}
	//cout << endl << "存进了多少数：" << userInput[0] << endl;

	//开始用链式存储构建树
	tree* treeNode[MaxNode];
	for (int i = 1; i < userInput[0]; i++) {
		if (userInput[i] == 0) {
			continue;
		}
		tree* newNode = new tree;
		//tree* newNode = (tree*)malloc(sizeof(tree));
		newNode->data = userInput[i];
		newNode->lChild = NULL;
		newNode->rChild = NULL;
		treeNode[i] = newNode;
		if (i != 1) {
			if (i % 2 == 0) {
				treeNode[i / 2]->lChild = treeNode[i];
			}
			else {
				treeNode[i / 2]->rChild = treeNode[i];
			}
		}
	}

	//输出树的深度
	int findFatherNode = userInput[0] - 1;
	int depth = 1;
	for (; findFatherNode != 1; depth++, findFatherNode /= 2) {}
	cout << "深度：" << depth << endl;

	//递归先序遍历输出
	outputTree(treeNode[1]);
	//中序后序换个cout位置就行


	return 0;
}