#include <iostream>
using namespace std;


int main() {
	//zombie等于1时代表僵尸出现
	int zombie = 0;
	//game等于0的时候表示游戏还没结束，等于1的时候游戏结束
	int game = 0;

	while (game == 0) {
		if (zombie == 1) {
			//输出“豌豆射手发射豌豆”
			cout << "豌豆射手发射豌豆" << endl;
		}
		else {
			cout << "不发射豌豆" << endl;
		}

		for (int i = 0; i < 3; i++) {
			cout << "向日葵摇摆第" << i << "次" << endl;
		}
		cout << "阳光！" << endl;
		game++;
	}
	do {
		if (zombie == 1) {
			//输出“豌豆射手发射豌豆”
			cout << "豌豆射手发射豌豆" << endl;
		}
		else {
			cout << "不发射豌豆" << endl;
		}

		for (int i = 0; i < 3; i++) {
			cout << "向日葵摇摆第" << i << "次" << endl;
		}
		cout << "阳光！" << endl;
		game--;
	} while (game != 0);

}