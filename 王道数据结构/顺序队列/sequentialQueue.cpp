#include <iostream>
using namespace std;

#define maxSize 4

typedef struct {
	int data[maxSize];
	int front, rear;
}sqQueue;

void initQueue(sqQueue& Q) {
	Q.rear = Q.front = 0;
}

bool isEmpty(sqQueue Q) {
	if (Q.rear == Q.front) {
		return true;
	}
	else {
		return false;
	}
}

bool enQueue(sqQueue& Q, int x) {
	if ((Q.rear + 1) % maxSize == Q.front) {
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % maxSize;
	return true;
}

//注意出队需要加&，引用调用x才能输出，否则只会输出0
bool deQueue(sqQueue& Q, int &x) {
	if (Q.rear == Q.front) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % maxSize;
	return true;
}

int main() {
	sqQueue Q;
	initQueue(Q);

	enQueue(Q, 10);
	enQueue(Q, 20);
	enQueue(Q, 30);

	int value = 0;
	while (!isEmpty(Q)) {
		deQueue(Q, value);
		cout << value << " ";
	}
	return 0;
}
