#include <iostream>
using namespace std;

typedef struct list {
	int data;
	struct list* next;
}lNode, * linkList;

void buildList(linkList& head, int array[], int len) {
	head = (linkList)malloc(sizeof(list));
	lNode* newNode, * rear = NULL;
	rear = head;
	for (int i = 0; i < len; i++) {
		newNode = (linkList)malloc(sizeof(list));
		newNode->data = array[i];
		rear->next = newNode;
		rear = newNode;
	}
	rear->next = NULL;
}

void outList(linkList head) {
	lNode* current = head->next; // 跳过头节点
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int main() {
	linkList head;
	int array[5] = { 111,222,333,444,555 };
	buildList(head, array, 5);
	outList(head);
}