/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int pos)
    {
        if (pos >= word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[pos])
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        bool res = dfs(board, word, i - 1, j, pos + 1) || dfs(board, word, i, j - 1, pos + 1) || dfs(board, word, i + 1, j, pos + 1) || dfs(board, word, i, j + 1, pos + 1);
        board[i][j] = c;
        return res;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
};
// @lc code=end
