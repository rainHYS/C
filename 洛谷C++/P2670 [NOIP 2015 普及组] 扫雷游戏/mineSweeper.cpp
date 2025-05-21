#include <iostream>
using namespace std;

int main() {
    // 声明两个整数变量n和m，分别表示地雷区的行数和列数
    int n, m;
    // 从标准输入读取用户输入的值，分别赋值给n和m
    cin >> n >> m;


    // 动态分配一个指针数组，数组大小为n（行数），每个元素是一个char*指针
    char** mineField = new char* [n];
    // 遍历每一行，为每一行动态分配一个char数组，数组大小为m（列数）
    for (int i = 0; i < n; i++) {
        mineField[i] = new char[m];
    }

    // 开始读取用户输入的雷区
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mineField[i][j]; // 读取每个格子的字符（* 或 ?）
        }
    }

    // 开始检验每个位置旁边有多少颗雷
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 如果当前格子不是地雷格（*），则计算周围地雷的数量
            if (mineField[i][j] != '*') {
                int mineNum = 0; // 初始化地雷计数器
                // 遍历当前格子的周围8个格子
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        // 检查边界条件：确保k和l在合法范围内
                        if (k >= 0 && k < n && l >= 0 && l < m) {
                            // 如果周围格子是地雷格（*），则地雷计数器加1
                            if (mineField[k][l] == '*') {
                                mineNum++;
                            }
                        }
                    }
                }
                // 将地雷数量转换为字符并存储到当前格子
                // '0' + mineNum 是将数字转换为对应的字符（例如，1 -> '1'，2 -> '2'）
                mineField[i][j] = '0' + mineNum;
            }
        }
    }

    // 输出最终的地雷分布结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mineField[i][j]; // 输出每个格子的字符
        }
        cout << endl; // 换行
    }

    return 0;
}