#include <iostream>
using namespace std;

int m, n;
int** maze;

#define maxSize 1000

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

bool deQueue(sqQueue& Q, int x) {
	if (Q.rear == Q.front) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % maxSize;
	return true;
}

int main() {
	cin >> m >> n;
	maze = new int* [m + 1];
	for (int i = 1; i <= m; i++) {
		maze[i] = new int[n + 1];
		for (int j = 1; j <= n; j++) {
			cin >> maze[i][j];
		}
	}
}