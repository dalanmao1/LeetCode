#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
bool Matrix[14][14];
int minvalue = 14 * 14;

int DFS(int n, int m, int _count) {
  int row = 0, column = 0;
  bool full = true;

  if (_count > minvalue) return 0;

  for (int i = 0; i < n && full; i++)  //检查空白的地方
    for (int j = 0; j < m && full; j++) {
      if (Matrix[i][j] == 0) {
        full = false;
        row = i;
        column = j;
      }
    }

  if (full)
    return (minvalue = min(_count, minvalue));  //没有可以填充的地方了，递归结束

  /**开始填充，从大到小**/
  for (int len = min(n - row, m - column); len >= 1; len--) {
    bool empty = true;

    for (int i = row; i < (row + len) && empty; i++) {
      for (int j = column; j < (column + len) && empty; j++) {
        if (Matrix[i][j] == 1) empty = false;
      }
    }

    if (empty == false) {  //表示方形太大了，换下一个小的
      continue;
    }

    for (int i = row; i < (row + len); i++) {
      for (int j = column; j < (column + len); j++) {
        Matrix[i][j] = 1;
      }
    }

    DFS(n, m, _count + 1);

    for (int i = row; i < (row + len); i++) {
      for (int j = column; j < (column + len); j++) {
        Matrix[i][j] = 0;
      }
    }
  }
}

int SquareNum(int n, int m) {
  // int count = 0;
  if (n == m) return 1;               //特殊情况
  memset(Matrix, 0, sizeof(Matrix));  //先清空数组
  DFS(n, m, 0);
  return minvalue;
}

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  cout << SquareNum(n, m);
  return 0;
}
