#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxSize 4

/***********************
 * 1️、手动实现：顺序循环队列
 ***********************/
typedef struct {
    int data[maxSize];
    int front, rear;
} SqQueue;

void initQueue(SqQueue& Q) {
    Q.rear = Q.front = 0;
}

bool isEmpty(SqQueue Q) {
    return Q.rear == Q.front;
}

bool enQueue(SqQueue& Q, int x) {
    if ((Q.rear + 1) % maxSize == Q.front) {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % maxSize;
    return true;
}

bool deQueue(SqQueue& Q, int& x) {
    if (Q.rear == Q.front) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % maxSize;
    return true;
}

/************************
 * 2️、使用 vector 实现简单队列逻辑（非循环）
 ************************/
struct VectorQueue {
    vector<int> v;
    int front = 0;

    void push(int x) {
        v.push_back(x);
    }

    bool pop(int& x) {
        if (front >= v.size()) {
            return false;
        }
        x = v[front++];
        return true;
    }

    bool isEmpty() {
        return front >= v.size();
    }
};

/************************
 * 3️、使用 STL 中的 queue 容器
 ************************/
void STLQueueDemo() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "STL queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

/***********************
 * 主函数：测试三种队列
 ***********************/
int main() {
    // 测试 1️、手动循环队列
    SqQueue Q;
    initQueue(Q);
    enQueue(Q, 10);
    enQueue(Q, 20);
    enQueue(Q, 30);

    int val = 0;
    cout << "循环队列: ";
    while (!isEmpty(Q)) {
        deQueue(Q, val);
        cout << val << " ";
    }
    cout << endl;

    // 测试 2️、vector 模拟队列
    VectorQueue vq;
    vq.push(10);
    vq.push(20);
    vq.push(30);

    cout << "vector队列: ";
    while (!vq.isEmpty()) {
        vq.pop(val);
        cout << val << " ";
    }
    cout << endl;

    // 测试 3️、STL queue
    STLQueueDemo();

    return 0;
}
