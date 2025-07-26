#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_set>
#include <string>
using namespace std;

vector<vector<int>> magicSquares = { {1,2,3,4},{8,7,6,5} };
vector<vector<int>> resultSquares;
queue<pair<vector<vector<int>>, string>> q;
unordered_set<string> visited;

// °Ñ¾ØÕó×´Ì¬×ªÎª×Ö·û´®
string matrixToString(vector<vector<int>>& mtx) {
	string s;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 4; ++j)
			s += to_string(mtx[i][j]) + ",";
	return s;
}

vector<vector<int>> A(vector<vector<int>> tempSquares) {
	for (int i = 0; i < 4; i++) {
		swap(tempSquares[0][i], tempSquares[1][i]);
	}
	return tempSquares;
}

vector<vector<int>> B(vector<vector<int>> tempSquares) {
	int temp0 = tempSquares[0][3];
	int temp1 = tempSquares[1][3];
	for (int i = 3; i >= 1; i--) {
		tempSquares[0][i] = tempSquares[0][i - 1];
		tempSquares[1][i] = tempSquares[1][i - 1];
	}
	tempSquares[0][0] = temp0;
	tempSquares[1][0] = temp1;
	return tempSquares;
}

vector<vector<int>> C(vector<vector<int>> tempSquares) {
	int temp = tempSquares[0][1];
	tempSquares[0][1] = tempSquares[1][1];
	tempSquares[1][1] = tempSquares[1][2];
	tempSquares[1][2] = tempSquares[0][2];
	tempSquares[0][2] = temp;
	return tempSquares;
}

void bfs() {
	while (!q.empty()) {
		vector<vector<int>> curSquares = q.front().first;
		string curPath = q.front().second;
		q.pop();

		string key = matrixToString(curSquares);
		if (visited.count(key)) continue;
		visited.insert(key);

		// A²Ù×÷
		vector<vector<int>> nextA = A(curSquares);
		if (nextA == resultSquares) {
			cout << curPath.length() + 1 << endl;
			cout << curPath + "A" << endl;
			return;
		}
		q.push({ nextA, curPath + "A" });

		// B²Ù×÷
		vector<vector<int>> nextB = B(curSquares);
		if (nextB == resultSquares) {
			cout << curPath.length() + 1 << endl;
			cout << curPath + "B" << endl;
			return;
		}
		q.push({ nextB, curPath + "B" });

		// C²Ù×÷
		vector<vector<int>> nextC = C(curSquares);
		if (nextC == resultSquares) {
			cout << curPath.length() + 1 << endl;
			cout << curPath + "C" << endl;
			return;
		}
		q.push({ nextC, curPath + "C" });
	}
}

int main() {
	resultSquares.resize(2, vector<int>(4));
	cin >> resultSquares[0][0]
		>> resultSquares[0][1]
		>> resultSquares[0][2]
		>> resultSquares[0][3]
		>> resultSquares[1][3]
		>> resultSquares[1][2]
		>> resultSquares[1][1]
		>> resultSquares[1][0];
	if (resultSquares == magicSquares) {
		cout << 0 << endl;
		return 0;
	}
	else {
		q.push({ magicSquares, "" });
		bfs();
		return 0;
	}
}