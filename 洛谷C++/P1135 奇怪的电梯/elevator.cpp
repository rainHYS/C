#include <iostream>
#include <climits>
using namespace std;

int n, a, b;
int* floorNum;
bool* status;
int* steps;
int minTime = INT_MAX;

void elevator(int pos, int time) {
	// 加了一个steps来剪枝，如果当前time次数大于当前位置的steps值，则直接跳过
	// 如果直接暴力地使用time > minTime来剪枝，会导致：  
	// 1. 可能错过某些中间节点较晚但能通往更短路径的情况，  
	// 2. 因为 minTime 是到达终点的全局最短时间，  
	//    在搜索过程中该值可能还没有被更新到真正的最优解，导致提前剪枝，漏掉更优路径。  
	// 3. 而使用 steps 数组记录每个位置的当前最短访问时间，能更准确地判断是否继续递归，  
	//    保证不会漏掉潜在更优解。
	if (pos > n || pos < 1 || time >= steps[pos]) {
		return;
	}
	steps[pos] = time;
	if (pos == b) {
		if (time < minTime) {
			minTime = time;
		}
		return;
	}
	status[pos] = true;
	elevator(pos + floorNum[pos], time + 1);
	elevator(pos - floorNum[pos], time + 1);
}

int main() {
	cin >> n >> a >> b;
	status = new bool[n + 1]();
	floorNum = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> floorNum[i];
	}
	steps = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		steps[i] = INT_MAX;
	}
	elevator(a, 0);
	if (minTime == INT_MAX) {
		cout << -1;
	}
	else {
		cout << minTime;
	}
}