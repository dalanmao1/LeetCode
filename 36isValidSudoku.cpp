#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 36. ��Ч������
 * �����ж�һ��?9 x 9 �������Ƿ���Ч��ֻ��Ҫ �������¹��� ����֤�Ѿ�����������Ƿ���Ч���ɡ�
 * ����?1-9?��ÿһ��ֻ�ܳ���һ�Ρ�
 * ����?1-9?��ÿһ��ֻ�ܳ���һ�Ρ�
 * ����?1-9?��ÿһ���Դ�ʵ�߷ָ���?3x3?����ֻ�ܳ���һ�Ρ�����ο�ʾ��ͼ��
 * ע�⣺һ����Ч�������������ѱ���䣩��һ���ǿɽ�ġ�ֻ��Ҫ�������Ϲ�����֤�Ѿ�����������Ƿ���Ч���ɡ��հ׸���?'.'?��ʾ��
 */

/**���
 * ����������ά���飬�ֱ��¼ÿһ�У�ÿһ��0��9���ֵĳ��ָ�����
 * Ȼ���ٽ���һ����ά���飬��¼ÿһ��С�ľŹ���1��9�������ֳ��ֵĴ�����
 * ����board������ֵ��Ϊ��ʱ������Ӧ����ֵ++���ж������ֵ�Ƿ����1�Ϳɵõ������Ƿ�ϸ�
 */

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[9][9] = {0};
        int column[9][9] = {0};
        int small[3][3][9] = {0}; //ÿ��С������1-9���ֵĴ���
        int value = 0;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {

                if (board[i][j] == '.')
                {
                    continue;
                }
                else
                {
                    value = board[i][j] - '0' - 1; //ע��Ҫ-1��-��0����j�ķ�Χֻ��0-8
                    ++row[i][value];
                    ++column[j][value];
                    ++small[i / 3][j / 3][value];
                    if (row[i][value] > 1 || column[j][value] > 1 || small[i / 3][j / 3][value] > 1)
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution sol;
    cout << sol.isValidSudoku(board);
    return 0;
}