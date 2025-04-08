#include <iostream>
//#include <bits\stdc++.h> ����ͷ
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
	// �ݹ����������
	outputTree(currentNode->lChild);
	// �ݹ����������
	outputTree(currentNode->rChild);
	// �����ǰ�ڵ������
	cout << currentNode->data << " ";
}

//�û������������Ĳ���������У�0������գ�-1����������ֹ

int main() {
	int userInput[MaxNode];	//Ϊ�����ѧ��userInput[0]������¼�������һλ���ģ����ݴ�λ��1��ʼ
	for (int i = 1;;i++) {
		cin >> userInput[i];
		if (userInput[i] == -1) {
			userInput[0] = i;
			break;
		}
	}
	////�����û���������Ƿ�ɹ��洢�����ڼǵ�ע�͵�
	//for (int i = 1; i < userInput[0]; i++) {
	//	cout << userInput[i] << " ";
	//}
	//cout << endl << "����˶�������" << userInput[0] << endl;

	//��ʼ����ʽ�洢������
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

	//����������
	int findFatherNode = userInput[0] - 1;
	int depth = 1;
	for (; findFatherNode != 1; depth++, findFatherNode /= 2) {}
	cout << "��ȣ�" << depth << endl;

	//�ݹ�����������
	outputTree(treeNode[1]);
	//������򻻸�coutλ�þ���


	return 0;
}