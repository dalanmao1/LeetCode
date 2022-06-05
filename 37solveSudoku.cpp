#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 37. 解数独
 * 编写一个程序，通过填充空格来解决数独问题。
 * 数独的解法需 遵循如下规则：
 * 数字?1-9?在每一行只能出现一次
 * 数字?1-9?在每一列只能出现一次。
 * 数字?1-9?在每一个以粗实线分隔的?3x3?宫内只能出现一次。（请参考示例图）
 * 数独部分空格内已填入了数字，空白格用?'.'?表示。
 */

/**解答
 * 建立两个二维数组，分别记录每一行，每一列0到9数字的出现个数，
 * 然后再建立一个三维数组，记录每一个小的九宫格1到9出现数字出现的次数，
 * 遍历board，当数值不为空时，对相应的数值++，spaces记录空白的值
 *
 * 判断完成之后，再用dfs遍历，依次遍历空白的结点
 * 最重要的是剪枝，如果有20个空白，每个有9种可能，时间复杂度会相当大，但这边恰恰不进行剪枝
 * 第一个点开始遍历，会从哪个0-8进行判断，假设0可行，就遍历下一个点，如此一直遍历，当有一个点0-8都不行时，返回。
 * 从上一个点0-8的位置继续往下走
 */

class Solution
{
private:
    bool row[9][9] = {0};
    bool column[9][9] = {0};
    bool small[3][3][9] = {0}; //每个小三格中1-9出现的次数
    int value = 0;
    vector<pair<int, int>> spaces;
    bool valid = 0;

public:
    void dfs(vector<vector<char>> &board, int pos)
    {
        if (pos == spaces.size())
        {
            valid = true;
            return;
        }
        int i = spaces[pos].first, j = spaces[pos].second;
        for (int count = 0; count < 9 && !valid; ++count)
        {
            if (row[i][count] == false && column[j][count] == false && small[i / 3][j / 3][count] == false)
            {
                board[i][j] = count + 1 + '0';
                row[i][count] = column[j][count] = small[i / 3][j / 3][count] = true;
                dfs(board, pos + 1);
                row[i][count] = column[j][count] = small[i / 3][j / 3][count] = false;
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    spaces.emplace_back(i, j);
                }
                else
                {
                    value = board[i][j] - '0' - 1; //注意要-1和-‘0’，j的范围只有0-8
                    row[i][value] = true;
                    column[j][value] = true;
                    small[i / 3][j / 3][value] = true;
                }
            }
        }
        dfs(board, 0);
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution sol;
    sol.solveSudoku(board);
    for (auto row : board)
    {
        for (auto i : row)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}
