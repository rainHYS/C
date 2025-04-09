#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N > 0) {
		cout << "positive" << endl;
	}
	else if (N == 0) {
		cout << "zero" << endl;
	}
	else {
		cout << "negative" << endl;
	}

	//if(条件){ 
	// ①
	// }
	//如果满足了条件，则执行①

	//if(条件){ 
	// ①
	// }else{
	// ②
    //}
	//如果满足了条件，则执行①；如果不满足条件，则执行②

	//if(条件1){ 
	// ①
	// }else if(条件2){
	// ②
    //}else{
	// ③
	// }
	//如果满足了条件1，则执行①；如果满足条件2，则执行②；如果都不满足，则执行③
	do {} while (条件);
}