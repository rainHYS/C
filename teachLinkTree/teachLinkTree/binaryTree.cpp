#include <iostream>
using namespace std;
#define Max 1000

struct tree {
	int data;
	struct tree* lChild;	//指向左子树的指针
	struct tree* rChild;	//指向右子树的指针
};
//递归
void preOrder(tree *currentNode) {
	if (currentNode==NULL) {
		return;
	}
	preOrder(currentNode->lChild);
	cout << currentNode->data;
	preOrder(currentNode->rChild);
	return;
}

int main() {
	int userInput[Max];
	int length;
	for (int i = 1;; i++) {
		cin >> userInput[i];
		if (userInput[i] == -1) {
			length = i;
			break;
		}
	}
	tree* treeInfo[Max];
	for (int i = 1; i < length; i++) {
		tree* newNode = new tree;
		newNode->data = userInput[i];
		newNode->lChild = NULL;
		newNode->rChild = NULL;
		treeInfo[i] = newNode;
		if (i != 1) {
			if (i % 2 == 0) {
				treeInfo[i / 2]->lChild = treeInfo[i];
			}
			else {
				treeInfo[i / 2]->lChild = treeInfo[i];
			}
		}
	}

	preOrder(treeInfo[1]);
}