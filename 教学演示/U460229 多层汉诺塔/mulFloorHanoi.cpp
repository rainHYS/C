#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unsigned long long sum = 6 * pow(2, n) - 4 * n - 6;
    cout << sum;
    return 0;
}