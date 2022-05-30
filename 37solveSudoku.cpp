#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 37. ������
 * ��дһ������ͨ�����ո�������������⡣
 * �����Ľⷨ�� ��ѭ���¹���
 * ����?1-9?��ÿһ��ֻ�ܳ���һ��
 * ����?1-9?��ÿһ��ֻ�ܳ���һ�Ρ�
 * ����?1-9?��ÿһ���Դ�ʵ�߷ָ���?3x3?����ֻ�ܳ���һ�Ρ�����ο�ʾ��ͼ��
 * �������ֿո��������������֣��հ׸���?'.'?��ʾ��
 */

/**���
 * ����������ά���飬�ֱ��¼ÿһ�У�ÿһ��0��9���ֵĳ��ָ�����
 * Ȼ���ٽ���һ����ά���飬��¼ÿһ��С�ľŹ���1��9�������ֳ��ֵĴ�����
 * ����board������ֵ��Ϊ��ʱ������Ӧ����ֵ++��spaces��¼�հ׵�ֵ
 *
 * �ж����֮������dfs���������α����հ׵Ľ��
 * ����Ҫ���Ǽ�֦�������20���հף�ÿ����9�ֿ��ܣ�ʱ�临�ӶȻ��൱�󣬵����ǡǡ�����м�֦
 * ��һ���㿪ʼ����������ĸ�0-8�����жϣ�����0���У��ͱ�����һ���㣬���һֱ����������һ����0-8������ʱ�����ء�
 * ����һ����0-8��λ�ü���������
 */

class Solution
{
private:
    bool row[9][9] = {0};
    bool column[9][9] = {0};
    bool small[3][3][9] = {0}; //ÿ��С������1-9���ֵĴ���
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
                    value = board[i][j] - '0' - 1; //ע��Ҫ-1��-��0����j�ķ�Χֻ��0-8
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
